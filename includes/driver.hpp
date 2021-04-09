#ifndef DRIVER_HPP
#define DRIVER_HPP

#define BOOST_LOG_DYN_LINK 1

#include "../utils/leb128.hpp"
#include <boost/log/trivial.hpp>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include <thread>

const int SIZE_OF_SECTION_ID = 1;
const int MAX_SIZE_OF_SECTION_HEADER = 6; // Section Id + max LEB128 for u32

class Driver {
private:
  static std::shared_ptr<Driver> instance_;
  static std::mutex mutex_;
  static bool error_;

protected:
  static size_t fileSize_;
  static size_t pointer_;
  static uint8_t *buffer_; // TODO which size?
  static std::ifstream wasmFile_;
  static bool isParsing_;

public:
  /**
   * Constructor
   */
  Driver() {}

  /**
   * Destructor
   */
  ~Driver() {}

  /**
   * Returns the single existing instance. If it doesn't exist, it is created.
   * @return the instance
   */
  static std::shared_ptr<Driver> GetInstance();

  /**
   * It returns the requested number of bytes
   * @param nBytesToBeRead
   * @return The bytes from the current position of the pointer until
   * nBytesToBeRead.
   */
  static uint8_t *GetNextBytes(size_t nBytesToBeRead);

  /**
   * Returns the next 2 bytes. Alias of GetNextBytes when it is used for section
   * headers.
   * @return The next 2 bytes
   */
  static uint8_t *GetNextSectionHeader();

  /**
   * TODO
   * @return
   */
  static uint8_t *GetUTF8String();

  /**
   * Opens the file at the given position.
   * @param fileName
   * @return true if the file exists, false if it doesn't.
   */
  static bool OpenFile(const char *fileName);

  /**
   * It closes the file that is currently being parsed.
   */
  static void CloseFile();

  /**
   * Checks if a file is being parsed.
   * @return true if it is parsing a file, false if it is not.
   */
  static bool IsCurrentlyParsing();

  /**
   * Checks if the next request would reach the end of the file.
   * @param nextBytesSize
   * @return true if it has reached the end of the file, false if it has not.
   */
  static bool HasReachedFileSize(size_t nextBytesSize);

  /**
   * Gets the size of the file.
   * @return the size of the file. TODO 0 if there is no file.
   */
  static int GetFileSize();

  /**
   * Gets the current position of the pointer
   * @return pointer_
   */
  static int GetCurrentPos();
};

#endif
