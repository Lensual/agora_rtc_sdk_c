// 引入AgoraRTM SDK
#include "NGIAgoraAudioTrack.h"

using namespace agora;
using namespace agora::rtc;

// Agora C封装
#include "C_NGIAgoraAudioTrack.h"

#pragma region agora

#pragma region agora::rtc

struct C_RemoteAudioTrackStats *C_RemoteAudioTrackStats_New()
{
  return (C_RemoteAudioTrackStats *)(new RemoteAudioTrackStats());
}
void C_RemoteAudioTrackStats_Delete(struct C_RemoteAudioTrackStats *this_)
{
  delete ((RemoteAudioTrackStats *)(this_));
}

#pragma region C_IRemoteAudioTrack

void C_IRemoteAudioTrack_Delete(C_IRemoteAudioTrack *this_)
{
  delete ((IRemoteAudioTrack *)(this_));
}

bool C_IRemoteAudioTrack_getStatistics(C_IRemoteAudioTrack *this_, struct C_RemoteAudioTrackStats *stats)
{
  return ((IRemoteAudioTrack *)(this_))->getStatistics(*(RemoteAudioTrackStats *)stats);
}

enum C_REMOTE_AUDIO_STATE C_IRemoteAudioTrack_getState(C_IRemoteAudioTrack *this_)
{
  return C_REMOTE_AUDIO_STATE(((IRemoteAudioTrack *)(this_))->getState());
}

int C_IRemoteAudioTrack_registerMediaPacketReceiver(C_IRemoteAudioTrack *this_, C_IMediaPacketReceiver *packetReceiver)
{
  return ((IRemoteAudioTrack *)(this_))->registerMediaPacketReceiver((IMediaPacketReceiver *)packetReceiver);
}

int C_IRemoteAudioTrack_unregisterMediaPacketReceiver(C_IRemoteAudioTrack *this_, C_IMediaPacketReceiver *packetReceiver)
{
  return ((IRemoteAudioTrack *)(this_))->unregisterMediaPacketReceiver((IMediaPacketReceiver *)packetReceiver);
}

int C_IRemoteAudioTrack_registerAudioEncodedFrameReceiver(C_IRemoteAudioTrack *this_, C_IAudioEncodedFrameReceiver *packetReceiver)
{
  return ((IRemoteAudioTrack *)(this_))->registerAudioEncodedFrameReceiver((IAudioEncodedFrameReceiver *)packetReceiver);
}

int C_IRemoteAudioTrack_unregisterAudioEncodedFrameReceiver(C_IRemoteAudioTrack *this_, C_IAudioEncodedFrameReceiver *packetReceiver)
{
  return ((IRemoteAudioTrack *)(this_))->registerAudioEncodedFrameReceiver((IAudioEncodedFrameReceiver *)packetReceiver);
}

int C_IRemoteAudioTrack_setRemoteVoicePosition(C_IRemoteAudioTrack *this_, float pan, float gain)
{
  return ((IRemoteAudioTrack *)(this_))->setRemoteVoicePosition(pan, gain);
}

int C_IRemoteAudioTrack_adjustDecodedAudioVolume(C_IRemoteAudioTrack *this_, int decoded_index, int volume)
{
  return ((IRemoteAudioTrack *)(this_))->adjustDecodedAudioVolume(decoded_index, volume);
}

int C_IRemoteAudioTrack_muteRemoteFromTimestamp(C_IRemoteAudioTrack *this_, uint32_t timestamp)
{
  return ((IRemoteAudioTrack *)(this_))->muteRemoteFromTimestamp(timestamp);
}

int C_IRemoteAudioTrack_unmuteRemoteFromTimestamp(C_IRemoteAudioTrack *this_, uint32_t timestamp)
{
  return ((IRemoteAudioTrack *)(this_))->unmuteRemoteFromTimestamp(timestamp);
}

int C_IRemoteAudioTrack_adjustAudioAcceleration(C_IRemoteAudioTrack *this_, int percentage)
{
  return ((IRemoteAudioTrack *)(this_))->adjustAudioAcceleration(percentage);
}

int C_IRemoteAudioTrack_adjustAudioDeceleration(C_IRemoteAudioTrack *this_, int percentage)
{
  return ((IRemoteAudioTrack *)(this_))->adjustAudioDeceleration(percentage);
}

int C_IRemoteAudioTrack_enableSpatialAudio(C_IRemoteAudioTrack *this_, bool enabled)
{
  return ((IRemoteAudioTrack *)(this_))->enableSpatialAudio(enabled);
}

int C_IRemoteAudioTrack_setRemoteUserSpatialAudioParams(C_IRemoteAudioTrack *this_, const struct C_SpatialAudioParams *params)
{
  return ((IRemoteAudioTrack *)(this_))->setRemoteUserSpatialAudioParams(*(const SpatialAudioParams *)&params);
}
#pragma endregion C_IRemoteAudioTrack

#pragma endregion agora::rtc

#pragma endregion agora
