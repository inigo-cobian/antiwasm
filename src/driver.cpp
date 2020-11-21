#include "driver.hpp"

inline Driver* Driver::instance_;
inline std::mutex Driver::mutex_;
inline size_t Driver::fileSize_;
inline size_t Driver::pointer_;
inline char *Driver::buffer_;

Driver *Driver::GetInstance(const char* fileName)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (instance_ == nullptr)
    {
        instance_ = new Driver();
        instance_->pointer_ = 0;
        instance_->wasmFile_.open(fileName, std::ifstream::in);
        instance_->wasmFile_.seekg(0, std::ios::end);
        instance_->fileSize_ = instance_->wasmFile_.tellg();

        BOOST_LOG_TRIVIAL(debug) << "Size of file: " << instance_->fileSize_;
        instance_->wasmFile_.seekg(0, std::ios::beg);
    }

    return instance_;
}

Driver *Driver::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (instance_ == nullptr) //TODO exception
    {
        BOOST_LOG_TRIVIAL(debug) << "Generating new instance";
        return nullptr;
    }

    return instance_;
}

unsigned char* Driver::GetNextBytes(size_t nBytesToBeRead)
{
    BOOST_LOG_TRIVIAL(debug) << "Getting next " << nBytesToBeRead << " bytes";
    char* buffer = (char*)malloc(sizeof(char) * nBytesToBeRead + 1);
    instance_->wasmFile_.seekg(instance_->pointer_, std::ios::beg);
    instance_->pointer_ += nBytesToBeRead;
    instance_->wasmFile_.read(buffer, nBytesToBeRead);

    for(int i = 0; i < nBytesToBeRead; i++) {
        printf(" %02x", buffer[i]); //TODO format with Boost
    }
    printf("\n");

    return (unsigned char*)buffer;
}

unsigned char* Driver::GetNextSectionHeader()
{
    return Driver::GetNextBytes(SIZE_OF_SECTION_HEADER);
}

unsigned char* Driver::GetUTF8String() //TODO not ready to be used
{
    BOOST_LOG_TRIVIAL(debug) << "Getting UTF8 String";
    unsigned char delimiter = 0x03;
    std::string temp = "";

    instance_->wasmFile_.seekg(instance_->pointer_, std::ios::beg);
    std::istream& stream = instance_->wasmFile_;
    getline(stream, temp);

    return nullptr;
}

void Driver::CloseFile() {
    instance_->wasmFile_.close();
}