#ifndef C_I_AGORA_SERVICE_H
#define C_I_AGORA_SERVICE_H

#include "C_IAgoraLog.h"
#include "C_AgoraBase.h"
#include "C_AgoraOptional.h"

#include "C_NGIAgoraRtcConnection.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#pragma region agora

  // class ILocalDataChannel;
  // class IRemoteDataChannel;
  struct DataChannelConfig;

#pragma region agora::rtc

  // struct C_IRtcConnection;
  // class IRtmpConnection;
  // class ILocalUser;
  // class IMediaDeviceManager;
  // class INGAudioDeviceManager;
  struct C_TConnectionInfo;
  struct C_RtcConnectionConfiguration;
  struct C_RtmpConnectionConfiguration;
  // class ILocalAudioTrack;
  // class IMediaPlayerSource;
  // class IMediaStreamingSource;
  // class ICameraCapturer;
  // class IScreenCapturer;
  // class IScreenCapturer2;
  // class IAudioPcmDataSender;
  // class IAudioEncodedFrameSender;
  // class IVideoFrameSender;
  // class IVideoEncodedImageSender;
  // class IVideoSourceNode;
  // class IVideoMixerSource;
  // class IVideoFrameTransceiver;
  // class ILocalVideoTrack;
  // class IMediaNodeFactory;
  // class IRecordingDeviceSource;
  // class IRemoteAudioMixerSource;
  // class IRtmpStreamingService;
  // class IMediaPacketSender;
  // class IMediaRelayService;
  // class IAudioDeviceManager;
  // class IAudioDeviceManagerObserver;

  // class IMediaExtensionObserver;
  // class IExtensionProvider;
  // class IFileUploaderService;
  // class IConfigCenter;

  /**
   * The audio encoder configuration.
   */
  struct C_AudioEncoderConfiguration
  {
    /**
     * The audio profile: #AUDIO_PROFILE_TYPE
     */
    enum C_AUDIO_PROFILE_TYPE audioProfile;
  };
  struct C_AudioEncoderConfiguration *C_AudioEncoderConfiguration_New();
  void C_AudioEncoderConfiguration_Delete(struct C_AudioEncoderConfiguration *this_);

#pragma endregion agora::rtc

#pragma region agora::rtm

  // class IRtmService;

#pragma endregion agora::rtm

#pragma region agora::base

  // class IServiceObserver;

  /**
   * The global configurations for \ref agora::base::IAgoraService "AgoraService".
   *
   * Set these configurations when calling \ref agora::base::IAgoraService::initialize "initialize".
   */
  struct C_AgoraServiceConfiguration
  {
    /**
     * Whether to enable the audio processing module.
     * - `true`: (Default) Enable the audio processing module.
     * - `false`: Disable the audio processing module. If you disable the audio processing module, you cannot create audio tracks.
     */
    bool enableAudioProcessor;
    /**
     * Whether to enable the audio device module. The function of the audio device module is to manage audio devices,
     * such as recording and playing audio.
     * - `true`: (Default) Enable the audio device module. Audio recording and playback is available.
     * - `false`: Disable the audio device module. Audio recording and playback is unavailable.
     *
     * @note
     * If you set `enableAudioDevice` as `false` and set `enableAudioProcessor` as `true`, you cannot use audio devices,
     * but you can push PCM audio data.
     */
    bool enableAudioDevice;
    /**
     * Whether to enable video.
     * - `true`: Enable video.
     * - `false`: (Default) Disable video.
     */
    bool enableVideo;
    /**
     * The user context.
     * - For Windows, it is the handle of the window that loads the video. Specify this value to support plugging or unplugging the video devices while the host is powered on.
     * - For Android, it is the context of activity.
     */
    void *context;
    /**
     * The App ID of your project.
     */
    const char *appId;

    /**
     * The supported area code, default is AREA_CODE_GLOB
     */
    unsigned int areaCode;

    /** The channel profile. For details, see \ref agora::CHANNEL_PROFILE_TYPE "CHANNEL_PROFILE_TYPE". The default channel profile is `CHANNEL_PROFILE_LIVE_BROADCASTING`.
     */
    enum C_CHANNEL_PROFILE_TYPE channelProfile;

    /**
     * The license used for verification when connectting channel. Charge according to the license
     */
    const char *license;

    /**
     * The audio scenario. See \ref agora::rtc::AUDIO_SCENARIO_TYPE "AUDIO_SCENARIO_TYPE". The default value is `AUDIO_SCENARIO_DEFAULT`.
     */
    enum C_AUDIO_SCENARIO_TYPE audioScenario;
    /**
     * The config for custumer set log path, log size and log level.
     */
    struct C_LogConfig logConfig;
    /**
     * Whether to enable string uid.
     */
    bool useStringUid;

    /**
     * The service observer.
     */
    // C_IServiceObserver *serviceObserver;
    void *serviceObserver; // HACK

    unsigned char RESERVED[4]; // HACK for C++ agora::Optional
    /**
     * Thread priority for SDK common threads
     */
    // Optional<rtc::THREAD_PRIORITY_TYPE> threadPriority;
    enum C_THREAD_PRIORITY_TYPE threadPriority;

    /**
     * Whether use egl context in current thread as sdk‘s root egl context
     * which shared by all egl related modules. eg. camera capture, video renderer.
     * @note
     * This property applies to Android only.
     */
    bool useExternalEglContext;

    /**
     * Determines whether to enable domain limit.
     * - `true`: only connect to servers that already parsed by DNS
     * - `false`: (Default) connect to servers with no limit
     */
    bool domainLimit;
  };
  struct C_AgoraServiceConfiguration *C_AgoraServiceConfiguration_New();
  void C_AgoraServiceConfiguration_Delete(struct C_AgoraServiceConfiguration *this_);

  /**
   * The audio session configurations.
   *
   * Set these configurations when calling \ref agora::base::IAgoraService::setAudioSessionConfiguration "setAudioSessionConfiguration".
   */
  struct C_AudioSessionConfiguration
  {
    unsigned char RESERVED[4]; // HACK for C++ agora::Optional
    /**
     * Whether to enable audio input (recording) and audio output (playback):
     * - `true`: Enable audio recording and playback.
     * - `false`: Disable audio recording and playback, which prevents audio input
     * and output.
     *
     * @note
     * - For the recording function to work, the user must grant permission for audio recording.
     * - By default, the audio of your app is nonmixable, which means
     * activating audio sessions in your app interrupts other nonmixable audio sessions.
     * Set `allowMixWithOthers` as `true` to allow audio mixing.
     */
    // Optional<bool> playbackAndRecord;
    bool playbackAndRecord;

    unsigned char RESERVED[4]; // HACK for C++ agora::Optional
    /**
     * Whether to enable chat mode:
     * - `true`: Enable chat mode. This mode is for apps that are engaged in two-way
     * real-time communication, such as a voice or video chat.
     * - `false`: Disable chat mode.
     *
     * For a video chat, set this member as `true` and set the audio route to the speaker.
     */
    // Optional<bool> chatMode;
    bool chatMode;

    unsigned char RESERVED[4]; // HACK for C++ agora::Optional
    /**
     * Whether the audio defaults to the built-in speaker:
     * - `true`: The audio defaults to the built-in speaker.
     * - `false`: The audio does not default to the built-in speaker.
     *
     * @note
     * This member is available only when `playbackAndRecord` is set as `true`.
     */
    // Optional<bool> defaultToSpeaker;
    bool defaultToSpeaker;

    unsigned char RESERVED[4]; // HACK for C++ agora::Optional
    /**
     * Whether to temporarily change the current audio route to the built-in speaker:
     * - `true`: Set the current audio route to the built-in speaker.
     * - `false`: Do not set the current audio route to the built-in speaker.
     *
     * @note
     * This member is available only when the `playbackAndRecord` member is set as `true`.
     */
    // Optional<bool> overrideSpeaker;
    bool overrideSpeaker;

    unsigned char RESERVED[4]; // HACK for C++ agora::Optional
    /**
     * Whether to mix the audio from this session with the audio from active audio sessions in other apps.
     * - `true`: Mix the audio sessions.
     * - `false`: Do not mix the audio session.
     *
     * @note
     * This member is available only when the `playbackAndRecord` member is set as `true`.
     */
    // Optional<bool> allowMixWithOthers;
    bool allowMixWithOthers;

    unsigned char RESERVED[4]; // HACK for C++ agora::Optional
    /**
     * Whether to duck the audio from this session with the audio from active audio sessions in other apps.
     * - `true`: Duck the audio sessions.
     * - `false`: Do not duck the audio session.
     *
     * @note
     * This member is available only when the `playbackAndRecord` member is set as `true`.
     */
    // Optional<bool> allowDuckOthers;
    bool allowDuckOthers;

    unsigned char RESERVED[4]; // HACK for C++ agora::Optional
    /**
     * Whether to allow Bluetooth handsfree devices to appear as available audio input
     * devices:
     * - `true`: Allow Bluetooth handsfree devices to appear as available audio input routes.
     * - `false`: Do not allow Bluetooth handsfree devices to appear as available audio input
     * routes.
     *
     * @note
     * This member is available only when the `playbackAndRecord` member is set as `true`.
     */
    // Optional<bool> allowBluetooth;
    bool allowBluetooth;

    unsigned char RESERVED[4]; // HACK for C++ agora::Optional
    /**
     * Whether to allow the audio from this session to be routed to Bluetooth
     * devices that support the Advanced Audio Distribution Profile (A2DP).
     * - `true`: Allow the audio from this session to be routed to Bluetooth devices that
     * support the Advanced Audio Distribution Profile (A2DP).
     * - `false`: Do not allow the audio from this session to be routed to Bluetooth devices that
     * support the Advanced Audio Distribution Profile (A2DP).
     *
     * @note
     * This member is available only when the `playbackAndRecord` member is set as `true`.
     */
    // Optional<bool> allowBluetoothA2DP;
    bool allowBluetoothA2DP;

    unsigned char RESERVED[4]; // HACK for C++ agora::Optional
    /**
     * The expected audio sample rate (kHz) of this session.
     *
     * The value range is [8,48]. The actual sample rate may differ based on the audio sampling
     * device in use.
     */
    // Optional<double> sampleRate;
    double sampleRate;

    unsigned char RESERVED[4]; // HACK for C++ agora::Optional
    /**
     * The expected input and output buffer duration (ms) of this session.
     *
     * The value range is [0,93]. The actual I/O buffer duration might be lower
     * than the set value based on the hardware in use.
     */
    // Optional<double> ioBufferDuration;
    double ioBufferDuration;

    unsigned char RESERVED[4]; // HACK for C++ agora::Optional
    /**
     * The expected number of input audio channels of this session.
     */
    // Optional<int> inputNumberOfChannels;
    int inputNumberOfChannels;

    unsigned char RESERVED[4]; // HACK for C++ agora::Optional
    /**
     * The expected number of output audio channels of this session.
     */
    // Optional<int> outputNumberOfChannels;
    int outputNumberOfChannels;

    // bool operator==(const AudioSessionConfiguration &o) const
    // {
    //   return playbackAndRecord == o.playbackAndRecord && chatMode == o.chatMode &&
    //          defaultToSpeaker == o.defaultToSpeaker && overrideSpeaker == o.overrideSpeaker &&
    //          allowMixWithOthers == o.allowMixWithOthers && allowDuckOthers == o.allowDuckOthers &&
    //          allowBluetooth == o.allowBluetooth && allowBluetoothA2DP == o.allowBluetoothA2DP && sampleRate == o.sampleRate &&
    //          ioBufferDuration == o.ioBufferDuration &&
    //          inputNumberOfChannels == o.inputNumberOfChannels &&
    //          outputNumberOfChannels == o.outputNumberOfChannels;
    // }
    // bool operator!=(const AudioSessionConfiguration &o) const { return !(*this == o); }
  };
  struct C_AudioSessionConfiguration *C_AudioSessionConfiguration_New();
  void C_AudioSessionConfiguration_Delete(struct C_AudioSessionConfiguration *this_);
  void C_AudioSessionConfiguration_SetAll(struct C_AudioSessionConfiguration *this_, const struct C_AudioSessionConfiguration *change);

  /**
   * The audio mixing mode.
   */
  enum C_TMixMode
  {
    /**
     * Mix all the local audio tracks in the channel.
     */
    MIX_ENABLED,
    /**
     * Do not mix the local audio tracks in the channel.
     */
    MIX_DISABLED,
  };

  /**
   * The IServiceObserver class.
   */
  typedef void C_IServiceObserver;
#pragma region C_IServiceObserver

  void C_IServiceObserver_Delete(C_IServiceObserver *this_);

  /**
   * Reports the permission error.
   * @param permission {@link PERMISSION}
   */
  void C_IServiceObserver_onPermissionError(C_IServiceObserver *this_, enum C_PERMISSION_TYPE permissionType);
  /**
   * Reports the audio device error.
   * @param error {@link ERROR_CODE_TYPE}
   */
  void C_IServiceObserver_onAudioDeviceError(C_IServiceObserver *this_, enum C_ERROR_CODE_TYPE error, const char *description);
  /**
   * Reports the config fetch result.
   *
   * @param code The error code of fetching config.
   *  - 0(ERR_OK): Success.
   *  - 10(ERR_TIMEDOUT): Fetching config is timed out.
   * @param configType The type of fetching config.
   *  - 1(CONFIG_FETCH_TYPE_INITIALIZE): Fetch config when initializing RtcEngine without channel info.
   *  - 2(CONFIG_FETCH_TYPE_JOIN_CHANNEL): Fetch config when joining channel with channel info, such as channel name and uid.
   * @param configContent The config fetched from server.
   */
  void C_IServiceObserver_onFetchConfigResult(C_IServiceObserver *this_, int code, enum C_CONFIG_FETCH_TYPE configType, const char *configContent);

#pragma endregion C_IServiceObserver

  /**
   * The IAgoraService class.
   *
   * `IAgoraService` is the entry point of Agora low-level APIs. Use this interface to
   * create access points to Agora interfaces, including RTC connections and media tracks.
   *
   * You can create an `IAgoraService` object by calling \ref agora::base::IAgoraService::createAgoraService "createAgoraService".
   *
   * You can configure the `IAgoraService` object for different user scenarios on the global level by using `AgoraServiceConfiguration`.
   */
  typedef void C_IAgoraService;

#pragma region C_IAgoraService
  /**
   * Initializes the \ref agora::base::IAgoraService "AgoraService" object.
   *
   * @param config The configuration of the initialization. For details, see \ref agora::base::AgoraServiceConfiguration "AgoraServiceConfiguration".
   * @return
   * - 0: Success.
   * - < 0: Failure.
   *   - `ERR_INVALID_ARGUMENT`, if `context` in `AgoraServiceConfiguration` is not provided for
   * Android.
   *   - `ERR_INIT_NET_ENGINE`, if the network engine cannot be initialized. On Windows, the error occurs mostly because the connection to the local port is disabled by the firewall. In this case, turn off the firewall and then turn it on again.
   */
  int C_IAgoraService_initialize(C_IAgoraService *this_, const struct C_AgoraServiceConfiguration *config);

  /**
   * Flush log & cache before exit
   */
  void C_IAgoraService_atExit(C_IAgoraService *this_);

  /**
   * Releases the \ref agora::base::IAgoraService "AgoraService" object.
   *
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IAgoraService_release(C_IAgoraService *this_);

  /**
   * Configures the preset audio scenario.
   *
   * @param scenario The preset audio scenario: \ref agora::rtc::AUDIO_SCENARIO_TYPE
   * "AUDIO_SCENARIO_TYPE".
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IAgoraService_setAudioSessionPreset(C_IAgoraService *this_, enum C_AUDIO_SCENARIO_TYPE scenario);

  /**
   * Customizes the audio session configuration.
   *
   * @param config The reference to the audio session configuration: \ref agora::base::AudioSessionConfiguration "AudioSessionConfiguration".
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IAgoraService_setAudioSessionConfiguration(C_IAgoraService *this_, const struct C_AudioSessionConfiguration *config);

  /**
   * Gets the audio session configuration.
   *
   * @param [out] config The pointer to the audio session configuration: \ref agora::base::AudioSessionConfiguration "AudioSessionConfiguration".
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IAgoraService_getAudioSessionConfiguration(C_IAgoraService *this_, struct C_AudioSessionConfiguration *config);

  /**
   * Sets the path and size of the SDK log files.
   *
   * The SDK records all the log data during the SDK runtime in two log files,
   * each with a default size of 512 KB. If you set `fileSize` as 1024 KB,
   * the SDK outputs log files with a maximum size of 2 MB. If the total size
   * of the log files exceeds the set value, the new output log
   * overwrites the old output log.
   *
   * @note
   * To ensure that the output log is complete, call this method immediately after calling
   * \ref agora::base::IAgoraService::initialize "initialize".
   *
   * @param filePath The pointer to the log file. Ensure that the directory of the log file exists and is writable.
   * @param fileSize The size of the SDK log file size (KB).
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IAgoraService_setLogFile(C_IAgoraService *this_, const char *filePath, unsigned int fileSize);
  /**
   * Sets the SDK log output filter.
   *
   * The log level follows the sequence of OFF, CRITICAL, ERROR, WARNING, INFO, and DEBUG.
   *
   * Select a level to output the logs in and above the selected level.
   * For example, if you set the log level to WARNING, you can see the logs in the levels of CRITICAL, ERROR, and WARNING.
   *
   * @param filters The log output filter.
   * - `LOG_LEVEL_NONE (0x0000)`: Do not output any log file.
   * - `LOG_LEVEL_INFO (0x0001)`: (Recommended) Output log files of the INFO level.
   * - `LOG_LEVEL_WARN (0x0002)`: Output log files of the WARN level.
   * - `LOG_LEVEL_ERROR (0x0004)`: Output log files of the ERROR level.
   * - `LOG_LEVEL_FATAL (0x0008)`: Output log files of the FATAL level.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IAgoraService_setLogFilter(C_IAgoraService *this_, unsigned int filters);

  /**
   * Creates an \ref agora::rtc::IRtcConnection "RtcConnection" object and returns the pointer.
   *
   * @param cfg The reference to the RTC connection configuration: \ref agora::rtc::RtcConnectionConfiguration "RtcConnectionConfiguration".
   * @return
   * - The pointer to \ref rtc::IRtcConnection "IRtcConnection": Success.
   * - A null pointer: Failure.
   */
  C_IRtcConnection* C_IAgoraService_createRtcConnection(C_IAgoraService *this_,
                                                     const struct C_RtcConnectionConfiguration *cfg);

  // agora_refptr<rtc::IRtmpConnection>
  // C_agora_refptr C_IAgoraService_createRtmpConnection(C_IAgoraService *this_,
  //                                                     const struct C_RtmpConnectionConfiguration *cfg);

  /**
   * Creates a local audio track object and returns the pointer.
   *
   * By default, the audio track is created from the selected audio input device, such as
   * the built-in microphone on a mobile device.
   *
   * @return
   * - The pointer to \ref rtc::ILocalAudioTrack "ILocalAudioTrack": Success.
   * - A null pointer: Failure.
   * - `INVALID_STATE`, if `enableAudioProcessor` in \ref agora::base::AgoraServiceConfiguration "AgoraServiceConfiguration" is set as `false`.
   */
  C_agora_refptr C_IAgoraService_createLocalAudioTrack(C_IAgoraService *this_);

  /**
   * Creates a local mixed audio track object and returns the pointer.
   *
   * By default, the audio track is created from mix source, which could mixed target track.
   *
   * @return
   * - The pointer to \ref rtc::ILocalAudioTrack "ILocalAudioTrack": Success.
   * - A null pointer: Failure.
   */
  C_agora_refptr C_IAgoraService_createLocalMixedAudioTrack(C_IAgoraService *this_);

  /**
   * Creates a local audio track object with a PCM data sender and returns the pointer.
   *
   * Once created, this track can be used to send PCM audio data.
   *
   * @param audioSource The pointer to the PCM audio data sender: \ref agora::rtc::IAudioPcmDataSender "IAudioPcmDataSender".
   * @return
   * - The pointer to \ref rtc::ILocalAudioTrack "ILocalAudioTrack": Success.
   * - A null pointer: Failure.
   * - `INVALID_STATE`, if `enableAudioProcessor` in \ref agora::base::AgoraServiceConfiguration "AgoraServiceConfiguration" is set as `false`.
   */
  // C_agora_refptr C_IAgoraService_createCustomAudioTrack_pcmSender(C_IAgoraService *this_,
  //                                                       C_agora_refptr audioSource);

  /**
   * Creates a local audio track object with a PCM data sender and returns the pointer.
   * The source is not intended to be mixed with other source.
   *
   * Once created, this track can be used to send PCM audio data.
   *
   * @param audioSource The pointer to the PCM audio data sender: \ref agora::rtc::IAudioPcmDataSender "IAudioPcmDataSender".
   * @return
   * - The pointer to \ref rtc::ILocalAudioTrack "ILocalAudioTrack": Success.
   * - A null pointer: Failure.
   * - `INVALID_STATE`, if `enableAudioProcessor` in \ref agora::base::AgoraServiceConfiguration "AgoraServiceConfiguration" is set as `false`.
   */
  C_agora_refptr C_IAgoraService_createDirectCustomAudioTrack(C_IAgoraService *this_,
                                                              C_agora_refptr audioSource);

  /**
   * Creates a local audio track object with a PCM data sender and returns the pointer.
   *
   * Once created, this track can be used to send PCM audio data.
   *
   * @param audioSource The pointer to the PCM audio data sender: \ref agora::rtc::IAudioPcmDataSender "IAudioPcmDataSender".
   * @param enableAec Whether enable audio echo cancellation for PCM audio data.
   * @return
   * - The pointer to \ref rtc::ILocalAudioTrack "ILocalAudioTrack": Success.
   * - A null pointer: Failure.
   * - `INVALID_STATE`, if `enableAudioProcessor` in \ref agora::base::AgoraServiceConfiguration "AgoraServiceConfiguration" is set as `false`.
   */
  C_agora_refptr C_IAgoraService_createCustomAudioTrack_pcmSender_aec(C_IAgoraService *this_,
                                                                   C_agora_refptr audioSource, bool enableAec);

  /**
   * Creates a local audio track object with a audio mixer source and returns the pointer.
   *
   * Once created, this track can be used to send PCM audio data.
   *
   * @param audioSource The pointer to the audio mixer source : \ref agora::rtc::IRemoteAudioMixerSource "IRemoteAudioMixerSource".
   * @return
   * - The pointer to \ref rtc::ILocalAudioTrack "ILocalAudioTrack", if the method call succeeds.
   * - A null pointer, if the method call fails.
   * - `INVALID_STATE`, if `enableAudioProcessor` in `AgoraServiceConfiguration` is set as `false`.
   */
  C_agora_refptr C_IAgoraService_createCustomAudioTrack_mixerSource(C_IAgoraService *this_,
                                                                    C_agora_refptr audioSource);

  /**
   * Creates a local audio track object with an encoded audio frame sender and returns the pointer.
   *
   * Once created, this track can be used to send encoded audio frames, such as Opus frames.
   *
   * @param audioSource The pointer to the encoded audio frame sender: \ref agora::rtc::IAudioEncodedFrameSender "IAudioEncoderFrameSender".
   * @param mixMode The mixing mode of the encoded audio in the channel: #TMixMode.
   * @return
   * - The pointer to \ref rtc::ILocalAudioTrack "ILocalAudioTrack": Success.
   * - A null pointer: Failure.
   *   - `INVALID_STATE`, if `enableAudioProcessor` is set as `false` in \ref agora::base::AgoraServiceConfiguration "AgoraServiceConfiguration".
   */
  C_agora_refptr C_IAgoraService_createCustomAudioTrack_frameSender(C_IAgoraService *this_,
                                                                    C_agora_refptr audioSource, enum C_TMixMode mixMode);
  /// @cond (!Linux)
  /**
   * Creates a local audio track object with a media packet sender and returns the pointer.
   *
   * Once created, this track can be used to send audio packets, such as customized UDP/RTP packets.
   *
   * @param source The pointer to the media packet sender: \ref agora::rtc::IMediaPacketSender "IMediaPacketSender".
   * @return
   * - The pointer to \ref rtc::ILocalAudioTrack "ILocalAudioTrack": Success.
   * - A null pointer: Failure.
   * - `INVALID_STATE`, if `enableAudioProcessor` is set as `false` in \ref agora::base::AgoraServiceConfiguration "AgoraServiceConfiguration".
   */
  C_agora_refptr C_IAgoraService_createCustomAudioTrack_packetSender(C_IAgoraService *this_,
                                                                     C_agora_refptr source);
  /// @endcond
  /**
   * Creates a local audio track object with an IMediaPlayerSource object and returns the pointer.
   *
   * Once created, this track can be used to send PCM audio data decoded from a media player.
   *
   * @param audioSource The pointer to the player source. See \ref agora::rtc::IMediaPlayerSource "IMediaPlayerSource".
   * @return
   * - The pointer to \ref rtc::ILocalAudioTrack "ILocalAudioTrack": Success.
   * - A null pointer: Failure.
   * - `INVALID_STATE`, if `enableAudioProcessor` is set as `false` in \ref agora::base::AgoraServiceConfiguration "AgoraServiceConfiguration".
   */
  C_agora_refptr C_IAgoraService_createMediaPlayerAudioTrack(C_IAgoraService *this_,
                                                             C_agora_refptr audioSource);

  /**
   * Creates a local audio track object with an IMediaStreamingSource object and returns the pointer.
   *
   * Once created, this track can be used to send encoded audio data which demuxed from a media streaming.
   *
   * @param streamingSource The pointer to the streaming source. See \ref agora::rtc::IMediaStreamingSource "IMediaStreamingSource".
   * @return
   * - The pointer to \ref rtc::ILocalAudioTrack "ILocalAudioTrack": Success.
   * - A null pointer: Failure.
   * - `INVALID_STATE`, if `enableAudioProcessor` is set as `false` in \ref agora::base::AgoraServiceConfiguration "AgoraServiceConfiguration".
   */
  C_agora_refptr C_IAgoraService_createMediaStreamingAudioTrack(C_IAgoraService *this_,
                                                                C_agora_refptr streamingSource);

  /**
   * Creates a local audio track object with the recording device source and returns the pointer.
   *
   * Once created, this track can be used to send audio data got from a recording device.
   * @param audioSource The pointer to the recording device source. See \ref agora::rtc::IRecordingDeviceSource "IRecordingDeviceSource".
   * @param enableAec Whether enable audio echo cancellation for loopback recording. If loopback
   *                  recording device is a virtual sound card, it should be false, or it should be true.
   * @return
   * - The pointer to \ref rtc::ILocalAudioTrack "ILocalAudioTrack": Success.
   * - A null pointer: Failure.
   */
  C_agora_refptr C_IAgoraService_createRecordingDeviceAudioTrack(C_IAgoraService *this_,
                                                                 C_agora_refptr audioSource, bool enableAec);

  /**
   * Creates an audio device manager object and returns the pointer.
   *
   * @return
   * - The pointer to \ref rtc::INGAudioDeviceManager "INGAudioDeviceManager": Success.
   * - A null pointer: Failure.
   */
  C_agora_refptr C_IAgoraService_createAudioDeviceManager(C_IAgoraService *this_);

  /**
   * Creates a media node factory object and returns the pointer.
   *
   * @return
   * - The pointer to \ref rtc::IMediaNodeFactory "IMediaNodeFactory": Success.
   * - A null pointer: Failure.
   */
  C_agora_refptr C_IAgoraService_createMediaNodeFactory(C_IAgoraService *this_);

  /**
   * Creates a local video track object with a camera capturer and returns the pointer.
   *
   * Once created, this track can be used to send video data captured by the camera.
   *
   * @param videoSource The pointer to the camera capturer: \ref agora::rtc::ICameraCapturer "ICameraCapturer".
   *
   * @return
   * - The pointer to \ref rtc::ILocalVideoTrack "ILocalVideoTrack": Success.
   * - A null pointer: Failure.
   */
  C_agora_refptr C_IAgoraService_createCameraVideoTrack(C_IAgoraService *this_,
                                                        C_agora_refptr videoSource, const char *id);

  /**
   * Creates a local video track object with a screen capturer and returns the pointer.
   *
   * Once created, this track can be used to send video data for screen sharing.
   *
   * @param videoSource The pointer to the screen capturer: \ref agora::rtc::IScreenCapturer "IScreenCapturer".
   * @return
   * - The pointer to \ref rtc::ILocalVideoTrack "ILocalVideoTrack": Success.
   * - A null pointer: Failure.
   */
  C_agora_refptr C_IAgoraService_createScreenVideoTrack(C_IAgoraService *this_,
                                                        C_agora_refptr videoSource, const char *id);

  /**
   * Creates a local video track object with a video mixer and returns the pointer.
   *
   * Once created, this track can be used to send video data processed by the video mixer.
   *
   * @param videoSource The pointer to the video mixer. See \ref agora::rtc::IVideoMixerSource "IVideoMixerSource".
   *
   * @return
   * - The pointer to \ref rtc::ILocalVideoTrack "ILocalVideoTrack": Success.
   * - A null pointer: Failure.
   */
  C_agora_refptr C_IAgoraService_createMixedVideoTrack(C_IAgoraService *this_, C_agora_refptr videoSource,
                                                       const char *id);

  /**
   * Creates a local video track object with a video frame transceiver and returns the pointer.
   *
   * Once created, this track can be used to send video data processed by the transceiver.
   *
   * @param transceiver The pointer to the video transceiver. See \ref agora::rtc::IVideoFrameTransceiver "IVideoFrameTransceiver".
   *
   * @return
   * - The pointer to \ref rtc::ILocalVideoTrack "ILocalVideoTrack": Success.
   * - A null pointer: Failure.
   */
  C_agora_refptr C_IAgoraService_createTranscodedVideoTrack(C_IAgoraService *this_, C_agora_refptr transceiver,
                                                            const char *id);

  /// @cond (!RTSA)
  /**
   * Creates a local video track object with a customized video source and returns the pointer.
   *
   * Once created, this track can be used to send video data from a customized source.
   *
   * @param videoSource The pointer to the customized video frame sender: \ref agora::rtc::IVideoFrameSender "IVideoFrameSender".
   * @return
   * - The pointer to \ref rtc::ILocalVideoTrack "ILocalVideoTrack": Success.
   * - A null pointer: Failure.
   */
  C_agora_refptr C_IAgoraService_createCustomVideoTrack_frameSender(C_IAgoraService *this_,
                                                        C_agora_refptr videoSource, const char *id);
  /// @endcond

  /**
   * Creates a local video track object with an encoded video image sender and returns the pointer.
   *
   * Once created, this track can be used to send encoded video images, such as H.264 or VP8 frames.
   *
   * @param videoSource The pointer to the encoded video frame sender. See \ref agora::rtc::IVideoEncodedImageSender "IVideoEncodedImageSender".
   * @param options The configuration for creating video encoded image track.
   *
   * @return
   * - The pointer to \ref rtc::ILocalVideoTrack "ILocalVideoTrack": Success.
   * - A null pointer: Failure.
   */
  C_agora_refptr C_IAgoraService_createCustomVideoTrack_encoded(C_IAgoraService *this_,
                                                                C_agora_refptr videoSource,
                                                                const struct C_SenderOptions *options,
                                                                const char *id);

#if defined(__ANDROID__) || (defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE)
  /**
   * Creates a local video track object with a screen capture source extension and returns the pointer.
   *
   * Once created, this track can be used to work with the screen capture extension.
   *
   * @param screen The pointer to the screen capture source.
   *
   * @return
   * - The pointer to \ref rtc::ILocalVideoTrack "ILocalVideoTrack": Success.
   * - A null pointer: Failure.
   */
  C_agora_refptr C_IAgoraService_createScreenCaptureVideoTrack(C_IAgoraService *this_,
                                                               C_agora_refptr screen);

  /**
   * Creates a local audio track object with a screen capture source extension and returns the pointer.
   *
   * Once created, this track can be used to work with the screen capture extension.
   *
   * @param screen The pointer to the screen capture source.
   *
   * @return
   * - The pointer to \ref rtc::ILocalAudioTrack "ILocalAudioTrack": Success.
   * - A null pointer: Failure.
   */
  C_agora_refptr C_IAgoraService_createScreenCaptureAudioTrack(C_IAgoraService *this_,
                                                               C_agora_refptr screen);
#else
/**
 * Creates a local video track object with a screen capture source extension and returns the pointer.
 *
 * Once created, this track can be used to work with the screen capture extension.
 *
 * @param screen The pointer to the screen capture source.
 *
 * @return
 * - The pointer to \ref rtc::ILocalVideoTrack "ILocalVideoTrack": Success.
 * - A null pointer: Failure.
 */
C_agora_refptr C_IAgoraService_createScreenCaptureVideoTrack(C_IAgoraService *this_,
                                                             C_agora_refptr screen, const char *id);
#endif

  /// @cond (!Linux)
  /**
   * Creates a local video track object with a media packet sender and returns the pointer.
   *
   * Once created, this track can be used to send video packets, such as customized UDP/RTP packets.
   *
   * @param source The pointer to the media packet sender: \ref agora::rtc::IMediaPacketSender "IMediaPacketSender".
   * @return
   * - The pointer to \ref rtc::ILocalVideoTrack "ILocalVideoTrack": Success.
   * - A null pointer: Failure.
   */
  C_agora_refptr C_IAgoraService_createCustomVideoTrack_packetSender(C_IAgoraService *this_,
                                                        C_agora_refptr source, const char *id);
  /// @endcond
  /**
   * Creates a local video track object with an IMediaPlayerSource object and returns the pointer.
   *
   * Once created, this track can be used to send YUV frames decoded from a player.
   *
   * @param videoSource The pointer to the player source. See \ref agora::rtc::IMediaPlayerSource "IMediaPlayerSource".
   * @return
   * - The pointer to \ref rtc::ILocalAudioTrack "ILocalAudioTrack": Success.
   * - A null pointer: Failure.
   */
  C_agora_refptr C_IAgoraService_createMediaPlayerVideoTrack(C_IAgoraService *this_,
                                                             C_agora_refptr videoSource, const char *id);

  /**
   * Creates a local video track object with an IMediaStreamingSource object and returns the pointer.
   *
   * Once created, this track can be used to send H264 frames which demuxed from a streaming.
   *
   * @param streamingSource The pointer to the player source. See \ref agora::rtc::IMediaStreamingSource "IMediaStreamingSource".
   * @return
   * - The pointer to \ref rtc::ILocalAudioTrack "ILocalAudioTrack": Success.
   * - A null pointer: Failure.
   */
  C_agora_refptr C_IAgoraService_createMediaStreamingVideoTrack(C_IAgoraService *this_,
                                                                C_agora_refptr streamingSource, const char *id);

  /**
   * Creates an RTMP streaming service object and returns the pointer.
   *
   * @param rtcConnection The pointer to \ref rtc::IRtcConnection "IRtcConnection".
   * @param appId The App ID of the live streaming service.
   * @return
   * - The pointer to \ref rtc::IRtmpStreamingService "IRtmpStreamingService": Success.
   * - A null pointer: Failure.
   */
  C_agora_refptr C_IAgoraService_createRtmpStreamingService(C_IAgoraService *this_,
                                                            C_agora_refptr rtcConnection, const char *appId);

  /**
   * Creates an Media Relay service object and returns the pointer.
   *
   * @param rtcConnection The pointer to \ref rtc::IRtcConnection "IRtcConnection".
   * @param appId The App ID of the media relay service.
   * @return
   * - The pointer to \ref rtc::IMediaRelayService "IMediaRelayService", if the method call
   * succeeds.
   * - A null pointer, if the method call fails.
   */
  C_agora_refptr C_IAgoraService_createMediaRelayService(C_IAgoraService *this_,
                                                         C_agora_refptr rtcConnection, const char *appId);

  /**
   * Creates an file upload object and returns the pointer.
   *
   * @param rtcConnection The pointer to \ref rtc::IRtcConnection "IRtcConnection".
   * @param appId The App ID of the media relay service.
   * @return
   * - The pointer to \ref rtc::IFileUploaderService "IFileUploaderService", if the method call
   * succeeds.
   * - A null pointer, if the method call fails.
   */
  C_agora_refptr C_IAgoraService_createFileUploadService(C_IAgoraService *this_,
                                                         C_agora_refptr rtcConnection, const char *appId);

  // /**
  //  * Creates an RTM servive object and returns the pointer.
  //  *
  //  * @return
  //  * - The pointer to \ref rtm::IRtmService "IRtmService": Success.
  //  * - A null pointer: Failure.
  //  */
  // C_IRtmService *C_IAgoraService_createRtmService();

  int C_IAgoraService_addExtensionObserver(C_IAgoraService *this_, C_agora_refptr observer);

  int C_IAgoraService_removeExtensionObserver(C_IAgoraService *this_, C_agora_refptr observer);

  // /**
  //  * Creates an audio device manager and returns the pointer.
  //  *
  //  * @return
  //  * - The pointer to \ref rtc::IAudioDeviceManager "IAudioDeviceManager": Success.
  //  * - A null pointer: Failure.
  //  */
  // C_agora_refptr C_IAgoraService_createAudioDeviceManagerComponent(
  //     C_IAudioDeviceManagerObserver *observer);

  // /**
  //  * Creates an data channel and returns the pointer.
  //  *
  //  * @return
  //  * - The pointer to \ref rtc::ILocalDataChannel "ILocalDataChannel": Success.
  //  * - A null pointer: Failure.
  //  */
  // C_agora_refptr C_IAgoraService_createLocalDataChannel(const C_DataChannelConfig *config);

  /**
   * @brief Get the ID of the registered extension
   *
   * @param provider_name The pointer to provider name string (null-terminated)
   * @param extension_name The pointer to extension name string (null-terminated)
   * @return
   *  - Pointer to the extension id string (null-terminated). The pointer will be valid during service's lifetime
   */
  const char *C_IAgoraService_getExtensionId(C_IAgoraService *this_, const char *provider_name, const char *extension_name);

#if defined(_WIN32) || defined(__linux__) || defined(__ANDROID__)
  /**
   * @brief load the dynamic library of the extension
   *
   * @param path path of the extension library
   * @param unload_after_use unload the library when engine release
   * @return int
   */
  int C_IAgoraService_loadExtensionProvider(C_IAgoraService *this_, const char *path, bool unload_after_use);
#endif
  /**
   * Enable extension.
   * If the extension is enabled, the track loads the extension automatically.
   *
   * @param provider_name name for provider, e.g. agora.io.
   * @param extension_name name for extension, e.g. agora.beauty.
   * @param track_id id for the track, OPTIONAL_NULLPTR means effective on all tracks
   * @param auto_enable_on_track if the extension is automatically open on track.
   *
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IAgoraService_enableExtension(C_IAgoraService *this_,
                                      const char *provider_name, const char *extension_name, const char *track_id,
                                      bool auto_enable_on_track);
  /**
   * Disable extension.
   *
   * @param provider_name name for provider, e.g. agora.io.
   * @param extension_name name for extension, e.g. agora.beauty.
   * @param track_id id for the track, OPTIONAL_NULLPTR means effective on all tracks
   *
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IAgoraService_disableExtension(C_IAgoraService *this_,
                                       const char *provider_name, const char *extension_name, const char *track_id);

  /**
   * Get the \ref agora::rtc::IConfigCenter "IConfigCenter" object and return the pointer.
   *
   * @return
   * - The pointer to \ref rtc::IConfigCenter "IConfigCenter": Success.
   * - A null pointer: Failure.
   */
  C_agora_refptr C_IAgoraService_getConfigCenter(C_IAgoraService *this_);

#pragma endregion C_IAgoraService

#pragma endregion agora::base

#pragma endregion agora

  /** \addtogroup createAgoraService
   @{
   */
  /**
   * Creates an \ref agora::base::IAgoraService "IAgoraService" object and returns the pointer.
   *
   * @return
   * - The pointer to \ref agora::base::IAgoraService "IAgoraService": Success.
   * - A null pointer: Failure.
   */
  C_IAgoraService *C_createAgoraService();

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_I_AGORA_SERVICE_H
