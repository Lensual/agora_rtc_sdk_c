// 引入AgoraRTM SDK
#include "IAgoraService.h"
#include "NGIAgoraRtcConnection.h"
#include "NGIAgoraAudioTrack.h"
#include "NGIAgoraMediaNode.h"
#include "NGIAgoraRemoteAudioMixerSource.h"
#include "IAgoraMediaPlayerSource.h"
#include "IAgoraMediaStreamingSource.h"
#include "NGIAgoraAudioDeviceManager.h"
#include "NGIAgoraCameraCapturer.h"
#include "NGIAgoraScreenCapturer.h"
#include "NGIAgoraVideoMixerSource.h"
#include "NGIAgoraMediaNodeFactory.h"
#include "NGIAgoraVideoTrack.h"
#include "IAgoraRtmpStreamingService.h"
#include "IAgoraMediaRelayService.h"
#include "IAgoraFileUploader.h"
#include "IAgoraFileUploader.h"
#include "NGIAgoraConfigCenter.h"

using namespace agora;
using namespace agora::rtc;
using namespace agora::base;

// Agora C封装
#include "C_IAgoraService.h"

#pragma region agora

#pragma region agora::rtc

struct C_AudioEncoderConfiguration *C_AudioEncoderConfiguration_New()
{
  return (C_AudioEncoderConfiguration *)(new AudioEncoderConfiguration());
}
void C_AudioEncoderConfiguration_Delete(struct C_AudioEncoderConfiguration *this_)
{
  delete ((AudioEncoderConfiguration *)(this_));
}

#pragma endregion agora::rtc

#pragma region agora::rtm

#pragma endregion agora::rtm

#pragma region agora::base

#pragma region C_AgoraServiceConfiguration

struct C_AgoraServiceConfiguration *C_AgoraServiceConfiguration_New()
{
  return (C_AgoraServiceConfiguration *)(new AgoraServiceConfiguration());
}
void C_AgoraServiceConfiguration_Delete(struct C_AgoraServiceConfiguration *this_)
{
  delete ((AgoraServiceConfiguration *)(this_));
}

#pragma endregion C_AgoraServiceConfiguration

#pragma region C_AudioSessionConfiguration

struct C_AudioSessionConfiguration *C_AudioSessionConfiguration_New()
{
  return (C_AudioSessionConfiguration *)(new AudioSessionConfiguration());
}
void C_AudioSessionConfiguration_Delete(struct C_AudioSessionConfiguration *this_)
{
  delete ((AudioSessionConfiguration *)(this_));
}
void C_AudioSessionConfiguration_SetAll(struct C_AudioSessionConfiguration *this_, const struct C_AudioSessionConfiguration *change)
{
  ((AudioSessionConfiguration *)(this_))->SetAll(*(AudioSessionConfiguration *)(change));
}

#pragma endregion C_AudioSessionConfiguration

#pragma region C_IServiceObserver

void C_IServiceObserver_Delete(C_IServiceObserver *this_)
{
  delete ((IServiceObserver *)(this_));
}
void C_IServiceObserver_onPermissionError(C_IServiceObserver *this_, enum C_PERMISSION_TYPE permissionType)
{
  ((IServiceObserver *)(this_))->onPermissionError(PERMISSION_TYPE(permissionType));
}
void C_IServiceObserver_onAudioDeviceError(C_IServiceObserver *this_, enum C_ERROR_CODE_TYPE error, const char *description)
{
  ((IServiceObserver *)(this_))->onAudioDeviceError(ERROR_CODE_TYPE(error), description);
}
void C_IServiceObserver_onFetchConfigResult(C_IServiceObserver *this_, int code, enum C_CONFIG_FETCH_TYPE configType, const char *configContent)
{
  ((IServiceObserver *)(this_))->onFetchConfigResult(code, CONFIG_FETCH_TYPE(configType), configContent);
}

#pragma endregion C_IServiceObserver

#pragma region C_IAgoraService

int C_IAgoraService_initialize(C_IAgoraService *this_, const struct C_AgoraServiceConfiguration *config)
{
  return ((IAgoraService *)(this_))->initialize(*(AgoraServiceConfiguration *)(config));
}

void C_IAgoraService_atExit(C_IAgoraService *this_)
{
  ((IAgoraService *)(this_))->atExit();
}

int C_IAgoraService_release(C_IAgoraService *this_)
{
  return ((IAgoraService *)(this_))->release();
}

int C_IAgoraService_setAudioSessionPreset(C_IAgoraService *this_, enum C_AUDIO_SCENARIO_TYPE scenario)
{
  return ((IAgoraService *)(this_))->setAudioSessionPreset(AUDIO_SCENARIO_TYPE(scenario));
}

int C_IAgoraService_setAudioSessionConfiguration(C_IAgoraService *this_, const struct C_AudioSessionConfiguration *config)
{
  return ((IAgoraService *)(this_))->setAudioSessionConfiguration(*(const AudioSessionConfiguration *)config);
}

int C_IAgoraService_getAudioSessionConfiguration(C_IAgoraService *this_, const struct C_AudioSessionConfiguration *config)
{
  return ((IAgoraService *)(this_))->getAudioSessionConfiguration((AudioSessionConfiguration *)config);
}

int C_IAgoraService_setLogFile(C_IAgoraService *this_, const char *filePath, unsigned int fileSize)
{
  return ((IAgoraService *)(this_))->setLogFile(filePath, fileSize);
}

int C_IAgoraService_setLogFilter(C_IAgoraService *this_, unsigned int filters)
{
  return ((IAgoraService *)(this_))->setLogFilter(filters);
}

C_IRtcConnection* C_IAgoraService_createRtcConnection(C_IAgoraService *this_,
                                                   const struct C_RtcConnectionConfiguration *cfg)
{
  auto refptr = ((IAgoraService *)(this_))->createRtcConnection(*(const RtcConnectionConfiguration *)cfg);
  refptr->AddRef();
  return (C_IRtcConnection*)refptr.get();
}

// C_agora_refptr C_IAgoraService_createRtmpConnection(C_IAgoraService *this_,
//                                                     const C_RtmpConnectionConfiguration *cfg)
// {
//     auto ptr = ((IAgoraService *)(this_))->createRtmpConnection(*(const C_RtmpConnectionConfiguration *)cfg);
//     return *(C_agora_refptr *)&ptr;
// }

C_agora_refptr C_IAgoraService_createLocalAudioTrack(C_IAgoraService *this_)
{
  auto ptr = ((IAgoraService *)(this_))->createLocalAudioTrack();
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createLocalMixedAudioTrack(C_IAgoraService *this_)
{
  auto ptr = ((IAgoraService *)(this_))->createLocalMixedAudioTrack();
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createCustomAudioTrack_pcmSender(C_IAgoraService *this_,
                                                                C_agora_refptr audioSource)
{
  auto ptr = ((IAgoraService *)(this_))->createCustomAudioTrack(*(agora_refptr<rtc::IAudioPcmDataSender> *)&audioSource);
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createDirectCustomAudioTrack(C_IAgoraService *this_,
                                                            C_agora_refptr audioSource)
{
  auto ptr = ((IAgoraService *)(this_))->createDirectCustomAudioTrack(*(agora_refptr<rtc::IAudioPcmDataSender> *)&audioSource);
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createCustomAudioTrack_pcmSender_aec(C_IAgoraService *this_,
                                                                    C_agora_refptr audioSource, bool enableAec)
{
  auto ptr = ((IAgoraService *)(this_))->createCustomAudioTrack(*(agora_refptr<rtc::IAudioPcmDataSender> *)&audioSource, enableAec);
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createCustomAudioTrack_mixerSource(C_IAgoraService *this_,
                                                                  C_agora_refptr audioSource)
{
  auto ptr = ((IAgoraService *)(this_))->createCustomAudioTrack(*(agora_refptr<rtc::IRemoteAudioMixerSource> *)&audioSource);
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createCustomAudioTrack_frameSender(C_IAgoraService *this_,
                                                                  C_agora_refptr audioSource, enum C_TMixMode mixMode)
{
  auto ptr = ((IAgoraService *)(this_))->createCustomAudioTrack(*(agora_refptr<rtc::IAudioEncodedFrameSender> *)&audioSource, TMixMode(mixMode));
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createCustomAudioTrack_packetSender(C_IAgoraService *this_,
                                                                   C_agora_refptr source)
{
  auto ptr = ((IAgoraService *)(this_))->createCustomAudioTrack(*(agora_refptr<rtc::IMediaPacketSender> *)&source);
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createMediaPlayerAudioTrack(C_IAgoraService *this_,
                                                           C_agora_refptr audioSource)
{
  auto ptr = ((IAgoraService *)(this_))->createMediaPlayerAudioTrack(*(agora_refptr<rtc::IMediaPlayerSource> *)&audioSource);
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createMediaStreamingAudioTrack(C_IAgoraService *this_,
                                                              C_agora_refptr streamingSource)
{
  auto ptr = ((IAgoraService *)(this_))->createMediaStreamingAudioTrack(*(agora_refptr<rtc::IMediaStreamingSource> *)&streamingSource);
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createRecordingDeviceAudioTrack(C_IAgoraService *this_,
                                                               C_agora_refptr audioSource, bool enableAec)
{
  auto ptr = ((IAgoraService *)(this_))->createRecordingDeviceAudioTrack(*(agora_refptr<rtc::IRecordingDeviceSource> *)&audioSource, enableAec);
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createAudioDeviceManager(C_IAgoraService *this_)
{
  auto ptr = ((IAgoraService *)(this_))->createAudioDeviceManager();
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createMediaNodeFactory(C_IAgoraService *this_)
{
  auto ptr = ((IAgoraService *)(this_))->createMediaNodeFactory();
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createCameraVideoTrack(C_IAgoraService *this_,
                                                      C_agora_refptr videoSource, const char *id)
{
  auto ptr = ((IAgoraService *)(this_))->createCameraVideoTrack(*(agora_refptr<rtc::ICameraCapturer> *)&videoSource, id);
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createScreenVideoTrack(C_IAgoraService *this_,
                                                      C_agora_refptr videoSource, const char *id)
{
  auto ptr = ((IAgoraService *)(this_))->createScreenVideoTrack(*(agora_refptr<rtc::IScreenCapturer> *)&videoSource, id);
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createMixedVideoTrack(C_IAgoraService *this_, C_agora_refptr videoSource,
                                                     const char *id)
{
  auto ptr = ((IAgoraService *)(this_))->createMixedVideoTrack(*(agora_refptr<rtc::IVideoMixerSource> *)&videoSource, id);
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createTranscodedVideoTrack(C_IAgoraService *this_, C_agora_refptr transceiver,
                                                          const char *id)
{
  auto ptr = ((IAgoraService *)(this_))->createTranscodedVideoTrack(*(agora_refptr<rtc::IVideoFrameTransceiver> *)&transceiver, id);
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createCustomVideoTrack_frameSender(C_IAgoraService *this_,
                                                                  C_agora_refptr videoSource, const char *id)
{
  auto ptr = ((IAgoraService *)(this_))->createCustomVideoTrack(*(agora_refptr<rtc::IVideoFrameSender> *)&videoSource, id);
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createCustomVideoTrack_encoded(C_IAgoraService *this_,
                                                              C_agora_refptr videoSource,
                                                              const struct C_SenderOptions *options,
                                                              const char *id)
{
  auto ptr = ((IAgoraService *)(this_))->createCustomVideoTrack(*(agora_refptr<rtc::IVideoEncodedImageSender> *)&videoSource, *(SenderOptions *)&options, id);
  return *(C_agora_refptr *)&ptr;
}

#if defined(__ANDROID__) || (defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE)

C_agora_refptr C_IAgoraService_createScreenCaptureVideoTrack(C_IAgoraService *this_,
                                                             C_agora_refptr screen)
{
  auto ptr = ((IAgoraService *)(this_))->createScreenCaptureVideoTrack(*(agora_refptr<rtc::IScreenCapturer2> *)&screen);
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createScreenCaptureAudioTrack(C_IAgoraService *this_,
                                                             C_agora_refptr screen)
{
  auto ptr = ((IAgoraService *)(this_))->createScreenCaptureAudioTrack(*(agora_refptr<rtc::IScreenCapturer2> *)&screen);
  return *(C_agora_refptr *)&ptr;
}

#else

C_agora_refptr C_IAgoraService_createScreenCaptureVideoTrack(C_IAgoraService *this_,
                                                             C_agora_refptr screen, const char *id)
{
  auto ptr = ((IAgoraService *)(this_))->createScreenCaptureVideoTrack(*(agora_refptr<rtc::IScreenCapturer> *)&screen, id);
  return *(C_agora_refptr *)&ptr;
}

#endif

C_agora_refptr C_IAgoraService_createCustomVideoTrack_packetSender(C_IAgoraService *this_,
                                                                   C_agora_refptr source, const char *id)
{
  auto ptr = ((IAgoraService *)(this_))->createCustomVideoTrack(*(agora_refptr<rtc::IMediaPacketSender> *)&source, id);
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createMediaPlayerVideoTrack(C_IAgoraService *this_,
                                                           C_agora_refptr videoSource, const char *id)
{
  auto ptr = ((IAgoraService *)(this_))->createMediaPlayerVideoTrack(*(agora_refptr<rtc::IMediaPlayerSource> *)&videoSource, id);
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createMediaStreamingVideoTrack(C_IAgoraService *this_,
                                                              C_agora_refptr streamingSource, const char *id)
{
  auto ptr = ((IAgoraService *)(this_))->createMediaStreamingVideoTrack(*(agora_refptr<rtc::IMediaStreamingSource> *)&streamingSource, id);
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createRtmpStreamingService(C_IAgoraService *this_,
                                                          C_agora_refptr rtcConnection, const char *appId)
{
  auto ptr = ((IAgoraService *)(this_))->createRtmpStreamingService(*(agora_refptr<rtc::IRtcConnection> *)&rtcConnection, appId);
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createMediaRelayService(C_IAgoraService *this_,
                                                       C_agora_refptr rtcConnection, const char *appId)
{
  auto ptr = ((IAgoraService *)(this_))->createMediaRelayService(*(agora_refptr<rtc::IRtcConnection> *)&rtcConnection, appId);
  return *(C_agora_refptr *)&ptr;
}

C_agora_refptr C_IAgoraService_createFileUploadService(C_IAgoraService *this_,
                                                       C_agora_refptr rtcConnection, const char *appId)
{
  auto ptr = ((IAgoraService *)(this_))->createFileUploadService(*(agora_refptr<rtc::IRtcConnection> *)&rtcConnection, appId);
  return *(C_agora_refptr *)&ptr;
}

// C_IRtmService *C_IAgoraService_createRtmService();

int C_IAgoraService_addExtensionObserver(C_IAgoraService *this_, C_agora_refptr observer)
{
  return ((IAgoraService *)(this_))->addExtensionObserver(*(agora_refptr<rtc::IMediaExtensionObserver> *)&observer);
}

int C_IAgoraService_removeExtensionObserver(C_IAgoraService *this_, C_agora_refptr observer)
{
  return ((IAgoraService *)(this_))->removeExtensionObserver(*(agora_refptr<rtc::IMediaExtensionObserver> *)&observer);
}

// C_agora_refptr C_IAgoraService_createAudioDeviceManagerComponent(
//     C_IAudioDeviceManagerObserver *observer);

// C_agora_refptr C_IAgoraService_createLocalDataChannel(const C_DataChannelConfig *config);

const char *C_IAgoraService_getExtensionId(C_IAgoraService *this_, const char *provider_name, const char *extension_name)
{
  return ((IAgoraService *)(this_))->getExtensionId(provider_name, extension_name);
}

#if defined(_WIN32) || defined(__linux__) || defined(__ANDROID__)
int C_IAgoraService_loadExtensionProvider(C_IAgoraService *this_, const char *path, bool unload_after_use)
{
  return ((IAgoraService *)(this_))->loadExtensionProvider(path, unload_after_use);
}
#endif

int C_IAgoraService_enableExtension(C_IAgoraService *this_,
                                    const char *provider_name, const char *extension_name, const char *track_id,
                                    bool auto_enable_on_track)
{
  return ((IAgoraService *)(this_))->enableExtension(provider_name, extension_name, track_id, auto_enable_on_track);
}
int C_IAgoraService_disableExtension(C_IAgoraService *this_,
                                     const char *provider_name, const char *extension_name, const char *track_id)
{
  return ((IAgoraService *)(this_))->disableExtension(provider_name, extension_name, track_id);
}

C_agora_refptr C_IAgoraService_getConfigCenter(C_IAgoraService *this_)
{
  auto ptr = ((IAgoraService *)(this_))->getConfigCenter();
  return *(C_agora_refptr *)&ptr;
}

#pragma endregion C_IAgoraService

#pragma endregion agora::base

#pragma endregion agora

C_IAgoraService *C_createAgoraService()
{
  return createAgoraService();
}
