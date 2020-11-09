#include "driver.hpp"

Driver* Driver::instance_{nullptr};
std::mutex Driver::mutex_;
size_t Driver::fileSize_ = 0;
size_t Driver::pointer_ = 0;
char *Driver::buffer_ = nullptr;


