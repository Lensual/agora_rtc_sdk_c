#ifndef C_I_AGORA_PARAMETER_H
#define C_I_AGORA_PARAMETER_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

// external key
/**
 * set the range of ports available for connection
 * @example "{\"rtc.udp_port_range\":[4500, 5000]}"
 */
#define C_KEY_RTC_UDP_PORT_RANGE "rtc.udp_port_range"
/**
 * set the list of ports available for connection
 * @example  "{\"rtc.udp_port_list\":[4501, 4502, 4503, 4504, 4505, 4506]}"
 */
#define C_KEY_RTC_UDP_PORT_LIST "rtc.udp_port_list"

/**
 * get the fd of sending socket available for connection
 * note: set method is not supported.
 */
#define C_KEY_RTC_UDP_SEND_FD "rtc.udp_send_fd"

  /**
   * set the video encoder mode (hardware or software)
   */
#define C_KEY_RTC_VIDEO_ENABLED_HW_ENCODER "engine.video.enable_hw_encoder"
#define C_KEY_RTC_VIDEO_HARDWARE_ENCODEING "che.hardware_encoding"
#define C_KEY_RTC_VIDEO_H264_HWENC "che.video.h264.hwenc"
  /**
   * set the hardware video encoder provider (nv for nvidia or qsv for intel)
   */
#define C_KEY_RTC_VIDEO_HW_ENCODER_PROVIDER "engine.video.hw_encoder_provider"

  /**
   * set the video decoder mode (hardware or software)
   */
#define C_KEY_RTC_VIDEO_ENABLED_HW_DECODER "engine.video.enable_hw_decoder"
#define C_KEY_RTC_VIDEO_HARDWARE_DECODING "che.hardware_decoding"

  /**
   * set the hardware video decoder provider (h264_cuvid(default) or h264_qsv)
   */
#define C_KEY_RTC_VIDEO_HW_DECODER_PROVIDER "engine.video.hw_decoder_provider"

  /**
   * override the lua policy
   */
#define C_KEY_RTC_VIDEO_OVERRIDE_SMALLVIDEO_NOT_USE_HWENC_POLICY "engine.video.override_smallvideo_not_use_hwenc_policy"

/**
 * enable/disable video packet retransmission, enabled by default
 */
#define C_KEY_RTC_VIDEO_RESEND "rtc.video_resend"

/**
 * enable/disable audio packet retransmission, enabled by default
 */
#define C_KEY_RTC_AUDIO_RESEND "rtc.audio_resend"

/**
 * set the bitrate ratio for video
 */
#define C_KEY_RTC_VIDEO_BITRATE_ADJUST_RATIO "rtc.video.bitrate_adjust_ratio"

/**
 * set the minbitrate / bitrate ratio for video
 */
#define C_KEY_RTC_VIDEO_MINBITRATE_RATIO "rtc.video.minbitrate_ratio"

/**
 * set the degradation preference
 */
#define C_KEY_RTC_VIDEO_DEGRADATION_PREFERENCE "rtc.video.degradation_preference"

  /**
   * set the degradation fps down step
   */

#define C_KEY_RTC_VIDEO_DEGRADATION_FPS_DOWN_STEP "rtc.video.degradation_fps_down_step"
/**
 * set the degradation fps up step
 */
#define C_KEY_RTC_VIDEO_DEGRADATION_FPS_UP_STEP "rtc.video.degradation_fps_up_step"

/**
 * set the duration ms for connection lost callback
 */
#define C_KEY_RTC_CONNECTION_LOST_PERIOD "rtc.connection_lost_period"

/**
 * set the local ip
 */
#define C_KEY_RTC_LOCAL_IP "rtc.local.ip"

/**
 * set the network interface
 */
#define C_KEY_RTC_NETWORK_INTERFACE "rtc.network.interface"

/**
 * set the video codec type, such as "H264", "JPEG"
 */
#define C_KEY_RTC_VIDEO_CODEC_TYPE "engine.video.codec_type"
#define C_KEY_RTC_VIDEO_MINOR_STREAM_CODEC_TYPE "engine.video.minor_stream_codec_type"
#define C_KEY_RTC_VIDEO_CODEC_INDEX "che.video.videoCodecIndex"
/**
 * only use average QP for quality scaling
 */
#define C_KEY_RTC_VIDEO_QUALITY_SCALE_ONLY_ON_AVERAGE_QP "engine.video.quality_scale_only_on_average_qp"

/**
 * low bound for quality scaling
 */
#define C_KEY_RTC_VIDEO_H264_QP_THRESHOLD_LOW "engine.video.h264_qp_thresholds_low"

/**
 * high bound for quality scaling
 */
#define C_KEY_RTC_VIDEO_H264_QP_THRESHOLD_HIGH "engine.video.h264_qp_thresholds_high"

#pragma region agora

#pragma region agora::util

  // template <class T>
  // class CopyableAutoPtr;
  typedef struct C_AutoPtr C_CopyableAutoPtr;

  // class C_IString;
  // typedef CopyableAutoPtr<IString> AString;
  typedef C_CopyableAutoPtr C_AString;

#pragma endregion agora::util

#pragma region agora::base

  typedef void C_IAgoraParameter;

#pragma region agora::C_IAgoraParameter

  /**
   * release the resource
   */
  void C_IAgoraParameter_release(C_IAgoraParameter *this_);

  /**
   * set bool value of the json
   * @param [in] key
   *        the key name
   * @param [in] value
   *        the value
   * @return return 0 if success or an error code
   */
  int C_IAgoraParameter_setBool(C_IAgoraParameter *this_, const char *key, bool value);

  /**
   * set int value of the json
   * @param [in] key
   *        the key name
   * @param [in] value
   *        the value
   * @return return 0 if success or an error code
   */
  int C_IAgoraParameter_setInt(C_IAgoraParameter *this_, const char *key, int value);

  /**
   * set unsigned int value of the json
   * @param [in] key
   *        the key name
   * @param [in] value
   *        the value
   * @return return 0 if success or an error code
   */
  int C_IAgoraParameter_setUInt(C_IAgoraParameter *this_, const char *key, unsigned int value);

  /**
   * set double value of the json
   * @param [in] key
   *        the key name
   * @param [in] value
   *        the value
   * @return return 0 if success or an error code
   */
  int C_IAgoraParameter_setNumber(C_IAgoraParameter *this_, const char *key, double value);

  /**
   * set string value of the json
   * @param [in] key
   *        the key name
   * @param [in] value
   *        the value
   * @return return 0 if success or an error code
   */
  int C_IAgoraParameter_setString(C_IAgoraParameter *this_, const char *key, const char *value);

  /**
   * set object value of the json
   * @param [in] key
   *        the key name
   * @param [in] value
   *        the value
   * @return return 0 if success or an error code
   */
  int C_IAgoraParameter_setObject(C_IAgoraParameter *this_, const char *key, const char *value);

  /**
   * set array value of the json
   * @param [in] key
   *        the key name
   * @param [in] value
   *        the value
   * @return return 0 if success or an error code
   */
  int C_IAgoraParameter_setArray(C_IAgoraParameter *this_, const char *key, const char *value);
  /**
   * get bool value of the json
   * @param [in] key
   *        the key name
   * @param [in, out] value
   *        the value
   * @return return 0 if success or an error code
   */
  int C_IAgoraParameter_getBool(C_IAgoraParameter *this_, const char *key, bool *value);

  /**
   * get int value of the json
   * @param [in] key
   *        the key name
   * @param [in, out] value
   *        the value
   * @return return 0 if success or an error code
   */
  int C_IAgoraParameter_getInt(C_IAgoraParameter *this_, const char *key, int *value);

  /**
   * get unsigned int value of the json
   * @param [in] key
   *        the key name
   * @param [in, out] value
   *        the value
   * @return return 0 if success or an error code
   */
  int C_IAgoraParameter_getUInt(C_IAgoraParameter *this_, const char *key, unsigned int *value);

  /**
   * get double value of the json
   * @param [in] key
   *        the key name
   * @param [in, out] value
   *        the value
   * @return return 0 if success or an error code
   */
  int C_IAgoraParameter_getNumber(C_IAgoraParameter *this_, const char *key, double *value);

  /**
   * get string value of the json
   * @param [in] key
   *        the key name
   * @param [in, out] value
   *        the value
   * @return return 0 if success or an error code
   */
  int C_IAgoraParameter_getString(C_IAgoraParameter *this_, const char *key, C_AString *value);

  /**
   * get a child object value of the json
   * @param [in] key
   *        the key name
   * @param [in, out] value
   *        the value
   * @return return 0 if success or an error code
   */
  int C_IAgoraParameter_getObject(C_IAgoraParameter *this_, const char *key, C_AString *value);

  /**
   * get array value of the json
   * @param [in] key
   *        the key name
   * @param [in, out] value
   *        the value
   * @return return 0 if success or an error code
   */
  int C_IAgoraParameter_getArray(C_IAgoraParameter *this_, const char *key, const char *args, C_AString *value);

  /**
   * set parameters of the sdk or engine
   * @param [in] parameters
   *        the parameters
   * @return return 0 if success or an error code
   */
  int C_IAgoraParameter_setParameters(C_IAgoraParameter *this_, const char *parameters);

  int C_IAgoraParameter_convertPath(C_IAgoraParameter *this_, const char *filePath, C_AString *value);

  void C_IAgoraParameter_Delete(C_IAgoraParameter *this_);

#pragma endregion agora::C_IAgoraParameter

#pragma endregion agora::base

#pragma endregion agora

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_I_AGORA_PARAMETER_H
