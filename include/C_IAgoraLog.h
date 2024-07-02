#ifndef C_I_AGORA_LOG_H
#define C_I_AGORA_LOG_H

#include <stdlib.h>
#include <stdint.h>

#ifndef C_OPTIONAL_ENUM_CLASS
#if __cplusplus >= 201103L || (defined(_MSC_VER) && _MSC_VER >= 1800)
#define C_OPTIONAL_ENUM_CLASS enum class
#else
#define C_OPTIONAL_ENUM_CLASS enum
#endif
#endif

#ifndef C_OPTIONAL_LOG_LEVEL_SPECIFIER
#if __cplusplus >= 201103L || (defined(_MSC_VER) && _MSC_VER >= 1800)
#define C_OPTIONAL_LOG_LEVEL_SPECIFIER LOG_LEVEL::
#else
#define C_OPTIONAL_LOG_LEVEL_SPECIFIER
#endif
#endif

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#pragma region agora

#pragma region agora::commons

  /**
   * Supported logging severities of SDK
   */
  C_OPTIONAL_ENUM_CLASS C_LOG_LEVEL{
      LOG_LEVEL_NONE = 0x0000,
      LOG_LEVEL_INFO = 0x0001,
      LOG_LEVEL_WARN = 0x0002,
      LOG_LEVEL_ERROR = 0x0004,
      LOG_LEVEL_FATAL = 0x0008,
      LOG_LEVEL_API_CALL = 0x0010,
  };

  /*
  The SDK uses ILogWriter class Write interface to write logs as application
  The application inherits the methods Write() to implentation their own  log writ

  Write has default implementation, it writes logs to files.
  Application can use setLogFile() to change file location, see description of set
  */
  typedef void C_ILogWriter;
#pragma region C_ILogWriter
  /** user defined log Write function
  @param level log level
  @param message log message content
  @param length log message length
  @return
   - 0: success
   - <0: failure
  */
  int32_t C_ILogWriter_writeLog(C_ILogWriter *this_, enum C_LOG_LEVEL level, const char *message, uint16_t length);

  void C_ILogWriter_Delete(C_ILogWriter *this_);
#pragma endregion C_ILogWriter

  enum C_LOG_FILTER_TYPE
  {
    LOG_FILTER_OFF = 0,
    LOG_FILTER_DEBUG = 0x080f,
    LOG_FILTER_INFO = 0x000f,
    LOG_FILTER_WARN = 0x000e,
    LOG_FILTER_ERROR = 0x000c,
    LOG_FILTER_CRITICAL = 0x0008,
    LOG_FILTER_MASK = 0x80f,
  };

#define C_MAX_LOG_SIZE 20971520 // 20MB
#define C_MIN_LOG_SIZE 131072   // 128KB
  /** The default log size in kb
   */
#define C_DEFAULT_LOG_SIZE_IN_KB 1024

  /** Definition of LogConfiguration
   */
  struct C_LogConfig
  {
    /**The log file path, default is NULL for default log path
     */
    const char *filePath;
    /** The log file size, KB , set 1024KB to use default log size
     */
    uint32_t fileSizeInKB;
    /** The log level, set LOG_LEVEL_INFO to use default log level
     */
    enum C_LOG_LEVEL level;
  };
  struct C_LogConfig *C_LogConfig_New();
  void C_LogConfig_Delete(struct C_LogConfig *this_);

#pragma endregion agora::commons

#pragma endregion agora

#undef C_OPTIONAL_LOG_LEVEL_SPECIFIER

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_I_AGORA_LOG_H
