#ifndef C_RTC_CONNECTION_OBSERVER_BRIDGE_H
#define C_RTC_CONNECTION_OBSERVER_BRIDGE_H

#include "C_NGIAgoraRtcConnection.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

  typedef void C_RtcConnectionObserverBridge;
#pragma region C_RtmEventHandlerBridge
  // Callbacks

  /**
   * Occurs when the connection state between the SDK and the Agora channel changes to `CONNECTION_STATE_CONNECTED(3)`.
   *
   * @param connectionInfo The information of the connection. See \ref agora::rtc::TConnectionInfo "TConnectionInfo".
   * @param reason The reason of the connection state change. See #CONNECTION_CHANGED_REASON_TYPE.
   */
  typedef void (*C_RtcConnectionObserverBridge_onConnected)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                            const struct C_TConnectionInfo *connectionInfo, enum C_CONNECTION_CHANGED_REASON_TYPE reason);

  /**
   * Occurs when the connection state between the SDK and the Agora channel changes to `CONNECTION_STATE_DISCONNECTED(1)`.
   *
   * @param connectionInfo The information of the connection. See \ref agora::rtc::TConnectionInfo "TConnectionInfo".
   * @param reason The reason of the connection state change. See #CONNECTION_CHANGED_REASON_TYPE.
   */
  typedef void (*C_RtcConnectionObserverBridge_onDisconnected)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                               const struct C_TConnectionInfo *connectionInfo, enum C_CONNECTION_CHANGED_REASON_TYPE reason);

  /**
   * Occurs when the connection state between the SDK and the Agora channel changes to `CONNECTION_STATE_CONNECTING(2)`.
   *
   * @param connectionInfo The information of the connection. See \ref agora::rtc::TConnectionInfo "TConnectionInfo".
   * @param reason The reason of the connection state change. See #CONNECTION_CHANGED_REASON_TYPE.
   */
  typedef void (*C_RtcConnectionObserverBridge_onConnecting)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                             const struct C_TConnectionInfo *connectionInfo, enum C_CONNECTION_CHANGED_REASON_TYPE reason);

  /**
   * Occurs when the connection state between the SDK and the Agora channel changes to `CONNECTION_STATE_RECONNECTING(4)`.
   *
   * @param connectionInfo The information of the connection. See \ref agora::rtc::TConnectionInfo "TConnectionInfo".
   * @param reason The reason of the connection state change. See #CONNECTION_CHANGED_REASON_TYPE.
   */
  typedef void (*C_RtcConnectionObserverBridge_onReconnecting)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                               const struct C_TConnectionInfo *connectionInfo, enum C_CONNECTION_CHANGED_REASON_TYPE reason);

  // This should be deleted. onConnected is enough.
  typedef void (*C_RtcConnectionObserverBridge_onReconnected)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                              const struct C_TConnectionInfo *connectionInfo, enum C_CONNECTION_CHANGED_REASON_TYPE reason);

  /**
   * Occurs when the SDK loses connection with the Agora channel.
   *
   * @param connectionInfo The information of the connection. See \ref agora::rtc::TConnectionInfo "TConnectionInfo".
   */
  typedef void (*C_RtcConnectionObserverBridge_onConnectionLost)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                                 const struct C_TConnectionInfo *connectionInfo);

  /**
   * Reports the quality of the last-mile network.
   *
   * The SDK triggers this callback within two seconds after the app calls \ref IRtcConnection::startLastmileProbeTest "startLastmileProbeTest".
   *
   * @param quality Quality of the last-mile network: #QUALITY_TYPE.
   */
  typedef void (*C_RtcConnectionObserverBridge_onLastmileQuality)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                                  const enum C_QUALITY_TYPE quality);

  /**
   * Reports the result of the last-mile network probe test.
   *
   * The SDK triggers this callback within 30 seconds after the app calls \ref IRtcConnection::startLastmileProbeTest "startLastmileProbeTest".
   *
   * @param result The result of the last-mile network probe test: \ref agora::rtc::LastmileProbeResult "LastmileProbeResult".
   */
  typedef void (*C_RtcConnectionObserverBridge_onLastmileProbeResult)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                                      const struct C_LastmileProbeResult *result);

  /**
   * Occurs when the token expires in 30 seconds.
   *
   * The SDK triggers this callback to remind the app to get a new token before the token privilege expires.
   *
   * Upon receiving this callback, you must generate a new token on your server and call \ref IRtcConnection::renewToken
   * "renewToken" to pass the new token to the SDK.
   *
   * @param token The pointer to the token that expires in 30 seconds.
   */
  typedef void (*C_RtcConnectionObserverBridge_onTokenPrivilegeWillExpire)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                                           const char *token);

  /**
   * Occurs when the token has expired.
   *
   * Upon receiving this callback, you must generate a new token on your server and call \ref IRtcConnection::renewToken
   * "renewToken" to pass the new token to the SDK.
   */
  typedef void (*C_RtcConnectionObserverBridge_onTokenPrivilegeDidExpire)(C_RtcConnectionObserverBridge *this_, void *userData);

  /**
   * Occurs when the connection state between the SDK and the Agora channel changes to `CONNECTION_STATE_FAILED(5)`.
   *
   * @param connectionInfo The connection information: TConnectionInfo.
   * @param reason The reason of the connection state change: #CONNECTION_CHANGED_REASON_TYPE.
   */
  typedef void (*C_RtcConnectionObserverBridge_onConnectionFailure)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                                    const struct C_TConnectionInfo *connectionInfo,
                                                                    enum C_CONNECTION_CHANGED_REASON_TYPE reason);

  /**
   * Occurs when a remote user joins the channel.
   *
   * You can get the ID of the remote user in this callback.
   *
   * @param userId The ID of the remote user who joins the channel.
   */
  typedef void (*C_RtcConnectionObserverBridge_onUserJoined)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                             C_user_id_t userId);

  /**
   * Occurs when a remote user leaves the channel.
   *
   * You can know why the user leaves the channel through the `reason` parameter.
   *
   * @param userId The ID of the user who leaves the channel.
   * @param reason The reason why the remote user leaves the channel: #USER_OFFLINE_REASON_TYPE.
   */
  typedef void (*C_RtcConnectionObserverBridge_onUserLeft)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                           C_user_id_t userId, enum C_USER_OFFLINE_REASON_TYPE reason);

  /**
   * Reports the transport statistics of the connection.
   *
   * The SDK triggers this callback once every two seconds when the connection state is `CONNECTION_STATE_CONNECTED`.
   *
   * @param stats The pointer to \ref rtc::RtcStats "RtcStats".
   */
  typedef void (*C_RtcConnectionObserverBridge_onTransportStats)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                                 const struct C_RtcStats *stats);

  /**
   * Occurs when the role of the local user changes.
   *
   * @param oldRole The previous role of the local user: \ref rtc::CLIENT_ROLE_TYPE "CLIENT_ROLE_TYPE".
   * @param newRole The current role of the local user: \ref rtc::CLIENT_ROLE_TYPE "CLIENT_ROLE_TYPE".
   * @param newRoleOptions The client role options of the current role of the local user: \ref rtc::ClientRoleOptions "ClientRoleOptions".
   */
  typedef void (*C_RtcConnectionObserverBridge_onChangeRoleSuccess)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                                    enum C_CLIENT_ROLE_TYPE oldRole, enum C_CLIENT_ROLE_TYPE newRole, const struct C_ClientRoleOptions *newRoleOptions);

  /**
   * Occurs when the local user fails to change the user role.
   */
  typedef void (*C_RtcConnectionObserverBridge_onChangeRoleFailure)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                                    enum C_CLIENT_ROLE_CHANGE_FAILED_REASON reason, enum C_CLIENT_ROLE_TYPE currentRole);

  /**
   * Occurs when connection license verification fails
   *
   * You can know the reason accordding to error code
   * @param error verify fail reason
   */
  typedef void (*C_RtcConnectionObserverBridge_onLicenseValidationFailure)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                                           enum C_LICENSE_ERROR_TYPE error);

  /**
   * Reports the network quality of each user.
   *
   * The SDK triggers this callback once every two seconds to report the uplink and downlink network conditions
   * of each user in the channel, including the local user.
   *
   * @param userId The ID of the user. If `userId` is empty, this callback reports the network quality of the local user.
   * @param txQuality The uplink network quality: #QUALITY_TYPE.
   * @param rxQuality The downlink network quality: #QUALITY_TYPE.
   */
  typedef void (*C_RtcConnectionObserverBridge_onUserNetworkQuality)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                                     C_user_id_t userId, enum C_QUALITY_TYPE txQuality,
                                                                     enum C_QUALITY_TYPE rxQuality);

  /** Occurs when the network type is changed.
   * @param type The current network type. See #NETWORK_TYPE.
   */
  typedef void (*C_RtcConnectionObserverBridge_onNetworkTypeChanged)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                                     enum C_NETWORK_TYPE type);

  /** Reports result of Content Inspect*/
  typedef void (*C_RtcConnectionObserverBridge_onContentInspectResult)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                                       enum C_CONTENT_INSPECT_RESULT result);
  /** Occurs when takeSnapshot API result is obtained
   *
   *
   * @brief snapshot taken callback
   *
   * @param channel channel name
   * @param uid user id
   * @param filePath image is saveed file path
   * @param width image width
   * @param height image height
   * @param errCode 0 is ok negative is error
   */
  typedef void (*C_RtcConnectionObserverBridge_onSnapshotTaken)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                                C_uid_t uid, const char *filePath, int width, int height, int errCode);

  /**
   * Reports the error code and error message.
   * @param error The error code: #ERROR_CODE_TYPE.
   * @param msg The error message.
   */
  typedef void (*C_RtcConnectionObserverBridge_onError)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                        enum C_ERROR_CODE_TYPE error, const char *msg);

  /**
   * Occurs when the state of the channel media relay changes.
   *
   *
   * @param state The state code:
   * - `RELAY_STATE_IDLE(0)`: The SDK is initializing.
   * - `RELAY_STATE_CONNECTING(1)`: The SDK tries to relay the media stream to the destination
   * channel.
   * - `RELAY_STATE_RUNNING(2)`: The SDK successfully relays the media stream to the destination
   * channel.
   * - `RELAY_STATE_FAILURE(3)`: A failure occurs. See the details in `code`.
   * @param code The error code:
   * - `RELAY_OK(0)`: The state is normal.
   * - `RELAY_ERROR_SERVER_ERROR_RESPONSE(1)`: An error occurs in the server response.
   * - `RELAY_ERROR_SERVER_NO_RESPONSE(2)`: No server response. You can call the leaveChannel method
   * to leave the channel.
   * - `RELAY_ERROR_NO_RESOURCE_AVAILABLE(3)`: The SDK fails to access the service, probably due to
   * limited resources of the server.
   * - `RELAY_ERROR_FAILED_JOIN_SRC(4)`: Fails to send the relay request.
   * - `RELAY_ERROR_FAILED_JOIN_DEST(5)`: Fails to accept the relay request.
   * - `RELAY_ERROR_FAILED_PACKET_RECEIVED_FROM_SRC(6)`: The server fails to receive the media
   * stream.
   * - `RELAY_ERROR_FAILED_PACKET_SENT_TO_DEST(7)`: The server fails to send the media stream.
   * - `RELAY_ERROR_SERVER_CONNECTION_LOST(8)`: The SDK disconnects from the server due to poor
   * network connections. You can call the leaveChannel method to leave the channel.
   * - `RELAY_ERROR_INTERNAL_ERROR(9)`: An internal error occurs in the server.
   * - `RELAY_ERROR_SRC_TOKEN_EXPIRED(10)`: The token of the source channel has expired.
   * - `RELAY_ERROR_DEST_TOKEN_EXPIRED(11)`: The token of the destination channel has expired.
   */
  typedef void (*C_RtcConnectionObserverBridge_onChannelMediaRelayStateChanged)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                                                int state, int code);

  /** Occurs when the local user successfully registers a user account by calling the \ref IRtcEngine::joinChannelWithUserAccount "joinChannelWithUserAccount" method.This callback reports the user ID and user account of the local user.
   *
   * @param uid The ID of the local user.
   * @param userAccount The user account of the local user.
   */
  typedef void (*C_RtcConnectionObserverBridge_onLocalUserRegistered)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                                      C_uid_t uid, const char *userAccount);

  /** Technical Preview, please do not depend on this event. */
  typedef void (*C_RtcConnectionObserverBridge_onUserAccountUpdated)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                                     C_uid_t uid, const char *userAccount);

  /**
   * Reports the error that occurs when receiving data stream messages.
   *
   * @param userId The ID of the user sending the data stream.
   * @param streamId  the ID of the sent data stream, returned in the \ref agora::rtc::IRtcConnection::createDataStream "createDataStream" method.
   * @param code The error code.
   * @param missed The number of lost messages.
   * @param cached The number of incoming cached messages when the data stream is interrupted.
   */
  typedef void (*C_RtcConnectionObserverBridge_onStreamMessageError)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                                     C_user_id_t userId, int streamId, int code, int missed,
                                                                     int cached);

  /**
   * Reports the error type of encryption.
   * @param type See #ENCRYPTION_ERROR_TYPE.
   */
  typedef void (*C_RtcConnectionObserverBridge_onEncryptionError)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                                  enum C_ENCRYPTION_ERROR_TYPE errorType);
  /**
   * Reports the user log upload result
   * @param requestId RequestId of the upload
   * @param success Is upload success
   * @param reason Reason of the upload, 0: OK, 1 Network Error, 2 Server Error.
   */
  typedef void (*C_RtcConnectionObserverBridge_onUploadLogResult)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                                  const char *requestId, bool success, enum C_UPLOAD_ERROR_REASON reason);

  /** Occurs when the WIFI message need be sent to the user.
   *
   * @param reason The reason of notifying the user of a message.
   * @param action Suggest an action for the user.
   * @param wlAccMsg The message content of notifying the user.
   */
  typedef void (*C_RtcConnectionObserverBridge_onWlAccMessage)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                               enum C_WLACC_MESSAGE_REASON reason, enum C_WLACC_SUGGEST_ACTION action, const char *wlAccMsg);

  /** Occurs when SDK statistics wifi acceleration optimization effect.
   *
   * @param currentStats Instantaneous value of optimization effect.
   * @param averageStats Average value of cumulative optimization effect.
   */
  typedef void (*C_RtcConnectionObserverBridge_onWlAccStats)(C_RtcConnectionObserverBridge *this_, void *userData,
                                                             struct C_WlAccStats currentStats, struct C_WlAccStats averageStats);

  typedef struct C_RtcConnectionObserverBridge_Callbacks
  {
    C_RtcConnectionObserverBridge_onConnected onConnected;
    C_RtcConnectionObserverBridge_onDisconnected onDisconnected;
    C_RtcConnectionObserverBridge_onConnecting onConnecting;
    C_RtcConnectionObserverBridge_onReconnecting onReconnecting;
    C_RtcConnectionObserverBridge_onReconnected onReconnected;
    C_RtcConnectionObserverBridge_onConnectionLost onConnectionLost;
    C_RtcConnectionObserverBridge_onLastmileQuality onLastmileQuality;
    C_RtcConnectionObserverBridge_onLastmileProbeResult onLastmileProbeResult;
    C_RtcConnectionObserverBridge_onTokenPrivilegeWillExpire onTokenPrivilegeWillExpire;
    C_RtcConnectionObserverBridge_onTokenPrivilegeDidExpire onTokenPrivilegeDidExpire;
    C_RtcConnectionObserverBridge_onConnectionFailure onConnectionFailure;
    C_RtcConnectionObserverBridge_onUserJoined onUserJoined;
    C_RtcConnectionObserverBridge_onUserLeft onUserLeft;
    C_RtcConnectionObserverBridge_onTransportStats onTransportStats;
    C_RtcConnectionObserverBridge_onChangeRoleSuccess onChangeRoleSuccess;
    C_RtcConnectionObserverBridge_onChangeRoleFailure onChangeRoleFailure;
    C_RtcConnectionObserverBridge_onLicenseValidationFailure onLicenseValidationFailure;
    C_RtcConnectionObserverBridge_onUserNetworkQuality onUserNetworkQuality;
    C_RtcConnectionObserverBridge_onNetworkTypeChanged onNetworkTypeChanged;
    C_RtcConnectionObserverBridge_onContentInspectResult onContentInspectResult;
    C_RtcConnectionObserverBridge_onSnapshotTaken onSnapshotTaken;
    C_RtcConnectionObserverBridge_onError onError;
    C_RtcConnectionObserverBridge_onChannelMediaRelayStateChanged onChannelMediaRelayStateChanged;
    C_RtcConnectionObserverBridge_onLocalUserRegistered onLocalUserRegistered;
    C_RtcConnectionObserverBridge_onUserAccountUpdated onUserAccountUpdated;
    C_RtcConnectionObserverBridge_onStreamMessageError onStreamMessageError;
    C_RtcConnectionObserverBridge_onEncryptionError onEncryptionError;
    C_RtcConnectionObserverBridge_onUploadLogResult onUploadLogResult;
    C_RtcConnectionObserverBridge_onWlAccMessage onWlAccMessage;
    C_RtcConnectionObserverBridge_onWlAccStats onWlAccStats;
  } C_RtcConnectionObserverBridge_Callbacks;

  C_RtcConnectionObserverBridge *C_RtcConnectionObserverBridge_New(C_RtcConnectionObserverBridge_Callbacks cbs, void *userData);
  void C_RtcConnectionObserverBridge_Delete(C_RtcConnectionObserverBridge *this_);

#pragma endregion C_IRtcConnectionObserver

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_RTC_CONNECTION_OBSERVER_BRIDGE_H
