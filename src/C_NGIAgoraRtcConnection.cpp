// 引入AgoraRTM SDK
#include "NGIAgoraRtcConnection.h"

using namespace agora;
using namespace agora::rtc;

// Agora C封装
#include "C_NGIAgoraRtcConnection.h"

#pragma region agora

#pragma region agora::rtc

struct C_TConnectionInfo *C_TConnectionInfo_New()
{
  return (C_TConnectionInfo *)(new TConnectionInfo());
}
void C_TConnectionInfo_Delete(struct C_TConnectionInfo *this_)
{
  delete ((TConnectionInfo *)(this_));
}

struct C_TConnectSettings *C_TConnectSettings_New()
{
  return (C_TConnectSettings *)(new TConnectSettings());
}
void C_TConnectSettings_Delete(struct C_TConnectSettings *this_)
{
  delete ((TConnectSettings *)(this_));
}

struct C_RtcConnectionConfiguration *C_RtcConnectionConfiguration_New()
{
  return (C_RtcConnectionConfiguration *)(new RtcConnectionConfiguration());
}
void C_RtcConnectionConfiguration_Delete(struct C_RtcConnectionConfiguration *this_)
{
  delete ((RtcConnectionConfiguration *)(this_));
}

#pragma region C_IRtcConnectionObserver

void C_IRtcConnectionObserver_Delete(C_IRtcConnectionObserver *this_)
{
  delete ((IRtcConnectionObserver *)(this_));
}

void C_IRtcConnectionObserver_onConnected(C_IRtcConnectionObserver *this_, const struct C_TConnectionInfo *connectionInfo, enum C_CONNECTION_CHANGED_REASON_TYPE reason)
{
  ((IRtcConnectionObserver *)(this_))->onConnected(*(TConnectionInfo *)connectionInfo, CONNECTION_CHANGED_REASON_TYPE(reason));
}

void C_IRtcConnectionObserver_onDisconnected(C_IRtcConnectionObserver *this_, const struct C_TConnectionInfo *connectionInfo, enum C_CONNECTION_CHANGED_REASON_TYPE reason)
{
  ((IRtcConnectionObserver *)(this_))->onDisconnected(*(TConnectionInfo *)connectionInfo, CONNECTION_CHANGED_REASON_TYPE(reason));
}

void C_IRtcConnectionObserver_onConnecting(C_IRtcConnectionObserver *this_, const struct C_TConnectionInfo *connectionInfo, enum C_CONNECTION_CHANGED_REASON_TYPE reason)
{
  ((IRtcConnectionObserver *)(this_))->onConnecting(*(TConnectionInfo *)connectionInfo, CONNECTION_CHANGED_REASON_TYPE(reason));
}

void C_IRtcConnectionObserver_onReconnecting(C_IRtcConnectionObserver *this_, const struct C_TConnectionInfo *connectionInfo, enum C_CONNECTION_CHANGED_REASON_TYPE reason)
{
  ((IRtcConnectionObserver *)(this_))->onReconnecting(*(TConnectionInfo *)connectionInfo, CONNECTION_CHANGED_REASON_TYPE(reason));
}

void C_IRtcConnectionObserver_onReconnected(C_IRtcConnectionObserver *this_, const struct C_TConnectionInfo *connectionInfo, enum C_CONNECTION_CHANGED_REASON_TYPE reason)
{
  ((IRtcConnectionObserver *)(this_))->onReconnected(*(TConnectionInfo *)connectionInfo, CONNECTION_CHANGED_REASON_TYPE(reason));
}

void C_IRtcConnectionObserver_onConnectionLost(C_IRtcConnectionObserver *this_, const struct C_TConnectionInfo *connectionInfo)
{
  ((IRtcConnectionObserver *)(this_))->onConnectionLost(*(TConnectionInfo *)connectionInfo);
}

void C_IRtcConnectionObserver_onLastmileQuality(C_IRtcConnectionObserver *this_, const enum C_QUALITY_TYPE quality)
{
  ((IRtcConnectionObserver *)(this_))->onLastmileQuality(QUALITY_TYPE(quality));
}

void C_IRtcConnectionObserver_onLastmileProbeResult(C_IRtcConnectionObserver *this_, const struct C_LastmileProbeResult *result)
{
  ((IRtcConnectionObserver *)(this_))->onLastmileProbeResult(*(LastmileProbeResult *)result);
}

void C_IRtcConnectionObserver_onTokenPrivilegeWillExpire(C_IRtcConnectionObserver *this_, const char *token)
{
  ((IRtcConnectionObserver *)(this_))->onTokenPrivilegeWillExpire(token);
}

void C_IRtcConnectionObserver_onTokenPrivilegeDidExpire(C_IRtcConnectionObserver *this_)
{
  ((IRtcConnectionObserver *)(this_))->onTokenPrivilegeDidExpire();
}

void C_IRtcConnectionObserver_onConnectionFailure(C_IRtcConnectionObserver *this_, const struct C_TConnectionInfo *connectionInfo,
                                                  enum C_CONNECTION_CHANGED_REASON_TYPE reason)
{
  ((IRtcConnectionObserver *)(this_))->onConnectionFailure(*(TConnectionInfo *)connectionInfo, CONNECTION_CHANGED_REASON_TYPE(reason));
}

void C_IRtcConnectionObserver_onUserJoined(C_IRtcConnectionObserver *this_, C_user_id_t userId)
{
  ((IRtcConnectionObserver *)(this_))->onUserJoined(user_id_t(userId));
}

void C_IRtcConnectionObserver_onUserLeft(C_IRtcConnectionObserver *this_, C_user_id_t userId, enum C_USER_OFFLINE_REASON_TYPE reason)
{
  ((IRtcConnectionObserver *)(this_))->onUserLeft(user_id_t(userId), USER_OFFLINE_REASON_TYPE(reason));
}

void C_IRtcConnectionObserver_onTransportStats(C_IRtcConnectionObserver *this_, const struct C_RtcStats *stats)
{
  ((IRtcConnectionObserver *)(this_))->onTransportStats(*(RtcStats *)(stats));
}

void C_IRtcConnectionObserver_onChangeRoleSuccess(C_IRtcConnectionObserver *this_, enum C_CLIENT_ROLE_TYPE oldRole, enum C_CLIENT_ROLE_TYPE newRole, const struct C_ClientRoleOptions *newRoleOptions)
{
  ((IRtcConnectionObserver *)(this_))->onChangeRoleSuccess(CLIENT_ROLE_TYPE(oldRole), CLIENT_ROLE_TYPE(newRole), *(ClientRoleOptions *)(newRoleOptions));
}

void C_IRtcConnectionObserver_onChangeRoleFailure(C_IRtcConnectionObserver *this_, enum C_CLIENT_ROLE_CHANGE_FAILED_REASON reason, enum C_CLIENT_ROLE_TYPE currentRole)
{
  ((IRtcConnectionObserver *)(this_))->onChangeRoleFailure(CLIENT_ROLE_CHANGE_FAILED_REASON(reason), CLIENT_ROLE_TYPE(currentRole));
}

void C_IRtcConnectionObserver_onLicenseValidationFailure(C_IRtcConnectionObserver *this_, enum C_LICENSE_ERROR_TYPE error)
{
  ((IRtcConnectionObserver *)(this_))->onLicenseValidationFailure(LICENSE_ERROR_TYPE(error));
}

void C_IRtcConnectionObserver_onUserNetworkQuality(C_IRtcConnectionObserver *this_, C_user_id_t userId, enum C_QUALITY_TYPE txQuality,
                                                   enum C_QUALITY_TYPE rxQuality)
{
  ((IRtcConnectionObserver *)(this_))->onUserNetworkQuality(user_id_t(userId), QUALITY_TYPE(txQuality), QUALITY_TYPE(rxQuality));
}

void C_IRtcConnectionObserver_onNetworkTypeChanged(C_IRtcConnectionObserver *this_, enum C_NETWORK_TYPE type)
{
  ((IRtcConnectionObserver *)(this_))->onNetworkTypeChanged(NETWORK_TYPE(type));
}

void C_IRtcConnectionObserver_onContentInspectResult(C_IRtcConnectionObserver *this_, enum C_CONTENT_INSPECT_RESULT result)
{
  ((IRtcConnectionObserver *)(this_))->onContentInspectResult(media::CONTENT_INSPECT_RESULT(result));
}

void C_IRtcConnectionObserver_onSnapshotTaken(C_IRtcConnectionObserver *this_, C_uid_t uid, const char *filePath, int width, int height, int errCode)
{
  ((IRtcConnectionObserver *)(this_))->onSnapshotTaken(uid_t(uid), filePath, width, height, errCode);
}

void C_IRtcConnectionObserver_onError(C_IRtcConnectionObserver *this_, enum C_ERROR_CODE_TYPE error, const char *msg)
{
  ((IRtcConnectionObserver *)(this_))->onError(ERROR_CODE_TYPE(error), msg);
}

void C_IRtcConnectionObserver_onChannelMediaRelayStateChanged(C_IRtcConnectionObserver *this_, int state, int code)
{
  ((IRtcConnectionObserver *)(this_))->onChannelMediaRelayStateChanged(state, code);
}

void C_IRtcConnectionObserver_onLocalUserRegistered(C_IRtcConnectionObserver *this_, C_uid_t uid, const char *userAccount)
{
  ((IRtcConnectionObserver *)(this_))->onLocalUserRegistered(uid_t(uid), userAccount);
}

void C_IRtcConnectionObserver_onUserAccountUpdated(C_IRtcConnectionObserver *this_, C_uid_t uid, const char *userAccount)
{
  ((IRtcConnectionObserver *)(this_))->onUserAccountUpdated(uid_t(uid), userAccount);
}

void C_IRtcConnectionObserver_onStreamMessageError(C_IRtcConnectionObserver *this_, C_user_id_t userId, int streamId, int code, int missed,
                                                   int cached)
{
  ((IRtcConnectionObserver *)(this_))->onStreamMessageError(user_id_t(userId), streamId, code, missed, cached);
}

void C_IRtcConnectionObserver_onEncryptionError(C_IRtcConnectionObserver *this_, enum C_ENCRYPTION_ERROR_TYPE errorType)
{
  ((IRtcConnectionObserver *)(this_))->onEncryptionError(ENCRYPTION_ERROR_TYPE(errorType));
}

void C_IRtcConnectionObserver_onUploadLogResult(C_IRtcConnectionObserver *this_, const char *requestId, bool success, enum C_UPLOAD_ERROR_REASON reason)
{
  ((IRtcConnectionObserver *)(this_))->onUploadLogResult(requestId, success, UPLOAD_ERROR_REASON(reason));
}

void C_IRtcConnectionObserver_onWlAccMessage(C_IRtcConnectionObserver *this_, enum C_WLACC_MESSAGE_REASON reason, enum C_WLACC_SUGGEST_ACTION action, const char *wlAccMsg)
{
  ((IRtcConnectionObserver *)(this_))->onWlAccMessage(WLACC_MESSAGE_REASON(reason), WLACC_SUGGEST_ACTION(action), wlAccMsg);
}

void C_IRtcConnectionObserver_onWlAccStats(C_IRtcConnectionObserver *this_, struct C_WlAccStats currentStats, struct C_WlAccStats averageStats)
{
  ((IRtcConnectionObserver *)(this_))->onWlAccStats(*(WlAccStats *)&currentStats, *(WlAccStats *)&averageStats);
}

#pragma endregion C_IRtcConnectionObserver

#pragma region C_INetworkObserver

void C_INetworkObserver_Delete(C_INetworkObserver *this_)
{
  delete ((INetworkObserver *)(this_));
}

#pragma endregion C_INetworkObserver

#pragma region C_IRtcConnection

int C_IRtcConnection_connect(C_IRtcConnection *this_, const char *token, const char *channelId, C_user_id_t userId)
{
  return ((IRtcConnection *)(this_))->connect(token, channelId, user_id_t(userId));
}

int C_IRtcConnection_connect_settings(C_IRtcConnection *this_, const struct C_TConnectSettings *settings)
{
  return ((IRtcConnection *)(this_))->connect(*(TConnectSettings *)settings);
}

int C_IRtcConnection_disconnect(C_IRtcConnection *this_)
{
  return ((IRtcConnection *)(this_))->disconnect();
}

int C_IRtcConnection_stopLastmileProbeTest(C_IRtcConnection *this_)
{
  return ((IRtcConnection *)(this_))->stopLastmileProbeTest();
}

int C_IRtcConnection_renewToken(C_IRtcConnection *this_, const char *token)
{
  return ((IRtcConnection *)(this_))->renewToken(token);
}

struct C_TConnectionInfo C_IRtcConnection_getConnectionInfo(C_IRtcConnection *this_)
{
  auto ptr = ((IRtcConnection *)(this_))->getConnectionInfo();
  return *(C_TConnectionInfo *)&ptr;
}

C_ILocalUser *C_IRtcConnection_getLocalUser(C_IRtcConnection *this_)
{
  return ((IRtcConnection *)(this_))->getLocalUser();
}

int C_IRtcConnection_registerObserver(C_IRtcConnection *this_, C_IRtcConnectionObserver *observer, void (*safeDeleter)(C_IRtcConnectionObserver *))
{
  return ((IRtcConnection *)(this_))->registerObserver((IRtcConnectionObserver *)(observer), (void (*)(IRtcConnectionObserver *))safeDeleter);
}

int C_IRtcConnection_unregisterObserver(C_IRtcConnection *this_, C_IRtcConnectionObserver *observer)
{
  return ((IRtcConnection *)(this_))->unregisterObserver((IRtcConnectionObserver *)(observer));
}

int C_IRtcConnection_registerNetworkObserver(C_IRtcConnection *this_, C_INetworkObserver *observer, void (*safeDeleter)(C_INetworkObserver *))
{
  return ((IRtcConnection *)(this_))->registerNetworkObserver((INetworkObserver *)(observer), (void (*)(INetworkObserver *))safeDeleter);
}

int C_IRtcConnection_unregisterNetworkObserver(C_IRtcConnection *this_, C_INetworkObserver *observer)
{
  return ((IRtcConnection *)(this_))->registerNetworkObserver((INetworkObserver *)(observer));
}

C_conn_id_t C_IRtcConnection_getConnId(C_IRtcConnection *this_)
{
  return ((IRtcConnection *)(this_))->getConnId();
}

struct C_RtcStats C_IRtcConnection_getTransportStats(C_IRtcConnection *this_)
{
  auto ptr = (((IRtcConnection *)(this_))->getTransportStats());
  return *(C_RtcStats *)&ptr;
}

int C_IRtcConnection_createDataStream(C_IRtcConnection *this_, int *streamId, bool reliable, bool ordered, bool sync)
{
  return ((IRtcConnection *)(this_))->createDataStream(streamId, reliable, ordered, sync);
}

int C_IRtcConnection_sendStreamMessage(C_IRtcConnection *this_, int streamId, const char *data, size_t length)
{
  return ((IRtcConnection *)(this_))->sendStreamMessage(streamId, data, length);
}

int C_IRtcConnection_sendCustomReportMessage(C_IRtcConnection *this_, const char *id, const char *category, const char *event, const char *label, int value)
{
  return ((IRtcConnection *)(this_))->sendCustomReportMessage(id, category, event, label, value);
}

#pragma endregion C_IRtcConnection

#pragma endregion agora::rtc

#pragma endregion agora
