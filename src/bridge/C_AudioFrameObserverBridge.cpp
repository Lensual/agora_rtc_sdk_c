// Agora C封装
#include "bridge/C_AudioFrameObserverBridge.h"

// AudioFrameObserverBridge CPP实现
#include "bridge/AudioFrameObserverBridge.hh"

C_AudioFrameObserverBridge *C_AudioFrameObserverBridge_New(C_AudioFrameObserverBridge_Callbacks cbs, void *userData)
{
  auto this_ = new AudioFrameObserverBridge(cbs, userData);
  return (C_AudioFrameObserverBridge *)this_;
}

void C_AudioFrameObserverBridge_Delete(C_AudioFrameObserverBridge *this_)
{
  delete (AudioFrameObserverBridge *)this_;
  this_ = nullptr;
}