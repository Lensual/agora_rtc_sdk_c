// 引入AgoraRTM SDK
#include "IAgoraParameter.h"

using namespace agora;
using namespace agora::util;
using namespace agora::base;

// Agora C封装
#include "C_IAgoraParameter.h"

#pragma region agora

#pragma region agora::util

#pragma endregion agora::util

#pragma region agora::base

#pragma region agora::C_IAgoraParameter

void C_IAgoraParameter_release(C_IAgoraParameter *this_)
{
  ((IAgoraParameter *)(this_))->release();
}

int C_IAgoraParameter_setBool(C_IAgoraParameter *this_, const char *key, bool value)
{
  return ((IAgoraParameter *)(this_))->setBool(key, value);
}

int C_IAgoraParameter_setInt(C_IAgoraParameter *this_, const char *key, int value)
{
  return ((IAgoraParameter *)(this_))->setInt(key, value);
}

int C_IAgoraParameter_setUInt(C_IAgoraParameter *this_, const char *key, unsigned int value)
{
  return ((IAgoraParameter *)(this_))->setUInt(key, value);
}

int C_IAgoraParameter_setNumber(C_IAgoraParameter *this_, const char *key, double value)
{
  return ((IAgoraParameter *)(this_))->setNumber(key, value);
}

int C_IAgoraParameter_setString(C_IAgoraParameter *this_, const char *key, const char *value)
{
  return ((IAgoraParameter *)(this_))->setString(key, value);
}

int C_IAgoraParameter_setObject(C_IAgoraParameter *this_, const char *key, const char *value)
{
  return ((IAgoraParameter *)(this_))->setObject(key, value);
}

int C_IAgoraParameter_setArray(C_IAgoraParameter *this_, const char *key, const char *value)
{
  return ((IAgoraParameter *)(this_))->setArray(key, value);
}

int C_IAgoraParameter_getBool(C_IAgoraParameter *this_, const char *key, bool *value)
{
  return ((IAgoraParameter *)(this_))->getBool(key, *value);
}

int C_IAgoraParameter_getInt(C_IAgoraParameter *this_, const char *key, int *value)
{
  return ((IAgoraParameter *)(this_))->getInt(key, *value);
}

int C_IAgoraParameter_getUInt(C_IAgoraParameter *this_, const char *key, unsigned int *value)
{
  return ((IAgoraParameter *)(this_))->getUInt(key, *value);
}

int C_IAgoraParameter_getNumber(C_IAgoraParameter *this_, const char *key, double *value)
{
  return ((IAgoraParameter *)(this_))->getNumber(key, *value);
}

int C_IAgoraParameter_getString(C_IAgoraParameter *this_, const char *key, C_AString *value)
{
  return ((IAgoraParameter *)(this_))->getString(key, *(AString *)value);
}

int C_IAgoraParameter_getObject(C_IAgoraParameter *this_, const char *key, C_AString *value)
{
  return ((IAgoraParameter *)(this_))->getObject(key, *(AString *)value);
}

int C_IAgoraParameter_getArray(C_IAgoraParameter *this_, const char *key, const char *args, C_AString *value)
{
  return ((IAgoraParameter *)(this_))->getArray(key, args, *(AString *)value);
}

int C_IAgoraParameter_setParameters(C_IAgoraParameter *this_, const char *parameters)
{
  return ((IAgoraParameter *)(this_))->setParameters(parameters);
}

int C_IAgoraParameter_convertPath(C_IAgoraParameter *this_, const char *filePath, C_AString *value)
{
  return ((IAgoraParameter *)(this_))->convertPath(filePath, *(AString *)value);
}

void C_IAgoraParameter_Delete(C_IAgoraParameter *this_)
{
  delete ((IAgoraParameter *)(this_));
}

#pragma endregion agora::C_IAgoraParameter

#pragma endregion agora::base

#pragma endregion agora
