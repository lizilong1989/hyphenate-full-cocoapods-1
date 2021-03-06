/*!
 *  @header EMCallManagerDelegate.h
 *  @abstract This protocol defined the callbacks of real time voice/video
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMCallSession.h"

@class EMError;

/*!
 *  Callbacks of real time voice/video
 */
@protocol EMCallManagerDelegate <NSObject>
    
@optional

/*!
 *  User B will receive this callback after user A dial user B
 *
 *  @param aSession  Session instance
 */
- (void)callDidReceive:(EMCallSession *)aSession;

/*!
 *  Both user A and B will receive this callback after connection is established
 *
 *  @param aSession  Session instance
 */
- (void)callDidConnect:(EMCallSession *)aSession;

/*!
 *  User A will receive this callback after user B accept A's call
 *
 *  @param aSession
 */
- (void)callDidAccept:(EMCallSession *)aSession;

/*!
 *  1.The another peer will receive this callback after user A or user B terminate the call.
 *  2.Both user A and B will receive this callback after error occur.
 *
 *  @param aSession  Session instance
 *  @param aReason   Terminate reason
 *  @param aError    Error
 */
- (void)callDidEnd:(EMCallSession *)aSession
            reason:(EMCallEndReason)aReason
             error:(EMError *)aError;

/*!
 *  User A and B is on the call, A pause or resume the data stream, B will receive the callback
 *
 *  @param aSession  Session instance
 *  @param aType     Type
 */
- (void)callStateDidChange:(EMCallSession *)aSession
                      type:(EMCallStreamingStatus)aType;

/*!
 *  User A and B is on the call, A network status is not stable, A will receive the callback
 *
 *  @param aSession  Session instance
 *  @param aStatus   Current status
 */
- (void)callNetworkDidChange:(EMCallSession *)aSession
                      status:(EMCallNetworkStatus)aStatus;

#pragma mark - EM_DEPRECATED_IOS < 3.2.0
/*!
 *  Delegate method invokes when receiving a incoming call.
 *  User B will receive this callback when user A calls user B.
 *
 *  @param aSession  Session instance
 */
- (void)didReceiveCallIncoming:(EMCallSession *)aSession EM_DEPRECATED_IOS(3_1_0, 3_1_5, "Use -[EMCallManagerDelegate callDidReceive:]");

/*!
 *  Both user A and B will receive this callback after connection is established
 *
 *  @param aSession  Session instance
 */
- (void)didReceiveCallConnected:(EMCallSession *)aSession EM_DEPRECATED_IOS(3_1_0, 3_1_5, "Use -[EMCallManagerDelegate callDidConnect:]");

/*!
 *  User A will receive this callback after user B accept A's call
 *
 *  @param aSession
 */
- (void)didReceiveCallAccepted:(EMCallSession *)aSession EM_DEPRECATED_IOS(3_1_0, 3_1_5, "Use -[EMCallManagerDelegate callDidAccept:]");

/*!
 *  1.The another peer will receive this callback after user A or user B terminate the call.
 *  2.Both user A and B will receive this callback after error occur.
 *
 *  @param aSession  Session instance
 *  @param aReason   Terminate reason
 *  @param aError    Error
 */
- (void)didReceiveCallTerminated:(EMCallSession *)aSession
                          reason:(EMCallEndReason)aReason
                           error:(EMError *)aError EM_DEPRECATED_IOS(3_1_0, 3_1_5, "Use -[EMCallManagerDelegate callDidEnd:reason:error]");

/*!
 *  User A and B is on the call, A pause or resume the data stream, B will receive the callback
 *
 *  @param aSession  Session instance
 *  @param aType     Type
 */
- (void)didReceiveCallUpdated:(EMCallSession *)aSession
                         type:(EMCallStreamControlType)aType EM_DEPRECATED_IOS(3_1_0, 3_1_5, "Use -[EMCallManagerDelegate callStateDidChange:type]");

/*!
 *  User A and B is on the call, A network status is not stable, A will receive the callback
 *
 *  @param aSession  Session instance
 *  @param aStatus   Current status
 */
- (void)didReceiveCallNetworkChanged:(EMCallSession *)aSession
                              status:(EMCallNetworkStatus)aStatus EM_DEPRECATED_IOS(3_1_0, 3_1_5, "Use -[EMCallManagerDelegate callNetworkStatusDidChange:status:]");

@end
