#ifndef C_AUDIO_FRAME_OBSERVER_BRIDGE_H
#define C_AUDIO_FRAME_OBSERVER_BRIDGE_H

#include "C_AgoraMediaBase.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

  typedef void C_AudioFrameObserverBridge;
#pragma region C_AudioFrameObserverBridge
  // Callbacks

  /**
   * Occurs when the recorded audio frame is received.
   * @param channelId The channel name
   * @param audioFrame The reference to the audio frame: AudioFrame.
   * @return
   * - true: The recorded audio frame is valid and is encoded and sent.
   * - false: The recorded audio frame is invalid and is not encoded or sent.
   */
  typedef bool (*C_AudioFrameObserverBridge_onRecordAudioFrame)(C_AudioFrameObserverBridge *this_, void *userData,
                                                                const char *channelId, struct C_AudioFrame *audioFrame);
  /**
   * Occurs when the playback audio frame is received.
   * @param channelId The channel name
   * @param audioFrame The reference to the audio frame: AudioFrame.
   * @return
   * - true: The playback audio frame is valid and is encoded and sent.
   * - false: The playback audio frame is invalid and is not encoded or sent.
   */
  typedef bool (*C_AudioFrameObserverBridge_onPlaybackAudioFrame)(C_AudioFrameObserverBridge *this_, void *userData,
                                                                  const char *channelId, struct C_AudioFrame *audioFrame);
  /**
   * Occurs when the mixed audio data is received.
   * @param channelId The channel name
   * @param audioFrame The reference to the audio frame: AudioFrame.
   * @return
   * - true: The mixed audio data is valid and is encoded and sent.
   * - false: The mixed audio data is invalid and is not encoded or sent.
   */
  typedef bool (*C_AudioFrameObserverBridge_onMixedAudioFrame)(C_AudioFrameObserverBridge *this_, void *userData,
                                                               const char *channelId, struct C_AudioFrame *audioFrame);
  /**
   * Occurs when the ear monitoring audio frame is received.
   * @param audioFrame The reference to the audio frame: AudioFrame.
   * @return
   * - true: The ear monitoring audio data is valid and is encoded and sent.
   * - false: The ear monitoring audio data is invalid and is not encoded or sent.
   */
  typedef bool (*C_AudioFrameObserverBridge_onEarMonitoringAudioFrame)(C_AudioFrameObserverBridge *this_, void *userData,
                                                                       struct C_AudioFrame *audioFrame);
  /**
   * Occurs when the before-mixing playback audio frame is received.
   * @param channelId The channel name
   * @param userId ID of the remote user.
   * @param audioFrame The reference to the audio frame: AudioFrame.
   * @return
   * - true: The before-mixing playback audio frame is valid and is encoded and sent.
   * - false: The before-mixing playback audio frame is invalid and is not encoded or sent.
   */
  typedef bool (*C_AudioFrameObserverBridge_onPlaybackAudioFrameBeforeMixing)(C_AudioFrameObserverBridge *this_, void *userData,
                                                                              const char *channelId, C_user_id_t userId, struct C_AudioFrame *audioFrame);

  /**
   * Sets the frame position for the audio observer.
   * @return A bit mask that controls the frame position of the audio observer.
   * @note - Use '|' (the OR operator) to observe multiple frame positions.
   * <p>
   * After you successfully register the audio observer, the SDK triggers this callback each time it receives a audio frame. You can determine which position to observe by setting the return value.
   * The SDK provides 4 positions for observer. Each position corresponds to a callback function:
   * - `AUDIO_FRAME_POSITION_PLAYBACK (1 << 0)`: The position for playback audio frame is received, which corresponds to the \ref onPlaybackFrame "onPlaybackFrame" callback.
   * - `AUDIO_FRAME_POSITION_RECORD (1 << 1)`: The position for record audio frame is received, which corresponds to the \ref onRecordFrame "onRecordFrame" callback.
   * - `AUDIO_FRAME_POSITION_MIXED (1 << 2)`: The position for mixed audio frame is received, which corresponds to the \ref onMixedFrame "onMixedFrame" callback.
   * - `AUDIO_FRAME_POSITION_BEFORE_MIXING (1 << 3)`: The position for playback audio frame before mixing is received, which corresponds to the \ref onPlaybackFrameBeforeMixing "onPlaybackFrameBeforeMixing" callback.
   *  @return The bit mask that controls the audio observation positions.
   * See AUDIO_FRAME_POSITION.
   */
  typedef int (*C_AudioFrameObserverBridge_getObservedAudioFramePosition)(C_AudioFrameObserverBridge *this_, void *userData);

  /** Sets the audio playback format
   **Note**:

   - The SDK calculates the sample interval according to the `AudioParams`
   you set in the return value of this callback and triggers the
   `onPlaybackAudioFrame` callback at the calculated sample interval.
   Sample interval (seconds) = `samplesPerCall`/(`sampleRate` × `channel`).
   Ensure that the value of sample interval is equal to or greater than 0.01.

   @return Sets the audio format. See AgoraAudioParams.
   */
  typedef struct C_AudioParams (*C_AudioFrameObserverBridge_getPlaybackAudioParams)(C_AudioFrameObserverBridge *this_, void *userData);

  /** Sets the audio recording format
   **Note**:
   - The SDK calculates the sample interval according to the `AudioParams`
   you set in the return value of this callback and triggers the
   `onRecordAudioFrame` callback at the calculated sample interval.
   Sample interval (seconds) = `samplesPerCall`/(`sampleRate` × `channel`).
   Ensure that the value of sample interval is equal to or greater than 0.01.

   @return Sets the audio format. See AgoraAudioParams.
   */
  typedef struct C_AudioParams (*C_AudioFrameObserverBridge_getRecordAudioParams)(C_AudioFrameObserverBridge *this_, void *userData);

  /** Sets the audio mixing format
   **Note**:
   - The SDK calculates the sample interval according to the `AudioParams`
   you set in the return value of this callback and triggers the
   `onMixedAudioFrame` callback at the calculated sample interval.
   Sample interval (seconds) = `samplesPerCall`/(`sampleRate` × `channel`).
   Ensure that the value of sample interval is equal to or greater than 0.01.

   @return Sets the audio format. See AgoraAudioParams.
   */
  typedef struct C_AudioParams (*C_AudioFrameObserverBridge_getMixedAudioParams)(C_AudioFrameObserverBridge *this_, void *userData);

  /** Sets the ear monitoring audio format
   **Note**:
   - The SDK calculates the sample interval according to the `AudioParams`
   you set in the return value of this callback and triggers the
   `onEarMonitoringAudioFrame` callback at the calculated sample interval.
   Sample interval (seconds) = `samplesPerCall`/(`sampleRate` × `channel`).
   Ensure that the value of sample interval is equal to or greater than 0.01.

   @return Sets the audio format. See AgoraAudioParams.
   */
  typedef struct C_AudioParams (*C_AudioFrameObserverBridge_getEarMonitoringAudioParams)(C_AudioFrameObserverBridge *this_, void *userData);

  typedef struct C_AudioFrameObserverBridge_Callbacks
  {
    C_AudioFrameObserverBridge_onRecordAudioFrame onRecordAudioFrame;
    C_AudioFrameObserverBridge_onPlaybackAudioFrame onPlaybackAudioFrame;
    C_AudioFrameObserverBridge_onMixedAudioFrame onMixedAudioFrame;
    C_AudioFrameObserverBridge_onEarMonitoringAudioFrame onEarMonitoringAudioFrame;
    C_AudioFrameObserverBridge_onPlaybackAudioFrameBeforeMixing onPlaybackAudioFrameBeforeMixing;
    C_AudioFrameObserverBridge_getObservedAudioFramePosition getObservedAudioFramePosition;
    C_AudioFrameObserverBridge_getPlaybackAudioParams getPlaybackAudioParams;
    C_AudioFrameObserverBridge_getRecordAudioParams getRecordAudioParams;
    C_AudioFrameObserverBridge_getMixedAudioParams getMixedAudioParams;
    C_AudioFrameObserverBridge_getEarMonitoringAudioParams getEarMonitoringAudioParams;
  } C_AudioFrameObserverBridge_Callbacks;

  C_AudioFrameObserverBridge *C_AudioFrameObserverBridge_New(C_AudioFrameObserverBridge_Callbacks cbs, void *userData);
  void C_AudioFrameObserverBridge_Delete(C_AudioFrameObserverBridge *this_);

#pragma endregion C_AudioFrameObserverBridge

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_AUDIO_FRAME_OBSERVER_BRIDGE_H
