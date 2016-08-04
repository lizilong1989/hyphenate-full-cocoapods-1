/*!
 *  @header IEMCallManager.h
 *  @abstract This protocol defined the operations of real time voice/video call
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMCallSession.h"
#import "EMCallManagerDelegate.h"

@class EMError;

/*!
 *
 */
@protocol IEMCallManager <NSObject>

@optional

#pragma mark - Delegate

/*!
 *  Add delegate
 *
 *  @param aDelegate  Delegate
 *  @param aQueue     The queue of call delegate method
 */
- (void)addDelegate:(id<EMCallManagerDelegate>)aDelegate
      delegateQueue:(dispatch_queue_t)aQueue;

/*!
 *  Add delegate
 *
 *  @param aDelegate  Delegate
 *
 */
- (void)addDelegate:(id<EMCallManagerDelegate>)aDelegate;

/*!
 *  Remove delegate
 *
 *  @param aDelegate  Delegate
 */
- (void)removeDelegate:(id<EMCallManagerDelegate>)aDelegate;

#pragma mark - Answer and End

/*!
 *  Receiver answer the call
 *
 *  @param  aSessionId Session Id
 *
 *  @result Error
 */
- (EMError *)answerIncomingCall:(NSString *)aSessionId;

/*!
 *  End the call
 *
 *  @param aSessionId Session ID
 *  @param aReason    End reason
 */
- (void)endCall:(NSString *)aSessionId
         reason:(EMCallEndReason)aReason;

#pragma mark - voice

/*!
 *  Start a voice call session
 *
 *  @param aUsername        The callee
 *  @param aCompletionBlock The callback of completion
 *
 */
- (void)startVoiceCall:(NSString *)aUsername
            completion:(void (^)(EMCallSession *aCallSession, EMError *aError))aCompletionBlock;

/*!
 *  Pause voice data transmission
 *
 *  @param aSessionId   Session ID
 */
- (void)pauseVoiceWithSession:(NSString *)aSessionId error:(EMError**)pError;

/*!
 *  Resume voice data transmission
 *
 *  @param aSessionId   Session ID
 */
- (void)resumeVoiceWithSession:(NSString *)aSessionId error:(EMError**)pError;

#pragma mark - video

/*!
 *  Start a video call session
 *
 *  @param aUsername        The callee
 *  @param aSuccessBlock    The callback block of completion
 *
 */
- (void)startVideoCall:(NSString *)aUsername
            completion:(void (^)(EMCallSession *aCallSession, EMError *aError))aCompletionBlock;

/*!
 * Suspend video data transmission
 *
 *  @param aSessionId   Session ID
 */
- (void)pauseVideoWithSession:(NSString *)aSessionId error:(EMError**)pError;

/*!
 *  Resume video data transmission
 *
 *  @param aSessionId   Session ID
 */
- (void)resumeVideoWithSession:(NSString *)aSessionId error:(EMError**)pError;

/*!
 *  Enable video adaptive, default is disable
 *
 *  @param isAdaptive   YES is enable, NO is disable
 */
- (void)enableAdaptiveBirateStreaming:(BOOL)isAdaptive;

#pragma mark - Deprecated methods

/*!
 *  Start a voice call session
 *
 *  @param aUsername  The callee
 *  @param pError     Error
 *
 *  @result Session instance
 */
- (EMCallSession *)makeVoiceCall:(NSString *)aUsername
                           error:(EMError **)pError __deprecated_msg("Use -startVoiceCall:completion:");

/*!
 *  Get video package lost rate
 *
 *  @param aSessionId   Session ID
 *  @param aIsSilence   Is Silence
 *
 *  @result             Error
 */
- (EMError *)markCallSession:(NSString *)aSessionId
                   isSilence:(BOOL)aIsSilence __deprecated_msg("Use -pauseVoiceWithSession:error:");


/*!
 *  Suspend voice data transmission
 *
 *  @param aSessionId   Session ID
 */
- (void)pauseVoiceTransfer:(NSString *)aSessionId __deprecated_msg("Use -pauseVoiceWithSession:error:");

/*!
 *  Resume voice data transmission
 *
 *  @param aSessionId   Session ID
 */
- (void)resumeVoiceTransfer:(NSString *)aSessionId __deprecated_msg("Use -resumeVoiceWithSession:error:");

/*!
 *  Start a video call session
 *
 *  @param aUsername  The callee
 *  @param pError     Error
 *
 *  @result Session instance
 */
- (EMCallSession *)makeVideoCall:(NSString *)aUsername
                           error:(EMError **)pError __deprecated_msg("Use -startVideoCall:completion:");

/*!
 * Suspend video data transmission
 *
 *  @param aSessionId   Session ID
 */
- (void)pauseVideoTransfer:(NSString *)aSessionId __deprecated_msg("Use -pauseVideoWithSession:error:");

/*!
 *  Resume video data transmission
 *
 *  @param aSessionId   Session ID
 */
- (void)resumeVideoTransfer:(NSString *)aSessionId __deprecated_msg("Use -resumeVideoWithSession:error:");

/*!
 * Suspend voice and video data transmission
 *
 *  @param aSessionId   Session ID
 */
- (void)pauseVoiceAndVideoTransfer:(NSString *)aSessionId __deprecated_msg("Delete");

/*!
 *  Resume voice and video data transmission
 *
 *  @param aSessionId   Session ID
 */
- (void)resumeVoiceAndVideoTransfer:(NSString *)aSessionId __deprecated_msg("Delete");

/*!
 *  Enable video adaptive, default is disable
 *
 *  @param aFlag   YES is enable, NO is disable
 */
- (void)setVideoAdaptive:(BOOL)aFlag  __deprecated_msg("Use -enableAdaptiveBirateStreaming:");

@end
