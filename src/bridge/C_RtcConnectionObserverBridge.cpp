// Agora C封装
#include "bridge/C_RtcConnectionObserverBridge.h"

// RtcConnectionObserverBridge CPP实现
#include "bridge/RtcConnectionObserverBridge.hh"

C_RtcConnectionObserverBridge *C_RtcConnectionObserverBridge_New(C_RtcConnectionObserverBridge_Callbacks cbs, void *userData)
{
  auto this_ = new RtcConnectionObserverBridge(cbs, userData);
  return (C_RtcConnectionObserverBridge *)this_;
}

void C_RtcConnectionObserverBridge_Delete(C_RtcConnectionObserverBridge *this_)
{
  delete (RtcConnectionObserverBridge *)this_;
  this_ = nullptr;
}