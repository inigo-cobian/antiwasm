#include "driver.hpp"

using namespace std;
namespace antiwasm {
shared_ptr<Driver> Driver::instance_;
mutex Driver::mutex_;
bool Driver::error_;

size_t Driver::fileSize_;
size_t Driver::pointer_;
ifstream Driver::wasmFile_;
uint8_t *Driver::buffer_;
bool Driver::isParsing_;

shared_ptr<Driver> Driver::GetInstance() {
  lock_guard<mutex> lock(mutex_);
  if (instance_ == nullptr) {
    instance_ = make_shared<Driver>();
    instance_->pointer_ = -1;
    instance_->fileSize_ = -1;
    instance_->isParsing_ = false;
    instance_->error_ = false;
    BOOST_LOG_TRIVIAL(debug) << "[Driver] Creating a new instance of the driver";
  }
  BOOST_LOG_TRIVIAL(debug) << "[Driver] Returning instance of driver";
  return instance_;
}

uint8_t *Driver::GetNextBytes(size_t nBytesToBeRead) {
  if (Driver::HasReachedFileSize(nBytesToBeRead)) {
    return nullptr; // TODO avoid using nullptr
  }
  if (!Driver::IsCurrentlyParsing()) {
    error_ = true;
    return nullptr; // TODO avoid using nullptr
  }

  BOOST_LOG_TRIVIAL(debug) << "[Driver] Getting next " << (hex) << nBytesToBeRead << " bytes";
  auto *buffer = new char[nBytesToBeRead + 1];
  instance_->wasmFile_.seekg(instance_->pointer_, ios::beg);
  instance_->pointer_ += nBytesToBeRead;
  instance_->wasmFile_.read(buffer, nBytesToBeRead);

  for (int i = 0; i < nBytesToBeRead; i++) {
    // printf(" %02x", buffer[i]); //TODO format with Boost
  }
  // printf("\n");

  return (uint8_t *)buffer;
}

uint8_t *Driver::GetNextSectionHeader() {
  if (!Driver::IsCurrentlyParsing()) {
    error_ = true;
    return nullptr; // TODO avoid using nullptr
  }

  auto bytesToRead = MAX_SIZE_OF_SECTION_HEADER;
  if (Driver::HasReachedFileSize(MAX_SIZE_OF_SECTION_HEADER)) {
    bytesToRead = Driver::fileSize_ - Driver::pointer_;
  }

  BOOST_LOG_TRIVIAL(debug) << "[Driver] Getting next section header";
  auto *buffer = new char[bytesToRead];
  instance_->wasmFile_.seekg(instance_->pointer_, ios::beg);
  instance_->wasmFile_.read(buffer, MAX_SIZE_OF_SECTION_HEADER);
  instance_->pointer_ += antiwasm::sizeOfLeb128(reinterpret_cast<uint8_t *>(&buffer[1])) + SIZE_OF_SECTION_ID;
  BOOST_LOG_TRIVIAL(debug) << "[Driver] Pointer at position " << (hex) << instance_->pointer_;

  return reinterpret_cast<uint8_t *>(buffer);
}

void Driver::CloseFile() { instance_->wasmFile_.close(); }

bool Driver::HasReachedFileSize(size_t nextBytesSize) {
  if (pointer_ + nextBytesSize <= fileSize_)
    return false;
  return true;
}

bool Driver::IsCurrentlyParsing() { return isParsing_; }

bool Driver::OpenFile(const char *fileName) {
  instance_->pointer_ = 0;
  instance_->wasmFile_.open(fileName, ifstream::in);
  instance_->wasmFile_.seekg(0, ios::end);
  instance_->fileSize_ = instance_->wasmFile_.tellg();
  instance_->isParsing_ = true;
  instance_->wasmFile_.seekg(0, ios::beg);

  BOOST_LOG_TRIVIAL(debug) << "[Driver] Size of file [" << fileName << "]: " << (hex) << instance_->fileSize_;

  return instance_->wasmFile_.good();
}

int Driver::GetFileSize() {
  BOOST_LOG_TRIVIAL(trace) << "[Driver] Returning size of file: " << (hex) << instance_->fileSize_;
  return instance_->fileSize_;
}

int Driver::GetCurrentPos() {
  BOOST_LOG_TRIVIAL(trace) << "[Driver] Getting current position of the pointer: " << (hex) << instance_->pointer_;
  return instance_->pointer_;
}

} // namespace antiwasm