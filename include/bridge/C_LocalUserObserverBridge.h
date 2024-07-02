#ifndef C_LOCAL_USER_OBSERVER_BRIDGE_H
#define C_LOCAL_USER_OBSERVER_BRIDGE_H

#include "C_NGIAgoraLocalUser.h"
#include "C_NGIAgoraVideoTrack.h"
#include "C_NGIAgoraAudioTrack.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

  typedef void C_LocalUserObserverBridge;
#pragma region C_LocalUserObserverBridge
  // Callbacks

  typedef void (*C_LocalUserObserverBridge_onAudioTrackPublishStart)(C_LocalUserObserverBridge *this_, void *userData,
                                                                     C_ILocalAudioTrack *audioTrack);

  /**
   * Occurs when the first packet of the local audio track is sent, indicating that the local audio track
   * is successfully published.
   *
   * @param audioTrack The pointer to \ref agora::rtc::ILocalAudioTrack "ILocalAudioTrack".
   */
  typedef void (*C_LocalUserObserverBridge_onAudioTrackPublishSuccess)(C_LocalUserObserverBridge *this_, void *userData,
                                                                       C_ILocalAudioTrack *audioTrack);

  typedef void (*C_LocalUserObserverBridge_onAudioTrackUnpublished)(C_LocalUserObserverBridge *this_, void *userData,
                                                                    C_ILocalAudioTrack *audioTrack);

  /**
   * Occurs when a local audio track fails to be published.
   *
   * @param audioTrack The pointer to `ILocalAudioTrack`.
   * @param error The error information: #ERROR_CODE_TYPE.
   */
  typedef void (*C_LocalUserObserverBridge_onAudioTrackPublicationFailure)(C_LocalUserObserverBridge *this_, void *userData,
                                                                           C_ILocalAudioTrack *audioTrack,
                                                                           enum C_ERROR_CODE_TYPE error);

  /**
   * Reports the statistics of a local audio track.
   *
   * @param stats The reference to the statistics of the local audio track.
   */
  typedef void (*C_LocalUserObserverBridge_onLocalAudioTrackStatistics)(C_LocalUserObserverBridge *this_, void *userData,
                                                                        const struct C_LocalAudioStats *stats);

  /**
   * Reports the statistics of a remote audio track.
   *
   * @param audioTrack The pointer to `IRemoteAudioTrack`.
   * @param stats The statistics of the remote audio track.
   */
  typedef void (*C_LocalUserObserverBridge_onRemoteAudioTrackStatistics)(C_LocalUserObserverBridge *this_, void *userData,
                                                                         C_IRemoteAudioTrack *audioTrack,
                                                                         const struct C_RemoteAudioTrackStats *stats);

  /**
   * Occurs when the first remote audio frame is received.
   *
   * This callback indicates that the local user has subscribed to a specified remote audio track, and the first
   * frame of this audio track has been received.
   *
   * @param userId The ID of the remote user whose audio frame is received.
   * @param audioTrack The pointer to `IRemoteAudioTrack`.
   */
  typedef void (*C_LocalUserObserverBridge_onUserAudioTrackSubscribed)(C_LocalUserObserverBridge *this_, void *userData,
                                                                       C_user_id_t userId,
                                                                       C_IRemoteAudioTrack *audioTrack);

  /**
   * Occurs when the state of a remote audio track changes.
   *
   * @param userId The ID of the remote user whose audio track state has changed.
   * @param audioTrack The pointer to `IRemoteAudioTrack`.
   * @param state The current state of the audio track.
   * @param reason The reason for the state change.
   * @param elapsed The time (ms) since the user connects to an Agora channel.
   */
  typedef void (*C_LocalUserObserverBridge_onUserAudioTrackStateChanged)(C_LocalUserObserverBridge *this_, void *userData,
                                                                         C_user_id_t userId,
                                                                         C_IRemoteAudioTrack *audioTrack,
                                                                         enum C_REMOTE_AUDIO_STATE state,
                                                                         enum C_REMOTE_AUDIO_STATE_REASON reason,
                                                                         int elapsed);

  typedef void (*C_LocalUserObserverBridge_onVideoTrackPublishStart)(C_LocalUserObserverBridge *this_, void *userData,
                                                                     C_ILocalVideoTrack *videoTrack);

  /**
   * Occurs when the first packet of a local video track is sent, indicating that the local video track
   * is successfully published.
   * @param videoTrack The pointer to `ILocalVideoTrack`.
   */
  typedef void (*C_LocalUserObserverBridge_onVideoTrackPublishSuccess)(C_LocalUserObserverBridge *this_, void *userData,
                                                                       C_ILocalVideoTrack *videoTrack);

  /**
   * Occurs when a local video track fails to be published.
   *
   * @param videoTrack The pointer to `ILocalVideoTrack`.
   * @param error The error information: #ERROR_CODE_TYPE.
   */
  typedef void (*C_LocalUserObserverBridge_onVideoTrackPublicationFailure)(C_LocalUserObserverBridge *this_, void *userData,
                                                                           C_ILocalVideoTrack *videoTrack,
                                                                           enum C_ERROR_CODE_TYPE error);

  typedef void (*C_LocalUserObserverBridge_onVideoTrackUnpublished)(C_LocalUserObserverBridge *this_, void *userData,
                                                                    C_ILocalVideoTrack *videoTrack);

  /**
   * Occurs when the state of a local video track changes.
   * @note
   * When you receive error from this callback, the corresponding track is in error state.
   * To make the track recover from error state, we highly recommend that you disable the track and
   * try re-enabling it again.
   *
   * @param videoTrack The pointer to `ILocalVideoTrack`.
   * @param state The state of the local video track.
   * @param errorCode The error information.
   */
  typedef void (*C_LocalUserObserverBridge_onLocalVideoTrackStateChanged)(C_LocalUserObserverBridge *this_, void *userData,
                                                                          C_ILocalVideoTrack *videoTrack,
                                                                          enum C_LOCAL_VIDEO_STREAM_STATE state,
                                                                          enum C_LOCAL_VIDEO_STREAM_ERROR errorCode);

  /**
   * Reports the statistics of a local video track.
   *
   * @param videoTrack The pointer to `ILocalVideoTrack`.
   * @param stats The statistics of the local video track.
   */
  typedef void (*C_LocalUserObserverBridge_onLocalVideoTrackStatistics)(C_LocalUserObserverBridge *this_, void *userData,
                                                                        C_ILocalVideoTrack *videoTrack,
                                                                        const struct C_LocalVideoTrackStats *stats);

  /**
   * Occurs when the first remote video frame is received.
   *
   * This callback indicates that the local user has subscribed to a specified remote video track, and
   * the first frame of this video track has been received.
   *
   * @param userId The ID of the remote user whose video frame is received.
   * @param trackInfo The information of the remote video track.
   * @param videoTrack The pointer to `IRemoteVideoTrack`.
   */
  typedef void (*C_LocalUserObserverBridge_onUserVideoTrackSubscribed)(C_LocalUserObserverBridge *this_, void *userData,
                                                                       C_user_id_t userId, struct C_VideoTrackInfo trackInfo,
                                                                       C_IRemoteVideoTrack *videoTrack);

  /**
   * Occurs when the state of a remote video track changes.
   *
   * @param userId the ID of the remote user whose video track state has changed.
   * @param videoTrack The pointer to `IRemoteVideoTrack`.
   * @param state The current state of the video track.
   * @param reason The reason for the state change.
   * @param elapsed The time (ms) since the user connects to an Agora channel.
   */
  typedef void (*C_LocalUserObserverBridge_onUserVideoTrackStateChanged)(C_LocalUserObserverBridge *this_, void *userData,
                                                                         C_user_id_t userId,
                                                                         C_IRemoteVideoTrack *videoTrack,
                                                                         enum C_REMOTE_VIDEO_STATE state,
                                                                         enum C_REMOTE_VIDEO_STATE_REASON reason,
                                                                         int elapsed);

  /**
   * Occurs when the first remote video frame is rendered.
   *
   * @param userId the ID of the remote user.
   * @param width Width (px) of the video frame.
   * @param height Height (px) of the video stream.
   * @param elapsed The time (ms) since the user connects to an Agora channel.
   */
  typedef void (*C_LocalUserObserverBridge_onFirstRemoteVideoFrameRendered)(C_LocalUserObserverBridge *this_, void *userData,
                                                                            C_user_id_t userId, int width, int height, int elapsed);

  /**
   * Reports the statistics of a remote video track.
   *
   * @param videoTrack The pointer to `IRemoteVideoTrack`.
   * @param stats The statistics of the remote video track.
   */
  typedef void (*C_LocalUserObserverBridge_onRemoteVideoTrackStatistics)(C_LocalUserObserverBridge *this_, void *userData,
                                                                         C_IRemoteVideoTrack *videoTrack, const struct C_RemoteVideoTrackStats *stats);

  /**
   * Reports which users are speaking, the speakers' volumes, and whether the local user is speaking.
   *
   * This callback reports the IDs and volumes of the loudest speakers at the moment in the channel,
   * and whether the local user is speaking.
   *
   * You can set the time interval of this callback using \ref ILocalUser::setAudioVolumeIndicationParameters "setAudioVolumeIndicationParameters".
   *
   * The SDK triggers two `onAudioVolumeIndication` callbacks at one time, one reporting the
   * volume information of the local user and the other reporting the volume information of all remote users.
   *
   * @note
   * - To detect whether the local user is speaking, set `report_vad` in `enableAudioVolumeIndication` to `true`.
   *
   * @param speakers The pointer to \ref agora::rtc::AudioVolumeInformation "AudioVolumeInformation", which is an array containing the user ID and volume information for each speaker.
   * - In the local user's callback, this array contains the following members:
   *   - `uid`, which is always `0`
   *   - `volume`, which reports the sum of the voice volume and the audio-mixing volume of the local user
   *   - `vad`, which reports whether the local user is speaking
   * - In the remote users' callback, this array contains the following members:
   *   - `uid`, which is the UID of each remote speaker
   *   - `volume`, which reports the sum of the voice volume and the audio-mixing volume of each remote speaker.
   *   - `vad`, which is always `0`
   * An empty `speakers` array in the callback indicates that no remote user is speaking at the moment.
   * @param speakerNumber The total number of the speakers.
   * @param totalVolume The total volume after audio mixing. The value ranges between 0 (lowest volume) and 255 (highest volume).
   * - In the local user's callback, `totalVolume` is the sum of the voice volume and the audio-mixing volume of the local user.
   * - In the remote speakers' callback, `totalVolume` is the sum of the voice volume and the audio-mixing volume of all remote speakers.
   */
  typedef void (*C_LocalUserObserverBridge_onAudioVolumeIndication)(C_LocalUserObserverBridge *this_, void *userData,
                                                                    const struct C_AudioVolumeInformation *speakers, unsigned int speakerNumber,
                                                                    int totalVolume);

  /**
   * Occurs when an active speaker is detected.
   *
   * You can add relative functions on your app, for example, the active speaker, once detected,
   * will have the portrait zoomed in.
   *
   * @note
   * - The active speaker means the user ID of the speaker who speaks at the highest volume during a
   * certain period of time.
   *
   * @param userId The ID of the active speaker. A `userId` of `0` means the local user.
   */
  typedef void (*C_LocalUserObserverBridge_onActiveSpeaker)(C_LocalUserObserverBridge *this_, void *userData,
                                                            C_user_id_t userId);

  /**
   * Occurs when the audio subscribe state changed.
   *
   * @param channel The channel name of user joined.
   * @param userId The remote string user ID that is subscribed to.
   * @param oldState The old state of the audio stream subscribe : #STREAM_SUBSCRIBE_STATE.
   * @param newState The new state of the audio stream subscribe : #STREAM_SUBSCRIBE_STATE.
   * @param elapseSinceLastState The time elapsed (ms) from the old state to the new state.
   */
  typedef void (*C_LocalUserObserverBridge_onAudioSubscribeStateChanged)(C_LocalUserObserverBridge *this_, void *userData,
                                                                         const char *channel, C_user_id_t userId, enum C_STREAM_SUBSCRIBE_STATE oldState, enum C_STREAM_SUBSCRIBE_STATE newState, int elapseSinceLastState);

  /**
   * Occurs when the video subscribe state changed.
   *
   * @param channel The channel name of user joined.
   * @param userId The remote string user ID that is subscribed to.
   * @param oldState The old state of the video stream subscribe : #STREAM_SUBSCRIBE_STATE.
   * @param newState The new state of the video stream subscribe : #STREAM_SUBSCRIBE_STATE.
   * @param elapseSinceLastState The time elapsed (ms) from the old state to the new state.
   */
  typedef void (*C_LocalUserObserverBridge_onVideoSubscribeStateChanged)(C_LocalUserObserverBridge *this_, void *userData,
                                                                         const char *channel, C_user_id_t userId, enum C_STREAM_SUBSCRIBE_STATE oldState, enum C_STREAM_SUBSCRIBE_STATE newState, int elapseSinceLastState);

  /**
   * Occurs when the audio publish state changed.
   *
   * @param channel The channel name of user joined.
   * @param oldState The old state of the audio stream publish : #STREAM_PUBLISH_STATE.
   * @param newState The new state of the audio stream publish : #STREAM_PUBLISH_STATE.
   * @param elapseSinceLastState The time elapsed (ms) from the old state to the new state.
   */
  typedef void (*C_LocalUserObserverBridge_onAudioPublishStateChanged)(C_LocalUserObserverBridge *this_, void *userData,
                                                                       const char *channel, enum C_STREAM_PUBLISH_STATE oldState, enum C_STREAM_PUBLISH_STATE newState, int elapseSinceLastState);

  /**
   * Occurs when the video publish state changed.
   *
   * @param channel The channel name of user joined.
   * @param oldState The old state of the video stream publish : #STREAM_PUBLISH_STATE.
   * @param newState The new state of the video stream publish : #STREAM_PUBLISH_STATE.
   * @param elapseSinceLastState The time elapsed (ms) from the old state to the new state.
   */
  typedef void (*C_LocalUserObserverBridge_onVideoPublishStateChanged)(C_LocalUserObserverBridge *this_, void *userData,
                                                                       const char *channel, enum C_STREAM_PUBLISH_STATE oldState, enum C_STREAM_PUBLISH_STATE newState, int elapseSinceLastState);

  /** Occurs when the first remote audio frame is received.
   *
   * @param userId ID of the remote user.
   * @param isFallbackOrRecover Whether the remotely subscribed media stream
   * falls back to audio-only or switches back to the video:
   * - true: The remotely subscribed media stream falls back to audio-only
   * due to poor network conditions.
   * - false: The remotely subscribed media stream switches back to the
   * video stream after the network conditions improved.
   **/
  typedef void (*C_LocalUserObserverBridge_onRemoteSubscribeFallbackToAudioOnly)(C_LocalUserObserverBridge *this_, void *userData,
                                                                                 C_user_id_t userId, bool isFallbackOrRecover);

  /** Occurs when the first remote audio frame is received.
   *
   * @param userId ID of the remote user.
   * @param elapsed The time (ms) since the user connects to an Agora channel.
   **/
  typedef void (*C_LocalUserObserverBridge_onFirstRemoteAudioFrame)(C_LocalUserObserverBridge *this_, void *userData,
                                                                    C_user_id_t userId, int elapsed);

  /**
   * Occurs when the SDK decodes the first remote audio frame for playback.
   *
   * @param uid User ID of the remote user sending the audio stream.
   * @param elapsed The time (ms) since the user connects to an Agora channel.
   */
  typedef void (*C_LocalUserObserverBridge_onFirstRemoteAudioDecoded)(C_LocalUserObserverBridge *this_, void *userData,
                                                                      C_user_id_t userId, int elapsed);

  /**
   * Occurs when the first remote video frame is rendered.
   * The SDK triggers this callback when the first frame of the remote video is displayed in the user's video window. The application can get the time elapsed from a user joining the channel until the first video frame is displayed.
   *
   * @param userId ID of the remote user.
   * @param width Width (px) of the video frame.
   * @param height Height (px) of the video stream.
   * @param elapsed Time elapsed (ms) from the local user calling the \ref IRtcEngine::joinChannel "joinChannel" method until the SDK triggers this callback.
   */
  typedef void (*C_LocalUserObserverBridge_onFirstRemoteVideoFrame)(C_LocalUserObserverBridge *this_, void *userData,
                                                                    C_user_id_t userId, int width, int height, int elapsed);

  /**
   * Occurs when the SDK decodes the first remote video frame for playback.
   *
   * @param userId ID of the remote user.
   * @param width Width (px) of the video stream.
   * @param height Height (px) of the video stream.
   * @param elapsed The time (ms) since the user connects to an Agora channel.
   */
  typedef void (*C_LocalUserObserverBridge_onFirstRemoteVideoDecoded)(C_LocalUserObserverBridge *this_, void *userData,
                                                                      C_user_id_t userId, int width, int height, int elapsed);

  /**
   * The local or remote video size or rotation changed.
   *
   * @param uid User ID of the user whose video size or rotation has changed.
   * @param width Width (pixels) of the video stream.
   * @param height Height (pixels) of the video stream.
   * @param rotation Rotation [0 to 360).
   */
  typedef void (*C_LocalUserObserverBridge_onVideoSizeChanged)(C_LocalUserObserverBridge *this_, void *userData,
                                                               C_user_id_t userId, int width, int height, int rotation);

  /**
   * Occurs when the user media information is updated.
   *
   *
   * @param userId The ID of the user.
   * @param msg The media information of the user. See #USER_MEDIA_INFO.
   * @param val Whether the user is muted.
   */
  typedef void (*C_LocalUserObserverBridge_onUserInfoUpdated)(C_LocalUserObserverBridge *this_, void *userData,
                                                              C_user_id_t userId, enum C_USER_MEDIA_INFO msg, bool val);

  /**
   * Occurs when the intra request is received from a remote user.
   *
   * The method notifies the local user to encode a key frame.
   *
   */
  typedef void (*C_LocalUserObserverBridge_onIntraRequestReceived)(C_LocalUserObserverBridge *this_, void *userData);

  /**
   * datastream from this connection.
   */
  typedef void (*C_LocalUserObserverBridge_onStreamMessage)(C_LocalUserObserverBridge *this_, void *userData,
                                                            C_user_id_t user_id, int streamId, const char *data, size_t length);

  /**
   * Occurs when the remote user state is updated.
   * @param uid The uid of the remote user.
   * @param state The remote user state.Just & #REMOTE_USER_STATE
   */
  typedef void (*C_LocalUserObserverBridge_onUserStateChanged)(C_LocalUserObserverBridge *this_, void *userData,
                                                               C_user_id_t user_id, uint32_t state);

  typedef void (*C_LocalUserObserverBridge_onVideoRenderingTracingResult)(C_LocalUserObserverBridge *this_, void *userData,
                                                                          C_user_id_t user_id, enum C_MEDIA_TRACE_EVENT currentState, struct C_VideoRenderingTracingInfo tracingInfo);

  typedef struct C_LocalUserObserverBridge_Callbacks
  {
    C_LocalUserObserverBridge_onAudioTrackPublishStart onAudioTrackPublishStart;
    C_LocalUserObserverBridge_onAudioTrackPublishSuccess onAudioTrackPublishSuccess;
    C_LocalUserObserverBridge_onAudioTrackUnpublished onAudioTrackUnpublished;
    C_LocalUserObserverBridge_onAudioTrackPublicationFailure onAudioTrackPublicationFailure;
    C_LocalUserObserverBridge_onLocalAudioTrackStatistics onLocalAudioTrackStatistics;
    C_LocalUserObserverBridge_onRemoteAudioTrackStatistics onRemoteAudioTrackStatistics;
    C_LocalUserObserverBridge_onUserAudioTrackSubscribed onUserAudioTrackSubscribed;
    C_LocalUserObserverBridge_onUserAudioTrackStateChanged onUserAudioTrackStateChanged;
    C_LocalUserObserverBridge_onVideoTrackPublishStart onVideoTrackPublishStart;
    C_LocalUserObserverBridge_onVideoTrackPublishSuccess onVideoTrackPublishSuccess;
    C_LocalUserObserverBridge_onVideoTrackPublicationFailure onVideoTrackPublicationFailure;
    C_LocalUserObserverBridge_onVideoTrackUnpublished onVideoTrackUnpublished;
    C_LocalUserObserverBridge_onLocalVideoTrackStateChanged onLocalVideoTrackStateChanged;
    C_LocalUserObserverBridge_onLocalVideoTrackStatistics onLocalVideoTrackStatistics;
    C_LocalUserObserverBridge_onUserVideoTrackSubscribed onUserVideoTrackSubscribed;
    C_LocalUserObserverBridge_onUserVideoTrackStateChanged onUserVideoTrackStateChanged;
    C_LocalUserObserverBridge_onFirstRemoteVideoFrameRendered onFirstRemoteVideoFrameRendered;
    C_LocalUserObserverBridge_onRemoteVideoTrackStatistics onRemoteVideoTrackStatistics;
    C_LocalUserObserverBridge_onAudioVolumeIndication onAudioVolumeIndication;
    C_LocalUserObserverBridge_onActiveSpeaker onActiveSpeaker;
    C_LocalUserObserverBridge_onAudioSubscribeStateChanged onAudioSubscribeStateChanged;
    C_LocalUserObserverBridge_onVideoSubscribeStateChanged onVideoSubscribeStateChanged;
    C_LocalUserObserverBridge_onAudioPublishStateChanged onAudioPublishStateChanged;
    C_LocalUserObserverBridge_onVideoPublishStateChanged onVideoPublishStateChanged;
    C_LocalUserObserverBridge_onRemoteSubscribeFallbackToAudioOnly onRemoteSubscribeFallbackToAudioOnly;
    C_LocalUserObserverBridge_onFirstRemoteAudioFrame onFirstRemoteAudioFrame;
    C_LocalUserObserverBridge_onFirstRemoteAudioDecoded onFirstRemoteAudioDecoded;
    C_LocalUserObserverBridge_onFirstRemoteVideoFrame onFirstRemoteVideoFrame;
    C_LocalUserObserverBridge_onFirstRemoteVideoDecoded onFirstRemoteVideoDecoded;
    C_LocalUserObserverBridge_onVideoSizeChanged onVideoSizeChanged;
    C_LocalUserObserverBridge_onUserInfoUpdated onUserInfoUpdated;
    C_LocalUserObserverBridge_onIntraRequestReceived onIntraRequestReceived;
    C_LocalUserObserverBridge_onStreamMessage onStreamMessage;
    C_LocalUserObserverBridge_onUserStateChanged onUserStateChanged;
    C_LocalUserObserverBridge_onVideoRenderingTracingResult onVideoRenderingTracingResult;
  } C_LocalUserObserverBridge_Callbacks;

  C_LocalUserObserverBridge *C_LocalUserObserverBridge_New(C_LocalUserObserverBridge_Callbacks cbs, void *userData);
  void C_LocalUserObserverBridge_Delete(C_LocalUserObserverBridge *this_);

#pragma endregion C_LocalUserObserverBridge

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_LOCAL_USER_OBSERVER_BRIDGE_H
