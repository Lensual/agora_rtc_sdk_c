#include "bridge/LocalUserObserverBridge.hh"

void LocalUserObserverBridge::onAudioTrackPublishStart(agora_refptr<ILocalAudioTrack> audioTrack)
{
  if (cbs_.onAudioTrackPublishStart != nullptr)
  {
    audioTrack->AddRef();
    cbs_.onAudioTrackPublishStart(this, this->userData_, (C_ILocalAudioTrack *)audioTrack.get());
  }
}
/**
 * Occurs when the first packet of the local audio track is sent, indicating that the local audio track
 * is successfully published.
 *
 * @param audioTrack The pointer to \ref agora::rtc::ILocalAudioTrack "ILocalAudioTrack".
 */
void LocalUserObserverBridge::onAudioTrackPublishSuccess(agora_refptr<ILocalAudioTrack> audioTrack)
{
  if (cbs_.onAudioTrackPublishSuccess != nullptr)
  {
    audioTrack->AddRef();
    cbs_.onAudioTrackPublishSuccess(this, this->userData_, (C_ILocalAudioTrack *)audioTrack.get());
  }
}

void LocalUserObserverBridge::onAudioTrackUnpublished(agora_refptr<ILocalAudioTrack> audioTrack)
{
  if (cbs_.onAudioTrackUnpublished != nullptr)
  {
    audioTrack->AddRef();
    cbs_.onAudioTrackUnpublished(this, this->userData_, (C_ILocalAudioTrack *)audioTrack.get());
  }
}

/**
 * Occurs when a local audio track fails to be published.
 *
 * @param audioTrack The pointer to `ILocalAudioTrack`.
 * @param error The error information: #ERROR_CODE_TYPE.
 */
void LocalUserObserverBridge::onAudioTrackPublicationFailure(agora_refptr<ILocalAudioTrack> audioTrack,
                                                             ERROR_CODE_TYPE error)
{
  if (cbs_.onAudioTrackPublicationFailure != nullptr)
  {
    audioTrack->AddRef();
    cbs_.onAudioTrackPublicationFailure(this, this->userData_, (C_ILocalAudioTrack *)audioTrack.get(), C_ERROR_CODE_TYPE(error));
  }
}

/**
 * Reports the statistics of a local audio track.
 *
 * @param stats The reference to the statistics of the local audio track.
 */
void LocalUserObserverBridge::onLocalAudioTrackStatistics(const LocalAudioStats &stats)
{
  if (cbs_.onLocalAudioTrackStatistics != nullptr)
  {
    cbs_.onLocalAudioTrackStatistics(this, this->userData_, (const C_LocalAudioStats *)&stats);
  }
}
/**
 * Reports the statistics of a remote audio track.
 *
 * @param audioTrack The pointer to `IRemoteAudioTrack`.
 * @param stats The statistics of the remote audio track.
 */
void LocalUserObserverBridge::onRemoteAudioTrackStatistics(agora_refptr<rtc::IRemoteAudioTrack> audioTrack, const RemoteAudioTrackStats &stats)
{
  if (cbs_.onRemoteAudioTrackStatistics != nullptr)
  {
    audioTrack->AddRef();
    cbs_.onRemoteAudioTrackStatistics(this, this->userData_, (C_ILocalAudioTrack *)audioTrack.get(), (const C_RemoteAudioTrackStats *)&stats);
  }
}
/**
 * Occurs when the first remote audio frame is received.
 *
 * This callback indicates that the local user has subscribed to a specified remote audio track, and the first
 * frame of this audio track has been received.
 *
 * @param userId The ID of the remote user whose audio frame is received.
 * @param audioTrack The pointer to `IRemoteAudioTrack`.
 */
void LocalUserObserverBridge::onUserAudioTrackSubscribed(user_id_t userId,
                                                         agora_refptr<rtc::IRemoteAudioTrack> audioTrack)
{
  if (cbs_.onUserAudioTrackSubscribed != nullptr)
  {
    audioTrack->AddRef();
    cbs_.onUserAudioTrackSubscribed(this, this->userData_, C_user_id_t(userId), (C_IRemoteAudioTrack *)audioTrack.get());
  }
}

/**
 * Occurs when the state of a remote audio track changes.
 *
 * @param userId The ID of the remote user whose audio track state has changed.
 * @param audioTrack The pointer to `IRemoteAudioTrack`.
 * @param state The current state of the audio track.
 * @param reason The reason for the state change.
 * @param elapsed The time (ms) since the user connects to an Agora channel.
 */
void LocalUserObserverBridge::onUserAudioTrackStateChanged(user_id_t userId,
                                                           agora_refptr<rtc::IRemoteAudioTrack> audioTrack,
                                                           REMOTE_AUDIO_STATE state,
                                                           REMOTE_AUDIO_STATE_REASON reason,
                                                           int elapsed)
{
  if (cbs_.onUserAudioTrackStateChanged != nullptr)
  {
    audioTrack->AddRef();
    cbs_.onUserAudioTrackStateChanged(this, this->userData_,
                                      C_user_id_t(userId),
                                      (C_IRemoteAudioTrack *)audioTrack.get(),
                                      C_REMOTE_AUDIO_STATE(state),
                                      C_REMOTE_AUDIO_STATE_REASON(reason),
                                      elapsed);
  }
}

void LocalUserObserverBridge::onVideoTrackPublishStart(agora_refptr<ILocalVideoTrack> videoTrack)
{
  if (cbs_.onVideoTrackPublishStart != nullptr)
  {
    videoTrack->AddRef();
    cbs_.onVideoTrackPublishStart(this, this->userData_,
                                  (C_ILocalVideoTrack *)videoTrack.get());
  }
}
/**
 * Occurs when the first packet of a local video track is sent, indicating that the local video track
 * is successfully published.
 * @param videoTrack The pointer to `ILocalVideoTrack`.
 */
void LocalUserObserverBridge::onVideoTrackPublishSuccess(agora_refptr<ILocalVideoTrack> videoTrack)
{
  if (cbs_.onVideoTrackPublishSuccess != nullptr)
  {
    videoTrack->AddRef();
    cbs_.onVideoTrackPublishSuccess(this, this->userData_,
                                    (C_ILocalVideoTrack *)videoTrack.get());
  }
}

/**
 * Occurs when a local video track fails to be published.
 *
 * @param videoTrack The pointer to `ILocalVideoTrack`.
 * @param error The error information: #ERROR_CODE_TYPE.
 */
void LocalUserObserverBridge::onVideoTrackPublicationFailure(agora_refptr<ILocalVideoTrack> videoTrack,
                                                             ERROR_CODE_TYPE error)
{
  if (cbs_.onVideoTrackPublicationFailure != nullptr)
  {
    videoTrack->AddRef();
    cbs_.onVideoTrackPublicationFailure(this, this->userData_,
                                        (C_ILocalVideoTrack *)videoTrack.get(),
                                        C_ERROR_CODE_TYPE(error));
  }
}

void LocalUserObserverBridge::onVideoTrackUnpublished(agora_refptr<ILocalVideoTrack> videoTrack)
{
  if (cbs_.onVideoTrackUnpublished != nullptr)
  {
    videoTrack->AddRef();
    cbs_.onVideoTrackUnpublished(this, this->userData_,
                                 (C_ILocalVideoTrack *)videoTrack.get());
  }
}
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
void LocalUserObserverBridge::onLocalVideoTrackStateChanged(agora_refptr<rtc::ILocalVideoTrack> videoTrack,
                                                            LOCAL_VIDEO_STREAM_STATE state,
                                                            LOCAL_VIDEO_STREAM_ERROR errorCode)
{
  if (cbs_.onLocalVideoTrackStateChanged != nullptr)
  {
    videoTrack->AddRef();
    cbs_.onLocalVideoTrackStateChanged(this, this->userData_,
                                       (C_ILocalVideoTrack *)videoTrack.get(),
                                       C_LOCAL_VIDEO_STREAM_STATE(state),
                                       C_LOCAL_VIDEO_STREAM_ERROR(errorCode));
  }
}

/**
 * Reports the statistics of a local video track.
 *
 * @param videoTrack The pointer to `ILocalVideoTrack`.
 * @param stats The statistics of the local video track.
 */
void LocalUserObserverBridge::onLocalVideoTrackStatistics(agora_refptr<rtc::ILocalVideoTrack> videoTrack,
                                                          const LocalVideoTrackStats &stats)
{
  if (cbs_.onLocalVideoTrackStatistics != nullptr)
  {
    videoTrack->AddRef();
    cbs_.onLocalVideoTrackStatistics(this, this->userData_,
                                     (C_ILocalVideoTrack *)videoTrack.get(),
                                     (const C_LocalVideoTrackStats *)&stats);
  }
}

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
void LocalUserObserverBridge::onUserVideoTrackSubscribed(user_id_t userId, VideoTrackInfo trackInfo,
                                                         agora_refptr<rtc::IRemoteVideoTrack> videoTrack)
{
  if (cbs_.onUserVideoTrackSubscribed != nullptr)
  {
    videoTrack->AddRef();
    cbs_.onUserVideoTrackSubscribed(this, this->userData_,
                                    C_user_id_t(userId),
                                    *(C_VideoTrackInfo *)&trackInfo,
                                    (C_IRemoteVideoTrack *)videoTrack.get());
  }
}

/**
 * Occurs when the state of a remote video track changes.
 *
 * @param userId the ID of the remote user whose video track state has changed.
 * @param videoTrack The pointer to `IRemoteVideoTrack`.
 * @param state The current state of the video track.
 * @param reason The reason for the state change.
 * @param elapsed The time (ms) since the user connects to an Agora channel.
 */
void LocalUserObserverBridge::onUserVideoTrackStateChanged(user_id_t userId,
                                                           agora_refptr<rtc::IRemoteVideoTrack> videoTrack,
                                                           REMOTE_VIDEO_STATE state,
                                                           REMOTE_VIDEO_STATE_REASON reason,
                                                           int elapsed)
{
  if (cbs_.onUserVideoTrackStateChanged != nullptr)
  {
    videoTrack->AddRef();
    cbs_.onUserVideoTrackStateChanged(this, this->userData_,
                                      C_user_id_t(userId),
                                      (C_IRemoteVideoTrack *)videoTrack.get(),
                                      C_REMOTE_VIDEO_STATE(state),
                                      C_REMOTE_VIDEO_STATE_REASON(reason),
                                      elapsed);
  }
}

/**
 * Occurs when the first remote video frame is rendered.
 *
 * @param userId the ID of the remote user.
 * @param width Width (px) of the video frame.
 * @param height Height (px) of the video stream.
 * @param elapsed The time (ms) since the user connects to an Agora channel.
 */
void LocalUserObserverBridge::onFirstRemoteVideoFrameRendered(user_id_t userId, int width,
                                                              int height, int elapsed)
{
  if (cbs_.onFirstRemoteVideoFrameRendered != nullptr)
  {
    cbs_.onFirstRemoteVideoFrameRendered(this, this->userData_,
                                         C_user_id_t(userId),
                                         width,
                                         height, elapsed);
  }
}

/**
 * Reports the statistics of a remote video track.
 *
 * @param videoTrack The pointer to `IRemoteVideoTrack`.
 * @param stats The statistics of the remote video track.
 */
void LocalUserObserverBridge::onRemoteVideoTrackStatistics(agora_refptr<rtc::IRemoteVideoTrack> videoTrack,
                                                           const RemoteVideoTrackStats &stats)
{
  if (cbs_.onRemoteVideoTrackStatistics != nullptr)
  {
    videoTrack->AddRef();
    cbs_.onRemoteVideoTrackStatistics(this, this->userData_,
                                      (C_IRemoteVideoTrack *)videoTrack.get(),
                                      (const C_RemoteVideoTrackStats *)&stats);
  }
}

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
void LocalUserObserverBridge::onAudioVolumeIndication(const AudioVolumeInformation *speakers, unsigned int speakerNumber,
                                                      int totalVolume)
{
  if (cbs_.onAudioVolumeIndication != nullptr)
  {
    cbs_.onAudioVolumeIndication(this, this->userData_,
                                 (const C_AudioVolumeInformation *)speakers,
                                 speakerNumber,
                                 totalVolume);
  }
}

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
void LocalUserObserverBridge::onActiveSpeaker(user_id_t userId)
{
  if (cbs_.onActiveSpeaker != nullptr)
  {
    cbs_.onActiveSpeaker(this, this->userData_,
                         C_user_id_t(userId));
  }
}

/**
 * Occurs when the audio subscribe state changed.
 *
 * @param channel The channel name of user joined.
 * @param userId The remote string user ID that is subscribed to.
 * @param oldState The old state of the audio stream subscribe : #STREAM_SUBSCRIBE_STATE.
 * @param newState The new state of the audio stream subscribe : #STREAM_SUBSCRIBE_STATE.
 * @param elapseSinceLastState The time elapsed (ms) from the old state to the new state.
 */
void LocalUserObserverBridge::onAudioSubscribeStateChanged(const char *channel, user_id_t userId, STREAM_SUBSCRIBE_STATE oldState, STREAM_SUBSCRIBE_STATE newState, int elapseSinceLastState)
{
  if (cbs_.onAudioSubscribeStateChanged != nullptr)
  {
    cbs_.onAudioSubscribeStateChanged(this, this->userData_,
                                      channel,
                                      C_user_id_t(userId),
                                      C_STREAM_SUBSCRIBE_STATE(oldState),
                                      C_STREAM_SUBSCRIBE_STATE(newState),
                                      elapseSinceLastState);
  }
}

/**
 * Occurs when the video subscribe state changed.
 *
 * @param channel The channel name of user joined.
 * @param userId The remote string user ID that is subscribed to.
 * @param oldState The old state of the video stream subscribe : #STREAM_SUBSCRIBE_STATE.
 * @param newState The new state of the video stream subscribe : #STREAM_SUBSCRIBE_STATE.
 * @param elapseSinceLastState The time elapsed (ms) from the old state to the new state.
 */
void LocalUserObserverBridge::onVideoSubscribeStateChanged(const char *channel, user_id_t userId, STREAM_SUBSCRIBE_STATE oldState, STREAM_SUBSCRIBE_STATE newState, int elapseSinceLastState)
{
  if (cbs_.onVideoSubscribeStateChanged != nullptr)
  {
    cbs_.onVideoSubscribeStateChanged(this, this->userData_,
                                      channel,
                                      C_user_id_t(userId),
                                      C_STREAM_SUBSCRIBE_STATE(oldState),
                                      C_STREAM_SUBSCRIBE_STATE(newState),
                                      elapseSinceLastState);
  }
}

/**
 * Occurs when the audio publish state changed.
 *
 * @param channel The channel name of user joined.
 * @param oldState The old state of the audio stream publish : #STREAM_PUBLISH_STATE.
 * @param newState The new state of the audio stream publish : #STREAM_PUBLISH_STATE.
 * @param elapseSinceLastState The time elapsed (ms) from the old state to the new state.
 */
void LocalUserObserverBridge::onAudioPublishStateChanged(const char *channel, STREAM_PUBLISH_STATE oldState, STREAM_PUBLISH_STATE newState, int elapseSinceLastState)
{
  if (cbs_.onAudioPublishStateChanged != nullptr)
  {
    cbs_.onAudioPublishStateChanged(this, this->userData_,
                                    channel,
                                    C_STREAM_PUBLISH_STATE(oldState),
                                    C_STREAM_PUBLISH_STATE(newState),
                                    elapseSinceLastState);
  }
}

/**
 * Occurs when the video publish state changed.
 *
 * @param channel The channel name of user joined.
 * @param oldState The old state of the video stream publish : #STREAM_PUBLISH_STATE.
 * @param newState The new state of the video stream publish : #STREAM_PUBLISH_STATE.
 * @param elapseSinceLastState The time elapsed (ms) from the old state to the new state.
 */
void LocalUserObserverBridge::onVideoPublishStateChanged(const char *channel, STREAM_PUBLISH_STATE oldState, STREAM_PUBLISH_STATE newState, int elapseSinceLastState)
{
  if (cbs_.onVideoPublishStateChanged != nullptr)
  {
    cbs_.onVideoPublishStateChanged(this, this->userData_,
                                    channel,
                                    C_STREAM_PUBLISH_STATE(oldState),
                                    C_STREAM_PUBLISH_STATE(newState),
                                    elapseSinceLastState);
  }
}

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
void LocalUserObserverBridge::onRemoteSubscribeFallbackToAudioOnly(user_id_t userId, bool isFallbackOrRecover)
{
  if (cbs_.onRemoteSubscribeFallbackToAudioOnly != nullptr)
  {
    cbs_.onRemoteSubscribeFallbackToAudioOnly(this, this->userData_,
                                              C_user_id_t(userId),
                                              isFallbackOrRecover);
  }
}

/** Occurs when the first remote audio frame is received.
 *
 * @param userId ID of the remote user.
 * @param elapsed The time (ms) since the user connects to an Agora channel.
 **/
void LocalUserObserverBridge::onFirstRemoteAudioFrame(user_id_t userId, int elapsed)
{
  if (cbs_.onFirstRemoteAudioFrame != nullptr)
  {
    cbs_.onFirstRemoteAudioFrame(this, this->userData_,
                                 C_user_id_t(userId),
                                 elapsed);
  }
}

/**
 * Occurs when the SDK decodes the first remote audio frame for playback.
 *
 * @param uid User ID of the remote user sending the audio stream.
 * @param elapsed The time (ms) since the user connects to an Agora channel.
 */
void LocalUserObserverBridge::onFirstRemoteAudioDecoded(user_id_t userId, int elapsed)
{
  if (cbs_.onFirstRemoteAudioDecoded != nullptr)
  {
    cbs_.onFirstRemoteAudioDecoded(this, this->userData_,
                                   C_user_id_t(userId),
                                   elapsed);
  }
}

/**
 * Occurs when the first remote video frame is rendered.
 * The SDK triggers this callback when the first frame of the remote video is displayed in the user's video window. The application can get the time elapsed from a user joining the channel until the first video frame is displayed.
 *
 * @param userId ID of the remote user.
 * @param width Width (px) of the video frame.
 * @param height Height (px) of the video stream.
 * @param elapsed Time elapsed (ms) from the local user calling the \ref IRtcEngine::joinChannel "joinChannel" method until the SDK triggers this callback.
 */
void LocalUserObserverBridge::onFirstRemoteVideoFrame(user_id_t userId, int width, int height, int elapsed)
{
  if (cbs_.onFirstRemoteVideoFrame != nullptr)
  {
    cbs_.onFirstRemoteVideoFrame(this, this->userData_,
                                 C_user_id_t(userId),
                                 width,
                                 height,
                                 elapsed);
  }
}

/**
 * Occurs when the SDK decodes the first remote video frame for playback.
 *
 * @param userId ID of the remote user.
 * @param width Width (px) of the video stream.
 * @param height Height (px) of the video stream.
 * @param elapsed The time (ms) since the user connects to an Agora channel.
 */
void LocalUserObserverBridge::onFirstRemoteVideoDecoded(user_id_t userId, int width, int height, int elapsed)
{
  if (cbs_.onFirstRemoteVideoDecoded != nullptr)
  {
    cbs_.onFirstRemoteVideoDecoded(this, this->userData_,
                                   C_user_id_t(userId),
                                   width,
                                   height,
                                   elapsed);
  }
}

/**
 * The local or remote video size or rotation changed.
 *
 * @param uid User ID of the user whose video size or rotation has changed.
 * @param width Width (pixels) of the video stream.
 * @param height Height (pixels) of the video stream.
 * @param rotation Rotation [0 to 360).
 */
void LocalUserObserverBridge::onVideoSizeChanged(user_id_t userId, int width, int height, int rotation)
{
  if (cbs_.onVideoSizeChanged != nullptr)
  {
    cbs_.onVideoSizeChanged(this, this->userData_,
                            C_user_id_t(userId),
                            width,
                            height,
                            rotation);
  }
}

/**
 * Occurs when the user media information is updated.
 *
 *
 * @param userId The ID of the user.
 * @param msg The media information of the user. See #USER_MEDIA_INFO.
 * @param val Whether the user is muted.
 */
void LocalUserObserverBridge::onUserInfoUpdated(user_id_t userId, USER_MEDIA_INFO msg, bool val)
{
  if (cbs_.onUserInfoUpdated != nullptr)
  {
    cbs_.onUserInfoUpdated(this, this->userData_,
                           C_user_id_t(userId),
                           C_USER_MEDIA_INFO(msg),
                           val);
  }
}

/**
 * Occurs when the intra request is received from a remote user.
 *
 * The method notifies the local user to encode a key frame.
 *
 */
void LocalUserObserverBridge::onIntraRequestReceived()
{
  if (cbs_.onIntraRequestReceived != nullptr)
  {
    cbs_.onIntraRequestReceived(this, this->userData_);
  }
}

/**
 * datastream from this connection.
 */
void LocalUserObserverBridge::onStreamMessage(user_id_t userId, int streamId, const char *data, size_t length)
{
  if (cbs_.onStreamMessage != nullptr)
  {
    cbs_.onStreamMessage(this, this->userData_,
                         C_user_id_t(userId),
                         streamId,
                         data,
                         length);
  }
}

/**
 * Occurs when the remote user state is updated.
 * @param uid The uid of the remote user.
 * @param state The remote user state.Just & #REMOTE_USER_STATE
 */
void LocalUserObserverBridge::onUserStateChanged(user_id_t userId, uint32_t state)
{
  if (cbs_.onUserStateChanged != nullptr)
  {
    cbs_.onUserStateChanged(this, this->userData_,
                            C_user_id_t(userId),
                            state);
  }
}

void LocalUserObserverBridge::onVideoRenderingTracingResult(user_id_t user_id, MEDIA_TRACE_EVENT currentState, VideoRenderingTracingInfo tracingInfo)
{
  if (cbs_.onVideoRenderingTracingResult != nullptr)
  {
    cbs_.onVideoRenderingTracingResult(this, this->userData_,
                                       C_user_id_t(user_id),
                                       C_MEDIA_TRACE_EVENT(currentState),
                                       *(C_VideoRenderingTracingInfo *)&tracingInfo);
  }
}