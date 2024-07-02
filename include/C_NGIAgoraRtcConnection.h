#ifndef C_NGI_AGORA_RTC_CONNECTION_H
#define C_NGI_AGORA_RTC_CONNECTION_H

#include "C_AgoraBase.h"
// #include "time_utils.h"

#include "C_NGIAgoraLocalUser.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#pragma region agora

#pragma region agora::rtc

  // class IAudioEncodedFrameSender;
  // class IRtcConnectionObserver;
  // class INetworkObserver;
  // class IRtcConnection;
  // class IVideoEncodedImageSender;
  // class ILocalUser;

  /**
   * The information of an RTC Connection.
   */
  struct C_TConnectionInfo
  {
    /**
     * The ID of the RTC Connection.
     */
    C_conn_id_t id;
    /**
     * The ID of the channel. If you have not called \ref agora::rtc::IRtcConnection::connect "connect", this member is `NULL`.
     */
    C_AString channelId;
    /**
     * The connection state: #CONNECTION_STATE_TYPE.
     */
    enum C_CONNECTION_STATE_TYPE state;
    /**
     * The ID of the local user.
     */
    C_AString localUserId;
    /**
     * Internal use only.
     */
    C_uid_t internalUid;

    int proxyType;

    C_AString connectionIp;
  };
  struct C_TConnectionInfo *C_TConnectionInfo_New();
  void C_TConnectionInfo_Delete(struct C_TConnectionInfo *this_);

  struct C_TConnectSettings
  {
    /**
     * The app ID.
     */
    const char *token;
    /**
    The channel name. It must be in the string format and not exceed 64 bytes in length. Supported character scopes are:
     * - All lowercase English letters: a to z.
     * - All uppercase English letters: A to Z.
     * - All numeric characters: 0 to 9.
     * - The space character.
     * - Punctuation characters and other symbols, including: "!", "#", "$", "%", "&", "(", ")", "+",
     * "-", ":", ";", "<", "=",
     * ".", ">", "?", "@", "[", "]", "^", "_", " {", "}", "|", "~", ","
    */
    const char *channelId;
    /**
    The ID of the local user. If you do not specify a user ID or set `userId` as `null`,
     * the SDK returns a user ID in the \ref IRtcConnectionObserver::onConnected "onConnected"
     * callback. Your app must record and maintain the `userId` since the SDK does not do so.
    */
    C_user_id_t userId;

    unsigned char RESERVED[4]; // HACK for C++ agora::Optional
    /*
    App can provide a app defined start time to trace some events like connect cost , first video, etc.
    */
    int64_t appDefinedStartTimeMs;
  };
  struct C_TConnectSettings *C_TConnectSettings_New();
  void C_TConnectSettings_Delete(struct C_TConnectSettings *this_);

  /**
   * Configurations for an RTC connection.
   *
   * Set these configurations when calling \ref agora::base::IAgoraService::createRtcConnection "createRtcConnection".
   */
  struct C_RtcConnectionConfiguration
  {
    /**
     * Whether to subscribe to all audio tracks automatically.
     * - `true`: (Default) Subscribe to all audio tracks automatically.
     * - `false`: Do not subscribe to any audio track automatically.
     */
    bool autoSubscribeAudio;
    /**
     * Whether to subscribe to all video tracks automatically.
     * - `true`: (Default) Subscribe to all video tracks automatically.
     * - `false`: Do not subscribe to any video track automatically.
     */
    bool autoSubscribeVideo;
    /**
     * Whether to enable audio recording or playout.
     * - `true`: Enables audio recording or playout. Use this option when you publish and mix audio tracks, or subscribe to one or multiple audio tracks and play audio.
     * - `false`: Disables audio recording or playout. Use this option when you publish external audio frames without audio mixing, or you do not need audio devices to play audio.
     */
    bool enableAudioRecordingOrPlayout;
    /**
     * The maximum sending bitrate.
     */
    int maxSendBitrate;
    /**
     * The minimum port.
     */
    int minPort;
    /**
     * The maximum port.
     */
    int maxPort;
    /**
     * The user role. For details, see #CLIENT_ROLE_TYPE. The default user role is `CLIENT_ROLE_AUDIENCE`.
     */
    enum C_CLIENT_ROLE_TYPE clientRoleType;
    /** The channel profile. For details, see #CHANNEL_PROFILE_TYPE. The default channel profile is `CHANNEL_PROFILE_LIVE_BROADCASTING`.
     */
    enum C_CHANNEL_PROFILE_TYPE channelProfile;

    /**
     * Determines whether to receive audio encoded frame or not.
     */
    bool audioRecvEncodedFrame;

    /**
     * Determines whether to receive audio media packet or not.
     */
    bool audioRecvMediaPacket;

    /**
     * Determines whether to receive video media packet or not.
     */
    bool videoRecvMediaPacket;

    /**
     * This mode is only used for audience. In PK mode, client might join one
     * channel as broadcaster, and join another channel as interactive audience to
     * achieve low lentancy and smooth video from remote user.
     * - true: Enable low lentancy and smooth video when joining as an audience.
     * - false: (Default) Use default settings for audience role.
     */
    bool isInteractiveAudience;
  };
  struct C_RtcConnectionConfiguration *C_RtcConnectionConfiguration_New();
  void C_RtcConnectionConfiguration_Delete(struct C_RtcConnectionConfiguration *this_);

  /**
   * The IRtcConnectionObserver class, which observes the connection state of the SDK.
   */
  typedef void C_IRtcConnectionObserver;
#pragma region C_IRtcConnectionObserver

  void C_IRtcConnectionObserver_Delete(C_IRtcConnectionObserver *this_);

  /**
   * Occurs when the connection state between the SDK and the Agora channel changes to `CONNECTION_STATE_CONNECTED(3)`.
   *
   * @param connectionInfo The information of the connection. See \ref agora::rtc::TConnectionInfo "TConnectionInfo".
   * @param reason The reason of the connection state change. See #CONNECTION_CHANGED_REASON_TYPE.
   */
  void C_IRtcConnectionObserver_onConnected(C_IRtcConnectionObserver *this_, const struct C_TConnectionInfo *connectionInfo, enum C_CONNECTION_CHANGED_REASON_TYPE reason);

  /**
   * Occurs when the connection state between the SDK and the Agora channel changes to `CONNECTION_STATE_DISCONNECTED(1)`.
   *
   * @param connectionInfo The information of the connection. See \ref agora::rtc::TConnectionInfo "TConnectionInfo".
   * @param reason The reason of the connection state change. See #CONNECTION_CHANGED_REASON_TYPE.
   */
  void C_IRtcConnectionObserver_onDisconnected(C_IRtcConnectionObserver *this_, const struct C_TConnectionInfo *connectionInfo, enum C_CONNECTION_CHANGED_REASON_TYPE reason);

  /**
   * Occurs when the connection state between the SDK and the Agora channel changes to `CONNECTION_STATE_CONNECTING(2)`.
   *
   * @param connectionInfo The information of the connection. See \ref agora::rtc::TConnectionInfo "TConnectionInfo".
   * @param reason The reason of the connection state change. See #CONNECTION_CHANGED_REASON_TYPE.
   */
  void C_IRtcConnectionObserver_onConnecting(C_IRtcConnectionObserver *this_, const struct C_TConnectionInfo *connectionInfo, enum C_CONNECTION_CHANGED_REASON_TYPE reason);

  /**
   * Occurs when the connection state between the SDK and the Agora channel changes to `CONNECTION_STATE_RECONNECTING(4)`.
   *
   * @param connectionInfo The information of the connection. See \ref agora::rtc::TConnectionInfo "TConnectionInfo".
   * @param reason The reason of the connection state change. See #CONNECTION_CHANGED_REASON_TYPE.
   */
  void C_IRtcConnectionObserver_onReconnecting(C_IRtcConnectionObserver *this_, const struct C_TConnectionInfo *connectionInfo, enum C_CONNECTION_CHANGED_REASON_TYPE reason);

  // This should be deleted. onConnected is enough.
  void C_IRtcConnectionObserver_onReconnected(C_IRtcConnectionObserver *this_, const struct C_TConnectionInfo *connectionInfo, enum C_CONNECTION_CHANGED_REASON_TYPE reason);

  /**
   * Occurs when the SDK loses connection with the Agora channel.
   *
   * @param connectionInfo The information of the connection. See \ref agora::rtc::TConnectionInfo "TConnectionInfo".
   */
  void C_IRtcConnectionObserver_onConnectionLost(C_IRtcConnectionObserver *this_, const struct C_TConnectionInfo *connectionInfo);

  /**
   * Reports the quality of the last-mile network.
   *
   * The SDK triggers this callback within two seconds after the app calls \ref IRtcConnection::startLastmileProbeTest "startLastmileProbeTest".
   *
   * @param quality Quality of the last-mile network: #QUALITY_TYPE.
   */
  void C_IRtcConnectionObserver_onLastmileQuality(C_IRtcConnectionObserver *this_, const enum C_QUALITY_TYPE quality);

  /**
   * Reports the result of the last-mile network probe test.
   *
   * The SDK triggers this callback within 30 seconds after the app calls \ref IRtcConnection::startLastmileProbeTest "startLastmileProbeTest".
   *
   * @param result The result of the last-mile network probe test: \ref agora::rtc::LastmileProbeResult "LastmileProbeResult".
   */
  void C_IRtcConnectionObserver_onLastmileProbeResult(C_IRtcConnectionObserver *this_, const struct C_LastmileProbeResult *result);

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
  void C_IRtcConnectionObserver_onTokenPrivilegeWillExpire(C_IRtcConnectionObserver *this_, const char *token);

  /**
   * Occurs when the token has expired.
   *
   * Upon receiving this callback, you must generate a new token on your server and call \ref IRtcConnection::renewToken
   * "renewToken" to pass the new token to the SDK.
   */
  void C_IRtcConnectionObserver_onTokenPrivilegeDidExpire(C_IRtcConnectionObserver *this_);

  /**
   * Occurs when the connection state between the SDK and the Agora channel changes to `CONNECTION_STATE_FAILED(5)`.
   *
   * @param connectionInfo The connection information: TConnectionInfo.
   * @param reason The reason of the connection state change: #CONNECTION_CHANGED_REASON_TYPE.
   */
  void C_IRtcConnectionObserver_onConnectionFailure(C_IRtcConnectionObserver *this_, const struct C_TConnectionInfo *connectionInfo,
                                                    enum C_CONNECTION_CHANGED_REASON_TYPE reason);

  /**
   * Occurs when a remote user joins the channel.
   *
   * You can get the ID of the remote user in this callback.
   *
   * @param userId The ID of the remote user who joins the channel.
   */
  void C_IRtcConnectionObserver_onUserJoined(C_IRtcConnectionObserver *this_, C_user_id_t userId);

  /**
   * Occurs when a remote user leaves the channel.
   *
   * You can know why the user leaves the channel through the `reason` parameter.
   *
   * @param userId The ID of the user who leaves the channel.
   * @param reason The reason why the remote user leaves the channel: #USER_OFFLINE_REASON_TYPE.
   */
  void C_IRtcConnectionObserver_onUserLeft(C_IRtcConnectionObserver *this_, C_user_id_t userId, enum C_USER_OFFLINE_REASON_TYPE reason);

  /**
   * Reports the transport statistics of the connection.
   *
   * The SDK triggers this callback once every two seconds when the connection state is `CONNECTION_STATE_CONNECTED`.
   *
   * @param stats The pointer to \ref rtc::RtcStats "RtcStats".
   */
  void C_IRtcConnectionObserver_onTransportStats(C_IRtcConnectionObserver *this_, const struct C_RtcStats *stats);

  /**
   * Occurs when the role of the local user changes.
   *
   * @param oldRole The previous role of the local user: \ref rtc::CLIENT_ROLE_TYPE "CLIENT_ROLE_TYPE".
   * @param newRole The current role of the local user: \ref rtc::CLIENT_ROLE_TYPE "CLIENT_ROLE_TYPE".
   * @param newRoleOptions The client role options of the current role of the local user: \ref rtc::ClientRoleOptions "ClientRoleOptions".
   */
  void C_IRtcConnectionObserver_onChangeRoleSuccess(C_IRtcConnectionObserver *this_, enum C_CLIENT_ROLE_TYPE oldRole, enum C_CLIENT_ROLE_TYPE newRole, const struct C_ClientRoleOptions *newRoleOptions);

  /**
   * Occurs when the local user fails to change the user role.
   */
  void C_IRtcConnectionObserver_onChangeRoleFailure(C_IRtcConnectionObserver *this_, enum C_CLIENT_ROLE_CHANGE_FAILED_REASON reason, enum C_CLIENT_ROLE_TYPE currentRole);

  /**
   * Occurs when connection license verification fails
   *
   * You can know the reason accordding to error code
   * @param error verify fail reason
   */
  void C_IRtcConnectionObserver_onLicenseValidationFailure(C_IRtcConnectionObserver *this_, enum C_LICENSE_ERROR_TYPE error);

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
  void C_IRtcConnectionObserver_onUserNetworkQuality(C_IRtcConnectionObserver *this_, C_user_id_t userId, enum C_QUALITY_TYPE txQuality,
                                                     enum C_QUALITY_TYPE rxQuality);

  /** Occurs when the network type is changed.
   * @param type The current network type. See #NETWORK_TYPE.
   */
  void C_IRtcConnectionObserver_onNetworkTypeChanged(C_IRtcConnectionObserver *this_, enum C_NETWORK_TYPE type);

  /** Reports result of Content Inspect*/
  void C_IRtcConnectionObserver_onContentInspectResult(C_IRtcConnectionObserver *this_, enum C_CONTENT_INSPECT_RESULT result);
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
  void C_IRtcConnectionObserver_onSnapshotTaken(C_IRtcConnectionObserver *this_, C_uid_t uid, const char *filePath, int width, int height, int errCode);

  /**
   * Reports the error code and error message.
   * @param error The error code: #ERROR_CODE_TYPE.
   * @param msg The error message.
   */
  void C_IRtcConnectionObserver_onError(C_IRtcConnectionObserver *this_, enum C_ERROR_CODE_TYPE error, const char *msg);

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
  void C_IRtcConnectionObserver_onChannelMediaRelayStateChanged(C_IRtcConnectionObserver *this_, int state, int code);

  /** Occurs when the local user successfully registers a user account by calling the \ref IRtcEngine::joinChannelWithUserAccount "joinChannelWithUserAccount" method.This callback reports the user ID and user account of the local user.
   *
   * @param uid The ID of the local user.
   * @param userAccount The user account of the local user.
   */
  void C_IRtcConnectionObserver_onLocalUserRegistered(C_IRtcConnectionObserver *this_, C_uid_t uid, const char *userAccount);

  /** Technical Preview, please do not depend on this event. */
  void C_IRtcConnectionObserver_onUserAccountUpdated(C_IRtcConnectionObserver *this_, C_uid_t uid, const char *userAccount);

  /**
   * Reports the error that occurs when receiving data stream messages.
   *
   * @param userId The ID of the user sending the data stream.
   * @param streamId  the ID of the sent data stream, returned in the \ref agora::rtc::IRtcConnection::createDataStream "createDataStream" method.
   * @param code The error code.
   * @param missed The number of lost messages.
   * @param cached The number of incoming cached messages when the data stream is interrupted.
   */
  void C_IRtcConnectionObserver_onStreamMessageError(C_IRtcConnectionObserver *this_, C_user_id_t userId, int streamId, int code, int missed,
                                                     int cached);

  /**
   * Reports the error type of encryption.
   * @param type See #ENCRYPTION_ERROR_TYPE.
   */
  void C_IRtcConnectionObserver_onEncryptionError(C_IRtcConnectionObserver *this_, enum C_ENCRYPTION_ERROR_TYPE errorType);
  /**
   * Reports the user log upload result
   * @param requestId RequestId of the upload
   * @param success Is upload success
   * @param reason Reason of the upload, 0: OK, 1 Network Error, 2 Server Error.
   */
  void C_IRtcConnectionObserver_onUploadLogResult(C_IRtcConnectionObserver *this_, const char *requestId, bool success, enum C_UPLOAD_ERROR_REASON reason);

  /** Occurs when the WIFI message need be sent to the user.
   *
   * @param reason The reason of notifying the user of a message.
   * @param action Suggest an action for the user.
   * @param wlAccMsg The message content of notifying the user.
   */
  void C_IRtcConnectionObserver_onWlAccMessage(C_IRtcConnectionObserver *this_, enum C_WLACC_MESSAGE_REASON reason, enum C_WLACC_SUGGEST_ACTION action, const char *wlAccMsg);

  /** Occurs when SDK statistics wifi acceleration optimization effect.
   *
   * @param currentStats Instantaneous value of optimization effect.
   * @param averageStats Average value of cumulative optimization effect.
   */
  void C_IRtcConnectionObserver_onWlAccStats(C_IRtcConnectionObserver *this_, struct C_WlAccStats currentStats, struct C_WlAccStats averageStats);

#pragma endregion C_IRtcConnectionObserver

  typedef void C_INetworkObserver;
#pragma region C_INetworkObserver

  void C_INetworkObserver_Delete(C_INetworkObserver *this_);

  /**
   * Occurs when downlink network info is updated.
   *
   * This callback is used for notifying user to adjust the send pace based
   * on the target bitrate.
   *
   * @param info The uplink network info collections.
   */
  // void C_INetworkObserver_onUplinkNetworkInfoUpdated(const C_UplinkNetworkInfo *info);

  /**
   * Occurs when downlink network info is updated.
   *
   * This callback is used for notifying user to switch major/minor stream if needed.
   *
   * @param info The downlink network info collections.
   */
  // void C_INetworkObserver_onDownlinkNetworkInfoUpdated(const C_DownlinkNetworkInfo *info);

#pragma endregion C_INetworkObserver

  /**
   * The `IRtcConnection` class.
   *
   * You can use this class for managing the connection between your app and an Agora Channel.
   *
   * Once connected, your app gets an `AgoraLocalUser` object for publishing and subscribing to media streams in the Agora Channel.
   *
   * Connecting to a channel is done asynchronously, and your app can listen for the connection states or events through `IRtcConnectionObserver`.
   * `IRtcConnection` also monitors remote users in the channel. The SDK notifies your app when a remote user joins or leaves the channel.
   */
  typedef C_RefCountInterface C_IRtcConnection;
#pragma region C_IRtcConnection

  /**
   * Connects to an Agora channel.
   *
   * When the method call succeeds, the connection state changes from `CONNECTION_STATE_DISCONNECTED(1)` to
   * `CONNECTION_STATE_CONNECTING(2)`.
   *
   * Depending on the whether the connection succeeds or not, the
   * connection state changes to either `CONNECTION_STATE_CONNECTED(3)` or `CONNECTION_STATE_FAILED(5)`. The SDK also triggers `onConnected` or `onDisconnected` to notify you of the state change.
   *
   * @param token The app ID.
   * @param channelId The channel name. It must be in the string format and not exceed 64 bytes in length. Supported character scopes are:
   * - All lowercase English letters: a to z.
   * - All uppercase English letters: A to Z.
   * - All numeric characters: 0 to 9.
   * - The space character.
   * - Punctuation characters and other symbols, including: "!", "#", "$", "%", "&", "(", ")", "+",
   * "-", ":", ";", "<", "=",
   * ".", ">", "?", "@", "[", "]", "^", "_", " {", "}", "|", "~", ","
   * @param userId The ID of the local user. If you do not specify a user ID or set `userId` as `null`,
   * the SDK returns a user ID in the \ref IRtcConnectionObserver::onConnected "onConnected"
   * callback. Your app must record and maintain the `userId` since the SDK does not do so.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   *   - -2(ERR_INVALID_ARGUMENT): The argument that you pass is invalid.
   *   - -8(ERR_INVALID_STATE): The current connection state is not CONNECTION_STATE_DISCONNECTED(1).
   */
  int C_IRtcConnection_connect(C_IRtcConnection *this_, const char *token, const char *channelId, C_user_id_t userId);

  /**
   * Connects to an Agora channel.
   *
   * When the method call succeeds, the connection state changes from `CONNECTION_STATE_DISCONNECTED(1)` to
   * `CONNECTION_STATE_CONNECTING(2)`.
   *
   * Depending on the whether the connection succeeds or not, the
   * connection state changes to either `CONNECTION_STATE_CONNECTED(3)` or `CONNECTION_STATE_FAILED(5)`.
   * The SDK also triggers `onConnected` or `onDisconnected` to notify you of the state change.
   * @param settings The settings of connecting.
   */
  int C_IRtcConnection_connect_settings(C_IRtcConnection *this_, const struct C_TConnectSettings *settings);

  /**
   * Disconnects from the Agora channel.
   *
   * Once your app successful disconnects from the channel, the connection state changes to
   * `CONNECTION_STATE_DISCONNECTED(1)`. You are also notified with the callback
   * \ref IRtcConnectionObserver::onDisconnected "onDisconnected".
   *
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtcConnection_disconnect(C_IRtcConnection *this_);

  // /**
  //  * Starts the last-mile network probe test.
  //  *
  //  * Call this method before connecting to the channel to get the uplink and
  //  * downlink last-mile network statistics, including the bandwidth, packet loss, jitter, and
  //  * round-trip time (RTT).
  //  *
  //  * After you enable the last-mile network probe test, the SDK triggers the following callbacks:
  //  * - \ref IRtcConnectionObserver::onLastmileQuality "onLastmileQuality": The SDK triggers this
  //  * callback within two seconds depending on the network conditions. This callback rates the network
  //  * conditions and is more closely linked to the user experience.
  //  * - \ref IRtcConnectionObserver::onLastmileProbeResult "onLastmileProbeResult": The SDK triggers
  //  * this callback within 30 seconds depending on the network conditions. This callback reports the
  //  * real-time statistics of the network conditions and is more objective.
  //  *
  //  * @note
  //  * - Do not call any other method before receiving the \ref IRtcConnectionObserver::onLastmileQuality
  //  * "onLastmileQuality" and \ref IRtcConnectionObserver::onLastmileProbeResult "onLastmileProbeResult"
  //  * callbacks. Otherwise, the callbacks may be interrupted.
  //  * - In the live-broadcast profile, a host should not call this method after connecting to a channel.
  //  *
  //  * @param config The configurations of the last-mile network probe test. See \ref agora::rtc::LastmileProbeConfig "LastmileProbeConfig".
  //  *
  //  * @return
  //  * - 0: Success.
  //  * - < 0: Failure.
  //  */
  // int C_IRtcConnection_startLastmileProbeTest(const LastmileProbeConfig *config);

  /**
   * Stops the last-mile network probe test.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtcConnection_stopLastmileProbeTest(C_IRtcConnection *this_);

  /**
   * Renews the token.
   *
   * The token expires after a certain period of time.
   * When the \ref IRtcConnectionObserver::onError "onError" callback reports `ERR_TOKEN_EXPIRED(109)`, you must generate a new token from the server
   * and then call this method to renew it. Otherwise, the SDK disconnects from the Agora channel.
   *
   * @param token The pointer to the new token.
   */
  int C_IRtcConnection_renewToken(C_IRtcConnection *this_, const char *token);

  /**
   * Gets the connection information.
   *
   * @return
   * - The pointer to the \ref agora::rtc::TConnectionInfo "TConnectionInfo" object: Success.
   * - A null pointer: Failure.
   */
  struct C_TConnectionInfo C_IRtcConnection_getConnectionInfo(C_IRtcConnection *this_);

  /**
   * Gets the \ref agora::rtc::ILocalUser "ILocalUser" object.
   *
   * @return
   * - The pointer to the \ref agora::rtc::ILocalUser "ILocalUser" object: Success.
   * - A null pointer: Failure.
   */
  C_ILocalUser *C_IRtcConnection_getLocalUser(C_IRtcConnection *this_);

  // /**
  //  * Gets the information of all the remote users in the channel.
  //  *
  //  * After a user successfully connects to the channel, you can also get the information of this remote user
  //  * with the \ref IRtcConnectionObserver::onUserJoined "onUserJoined" callback.
  //  *
  //  * @param [out] users The reference to the \ref agora::UserList "UserList" object, which contains the information of all users
  //  * in the channel.
  //  * @return
  //  * - 0: Success.
  //  * - < 0: Failure.
  //  */
  // int C_IRtcConnection_getRemoteUsers(UserList &users);

  // /**
  //  * Gets the information of a specified remote user in the channel.
  //  *
  //  * @param [in] userId ID of the user whose information you want to get.
  //  * @param [out] userInfo The reference to the \ref agora::UserInfo "UserInfo" object, which contains the information of the
  //  * specified user.
  //  * @return
  //  * - 0: Success.
  //  * - < 0: Failure.
  //  */
  // int C_IRtcConnection_getUserInfo(user_id_t userId, agora::UserInfo &userInfo);

  /**
   * Registers an RTC connection observer. You can call this method only after creating an `IRtcConnection` object.
   *
   * @param observer The pointer to the IRtcConnectionObserver object.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtcConnection_registerObserver(C_IRtcConnection *this_, C_IRtcConnectionObserver *observer, void (*safeDeleter)(C_IRtcConnectionObserver *));

  /**
   * Releases the registered IRtcConnectionObserver object.
   *
   * @param observer The pointer to the IRtcConnectionObserver object created by the \ref registerObserver
   * "registerObserver" method.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtcConnection_unregisterObserver(C_IRtcConnection *this_, C_IRtcConnectionObserver *observer);

  /**
   * Registers an network observer object.
   *
   * @param observer The pointer to the INetworkObserver object.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtcConnection_registerNetworkObserver(C_IRtcConnection *this_, C_INetworkObserver *observer, void (*safeDeleter)(C_INetworkObserver *));

  /**
   * Releases the registered INetworkObserver object.
   *
   * @param observer The pointer to the INetworkObserver object created by the \ref registerNetworkObserver
   * "registerNetworkObserver" method.
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtcConnection_unregisterNetworkObserver(C_IRtcConnection *this_, C_INetworkObserver *observer);

  /**
   * Gets the ID of the connection.
   *
   * @return
   * - The connection ID: Success.
   * - A null pointer: Failure.
   */
  C_conn_id_t C_IRtcConnection_getConnId(C_IRtcConnection *this_);

  /**
   * Gets the transportation statistics of the RTC connection.
   *
   * @return
   * - The pointer to \ref agora::rtc::RtcStats "RtcStats": Success.
   * - A null pointer: Failure.
   */
  struct C_RtcStats C_IRtcConnection_getTransportStats(C_IRtcConnection *this_);

  // /**
  //  * Gets the IAgoraParameter object.
  //  *
  //  * @return
  //  * - The pointer to the \ref agora::base::IAgoraParameter "IAgoraParameter" object.
  //  * - A null pointer: Failure.
  //  */
  // agora::base::IAgoraParameter *C_IRtcConnection_getAgoraParameter();

  /**
   * Creates a data stream.
   *
   * Each user can create up to five data streams during the lifecycle of an RTC connection.
   *
   * @note Set both the `reliable` and `ordered` parameters as `true` or `false`. Do not set one as `true` and the other as `false`.
   *
   * @param streamId The pointer to the ID of the data stream.
   * @param reliable Whether to guarantee the receivers receive the data stream within five seconds:
   * - `true`: Guarantee that the receivers receive the data stream within five seconds. If the receivers do not receive the data stream within five seconds, the SDK reports an error to the application.
   * - `false`: Do not guarantee that the receivers receive the data stream within five seconds and the SDK does not report any error message for data stream delay or missing.
   * @param ordered Whether the receivers receive the data stream in the order of sending:
   * - `true`: The receivers receive the data stream in the order of sending.
   * - `false`: The receivers do not receive the data stream in the order of sending.
   *
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtcConnection_createDataStream(C_IRtcConnection *this_, int *streamId, bool reliable, bool ordered, bool sync);

  /** Sends data stream messages to all users in a channel.
   *
   * @note This method has the following restrictions:
   * - Up to 30 packets can be sent per second in a channel with a maximum size of 1 kB for each packet.
   * - Each client can send up to 6 kB of data per second.
   * - Each user can have up to five data streams simultaneously.
   *
   * @param streamId The ID of the sent data stream, returned in the \ref agora::rtc::IRtcConnection::createDataStream "createDataStream" method.
   * @param data The pointer to the sent data.
   * @param length The length of the sent data.
   *
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtcConnection_sendStreamMessage(C_IRtcConnection *this_, int streamId, const char *data, size_t length);

  // /** Enables/Disables the built-in encryption.
  //  *
  //  * In scenarios requiring high security, Agora recommends calling this method to enable the built-in encryption before joining a channel.
  //  *
  //  * All users in the same channel must use the same encryption mode and encryption key. Once all users leave the channel, the encryption key of this channel is automatically cleared.
  //  *
  //  * @note
  //  * - If you enable the built-in encryption, you cannot use the RTMP streaming function.
  //  *
  //  * @param enabled Whether to enable the built-in encryption:
  //  * - true: Enable the built-in encryption.
  //  * - false: Disable the built-in encryption.
  //  * @param config Configurations of built-in encryption schemas. See \ref agora::rtc::EncryptionConfig "EncryptionConfig".
  //  *
  //  * @return
  //  * - 0: Success.
  //  * - < 0: Failure.
  //  */
  // int C_IRtcConnection_enableEncryption(bool enabled, const EncryptionConfig *config);

  /**
   * Reports a custom event to Agora.
   *
   * @param id The custom event ID.
   * @param category The category of the custom event.
   * @param event The custom event to report.
   * @param label The label of the custom event.
   * @param value The value of the custom event.
   *
   * @return
   * - 0: Success.
   * - < 0: Failure.
   */
  int C_IRtcConnection_sendCustomReportMessage(C_IRtcConnection *this_, const char *id, const char *category, const char *event, const char *label, int value);
  // /** Gets the user information by user account, which is in string format.
  //  *
  //  * @param userAccount The user account of the user.
  //  * @param [in,out] userInfo A \ref rtc::UserInfo "UserInfo" object that identifies the user:
  //  * - Input: A userInfo object.
  //  * - Output: A userInfo object that contains the user account and user ID of the user.
  //  *
  //  * @return
  //  * - 0: Success.
  //  * - < 0: Failure.
  //  */
  // int C_IRtcConnection_getUserInfoByUserAccount(const char *userAccount, C_UserInfo *userInfo);
  // /** Gets the user information by user ID, which is in integer format.
  //  *
  //  * @param uid The ID of the remote user.
  //  * @param [in,out] userInfo A \ref rtc::UserInfo "UserInfo" object that identifies the user:
  //  * - Input: A userInfo object.
  //  * - Output: A userInfo object that contains the user account and user ID of the user.
  //  *
  //  * @return
  //  * - 0: Success.
  //  * - < 0: Failure.
  //  */
  // int C_IRtcConnection_getUserInfoByUid(uid_t uid, C_UserInfo *userInfo);
#pragma endregion C_IRtcConnection

#pragma endregion agora::rtc

#pragma endregion agora

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // C_NGI_AGORA_RTC_CONNECTION_H
