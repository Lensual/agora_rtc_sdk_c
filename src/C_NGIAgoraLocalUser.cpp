// 引入AgoraRTM SDK
#include "NGIAgoraLocalUser.h"

using namespace agora;
using namespace agora::media;
using namespace agora::rtc;

// Agora C封装
#include "C_NGIAgoraLocalUser.h"

#pragma region agora

#pragma region agora::media

#pragma endregion agora::media

#pragma region agora::rtc

struct C_AudioVolumeInformation *C_AudioVolumeInformation_New()
{
  return (C_AudioVolumeInformation *)(new AudioVolumeInformation());
}
void C_AudioVolumeInformation_Delete(struct C_AudioVolumeInformation *this_)
{
  delete ((AudioVolumeInformation *)(this_));
}

#pragma region C_ILocalUser

void C_ILocalUser_Delete(C_ILocalUser *this_)
{
  delete ((ILocalUser *)(this_));
}

void C_ILocalUser_setUserRole(C_ILocalUser *this_, enum C_CLIENT_ROLE_TYPE role)
{
  ((ILocalUser *)(this_))->setUserRole(CLIENT_ROLE_TYPE(role));
}

enum C_CLIENT_ROLE_TYPE C_ILocalUser_getUserRole(C_ILocalUser *this_)
{
  return C_CLIENT_ROLE_TYPE(((ILocalUser *)(this_))->getUserRole());
}

void C_ILocalUser_setAudienceLatencyLevel(C_ILocalUser *this_, enum C_AUDIENCE_LATENCY_LEVEL_TYPE level)
{
  ((ILocalUser *)(this_))->setAudienceLatencyLevel(AUDIENCE_LATENCY_LEVEL_TYPE(level));
}

enum C_AUDIENCE_LATENCY_LEVEL_TYPE C_ILocalUser_getAudienceLatencyLevel(C_ILocalUser *this_)
{
  return C_AUDIENCE_LATENCY_LEVEL_TYPE(((ILocalUser *)(this_))->getAudienceLatencyLevel());
}

int C_ILocalUser_setAudioEncoderConfiguration(C_ILocalUser *this_, const struct C_AudioEncoderConfiguration *config)
{
  return ((ILocalUser *)(this_))->setAudioEncoderConfiguration(*(AudioEncoderConfiguration *)(config));
}

int C_ILocalUser_setAudioScenario(C_ILocalUser *this_, enum C_AUDIO_SCENARIO_TYPE scenario)
{
  return ((ILocalUser *)(this_))->setAudioScenario(AUDIO_SCENARIO_TYPE(scenario));
}

int C_ILocalUser_setVideoScenario(C_ILocalUser *this_, enum C_VIDEO_APPLICATION_SCENARIO_TYPE scenarioType)
{
  return ((ILocalUser *)(this_))->setVideoScenario(VIDEO_APPLICATION_SCENARIO_TYPE(scenarioType));
}

int C_ILocalUser_subscribeAudio(C_ILocalUser *this_, C_user_id_t userId)
{
  return ((ILocalUser *)(this_))->subscribeAudio(user_id_t(userId));
}

int C_ILocalUser_subscribeAllAudio(C_ILocalUser *this_)
{
  return ((ILocalUser *)(this_))->subscribeAllAudio();
}

int C_ILocalUser_unsubscribeAudio(C_ILocalUser *this_, C_user_id_t userId)
{
  return ((ILocalUser *)(this_))->unsubscribeAudio(user_id_t(userId));
}

int C_ILocalUser_unsubscribeAllAudio(C_ILocalUser *this_)
{
  return ((ILocalUser *)(this_))->unsubscribeAllAudio();
}

int C_ILocalUser_adjustPlaybackSignalVolume(C_ILocalUser *this_, int volume)
{
  return ((ILocalUser *)(this_))->adjustPlaybackSignalVolume(volume);
}

int C_ILocalUser_getPlaybackSignalVolume(C_ILocalUser *this_, int *volume)
{
  return ((ILocalUser *)(this_))->getPlaybackSignalVolume(volume);
}

int C_ILocalUser_adjustUserPlaybackSignalVolume(C_ILocalUser *this_, C_user_id_t userId, int volume)
{
  return ((ILocalUser *)(this_))->adjustUserPlaybackSignalVolume(user_id_t(userId), volume);
}

int C_ILocalUser_getUserPlaybackSignalVolume(C_ILocalUser *this_, C_user_id_t userId, int *volume)
{
  return ((ILocalUser *)(this_))->getUserPlaybackSignalVolume(user_id_t(userId), volume);
}

int C_ILocalUser_enableSoundPositionIndication(C_ILocalUser *this_, bool enabled)
{
  return ((ILocalUser *)(this_))->enableSoundPositionIndication(enabled);
}

int C_ILocalUser_setRemoteVoicePosition(C_ILocalUser *this_, C_user_id_t userId, double pan, double gain)
{
  return ((ILocalUser *)(this_))->setRemoteVoicePosition(user_id_t(userId), pan, gain);
}

int C_ILocalUser_enableSpatialAudio(C_ILocalUser *this_, bool enabled)
{
  return ((ILocalUser *)(this_))->enableSpatialAudio(enabled);
}

int C_ILocalUser_setPlaybackAudioFrameParameters(C_ILocalUser *this_, size_t numberOfChannels,
                                                 uint32_t sampleRateHz,
                                                 enum C_RAW_AUDIO_FRAME_OP_MODE_TYPE mode,
                                                 int samplesPerCall)
{
  return ((ILocalUser *)(this_))->setPlaybackAudioFrameParameters(numberOfChannels, sampleRateHz, RAW_AUDIO_FRAME_OP_MODE_TYPE(mode), samplesPerCall);
}

int C_ILocalUser_setRecordingAudioFrameParameters(C_ILocalUser *this_, size_t numberOfChannels,
                                                  uint32_t sampleRateHz,
                                                  enum C_RAW_AUDIO_FRAME_OP_MODE_TYPE mode,
                                                  int samplesPerCall)
{
  return ((ILocalUser *)(this_))->setRecordingAudioFrameParameters(numberOfChannels, sampleRateHz, RAW_AUDIO_FRAME_OP_MODE_TYPE(mode), samplesPerCall);
}

int C_ILocalUser_setMixedAudioFrameParameters(C_ILocalUser *this_, size_t numberOfChannels,
                                              uint32_t sampleRateHz,
                                              int samplesPerCall)
{
  return ((ILocalUser *)(this_))->setMixedAudioFrameParameters(numberOfChannels, sampleRateHz, samplesPerCall);
}

int C_ILocalUser_setEarMonitoringAudioFrameParameters(C_ILocalUser *this_, bool enabled,
                                                      size_t numberOfChannels,
                                                      uint32_t sampleRateHz,
                                                      enum C_RAW_AUDIO_FRAME_OP_MODE_TYPE mode,
                                                      int samplesPerCall)
{
  return ((ILocalUser *)(this_))->setEarMonitoringAudioFrameParameters(enabled, numberOfChannels, sampleRateHz, RAW_AUDIO_FRAME_OP_MODE_TYPE(mode), samplesPerCall);
}

int C_ILocalUser_setPlaybackAudioFrameBeforeMixingParameters(C_ILocalUser *this_, size_t numberOfChannels,
                                                             uint32_t sampleRateHz)
{
  return ((ILocalUser *)(this_))->setPlaybackAudioFrameBeforeMixingParameters(numberOfChannels, sampleRateHz);
}

int C_ILocalUser_registerAudioFrameObserver(C_ILocalUser *this_, C_IAudioFrameObserverBase *observer)
{
  return ((ILocalUser *)(this_))->registerAudioFrameObserver((IAudioFrameObserverBase *)observer);
}

int C_ILocalUser_unregisterAudioFrameObserver(C_ILocalUser *this_, C_IAudioFrameObserverBase *observer)
{
  return ((ILocalUser *)(this_))->unregisterAudioFrameObserver((IAudioFrameObserverBase *)observer);
}

int C_ILocalUser_enableAudioSpectrumMonitor(C_ILocalUser *this_, int intervalInMS)
{
  return ((ILocalUser *)(this_))->enableAudioSpectrumMonitor(intervalInMS);
}

int C_ILocalUser_disableAudioSpectrumMonitor(C_ILocalUser *this_)
{
  return ((ILocalUser *)(this_))->enableAudioSpectrumMonitor();
}

int C_ILocalUser_registerAudioSpectrumObserver(C_ILocalUser *this_, C_IAudioSpectrumObserver *observer, void (*safeDeleter)(C_IAudioSpectrumObserver *))
{
  return ((ILocalUser *)(this_))->registerAudioSpectrumObserver((IAudioSpectrumObserver *)(observer), (void (*)(IAudioSpectrumObserver *))safeDeleter);
}

int C_ILocalUser_unregisterAudioSpectrumObserver(C_ILocalUser *this_, C_IAudioSpectrumObserver *observer)
{
  return ((ILocalUser *)(this_))->unregisterAudioSpectrumObserver((IAudioSpectrumObserver *)(observer));
}

int C_ILocalUser_registerLocalVideoEncodedFrameObserver(C_ILocalUser *this_, C_IVideoEncodedFrameObserver *observer)
{
  return ((ILocalUser *)(this_))->registerLocalVideoEncodedFrameObserver((IVideoEncodedFrameObserver *)(observer));
}

int C_ILocalUser_unregisterLocalVideoEncodedFrameObserver(C_ILocalUser *this_, C_IVideoEncodedFrameObserver *observer)
{
  return ((ILocalUser *)(this_))->unregisterLocalVideoEncodedFrameObserver((IVideoEncodedFrameObserver *)(observer));
}

int C_ILocalUser_forceNextIntraFrame(C_ILocalUser *this_)
{
  return ((ILocalUser *)(this_))->forceNextIntraFrame();
}

int C_ILocalUser_registerVideoEncodedFrameObserver(C_ILocalUser *this_, C_IVideoEncodedFrameObserver *observer)
{
  return ((ILocalUser *)(this_))->registerVideoEncodedFrameObserver((IVideoEncodedFrameObserver *)(observer));
}

int C_ILocalUser_unregisterVideoEncodedFrameObserver(C_ILocalUser *this_, C_IVideoEncodedFrameObserver *observer)
{
  return ((ILocalUser *)(this_))->unregisterVideoEncodedFrameObserver((IVideoEncodedFrameObserver *)(observer));
}

int C_ILocalUser_registerVideoFrameObserver(C_ILocalUser *this_, C_IVideoFrameObserver2 *observer)
{
  return ((ILocalUser *)(this_))->registerVideoFrameObserver((IVideoFrameObserver2 *)(observer));
}

int C_ILocalUser_unregisterVideoFrameObserver(C_ILocalUser *this_, C_IVideoFrameObserver2 *observer)
{
  return ((ILocalUser *)(this_))->unregisterVideoFrameObserver((IVideoFrameObserver2 *)(observer));
}

int C_ILocalUser_setVideoSubscriptionOptions(C_ILocalUser *this_, C_user_id_t userId,
                                             const struct C_VideoSubscriptionOptions *options)
{
  return ((ILocalUser *)(this_))->setVideoSubscriptionOptions(userId, *(const VideoSubscriptionOptions *)(options));
}

int C_ILocalUser_setSubscribeAudioBlocklist(C_ILocalUser *this_, C_user_id_t *userList, int userNumber)
{
  return ((ILocalUser *)(this_))->setSubscribeAudioBlocklist((user_id_t *)(userList), userNumber);
}

int C_ILocalUser_setSubscribeAudioAllowlist(C_ILocalUser *this_, C_user_id_t *userList, int userNumber)
{
  return ((ILocalUser *)(this_))->setSubscribeAudioAllowlist((user_id_t *)(userList), userNumber);
}

int C_ILocalUser_setSubscribeVideoBlocklist(C_ILocalUser *this_, C_user_id_t *userList, int userNumber)
{
  return ((ILocalUser *)(this_))->setSubscribeVideoBlocklist((user_id_t *)(userList), userNumber);
}

int C_ILocalUser_setSubscribeVideoAllowlist(C_ILocalUser *this_, user_id_t *userList, int userNumber)
{
  return ((ILocalUser *)(this_))->setSubscribeVideoAllowlist((user_id_t *)(userList), userNumber);
}

int C_ILocalUser_subscribeVideo(C_ILocalUser *this_, C_user_id_t userId, const struct C_VideoSubscriptionOptions *subscriptionOptions)
{
  return ((ILocalUser *)(this_))->subscribeVideo(userId, *(const VideoSubscriptionOptions *)(subscriptionOptions));
}

int C_ILocalUser_subscribeAllVideo(C_ILocalUser *this_, const struct C_VideoSubscriptionOptions *subscriptionOptions)
{
  return ((ILocalUser *)(this_))->subscribeAllVideo(*(const VideoSubscriptionOptions *)(subscriptionOptions));
}

int C_ILocalUser_unsubscribeVideo(C_ILocalUser *this_, C_user_id_t userId)
{
  return ((ILocalUser *)(this_))->unsubscribeVideo(user_id_t(userId));
}

int C_ILocalUser_unsubscribeAllVideo(C_ILocalUser *this_)
{
  return ((ILocalUser *)(this_))->unsubscribeAllVideo();
}

int C_ILocalUser_setAudioVolumeIndicationParameters(C_ILocalUser *this_, int intervalInMS, int smooth, bool reportVad)
{
  return ((ILocalUser *)(this_))->setAudioVolumeIndicationParameters(intervalInMS, smooth, reportVad);
}

int C_ILocalUser_registerLocalUserObserver(C_ILocalUser *this_,
                                           C_ILocalUserObserver *observer,
                                           void (*safeDeleter)(C_ILocalUserObserver *))
{
  return ((ILocalUser *)(this_))->registerLocalUserObserver((ILocalUserObserver *)(observer), (void (*)(ILocalUserObserver *))safeDeleter);
}

int C_ILocalUser_unregisterLocalUserObserver(C_ILocalUser *this_, C_ILocalUserObserver *observer)
{
  return ((ILocalUser *)(this_))->registerLocalUserObserver((ILocalUserObserver *)(observer));
}

#pragma endregion C_ILocalUser

#pragma endregion agora::rtc

#pragma endregion agora
