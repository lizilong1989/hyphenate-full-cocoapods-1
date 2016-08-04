/*!
 *  @header EMClient.h
 *  @abstract SDK Client
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMClientDelegate.h"
#import "EMOptions.h"
#import "EMPushOptions.h"
#import "EMError.h"

#import "IEMChatManager.h"
#import "IEMContactManager.h"
#import "IEMGroupManager.h"
#import "IEMChatroomManager.h"

/*!
 *  SDK Client
 */
@interface EMClient : NSObject
{
    EMPushOptions *_pushOptions;
}

/*!
 *  SDK version
 */
@property (nonatomic, strong, readonly) NSString *version;

/*!
 *  Current logined account
 */
@property (nonatomic, strong, readonly) NSString *currentUsername;

/*!
 *  SDK setting options
 */
@property (nonatomic, strong, readonly) EMOptions *options;

/*!
 *  Apple APNS setting
 */
@property (nonatomic, strong, readonly) EMPushOptions *pushOptions;

/*!
 *  Chat module
 */
@property (nonatomic, strong, readonly) id<IEMChatManager> chatManager;

/*!
 *  Contact module
 */
@property (nonatomic, strong, readonly) id<IEMContactManager> contactManager;

/*!
 *  Group module
 */
@property (nonatomic, strong, readonly) id<IEMGroupManager> groupManager;

/*!
 *  Chatroom module
 */
@property (nonatomic, strong, readonly) id<IEMChatroomManager> roomManager;

/*!
 *  Whether SDK will automatically login last logined account
 */
@property (nonatomic, readonly) BOOL isAutoLogin;

/*!
 *  Whether user has logged in
 */
@property (nonatomic, readonly) BOOL isLoggedIn;

/*!
 *  Whether has connected to chat server
 */
@property (nonatomic, readonly) BOOL isConnected;

/*!
 *  Get SDK single instance
 */
+ (instancetype)sharedClient;

#pragma mark - Delegate

/*!
 *  Add delegate
 *
 *  @param aDelegate  Delegate
 *  @param aQueue     The queue of call delegate method
 */
- (void)addDelegate:(id<EMClientDelegate>)aDelegate
      delegateQueue:(dispatch_queue_t)aQueue;

/*!
 *  Add delegate
 *
 *  @param aDelegate  Delegate
 */
- (void)addDelegate:(id<EMClientDelegate>)aDelegate;

/*!
 *  Remove delegate
 *  
 *  @param aDelegate  Delegate
 */
- (void)removeDelegate:(id)aDelegate;

#pragma mark - Initialize SDK

/*!
 *  Initialization sdk
 *  
 *  @param aOptions  SDK setting options
 *
 *  @result Error
 */
- (EMError *)initializeSDKWithOptions:(EMOptions *)aOptions;

#pragma mark - Sync method

#pragma mark - Register

/*!
 *  Register a new user
 *
 *  Synchronization method will block the current thread. It is not recommended, advise to register new user through REST API
 *
 *  @param aUsername  Username
 *  @param aPassword  Password
 *
 *  @result Error
 */
- (EMError *)registerWithUsername:(NSString *)aUsername
                         password:(NSString *)aPassword;

#pragma mark - Login

/*!
 *  Login
 *
 *  Synchronization method will block the current thread
 *
 *  @param aUsername  Username
 *  @param aPassword  Password
 *
 *  @result Error
 */
- (EMError *)loginWithUsername:(NSString *)aUsername
                      password:(NSString *)aPassword;

#pragma makr - Logout

/*!
 *  Logout
 *
 *  Synchronization method will block the current thread
 *
 *  @param aIsUnbindDeviceToken Whether unbind device token, device will don't receive message push after unbind token, if input YES, unbind failed will return error
 *
 *  @result Error
 */
- (EMError *)logout:(BOOL)aIsUnbindDeviceToken;

#pragma mark - Apns

/*!
 *  Bind device token
 *
 *  Synchronization method will block the current thread
 *
 *  @param aDeviceToken  Device token to bind
 *
 *  @result Error
 */
- (EMError *)bindDeviceToken:(NSData *)aDeviceToken;

/*!
 *  Set nick name to show in push message
 *
 *  Synchronization method will block the current thread
 *
 *  @param aNickname  Nickname
 *
 *  @result Error
 */
- (EMError *)setApnsNickname:(NSString *)aNickname;

/*!
 *  Get apns options from the server
 *
 *  Synchronization method will block the current thread
 *
 *  @param pError  Error
 *
 *  @result Apns options
 */
- (EMPushOptions *)getPushOptionsFromServerWithError:(EMError **)pError;

/*!
 *  Update APNS options to the server
 *
 *  Synchronization method will block the current thread
 *
 *  @result Error
 */
- (EMError *)updatePushOptionsToServer;

/*!
 *  Upload log to server
 *
 *  Synchronization method will block the current thread
 *
 *  @result Error
 */
- (EMError *)uploadLogToServer;

#pragma mark - Async method

/*!
 *  Register a new user
 *
 *  It is not recommended, advise to register new user through REST API
 *
 *  @param aUsername        Username
 *  @param aPassword        Password
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)registerWithUsername:(NSString *)aUsername
                    password:(NSString *)aPassword
                  completion:(void (^)(NSString *aUsername, EMError *aError))aCompletionBlock;

/*!
 *  Login
 *
 *  @param aUsername        Username
 *  @param aPassword        Password
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)loginWithUsername:(NSString *)aUsername
                 password:(NSString *)aPassword
               completion:(void (^)(NSString *aUsername, EMError *aError))aCompletionBlock;

/*!
 *  Logout
 *
 *  @param aIsUnbindDeviceToken Whether unbind device token, device will don't receive message push after unbind token, if input YES, unbind failed will return error
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)logout:(BOOL)aIsUnbindDeviceToken
    completion:(void (^)(EMError *aError))aCompletionBlock;

/*!
 *  Bind device token
 *
 *  @param aDeviceToken     Device token to bind
 *  @param aCompletionBlock The callback block of completion
 */
- (void)registerForRemoteNotificationsWithDeviceToken:(NSData *)aDeviceToken
                                           completion:(void (^)(EMError *aError))aCompletionBlock;

/*!
 *  Set nick name to show in push message
 *
 *  @param aDisplayName     Display name of push
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)updateAPNsDisplayName:(NSString *)aDisplayName
                   completion:(void (^)(NSString *aDisplayName, EMError *aError))aCompletionBlock;

/*!
 *  Get apns options from the server
 *
 *  @param aCompletionBlock The callback block of completion
 */
- (void)getPushOptionsFromServerWithCompletion:(void (^)(EMPushOptions *aOptions, EMError *aError))aCompletionBlock;

/*!
 *  Update APNS options to the server
 *
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)updatePushOptionsToServerWithCompletion:(void (^)(EMError *aError))aCompletionBlock;

/*!
 *  Upload log to server
 *
 *  @param aCompletionBlock The callback block of completion
 */
- (void)uploadDebugLogToServerWithCompletion:(void (^)(EMError *aError))aCompletionBlock;

#pragma mark - iOS

/*!
 *  iOS only, data migration to SDK3.0
 *
 *  Synchronization method, will block the current thread
 *
 *  It's needed to call this method when update to SDK3.0, developers need to wait this method complete before DB related operations
 *
 *  @result Whether migration successful
 */
- (BOOL)migrateDatabaseToLatestSDK;

/*!
 *  iOS only, should call this method to disconnect from server when app enter backgroup
 *
 *  @param aApplication  UIApplication
 */
- (void)applicationDidEnterBackground:(id)aApplication;

/*!
 *  iOS only, should call this method to re-connect to server when app restore to foreground
 *
 *  @param aApplication  UIApplication
 */
- (void)applicationWillEnterForeground:(id)aApplication;

#pragma mark - Deprecated methods

/*!
 *  Register a new user
 *
 *  It is not recommended, advise to register new user through REST API
 *
 *  @param aUsername        Username
 *  @param aPassword        Password
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncRegisterWithUsername:(NSString *)aUsername
                         password:(NSString *)aPassword
                          success:(void (^)())aSuccessBlock
                          failure:(void (^)(EMError *aError))aFailureBlock __deprecated_msg("Use -registerWithUsername:password:completion:");

/*!
 *  Login
 *
 *  @param aUsername        Username
 *  @param aPassword        Password
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncLoginWithUsername:(NSString *)aUsername
                      password:(NSString *)aPassword
                       success:(void (^)())aSuccessBlock
                       failure:(void (^)(EMError *aError))aFailureBlock __deprecated_msg("Use -loginWithUsername:password:completion");

/*!
 *  Logout
 *
 *  @param aIsUnbindDeviceToken Whether unbind device token, device will don't receive message push after unbind token, if input YES, unbind failed will return error
 *
 *  @result Error
 */
- (void)asyncLogout:(BOOL)aIsUnbindDeviceToken
            success:(void (^)())aSuccessBlock
            failure:(void (^)(EMError *aError))aFailureBlock __deprecated_msg("Use -logout:completion:");

/*!
 *  Bind device token
 *
 *  @param aDeviceToken     Device token to bind
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 */
- (void)asyncBindDeviceToken:(NSData *)aDeviceToken
                     success:(void (^)())aSuccessBlock
                     failure:(void (^)(EMError *aError))aFailureBlock __deprecated_msg("Use -registerForRemoteNotificationsWithDeviceToken:completion:");

/*!
 *  Set nick name to show in push message
 *
 *  @param aNickname        Nickname
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncSetApnsNickname:(NSString *)aNickname
                     success:(void (^)())aSuccessBlock
                     failure:(void (^)(EMError *aError))aFailureBlock __deprecated_msg("Use -updateAPNsDisplayName:copletion");

/*!
 *  Get apns options from the server
 *
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 */
- (void)asyncGetPushOptionsFromServer:(void (^)(EMPushOptions *aOptions))aSuccessBlock
                              failure:(void (^)(EMError *aError))aFailureBlock __deprecated_msg("Use -getPushOptionsFromServerWithCompletion:");

/*!
 *  Update APNS options to the server
 *
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncUpdatePushOptionsToServer:(void (^)())aSuccessBlock
                               failure:(void (^)(EMError *aError))aFailureBlock __deprecated_msg("Use -updatePushOptionsToServerWithCompletion:");

/*!
 *  Upload log to server
 *
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 */
- (void)asyncUploadLogToServer:(void (^)())aSuccessBlock
                       failure:(void (^)(EMError *aError))aFailureBlock __deprecated_msg("Use -uploadDebugLogToServerWithCompletion:");

/*!
 *  iOS-specific, data migration to SDK3.0
 *
 *  Synchronization method will block the current thread
 *
 *  It's needed to call this method when update to SDK3.0, developers need to wait this method complete before DB related operations
 *
 *  @result Whether migration successful
 */
- (BOOL)dataMigrationTo3 __deprecated_msg("Use -migrateDatabaseToLatestSDK");

@end
