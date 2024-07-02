// 引入AgoraRTM SDK
#include "IAgoraLog.h"

using namespace agora;
using namespace agora::commons;

// Agora C封装
#include "C_IAgoraLog.h"

#pragma region agora

#pragma region agora::commons

#pragma region C_ILogWriter

int32_t C_ILogWriter_writeLog(C_ILogWriter *this_, enum C_LOG_LEVEL level, const char *message, uint16_t length)
{
  return ((ILogWriter *)(this_))->writeLog(LOG_LEVEL(level), message, length);
}

void C_ILogWriter_Delete(C_ILogWriter *this_)
{
  delete ((ILogWriter *)(this_));
}

#pragma endregion C_ILogWriter

struct C_LogConfig *C_LogConfig_New()
{
  return (C_LogConfig *)(new LogConfig());
}
void C_LogConfig_Delete(struct C_LogConfig *this_)
{
  delete ((C_LogConfig *)(this_));
}

#pragma endregion agora::commons

#pragma endregion agora