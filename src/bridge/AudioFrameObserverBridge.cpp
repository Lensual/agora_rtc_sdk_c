#include "bridge/AudioFrameObserverBridge.hh"

bool AudioFrameObserverBridge::onRecordAudioFrame(const char *channelId, AudioFrame &audioFrame)
{
  if (cbs_.onRecordAudioFrame != nullptr)
  {
    return cbs_.onRecordAudioFrame(this, this->userData_, channelId, (C_AudioFrame *)&audioFrame);
  }
  return true;
}

bool AudioFrameObserverBridge::onPlaybackAudioFrame(const char *channelId, AudioFrame &audioFrame)
{
  if (cbs_.onPlaybackAudioFrame != nullptr)
  {
    return cbs_.onPlaybackAudioFrame(this, this->userData_, channelId, (C_AudioFrame *)&audioFrame);
  }
  return true;
}

bool AudioFrameObserverBridge::onMixedAudioFrame(const char *channelId, AudioFrame &audioFrame)
{
  if (cbs_.onMixedAudioFrame != nullptr)
  {
    return cbs_.onMixedAudioFrame(this, this->userData_, channelId, (C_AudioFrame *)&audioFrame);
  }
  return true;
}

bool AudioFrameObserverBridge::onEarMonitoringAudioFrame(AudioFrame &audioFrame)
{
  if (cbs_.onEarMonitoringAudioFrame != nullptr)
  {
    return cbs_.onEarMonitoringAudioFrame(this, this->userData_, (C_AudioFrame *)&audioFrame);
  }
  return true;
}

bool AudioFrameObserverBridge::onPlaybackAudioFrameBeforeMixing(const char *channelId, base::user_id_t userId, AudioFrame &audioFrame)
{
  if (cbs_.onPlaybackAudioFrameBeforeMixing != nullptr)
  {
    return cbs_.onPlaybackAudioFrameBeforeMixing(this, this->userData_, channelId, C_user_id_t(userId), (C_AudioFrame *)&audioFrame);
  }
  return true;
}

int AudioFrameObserverBridge::getObservedAudioFramePosition()
{
  if (cbs_.getObservedAudioFramePosition != nullptr)
  {
    return cbs_.getObservedAudioFramePosition(this, this->userData_);
  }
  return 0;
}

AudioFrameObserverBridge::AudioParams AudioFrameObserverBridge::getPlaybackAudioParams()
{
  if (cbs_.getPlaybackAudioParams != nullptr)
  {
    auto ptr = cbs_.getPlaybackAudioParams(this, this->userData_);
    return *(AudioFrameObserverBridge::AudioParams *)&ptr;
  }
  return {};
}

AudioFrameObserverBridge::AudioParams AudioFrameObserverBridge::getRecordAudioParams()
{
  if (cbs_.getRecordAudioParams != nullptr)
  {
    auto ptr = cbs_.getRecordAudioParams(this, this->userData_);
    return *(AudioFrameObserverBridge::AudioParams *)&ptr;
  }
  return {};
}

AudioFrameObserverBridge::AudioParams AudioFrameObserverBridge::getMixedAudioParams()
{
  if (cbs_.getMixedAudioParams != nullptr)
  {
    auto ptr = cbs_.getMixedAudioParams(this, this->userData_);
    return *(AudioFrameObserverBridge::AudioParams *)&ptr;
  }
  return {};
}

AudioFrameObserverBridge::AudioParams AudioFrameObserverBridge::getEarMonitoringAudioParams()
{
  if (cbs_.getEarMonitoringAudioParams != nullptr)
  {
    auto ptr = cbs_.getEarMonitoringAudioParams(this, this->userData_);
    return *(AudioFrameObserverBridge::AudioParams *)&ptr;
  }
  return {};
}
