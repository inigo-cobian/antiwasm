#ifndef DRIVER_HPP
#define DRIVER_HPP

#define BOOST_LOG_DYN_LINK 1

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>
#include <thread>
#include <mutex>
#include <string>
#include <boost/log/trivial.hpp>

#define SIZE_OF_SECTION_HEADER 2 //Section Id and Section Size

class Driver {
    private:
        static Driver *instance_;
        static std::mutex mutex_;

    protected:
        Driver()
        {
        }

        ~Driver() {}

        static size_t fileSize_;
        static size_t pointer_;
        static char *buffer_;  //TODO which size?
        std::ifstream wasmFile_;


    public:
        Driver(Driver &driver) = delete;
        Driver *GetInstance(const char* fileName);
        Driver *GetInstance();
        unsigned char* GetNextBytes(size_t nBytesToBeRead);
        unsigned char* GetNextSectionHeader();
        unsigned char* GetUTF8String();
        void CloseFile();
};

inline extern Driver* Driver::instance_;
inline extern std::mutex Driver::mutex_;
inline extern size_t Driver::fileSize_;
inline extern size_t Driver::pointer_;
inline extern char *Driver::buffer_;

inline Driver *Driver::GetInstance(const char* fileName)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (instance_ == nullptr)
    {
        instance_ = new Driver();
        instance_->pointer_ = 0;
        instance_->wasmFile_.open(fileName, std::ifstream::in);
        instance_->wasmFile_.seekg(0, std::ios::end);
        instance_->fileSize_ = instance_->wasmFile_.tellg(); //FIXME

        BOOST_LOG_TRIVIAL(debug) << "Size of file: " << instance_->fileSize_;
        instance_->wasmFile_.seekg(0, std::ios::beg);
    }

    return instance_;
}

inline Driver *Driver::GetInstance()
{
    std::cout << "GetInstance" << std::endl;
    std::lock_guard<std::mutex> lock(mutex_);
    if (instance_ == nullptr) //TODO exception
    {
        BOOST_LOG_TRIVIAL(debug) << "Generating new instance";
        return nullptr;
    }

    return instance_;
}

inline unsigned char* Driver::GetNextBytes(size_t nBytesToBeRead)
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

inline unsigned char* Driver::GetNextSectionHeader()
{
    return Driver::GetNextBytes(SIZE_OF_SECTION_HEADER);
}

inline unsigned char* Driver::GetUTF8String() //TODO not ready to be used
{
    BOOST_LOG_TRIVIAL(debug) << "Getting UTF8 String";
    unsigned char delimiter = 0x03;
    std::string temp = "";

    instance_->wasmFile_.seekg(instance_->pointer_, std::ios::beg);
    std::istream& stream = instance_->wasmFile_;
    getline(stream, temp);

    return nullptr;
}

inline void Driver::CloseFile()
{
    instance_->wasmFile_.close();
}

#endif
