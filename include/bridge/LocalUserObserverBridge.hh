#pragma once

#include "AgoraBase.h"
#include "NGIAgoraLocalUser.h"
#include "NGIAgoraAudioTrack.h"
#include "NGIAgoraVideoTrack.h"
using namespace agora;
using namespace agora::rtc;

#include "C_LocalUserObserverBridge.h"

class LocalUserObserverBridge : public ILocalUserObserver
{
public:
  LocalUserObserverBridge(C_LocalUserObserverBridge_Callbacks cbs, void *userData)
      : cbs_(cbs),
        userData_(userData) {}

  ~LocalUserObserverBridge(){};

  void onAudioTrackPublishStart(agora_refptr<ILocalAudioTrack> audioTrack) override;
  /**
   * Occurs when the first packet of the local audio track is sent, indicating that the local audio track
   * is successfully published.
   *
   * @param audioTrack The pointer to \ref agora::rtc::ILocalAudioTrack "ILocalAudioTrack".
   */
  void onAudioTrackPublishSuccess(agora_refptr<ILocalAudioTrack> audioTrack) override;

  void onAudioTrackUnpublished(agora_refptr<ILocalAudioTrack> audioTrack) override;

  /**
   * Occurs when a local audio track fails to be published.
   *
   * @param audioTrack The pointer to `ILocalAudioTrack`.
   * @param error The error information: #ERROR_CODE_TYPE.
   */
  void onAudioTrackPublicationFailure(agora_refptr<ILocalAudioTrack> audioTrack,
                                      ERROR_CODE_TYPE error) override;

  /**
   * Reports the statistics of a local audio track.
   *
   * @param stats The reference to the statistics of the local audio track.
   */
  void onLocalAudioTrackStatistics(const LocalAudioStats &stats) override;
  /**
   * Reports the statistics of a remote audio track.
   *
   * @param audioTrack The pointer to `IRemoteAudioTrack`.
   * @param stats The statistics of the remote audio track.
   */
  void onRemoteAudioTrackStatistics(agora_refptr<rtc::IRemoteAudioTrack> audioTrack, const RemoteAudioTrackStats &stats) override;
  /**
   * Occurs when the first remote audio frame is received.
   *
   * This callback indicates that the local user has subscribed to a specified remote audio track, and the first
   * frame of this audio track has been received.
   *
   * @param userId The ID of the remote user whose audio frame is received.
   * @param audioTrack The pointer to `IRemoteAudioTrack`.
   */
  void onUserAudioTrackSubscribed(user_id_t userId,
                                  agora_refptr<rtc::IRemoteAudioTrack> audioTrack) override;

  /**
   * Occurs when the state of a remote audio track changes.
   *
   * @param userId The ID of the remote user whose audio track state has changed.
   * @param audioTrack The pointer to `IRemoteAudioTrack`.
   * @param state The current state of the audio track.
   * @param reason The reason for the state change.
   * @param elapsed The time (ms) since the user connects to an Agora channel.
   */
  void onUserAudioTrackStateChanged(user_id_t userId,
                                    agora_refptr<rtc::IRemoteAudioTrack> audioTrack,
                                    REMOTE_AUDIO_STATE state,
                                    REMOTE_AUDIO_STATE_REASON reason,
                                    int elapsed) override;

  void onVideoTrackPublishStart(agora_refptr<ILocalVideoTrack> videoTrack) override;
  /**
   * Occurs when the first packet of a local video track is sent, indicating that the local video track
   * is successfully published.
   * @param videoTrack The pointer to `ILocalVideoTrack`.
   */
  void onVideoTrackPublishSuccess(agora_refptr<ILocalVideoTrack> videoTrack) override;

  /**
   * Occurs when a local video track fails to be published.
   *
   * @param videoTrack The pointer to `ILocalVideoTrack`.
   * @param error The error information: #ERROR_CODE_TYPE.
   */
  void onVideoTrackPublicationFailure(agora_refptr<ILocalVideoTrack> videoTrack,
                                      ERROR_CODE_TYPE error) override;

  void onVideoTrackUnpublished(agora_refptr<ILocalVideoTrack> videoTrack) override;
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
  void onLocalVideoTrackStateChanged(agora_refptr<rtc::ILocalVideoTrack> videoTrack,
                                     LOCAL_VIDEO_STREAM_STATE state,
                                     LOCAL_VIDEO_STREAM_ERROR errorCode) override;

  /**
   * Reports the statistics of a local video track.
   *
   * @param videoTrack The pointer to `ILocalVideoTrack`.
   * @param stats The statistics of the local video track.
   */
  void onLocalVideoTrackStatistics(agora_refptr<rtc::ILocalVideoTrack> videoTrack,
                                   const LocalVideoTrackStats &stats) override;

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
  void onUserVideoTrackSubscribed(user_id_t userId, VideoTrackInfo trackInfo,
                                  agora_refptr<rtc::IRemoteVideoTrack> videoTrack) override;

  /**
   * Occurs when the state of a remote video track changes.
   *
   * @param userId the ID of the remote user whose video track state has changed.
   * @param videoTrack The pointer to `IRemoteVideoTrack`.
   * @param state The current state of the video track.
   * @param reason The reason for the state change.
   * @param elapsed The time (ms) since the user connects to an Agora channel.
   */
  void onUserVideoTrackStateChanged(user_id_t userId,
                                    agora_refptr<rtc::IRemoteVideoTrack> videoTrack,
                                    REMOTE_VIDEO_STATE state,
                                    REMOTE_VIDEO_STATE_REASON reason,
                                    int elapsed) override;

  /**
   * Occurs when the first remote video frame is rendered.
   *
   * @param userId the ID of the remote user.
   * @param width Width (px) of the video frame.
   * @param height Height (px) of the video stream.
   * @param elapsed The time (ms) since the user connects to an Agora channel.
   */
  void onFirstRemoteVideoFrameRendered(user_id_t userId, int width,
                                       int height, int elapsed) override;

  /**
   * Reports the statistics of a remote video track.
   *
   * @param videoTrack The pointer to `IRemoteVideoTrack`.
   * @param stats The statistics of the remote video track.
   */
  void onRemoteVideoTrackStatistics(agora_refptr<rtc::IRemoteVideoTrack> videoTrack,
                                    const RemoteVideoTrackStats &stats) override;

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
  void onAudioVolumeIndication(const AudioVolumeInformation *speakers, unsigned int speakerNumber,
                               int totalVolume) override;

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
  void onActiveSpeaker(user_id_t userId) override;

  /**
   * Occurs when the audio subscribe state changed.
   *
   * @param channel The channel name of user joined.
   * @param userId The remote string user ID that is subscribed to.
   * @param oldState The old state of the audio stream subscribe : #STREAM_SUBSCRIBE_STATE.
   * @param newState The new state of the audio stream subscribe : #STREAM_SUBSCRIBE_STATE.
   * @param elapseSinceLastState The time elapsed (ms) from the old state to the new state.
   */
  void onAudioSubscribeStateChanged(const char *channel, user_id_t userId, STREAM_SUBSCRIBE_STATE oldState, STREAM_SUBSCRIBE_STATE newState, int elapseSinceLastState) override;

  /**
   * Occurs when the video subscribe state changed.
   *
   * @param channel The channel name of user joined.
   * @param userId The remote string user ID that is subscribed to.
   * @param oldState The old state of the video stream subscribe : #STREAM_SUBSCRIBE_STATE.
   * @param newState The new state of the video stream subscribe : #STREAM_SUBSCRIBE_STATE.
   * @param elapseSinceLastState The time elapsed (ms) from the old state to the new state.
   */
  void onVideoSubscribeStateChanged(const char *channel, user_id_t userId, STREAM_SUBSCRIBE_STATE oldState, STREAM_SUBSCRIBE_STATE newState, int elapseSinceLastState) override;

  /**
   * Occurs when the audio publish state changed.
   *
   * @param channel The channel name of user joined.
   * @param oldState The old state of the audio stream publish : #STREAM_PUBLISH_STATE.
   * @param newState The new state of the audio stream publish : #STREAM_PUBLISH_STATE.
   * @param elapseSinceLastState The time elapsed (ms) from the old state to the new state.
   */
  void onAudioPublishStateChanged(const char *channel, STREAM_PUBLISH_STATE oldState, STREAM_PUBLISH_STATE newState, int elapseSinceLastState) override;

  /**
   * Occurs when the video publish state changed.
   *
   * @param channel The channel name of user joined.
   * @param oldState The old state of the video stream publish : #STREAM_PUBLISH_STATE.
   * @param newState The new state of the video stream publish : #STREAM_PUBLISH_STATE.
   * @param elapseSinceLastState The time elapsed (ms) from the old state to the new state.
   */
  void onVideoPublishStateChanged(const char *channel, STREAM_PUBLISH_STATE oldState, STREAM_PUBLISH_STATE newState, int elapseSinceLastState) override;

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
  void onRemoteSubscribeFallbackToAudioOnly(user_id_t userId, bool isFallbackOrRecover) override;

  /** Occurs when the first remote audio frame is received.
   *
   * @param userId ID of the remote user.
   * @param elapsed The time (ms) since the user connects to an Agora channel.
   **/
  void onFirstRemoteAudioFrame(user_id_t userId, int elapsed) override;

  /**
   * Occurs when the SDK decodes the first remote audio frame for playback.
   *
   * @param uid User ID of the remote user sending the audio stream.
   * @param elapsed The time (ms) since the user connects to an Agora channel.
   */
  void onFirstRemoteAudioDecoded(user_id_t userId, int elapsed) override;

  /**
   * Occurs when the first remote video frame is rendered.
   * The SDK triggers this callback when the first frame of the remote video is displayed in the user's video window. The application can get the time elapsed from a user joining the channel until the first video frame is displayed.
   *
   * @param userId ID of the remote user.
   * @param width Width (px) of the video frame.
   * @param height Height (px) of the video stream.
   * @param elapsed Time elapsed (ms) from the local user calling the \ref IRtcEngine::joinChannel "joinChannel" method until the SDK triggers this callback.
   */
  void onFirstRemoteVideoFrame(user_id_t userId, int width, int height, int elapsed) override;

  /**
   * Occurs when the SDK decodes the first remote video frame for playback.
   *
   * @param userId ID of the remote user.
   * @param width Width (px) of the video stream.
   * @param height Height (px) of the video stream.
   * @param elapsed The time (ms) since the user connects to an Agora channel.
   */
  void onFirstRemoteVideoDecoded(user_id_t userId, int width, int height, int elapsed) override;

  /**
   * The local or remote video size or rotation changed.
   *
   * @param uid User ID of the user whose video size or rotation has changed.
   * @param width Width (pixels) of the video stream.
   * @param height Height (pixels) of the video stream.
   * @param rotation Rotation [0 to 360).
   */
  void onVideoSizeChanged(user_id_t userId, int width, int height, int rotation) override;

  /**
   * Occurs when the user media information is updated.
   *
   *
   * @param userId The ID of the user.
   * @param msg The media information of the user. See #USER_MEDIA_INFO.
   * @param val Whether the user is muted.
   */
  void onUserInfoUpdated(user_id_t userId, USER_MEDIA_INFO msg, bool val) override;

  /**
   * Occurs when the intra request is received from a remote user.
   *
   * The method notifies the local user to encode a key frame.
   *
   */
  void onIntraRequestReceived() override;

  /**
   * datastream from this connection.
   */
  void onStreamMessage(user_id_t userId, int streamId, const char *data, size_t length) override;

  /**
   * Occurs when the remote user state is updated.
   * @param uid The uid of the remote user.
   * @param state The remote user state.Just & #REMOTE_USER_STATE
   */
  void onUserStateChanged(user_id_t userId, uint32_t state) override;

  void onVideoRenderingTracingResult(user_id_t user_id, MEDIA_TRACE_EVENT currentState, VideoRenderingTracingInfo tracingInfo) override;

private:
  C_LocalUserObserverBridge_Callbacks cbs_;
  void *userData_;
};
