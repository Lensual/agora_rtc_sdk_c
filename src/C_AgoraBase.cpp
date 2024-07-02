// 引入AgoraRTM SDK
#include "AgoraBase.h"

using namespace agora;
using namespace agora::rtc;
using namespace agora::base;

// Agora C封装
#include "C_AgoraBase.h"

#pragma region agora

#pragma region agora::util

#pragma endregion agora::util

#pragma region agora::rtc

struct C_VideoDimensions *C_VideoDimensions_New()
{
  return (C_VideoDimensions *)(new VideoDimensions());
}
void C_VideoDimensions_Delete(struct C_VideoDimensions *this_)
{
  delete ((VideoDimensions *)(this_));
}

struct C_SenderOptions *C_SenderOptions_New()
{
  return (C_SenderOptions *)(new SenderOptions());
}
void C_SenderOptions_Delete(struct C_SenderOptions *this_)
{
  delete ((SenderOptions *)(this_));
}

struct C_EncodedAudioFrameAdvancedSettings *C_EncodedAudioFrameAdvancedSettings_New()
{
  return (C_EncodedAudioFrameAdvancedSettings *)(new EncodedAudioFrameAdvancedSettings());
}
void C_EncodedAudioFrameAdvancedSettings_Delete(struct C_EncodedAudioFrameAdvancedSettings *this_)
{
  delete ((EncodedAudioFrameAdvancedSettings *)(this_));
}

struct C_EncodedAudioFrameInfo *C_EncodedAudioFrameInfo_New()
{
  return (C_EncodedAudioFrameInfo *)(new EncodedAudioFrameInfo());
}
void C_EncodedAudioFrameInfo_Delete(struct C_EncodedAudioFrameInfo *this_)
{
  delete ((EncodedAudioFrameInfo *)(this_));
}

struct C_AudioPcmDataInfo *C_AudioPcmDataInfo_New()
{
  return (C_AudioPcmDataInfo *)(new AudioPcmDataInfo());
}
void C_AudioPcmDataInfo_Delete(struct C_AudioPcmDataInfo *this_)
{
  delete ((AudioPcmDataInfo *)(this_));
}

struct C_VideoSubscriptionOptions *C_VideoSubscriptionOptions_New()
{
  return (C_VideoSubscriptionOptions *)(new VideoSubscriptionOptions());
}
void C_VideoSubscriptionOptions_Delete(struct C_VideoSubscriptionOptions *this_)
{
  delete ((VideoSubscriptionOptions *)(this_));
}

struct C_EncodedVideoFrameInfo *C_EncodedVideoFrameInfo_New()
{
  return (C_EncodedVideoFrameInfo *)(new EncodedVideoFrameInfo());
}
void C_EncodedVideoFrameInfo_Delete(struct C_EncodedVideoFrameInfo *this_)
{
  delete ((EncodedVideoFrameInfo *)(this_));
}

struct C_AdvanceOptions *C_AdvanceOptions_New()
{
  return (C_AdvanceOptions *)(new AdvanceOptions());
}
void C_AdvanceOptions_Delete(struct C_AdvanceOptions *this_)
{
  delete ((AdvanceOptions *)(this_));
}

struct C_CodecCapLevels *C_CodecCapLevels_New()
{
  return (C_CodecCapLevels *)(new CodecCapLevels());
}
void C_CodecCapLevels_Delete(struct C_CodecCapLevels *this_)
{
  delete ((CodecCapLevels *)(this_));
}

struct C_CodecCapInfo *C_CodecCapInfo_New()
{
  return (C_CodecCapInfo *)(new CodecCapInfo());
}
void C_CodecCapInfo_Delete(struct C_CodecCapInfo *this_)
{
  delete ((CodecCapInfo *)(this_));
}

struct C_VideoEncoderConfiguration *C_VideoEncoderConfiguration_New()
{
  return (C_VideoEncoderConfiguration *)(new VideoEncoderConfiguration());
}
void VideoEncoderConfiguration_Delete(struct VideoEncoderConfiguration *this_)
{
  delete ((VideoEncoderConfiguration *)(this_));
}

struct C_DataStreamConfig *C_DataStreamConfig_New()
{
  return (C_DataStreamConfig *)(new DataStreamConfig());
}
void C_DataStreamConfig_Delete(struct C_DataStreamConfig *this_)
{
  delete ((DataStreamConfig *)(this_));
}

struct C_SimulcastStreamConfig *C_SimulcastStreamConfig_New()
{
  return (C_SimulcastStreamConfig *)(new SimulcastStreamConfig());
}
void C_SimulcastStreamConfig_Delete(struct C_SimulcastStreamConfig *this_)
{
  delete ((SimulcastStreamConfig *)(this_));
}

struct C_Rectangle *C_Rectangle_New()
{
  return (C_Rectangle *)(new Rectangle());
}
void C_Rectangle_Delete(struct C_Rectangle *this_)
{
  delete ((Rectangle *)(this_));
}

struct C_WatermarkRatio *C_WatermarkRatio_New()
{
  return (C_WatermarkRatio *)(new WatermarkRatio());
}
void C_WatermarkRatio_Delete(struct C_WatermarkRatio *this_)
{
  delete ((WatermarkRatio *)(this_));
}

struct C_WatermarkOptions *C_WatermarkOptions_New()
{
  return (C_WatermarkOptions *)(new WatermarkOptions());
}
void C_WatermarkOptions_Delete(struct C_WatermarkOptions *this_)
{
  delete ((WatermarkOptions *)(this_));
}

struct C_RtcStats *C_RtcStats_New()
{
  return (C_RtcStats *)(new RtcStats());
}
void C_RtcStats_Delete(struct C_RtcStats *this_)
{
  delete ((RtcStats *)(this_));
}

struct C_ClientRoleOptions *C_ClientRoleOptions_New()
{
  return (C_ClientRoleOptions *)(new ClientRoleOptions());
}
void C_ClientRoleOptions_Delete(struct C_ClientRoleOptions *this_)
{
  delete ((ClientRoleOptions *)(this_));
}

struct C_VideoTrackInfo *C_VideoTrackInfo_New()
{
  return (C_VideoTrackInfo *)(new VideoTrackInfo());
}
void C_VideoTrackInfo_Delete(struct C_VideoTrackInfo *this_)
{
  delete ((VideoTrackInfo *)(this_));
}

struct C_AudioVolumeInfo *C_AudioVolumeInfo_New()
{
  return (C_AudioVolumeInfo *)(new AudioVolumeInfo());
}
void C_AudioVolumeInfo_Delete(struct C_AudioVolumeInfo *this_)
{
  delete ((AudioVolumeInfo *)(this_));
}

struct C_DeviceInfo *C_DeviceInfo_New()
{
  return (C_DeviceInfo *)(new DeviceInfo());
}
void C_DeviceInfo_Delete(struct C_DeviceInfo *this_)
{
  delete ((DeviceInfo *)(this_));
}

struct C_LocalAudioStats *C_LocalAudioStats_New()
{
  return (C_LocalAudioStats *)(new LocalAudioStats());
}
void C_LocalAudioStats_Delete(struct C_LocalAudioStats *this_)
{
  delete ((LocalAudioStats *)(this_));
}

struct C_LastmileProbeOneWayResult *C_LastmileProbeOneWayResult_New()
{
  return (C_LastmileProbeOneWayResult *)(new LastmileProbeOneWayResult());
}
void C_LastmileProbeOneWayResult_Delete(struct C_LastmileProbeOneWayResult *this_)
{
  delete ((LastmileProbeOneWayResult *)(this_));
}

struct C_LastmileProbeResult *C_LastmileProbeResult_New()
{
  return (C_LastmileProbeResult *)(new LastmileProbeResult());
}
void C_LastmileProbeResult_Delete(struct C_LastmileProbeResult *this_)
{
  delete ((LastmileProbeResult *)(this_));
}

struct C_WlAccStats *C_WlAccStats_New()
{
  return (C_WlAccStats *)(new WlAccStats());
}
void C_WlAccStats_Delete(struct C_WlAccStats *this_)
{
  delete ((WlAccStats *)(this_));
}

struct C_VideoRenderingTracingInfo *C_VideoRenderingTracingInfo_New()
{
  return (C_VideoRenderingTracingInfo *)(new VideoRenderingTracingInfo());
}
void C_VideoRenderingTracingInfo_Delete(struct C_VideoRenderingTracingInfo *this_)
{
  delete ((VideoRenderingTracingInfo *)(this_));
}

#pragma endregion agora::rtc

#pragma region agora::base

#pragma endregion agora::base

struct C_SpatialAudioParams *C_SpatialAudioParams_New()
{
  return (C_SpatialAudioParams *)(new SpatialAudioParams());
}
void C_SpatialAudioParams_Delete(struct C_SpatialAudioParams *this_)
{
  delete ((SpatialAudioParams *)(this_));
}

#pragma endregion agora

const char *C_getAgoraSdkVersion(int *build)
{
  return getAgoraSdkVersion(build);
}

const char *C_getAgoraSdkErrorDescription(int err)
{
  return getAgoraSdkErrorDescription(err);
}

int C_setAgoraSdkExternalSymbolLoader(void *(*func)(const char *symname))
{
  return setAgoraSdkExternalSymbolLoader(func);
}

int C_createAgoraCredential(C_AString *credential)
{
  return createAgoraCredential(*(agora::util::AString *)credential);
}

int C_getAgoraCertificateVerifyResult(const char *credential_buf, int credential_len,
                                      const char *certificate_buf, int certificate_len)
{
  return getAgoraCertificateVerifyResult(credential_buf, credential_len,
                                         certificate_buf, certificate_len);
}

int64_t C_getAgoraCurrentMonotonicTimeInMs()
{
  return getAgoraCurrentMonotonicTimeInMs();
}