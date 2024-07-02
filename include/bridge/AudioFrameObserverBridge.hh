#pragma once

#include "AgoraMediaBase.h"
using namespace agora;
using namespace agora::media;

#include "C_AudioFrameObserverBridge.h"

class AudioFrameObserverBridge : public IAudioFrameObserverBase
{
public:
  AudioFrameObserverBridge(C_AudioFrameObserverBridge_Callbacks cbs, void *userData)
      : cbs_(cbs),
        userData_(userData) {}

  ~AudioFrameObserverBridge(){};

  /**
   * Occurs when the recorded audio frame is received.
   * @param channelId The channel name
   * @param audioFrame The reference to the audio frame: AudioFrame.
   * @return
   * - true: The recorded audio frame is valid and is encoded and sent.
   * - false: The recorded audio frame is invalid and is not encoded or sent.
   */
  bool onRecordAudioFrame(const char *channelId, AudioFrame &audioFrame) override;
  /**
   * Occurs when the playback audio frame is received.
   * @param channelId The channel name
   * @param audioFrame The reference to the audio frame: AudioFrame.
   * @return
   * - true: The playback audio frame is valid and is encoded and sent.
   * - false: The playback audio frame is invalid and is not encoded or sent.
   */
  bool onPlaybackAudioFrame(const char *channelId, AudioFrame &audioFrame) override;
  /**
   * Occurs when the mixed audio data is received.
   * @param channelId The channel name
   * @param audioFrame The reference to the audio frame: AudioFrame.
   * @return
   * - true: The mixed audio data is valid and is encoded and sent.
   * - false: The mixed audio data is invalid and is not encoded or sent.
   */
  bool onMixedAudioFrame(const char *channelId, AudioFrame &audioFrame) override;
  /**
   * Occurs when the ear monitoring audio frame is received.
   * @param audioFrame The reference to the audio frame: AudioFrame.
   * @return
   * - true: The ear monitoring audio data is valid and is encoded and sent.
   * - false: The ear monitoring audio data is invalid and is not encoded or sent.
   */
  bool onEarMonitoringAudioFrame(AudioFrame &audioFrame) override;
  /**
   * Occurs when the before-mixing playback audio frame is received.
   * @param channelId The channel name
   * @param userId ID of the remote user.
   * @param audioFrame The reference to the audio frame: AudioFrame.
   * @return
   * - true: The before-mixing playback audio frame is valid and is encoded and sent.
   * - false: The before-mixing playback audio frame is invalid and is not encoded or sent.
   */
  bool onPlaybackAudioFrameBeforeMixing(const char *channelId, base::user_id_t userId, AudioFrame &audioFrame) override;

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
  int getObservedAudioFramePosition() override;

  /** Sets the audio playback format
   **Note**:

   - The SDK calculates the sample interval according to the `AudioParams`
   you set in the return value of this callback and triggers the
   `onPlaybackAudioFrame` callback at the calculated sample interval.
   Sample interval (seconds) = `samplesPerCall`/(`sampleRate` × `channel`).
   Ensure that the value of sample interval is equal to or greater than 0.01.

   @return Sets the audio format. See AgoraAudioParams.
   */
  AudioParams getPlaybackAudioParams() override;

  /** Sets the audio recording format
   **Note**:
   - The SDK calculates the sample interval according to the `AudioParams`
   you set in the return value of this callback and triggers the
   `onRecordAudioFrame` callback at the calculated sample interval.
   Sample interval (seconds) = `samplesPerCall`/(`sampleRate` × `channel`).
   Ensure that the value of sample interval is equal to or greater than 0.01.

   @return Sets the audio format. See AgoraAudioParams.
   */
  AudioParams getRecordAudioParams() override;

  /** Sets the audio mixing format
   **Note**:
   - The SDK calculates the sample interval according to the `AudioParams`
   you set in the return value of this callback and triggers the
   `onMixedAudioFrame` callback at the calculated sample interval.
   Sample interval (seconds) = `samplesPerCall`/(`sampleRate` × `channel`).
   Ensure that the value of sample interval is equal to or greater than 0.01.

   @return Sets the audio format. See AgoraAudioParams.
   */
  AudioParams getMixedAudioParams() override;

  /** Sets the ear monitoring audio format
   **Note**:
   - The SDK calculates the sample interval according to the `AudioParams`
   you set in the return value of this callback and triggers the
   `onEarMonitoringAudioFrame` callback at the calculated sample interval.
   Sample interval (seconds) = `samplesPerCall`/(`sampleRate` × `channel`).
   Ensure that the value of sample interval is equal to or greater than 0.01.

   @return Sets the audio format. See AgoraAudioParams.
   */
  AudioParams getEarMonitoringAudioParams() override;

private:
  C_AudioFrameObserverBridge_Callbacks cbs_;
  void *userData_;
};
