// 引入AgoraRTM SDK
#include "AgoraMediaBase.h"

using namespace agora;
using namespace agora::rtc;
using namespace agora::media;
using namespace agora::media::base;

// Agora C封装
#include "C_AgoraMediaBase.h"

#pragma region agora

#pragma region agora::rtc

struct C_AudioParameters *C_AudioParameters_New()
{
  return (C_AudioParameters *)(new AudioParameters());
}
void C_AudioParameters_Delete(struct C_AudioParameters *this_)
{
  delete ((AudioParameters *)(this_));
}

struct C_AudioDeviceInfo *C_AudioDeviceInfo_New()
{
  return (C_AudioDeviceInfo *)(new AudioDeviceInfo());
}
void C_AudioDeviceInfo_Delete(struct C_AudioDeviceInfo *this_)
{
  delete ((AudioDeviceInfo *)(this_));
}

#pragma endregion agora::rtc

#pragma region agora::media

struct C_ContentInspectModule *C_ContentInspectModule_New()
{
  return (C_ContentInspectModule *)(new ContentInspectModule());
}
void C_ContentInspectModule_Delete(struct C_ContentInspectModule *this_)
{
  delete ((ContentInspectModule *)(this_));
}

struct C_ContentInspectConfig *C_ContentInspectConfig_New()
{
  return (C_ContentInspectConfig *)(new ContentInspectConfig());
}
void C_ContentInspectConfig_Delete(struct C_ContentInspectConfig *this_)
{
  delete ((ContentInspectConfig *)(this_));
}

#pragma region agora::media::base

struct C_PacketOptions *C_PacketOptions_New()
{
  return (C_PacketOptions *)(new PacketOptions());
}
void C_PacketOptions_Delete(struct C_PacketOptions *this_)
{
  delete ((PacketOptions *)(this_));
}

struct C_AudioEncodedFrameInfo *C_AudioEncodedFrameInfo_New()
{
  return (C_AudioEncodedFrameInfo *)(new AudioEncodedFrameInfo());
}
void C_AudioEncodedFrameInfo_Delete(struct C_AudioEncodedFrameInfo *this_)
{
  delete ((AudioEncodedFrameInfo *)(this_));
}

struct C_AudioPcmFrame *C_AudioPcmFrame_New()
{
  return (C_AudioPcmFrame *)(new AudioPcmFrame());
}
void C_AudioPcmFrame_Delete(struct C_AudioPcmFrame *this_)
{
  delete ((AudioPcmFrame *)(this_));
}

#pragma endregion agora::media::base

#pragma region C_IAudioFrameObserverBase

struct C_AudioFrame *C_AudioFrame_New()
{
  return (C_AudioFrame *)(new IAudioFrameObserverBase::AudioFrame());
}
void C_AudioFrame_Delete(struct C_AudioFrame *this_)
{
  delete ((IAudioFrameObserverBase::AudioFrame *)(this_));
}

struct C_AudioParams *C_AudioParams_New()
{
  return (C_AudioParams *)(new IAudioFrameObserverBase::AudioParams());
}
void C_AudioParams_Delete(struct C_AudioParams *this_)
{
  delete ((IAudioFrameObserverBase::AudioParams *)(this_));
}

void C_IAudioFrameObserverBase_Delete(C_IAudioFrameObserverBase *this_)
{
  delete ((IAudioFrameObserverBase *)(this_));
}
bool C_IAudioFrameObserverBase_onRecordAudioFrame(C_IAudioFrameObserverBase *this_, const char *channelId, struct C_AudioFrame *audioFrame)
{
  return ((IAudioFrameObserverBase *)(this_))->onRecordAudioFrame(channelId, *(IAudioFrameObserverBase::AudioFrame *)audioFrame);
}
bool C_IAudioFrameObserverBase_onPlaybackAudioFrame(C_IAudioFrameObserverBase *this_, const char *channelId, struct C_AudioFrame *audioFrame)
{
  return ((IAudioFrameObserverBase *)(this_))->onPlaybackAudioFrame(channelId, *(IAudioFrameObserverBase::AudioFrame *)audioFrame);
}
bool C_IAudioFrameObserverBase_onMixedAudioFrame(C_IAudioFrameObserverBase *this_, const char *channelId, struct C_AudioFrame *audioFrame)
{
  return ((IAudioFrameObserverBase *)(this_))->onMixedAudioFrame(channelId, *(IAudioFrameObserverBase::AudioFrame *)audioFrame);
}
bool C_IAudioFrameObserverBase_onEarMonitoringAudioFrame(C_IAudioFrameObserverBase *this_, struct C_AudioFrame *audioFrame)
{
  return ((IAudioFrameObserverBase *)(this_))->onEarMonitoringAudioFrame(*(IAudioFrameObserverBase::AudioFrame *)audioFrame);
}
bool C_IAudioFrameObserverBase_onPlaybackAudioFrameBeforeMixing(C_IAudioFrameObserverBase *this_, const char *channelId, C_user_id_t userId, struct C_AudioFrame *audioFrame)
{
  return ((IAudioFrameObserverBase *)(this_))->onPlaybackAudioFrameBeforeMixing(channelId, user_id_t(userId), *(IAudioFrameObserverBase::AudioFrame *)audioFrame);
}
int C_IAudioFrameObserverBase_getObservedAudioFramePosition(C_IAudioFrameObserverBase *this_)
{
  return ((IAudioFrameObserverBase *)(this_))->getObservedAudioFramePosition();
}
struct C_AudioParams C_IAudioFrameObserverBase_getPlaybackAudioParams(C_IAudioFrameObserverBase *this_)
{
  auto ptr = ((IAudioFrameObserverBase *)(this_))->getPlaybackAudioParams();
  return *(C_AudioParams *)&ptr;
}
struct C_AudioParams C_IAudioFrameObserverBase_getRecordAudioParams(C_IAudioFrameObserverBase *this_)
{
  auto ptr = ((IAudioFrameObserverBase *)(this_))->getRecordAudioParams();
  return *(C_AudioParams *)&ptr;
}
struct C_AudioParams C_IAudioFrameObserverBase_getMixedAudioParams(C_IAudioFrameObserverBase *this_)
{
  auto ptr = ((IAudioFrameObserverBase *)(this_))->getMixedAudioParams();
  return *(C_AudioParams *)&ptr;
}
struct C_AudioParams C_IAudioFrameObserverBase_getEarMonitoringAudioParams(C_IAudioFrameObserverBase *this_)
{
  auto ptr = ((IAudioFrameObserverBase *)(this_))->getEarMonitoringAudioParams();
  return *(C_AudioParams *)&ptr;
}

#pragma endregion C_IAudioFrameObserverBase

#pragma region C_IAudioFrameObserver

bool C_IAudioFrameObserver_onPlaybackAudioFrameBeforeMixing(C_IAudioFrameObserver *this_, const char *channelId, C_uid_t uid, struct C_AudioFrame *audioFrame)
{
  return ((IAudioFrameObserver *)(this_))->onPlaybackAudioFrameBeforeMixing(channelId, uid_t(uid), *(IAudioFrameObserverBase::AudioFrame *)audioFrame);
}

#pragma endregion C_IAudioFrameObserver

#pragma endregion agora::media

#pragma endregion agora