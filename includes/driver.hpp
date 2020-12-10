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
#include <memory>
#include <boost/log/trivial.hpp>

#define SIZE_OF_SECTION_HEADER 2 //Section Id and Section Size

class Driver {
    private:
        static std::shared_ptr<Driver> instance_;
        static std::mutex mutex_;

    protected:
        static size_t fileSize_;
        static size_t pointer_;
        static char *buffer_;  //TODO which size?
        static std::ifstream wasmFile_;
        static bool isParsing_;
        static bool HasReachedFileSize(size_t nextBytesSize);

    public:
        Driver() {}
        ~Driver() {}
        Driver(Driver &driver) = delete;
        static std::shared_ptr<Driver> GetInstance(const char* fileName);
        static std::shared_ptr<Driver> GetInstance();
        static unsigned char* GetNextBytes(size_t nBytesToBeRead);
        static unsigned char* GetNextSectionHeader();
        static unsigned char* GetUTF8String();
        static void OpenFile(const char* fileName);
        static void CloseFile();
        static bool IsCurrentlyParsing();
};

#endif
