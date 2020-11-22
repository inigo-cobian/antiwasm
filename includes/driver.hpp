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
        static Driver *GetInstance(const char* fileName);
        static Driver *GetInstance();
        unsigned char* GetNextBytes(size_t nBytesToBeRead);
        unsigned char* GetNextSectionHeader();
        unsigned char* GetUTF8String();
        void CloseFile();
};

#endif
