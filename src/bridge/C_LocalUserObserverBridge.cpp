// Agora C封装
#include "bridge/C_LocalUserObserverBridge.h"

// LocalUserObserverBridge CPP实现
#include "bridge/LocalUserObserverBridge.hh"

C_LocalUserObserverBridge *C_LocalUserObserverBridge_New(C_LocalUserObserverBridge_Callbacks cbs, void *userData)
{
  auto this_ = new LocalUserObserverBridge(cbs, userData);
  return (C_LocalUserObserverBridge *)this_;
}

void C_LocalUserObserverBridge_Delete(C_LocalUserObserverBridge *this_)
{
  delete (LocalUserObserverBridge *)this_;
  this_ = nullptr;
}