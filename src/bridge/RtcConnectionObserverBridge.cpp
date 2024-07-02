#include "bridge/RtcConnectionObserverBridge.hh"

void RtcConnectionObserverBridge::onConnected(const TConnectionInfo &connectionInfo, CONNECTION_CHANGED_REASON_TYPE reason)
{
  if (cbs_.onConnected != nullptr)
  {
    return cbs_.onConnected(this, this->userData_, (const C_TConnectionInfo *)&connectionInfo, C_CONNECTION_CHANGED_REASON_TYPE(reason));
  }
}

void RtcConnectionObserverBridge::onDisconnected(const TConnectionInfo &connectionInfo, CONNECTION_CHANGED_REASON_TYPE reason)
{
  if (cbs_.onDisconnected != nullptr)
  {
    return cbs_.onDisconnected(this, this->userData_, (const C_TConnectionInfo *)&connectionInfo, C_CONNECTION_CHANGED_REASON_TYPE(reason));
  }
}

void RtcConnectionObserverBridge::onConnecting(const TConnectionInfo &connectionInfo, CONNECTION_CHANGED_REASON_TYPE reason)
{
  if (cbs_.onConnecting != nullptr)
  {
    return cbs_.onConnecting(this, this->userData_, (const C_TConnectionInfo *)&connectionInfo, C_CONNECTION_CHANGED_REASON_TYPE(reason));
  }
}

void RtcConnectionObserverBridge::onReconnecting(const TConnectionInfo &connectionInfo, CONNECTION_CHANGED_REASON_TYPE reason)
{
  if (cbs_.onReconnecting != nullptr)
  {
    return cbs_.onReconnecting(this, this->userData_, (const C_TConnectionInfo *)&connectionInfo, C_CONNECTION_CHANGED_REASON_TYPE(reason));
  }
}

void RtcConnectionObserverBridge::onReconnected(const TConnectionInfo &connectionInfo, CONNECTION_CHANGED_REASON_TYPE reason)
{
  if (cbs_.onReconnected != nullptr)
  {
    return cbs_.onReconnected(this, this->userData_, (const C_TConnectionInfo *)&connectionInfo, C_CONNECTION_CHANGED_REASON_TYPE(reason));
  }
}

void RtcConnectionObserverBridge::onConnectionLost(const TConnectionInfo &connectionInfo)
{
  if (cbs_.onConnectionLost != nullptr)
  {
    return cbs_.onConnectionLost(this, this->userData_, (const C_TConnectionInfo *)&connectionInfo);
  }
}

void RtcConnectionObserverBridge::onLastmileQuality(const QUALITY_TYPE quality)
{
  if (cbs_.onLastmileQuality != nullptr)
  {
    return cbs_.onLastmileQuality(this, this->userData_, C_QUALITY_TYPE(quality));
  }
}

void RtcConnectionObserverBridge::onLastmileProbeResult(const LastmileProbeResult &result)
{
  if (cbs_.onLastmileProbeResult != nullptr)
  {
    return cbs_.onLastmileProbeResult(this, this->userData_, (const C_LastmileProbeResult *)&result);
  }
}

void RtcConnectionObserverBridge::onTokenPrivilegeWillExpire(const char *token)
{
  if (cbs_.onTokenPrivilegeWillExpire != nullptr)
  {
    return cbs_.onTokenPrivilegeWillExpire(this, this->userData_, token);
  }
}

void RtcConnectionObserverBridge::onTokenPrivilegeDidExpire()
{
  if (cbs_.onTokenPrivilegeDidExpire != nullptr)
  {
    return cbs_.onTokenPrivilegeDidExpire(this, this->userData_);
  }
}

void RtcConnectionObserverBridge::onConnectionFailure(const TConnectionInfo &connectionInfo,
                                                       CONNECTION_CHANGED_REASON_TYPE reason)
{
  if (cbs_.onConnectionFailure != nullptr)
  {
    return cbs_.onConnectionFailure(this, this->userData_, (const C_TConnectionInfo *)&connectionInfo, C_CONNECTION_CHANGED_REASON_TYPE(reason));
  }
}

void RtcConnectionObserverBridge::onUserJoined(user_id_t userId)
{
  if (cbs_.onUserJoined != nullptr)
  {
    return cbs_.onUserJoined(this, this->userData_, C_user_id_t(userId));
  }
}

void RtcConnectionObserverBridge::onUserLeft(user_id_t userId, USER_OFFLINE_REASON_TYPE reason)
{
  if (cbs_.onUserLeft != nullptr)
  {
    return cbs_.onUserLeft(this, this->userData_, C_user_id_t(userId), C_USER_OFFLINE_REASON_TYPE(reason));
  }
}

void RtcConnectionObserverBridge::onTransportStats(const RtcStats &stats)
{
  if (cbs_.onTransportStats != nullptr)
  {
    return cbs_.onTransportStats(this, this->userData_, (const C_RtcStats *)&stats);
  }
}

void RtcConnectionObserverBridge::onChangeRoleSuccess(CLIENT_ROLE_TYPE oldRole, CLIENT_ROLE_TYPE newRole, const ClientRoleOptions &newRoleOptions)
{
  if (cbs_.onChangeRoleSuccess != nullptr)
  {
    return cbs_.onChangeRoleSuccess(this, this->userData_, C_CLIENT_ROLE_TYPE(oldRole), C_CLIENT_ROLE_TYPE(newRole), (const C_ClientRoleOptions *)&newRoleOptions);
  }
}

void RtcConnectionObserverBridge::onChangeRoleFailure(CLIENT_ROLE_CHANGE_FAILED_REASON reason, CLIENT_ROLE_TYPE currentRole)
{
  if (cbs_.onChangeRoleFailure != nullptr)
  {
    return cbs_.onChangeRoleFailure(this, this->userData_, C_CLIENT_ROLE_CHANGE_FAILED_REASON(reason), C_CLIENT_ROLE_TYPE(currentRole));
  }
}

void RtcConnectionObserverBridge::onLicenseValidationFailure(LICENSE_ERROR_TYPE error)
{
  if (cbs_.onLicenseValidationFailure != nullptr)
  {
    return cbs_.onLicenseValidationFailure(this, this->userData_, C_LICENSE_ERROR_TYPE(error));
  }
}

void RtcConnectionObserverBridge::onUserNetworkQuality(user_id_t userId, QUALITY_TYPE txQuality,
                                                        QUALITY_TYPE rxQuality)
{
  if (cbs_.onUserNetworkQuality != nullptr)
  {
    return cbs_.onUserNetworkQuality(this, this->userData_, C_user_id_t(userId), C_QUALITY_TYPE(txQuality), C_QUALITY_TYPE(rxQuality));
  }
}

void RtcConnectionObserverBridge::onNetworkTypeChanged(NETWORK_TYPE type)
{
  if (cbs_.onNetworkTypeChanged != nullptr)
  {
    return cbs_.onNetworkTypeChanged(this, this->userData_, C_NETWORK_TYPE(type));
  }
}

void RtcConnectionObserverBridge::onContentInspectResult(media::CONTENT_INSPECT_RESULT result)
{
  if (cbs_.onContentInspectResult != nullptr)
  {
    return cbs_.onContentInspectResult(this, this->userData_, C_CONTENT_INSPECT_RESULT(result));
  }
}

void RtcConnectionObserverBridge::onSnapshotTaken(uid_t uid, const char *filePath, int width, int height, int errCode)
{
  if (cbs_.onSnapshotTaken != nullptr)
  {
    return cbs_.onSnapshotTaken(this, this->userData_, C_uid_t(uid), filePath, width, height, errCode);
  }
}

void RtcConnectionObserverBridge::onError(ERROR_CODE_TYPE error, const char *msg)
{
  if (cbs_.onError != nullptr)
  {
    return cbs_.onError(this, this->userData_, C_ERROR_CODE_TYPE(error), msg);
  }
}

void RtcConnectionObserverBridge::onChannelMediaRelayStateChanged(int state, int code)
{
  if (cbs_.onChannelMediaRelayStateChanged != nullptr)
  {
    return cbs_.onChannelMediaRelayStateChanged(this, this->userData_, state, code);
  }
}

void RtcConnectionObserverBridge::onLocalUserRegistered(uid_t uid, const char *userAccount)
{
  if (cbs_.onLocalUserRegistered != nullptr)
  {
    return cbs_.onLocalUserRegistered(this, this->userData_, C_uid_t(uid), userAccount);
  }
}

void RtcConnectionObserverBridge::onUserAccountUpdated(uid_t uid, const char *userAccount)
{
  if (cbs_.onUserAccountUpdated != nullptr)
  {
    return cbs_.onUserAccountUpdated(this, this->userData_, C_uid_t(uid), userAccount);
  }
}

void RtcConnectionObserverBridge::onStreamMessageError(user_id_t userId, int streamId, int code, int missed,
                                                        int cached)
{
  if (cbs_.onStreamMessageError != nullptr)
  {
    return cbs_.onStreamMessageError(this, this->userData_, C_user_id_t(userId), streamId, code, missed, cached);
  }
}

void RtcConnectionObserverBridge::onEncryptionError(ENCRYPTION_ERROR_TYPE errorType)
{
  if (cbs_.onEncryptionError != nullptr)
  {
    return cbs_.onEncryptionError(this, this->userData_, C_ENCRYPTION_ERROR_TYPE(errorType));
  }
}

void RtcConnectionObserverBridge::onUploadLogResult(const char *requestId, bool success, UPLOAD_ERROR_REASON reason)
{
  if (cbs_.onUploadLogResult != nullptr)
  {
    return cbs_.onUploadLogResult(this, this->userData_, requestId, success, C_UPLOAD_ERROR_REASON(reason));
  }
}

void RtcConnectionObserverBridge::onWlAccMessage(WLACC_MESSAGE_REASON reason, WLACC_SUGGEST_ACTION action, const char *wlAccMsg)
{
  if (cbs_.onWlAccMessage != nullptr)
  {
    return cbs_.onWlAccMessage(this, this->userData_, C_WLACC_MESSAGE_REASON(reason), C_WLACC_SUGGEST_ACTION(action), wlAccMsg);
  }
}

void RtcConnectionObserverBridge::onWlAccStats(WlAccStats currentStats, WlAccStats averageStats)
{
  if (cbs_.onWlAccStats != nullptr)
  {
    return cbs_.onWlAccStats(this, this->userData_, *(C_WlAccStats *)&currentStats, *(C_WlAccStats *)&averageStats);
  }
}
