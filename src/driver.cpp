#include "../includes/driver.hpp"

std::shared_ptr<Driver> Driver::instance_;
std::mutex Driver::mutex_;
bool Driver::error_;

size_t Driver::fileSize_;
size_t Driver::pointer_;
std::ifstream Driver::wasmFile_;
uint8_t *Driver::buffer_;
bool Driver::isParsing_;

std::shared_ptr<Driver> Driver::GetInstance() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (instance_ == nullptr) {
        instance_ = std::make_shared<Driver>();
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
        return nullptr; //TODO avoid using nullptr
    }
    if (!Driver::IsCurrentlyParsing()) {
        error_ = true;
        return nullptr; //TODO avoid using nullptr
    }

    BOOST_LOG_TRIVIAL(debug) << "[Driver]Getting next " << nBytesToBeRead << " bytes";
    char *buffer = (char *) malloc(sizeof(char) * nBytesToBeRead + 1);
    instance_->wasmFile_.seekg(instance_->pointer_, std::ios::beg);
    instance_->pointer_ += nBytesToBeRead;
    instance_->wasmFile_.read(buffer, nBytesToBeRead);

    for (int i = 0; i < nBytesToBeRead; i++) {
        //printf(" %02x", buffer[i]); //TODO format with Boost
    }
    //printf("\n");

    return (uint8_t *) buffer;
}

uint8_t *Driver::GetNextSectionHeader() {
    return Driver::GetNextBytes(SIZE_OF_SECTION_HEADER);
}

uint8_t *Driver::GetUTF8String() //TODO not ready to be used
{
    BOOST_LOG_TRIVIAL(debug) << "[Driver] Getting a UTF8 String";
    uint8_t delimiter = 0x03;
    std::string temp;

    instance_->wasmFile_.seekg(instance_->pointer_, std::ios::beg);
    std::istream &stream = instance_->wasmFile_;
    getline(stream, temp);

    return nullptr;
}

void Driver::CloseFile() {
    instance_->wasmFile_.close();
}

bool Driver::HasReachedFileSize(size_t nextBytesSize) {
    if (pointer_ <= fileSize_ + nextBytesSize)
        return false;
    return true;
}

bool Driver::IsCurrentlyParsing() {
    return isParsing_;
}

bool Driver::OpenFile(const char *fileName) {
    instance_->pointer_ = 0;
    instance_->wasmFile_.open(fileName, std::ifstream::in);
    instance_->wasmFile_.seekg(0, std::ios::end);
    instance_->fileSize_ = instance_->wasmFile_.tellg();
    instance_->isParsing_ = true;
    instance_->wasmFile_.seekg(0, std::ios::beg);

    BOOST_LOG_TRIVIAL(debug) << "[Driver] Size of file [" << fileName << "]: " << instance_->fileSize_;

    return instance_->wasmFile_.good();
}

int Driver::GetFileSize() {
    BOOST_LOG_TRIVIAL(trace) << "[Driver] Returning size of file: " << instance_->fileSize_;
    return fileSize_;
}

int Driver::GetCurrentPos() {
    BOOST_LOG_TRIVIAL(trace) << "[Driver] Getting current position of the pointer: " << instance_->pointer_;
    return pointer_;
}
