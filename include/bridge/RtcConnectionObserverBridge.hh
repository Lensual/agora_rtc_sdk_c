#pragma once

#include "AgoraBase.h"
#include "NGIAgoraRtcConnection.h"
using namespace agora;
using namespace agora::rtc;

#include "C_RtcConnectionObserverBridge.h"

class RtcConnectionObserverBridge : public IRtcConnectionObserver
{
public:
  RtcConnectionObserverBridge(C_RtcConnectionObserverBridge_Callbacks cbs, void *userData)
      : cbs_(cbs),
        userData_(userData) {}

  ~RtcConnectionObserverBridge(){};

  /**
   * Occurs when the connection state between the SDK and the Agora channel changes to `CONNECTION_STATE_CONNECTED(3)`.
   *
   * @param connectionInfo The information of the connection. See \ref agora::rtc::TConnectionInfo "TConnectionInfo".
   * @param reason The reason of the connection state change. See #CONNECTION_CHANGED_REASON_TYPE.
   */
  void onConnected(const TConnectionInfo &connectionInfo, CONNECTION_CHANGED_REASON_TYPE reason) override;

  /**
   * Occurs when the connection state between the SDK and the Agora channel changes to `CONNECTION_STATE_DISCONNECTED(1)`.
   *
   * @param connectionInfo The information of the connection. See \ref agora::rtc::TConnectionInfo "TConnectionInfo".
   * @param reason The reason of the connection state change. See #CONNECTION_CHANGED_REASON_TYPE.
   */
  void onDisconnected(const TConnectionInfo &connectionInfo, CONNECTION_CHANGED_REASON_TYPE reason) override;

  /**
   * Occurs when the connection state between the SDK and the Agora channel changes to `CONNECTION_STATE_CONNECTING(2)`.
   *
   * @param connectionInfo The information of the connection. See \ref agora::rtc::TConnectionInfo "TConnectionInfo".
   * @param reason The reason of the connection state change. See #CONNECTION_CHANGED_REASON_TYPE.
   */
  void onConnecting(const TConnectionInfo &connectionInfo, CONNECTION_CHANGED_REASON_TYPE reason) override;

  /**
   * Occurs when the connection state between the SDK and the Agora channel changes to `CONNECTION_STATE_RECONNECTING(4)`.
   *
   * @param connectionInfo The information of the connection. See \ref agora::rtc::TConnectionInfo "TConnectionInfo".
   * @param reason The reason of the connection state change. See #CONNECTION_CHANGED_REASON_TYPE.
   */
  void onReconnecting(const TConnectionInfo &connectionInfo, CONNECTION_CHANGED_REASON_TYPE reason) override;

  // This should be deleted. onConnected is enough.
  void onReconnected(const TConnectionInfo &connectionInfo, CONNECTION_CHANGED_REASON_TYPE reason) override;

  /**
   * Occurs when the SDK loses connection with the Agora channel.
   *
   * @param connectionInfo The information of the connection. See \ref agora::rtc::TConnectionInfo "TConnectionInfo".
   */
  void onConnectionLost(const TConnectionInfo &connectionInfo) override;

  /**
   * Reports the quality of the last-mile network.
   *
   * The SDK triggers this callback within two seconds after the app calls \ref IRtcConnection::startLastmileProbeTest "startLastmileProbeTest".
   *
   * @param quality Quality of the last-mile network: #QUALITY_TYPE.
   */
  void onLastmileQuality(const QUALITY_TYPE quality) override;

  /**
   * Reports the result of the last-mile network probe test.
   *
   * The SDK triggers this callback within 30 seconds after the app calls \ref IRtcConnection::startLastmileProbeTest "startLastmileProbeTest".
   *
   * @param result The result of the last-mile network probe test: \ref agora::rtc::LastmileProbeResult "LastmileProbeResult".
   */
  void onLastmileProbeResult(const LastmileProbeResult &result) override;

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
  void onTokenPrivilegeWillExpire(const char *token) override;

  /**
   * Occurs when the token has expired.
   *
   * Upon receiving this callback, you must generate a new token on your server and call \ref IRtcConnection::renewToken
   * "renewToken" to pass the new token to the SDK.
   */
  void onTokenPrivilegeDidExpire() override;

  /**
   * Occurs when the connection state between the SDK and the Agora channel changes to `CONNECTION_STATE_FAILED(5)`.
   *
   * @param connectionInfo The connection information: TConnectionInfo.
   * @param reason The reason of the connection state change: #CONNECTION_CHANGED_REASON_TYPE.
   */
  void onConnectionFailure(const TConnectionInfo &connectionInfo,
                           CONNECTION_CHANGED_REASON_TYPE reason) override;

  /**
   * Occurs when a remote user joins the channel.
   *
   * You can get the ID of the remote user in this callback.
   *
   * @param userId The ID of the remote user who joins the channel.
   */
  void onUserJoined(user_id_t userId) override;

  /**
   * Occurs when a remote user leaves the channel.
   *
   * You can know why the user leaves the channel through the `reason` parameter.
   *
   * @param userId The ID of the user who leaves the channel.
   * @param reason The reason why the remote user leaves the channel: #USER_OFFLINE_REASON_TYPE.
   */
  void onUserLeft(user_id_t userId, USER_OFFLINE_REASON_TYPE reason) override;

  /**
   * Reports the transport statistics of the connection.
   *
   * The SDK triggers this callback once every two seconds when the connection state is `CONNECTION_STATE_CONNECTED`.
   *
   * @param stats The pointer to \ref rtc::RtcStats "RtcStats".
   */
  void onTransportStats(const RtcStats &stats) override;

  /**
   * Occurs when the role of the local user changes.
   *
   * @param oldRole The previous role of the local user: \ref rtc::CLIENT_ROLE_TYPE "CLIENT_ROLE_TYPE".
   * @param newRole The current role of the local user: \ref rtc::CLIENT_ROLE_TYPE "CLIENT_ROLE_TYPE".
   * @param newRoleOptions The client role options of the current role of the local user: \ref rtc::ClientRoleOptions "ClientRoleOptions".
   */
  void onChangeRoleSuccess(CLIENT_ROLE_TYPE oldRole, CLIENT_ROLE_TYPE newRole, const ClientRoleOptions &newRoleOptions) override;

  /**
   * Occurs when the local user fails to change the user role.
   */
  void onChangeRoleFailure(CLIENT_ROLE_CHANGE_FAILED_REASON reason, CLIENT_ROLE_TYPE currentRole) override;

  /**
   * Occurs when connection license verification fails
   *
   * You can know the reason accordding to error code
   * @param error verify fail reason
   */
  void onLicenseValidationFailure(LICENSE_ERROR_TYPE error) override;

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
  void onUserNetworkQuality(user_id_t userId, QUALITY_TYPE txQuality,
                            QUALITY_TYPE rxQuality) override;

  /** Occurs when the network type is changed.
   * @param type The current network type. See #NETWORK_TYPE.
   */
  void onNetworkTypeChanged(NETWORK_TYPE type) override;

  /** Reports result of Content Inspect*/
  void onContentInspectResult(media::CONTENT_INSPECT_RESULT result) override;
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
  void onSnapshotTaken(uid_t uid, const char *filePath, int width, int height, int errCode) override;
  /**
   * Reports the error code and error message.
   * @param error The error code: #ERROR_CODE_TYPE.
   * @param msg The error message.
   */
  void onError(ERROR_CODE_TYPE error, const char *msg) override;

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
  void onChannelMediaRelayStateChanged(int state, int code) override;

  /** Occurs when the local user successfully registers a user account by calling the \ref IRtcEngine::joinChannelWithUserAccount "joinChannelWithUserAccount" method.This callback reports the user ID and user account of the local user.
   *
   * @param uid The ID of the local user.
   * @param userAccount The user account of the local user.
   */
  void onLocalUserRegistered(uid_t uid, const char *userAccount) override;

  /** Technical Preview, please do not depend on this event. */
  void onUserAccountUpdated(uid_t uid, const char *userAccount) override;

  /**
   * Reports the error that occurs when receiving data stream messages.
   *
   * @param userId The ID of the user sending the data stream.
   * @param streamId  the ID of the sent data stream, returned in the \ref agora::rtc::IRtcConnection::createDataStream "createDataStream" method.
   * @param code The error code.
   * @param missed The number of lost messages.
   * @param cached The number of incoming cached messages when the data stream is interrupted.
   */
  void onStreamMessageError(user_id_t userId, int streamId, int code, int missed,
                            int cached) override;

  /**
   * Reports the error type of encryption.
   * @param type See #ENCRYPTION_ERROR_TYPE.
   */
  void onEncryptionError(ENCRYPTION_ERROR_TYPE errorType) override;
  /**
   * Reports the user log upload result
   * @param requestId RequestId of the upload
   * @param success Is upload success
   * @param reason Reason of the upload, 0: OK, 1 Network Error, 2 Server Error.
   */
  void onUploadLogResult(const char *requestId, bool success, UPLOAD_ERROR_REASON reason) override;

  /** Occurs when the WIFI message need be sent to the user.
   *
   * @param reason The reason of notifying the user of a message.
   * @param action Suggest an action for the user.
   * @param wlAccMsg The message content of notifying the user.
   */
  void onWlAccMessage(WLACC_MESSAGE_REASON reason, WLACC_SUGGEST_ACTION action, const char *wlAccMsg) override;

  /** Occurs when SDK statistics wifi acceleration optimization effect.
   *
   * @param currentStats Instantaneous value of optimization effect.
   * @param averageStats Average value of cumulative optimization effect.
   */
  void onWlAccStats(WlAccStats currentStats, WlAccStats averageStats) override;

private:
  C_RtcConnectionObserverBridge_Callbacks cbs_;
  void *userData_;
};
