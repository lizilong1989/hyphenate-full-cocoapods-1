/*!
 *  @header EMCallSession.h
 *  @abstract Call session
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMCallLocalView.h"
#import "EMCallRemoteView.h"

/*!
 *  Call session status
 */
typedef enum{
    EMCallSessionStatusDisconnected = 0,    /*!  Disconnected */
    EMCallSessionStatusRinging,             /*!  Callee is Ringing */
    EMCallSessionStatusConnecting,          /*!  It's ready, wait to answer */
    EMCallSessionStatusConnected,           /*!  Connection is established */
    EMCallSessionStatusAccepted,            /*!  Accepted */
}EMCallSessionStatus;

/*!
 *  Call type
 */
typedef enum{
    EMCallTypeVoice = 0,    /*!  Voice call */
    EMCallTypeVideo,        /*!  Video call */
}EMCallType;

/*!
 *  Call end reason
 */
typedef enum{
    EMCallEndReasonHangup   = 0,    /*!  Another peer hang up */
    EMCallEndReasonNoResponse,      /*!  No response */
    EMCallEndReasonDecline,         /*!  Another peer declined the call */
    EMCallEndReasonBusy,            /*!  User is busy */
    EMCallEndReasonFailed,          /*!  Establish the call failed */
}EMCallEndReason;

/*!
 *  Connection type of the call
 */
typedef enum{
    EMCallConnectTypeNone = 0,  /*!  None */
    EMCallConnectTypeDirect,    /*!   Direct connect */
    EMCallConnectTypeRelay,     /*!  Relay connect */
}EMCallConnectType;


/*!
 *  Stream status
 */
typedef enum{
    EMCallStreamStatusVoicePause = 0,  /*!  Pause Voice */
    EMCallStreamStatusVoiceResume,     /*!  Resume Voice */
    EMCallStreamStatusVideoPause,      /*!  Pause Video */
    EMCallStreamStatusVideoResume,     /*!  Resume Video */
}EMCallStreamingStatus;

/*!
 *  Network status
 */
typedef enum{
    EMCallNetworkStatusNormal = 0,  /*!  Normal */
    EMCallNetworkStatusUnstable,    /*!  Unstable */
    EMCallNetworkStatusNoData,      /*!  No data */
}EMCallNetworkStatus;

/*!
 *  Call session
 */
@class EMError;
@interface EMCallSession : NSObject

/*!
 *  Unique session id
 */
@property (nonatomic, strong, readonly) NSString *sessionId;

/*!
 *  Local username
 */
@property (nonatomic, strong, readonly) NSString *username;

/*!
 *  The other side's username
 */
@property (nonatomic, strong, readonly) NSString *remoteUsername;

/*!
 *  Call type
 */
@property (nonatomic, readonly) EMCallType type;

/*!
 *  Connection type
 */
@property (nonatomic, readonly) EMCallConnectType connectType;

/*!
 *  Call session status
 */
@property (nonatomic, readonly) EMCallSessionStatus status;

/*!
 *  Local display view
 */
@property (nonatomic, strong) EMCallLocalView *localVideoView;

/*!
 *  Remote display view
 */
@property (nonatomic, strong) EMCallRemoteView *remoteVideoView;

/*!
 *  Set video bit rate, must set before start the session
 *
 *  Value is 150-1000, the default is 600
 */
@property (nonatomic) int videoBitrate;

/*!
 *  Get voice volume
 *
 *  @return Volume
 */
- (int)getVoiceVolume;

/*!
 *  Get video delay time, in milliseconds, it's real time changed
 *
 *  @result The delay time
 */
- (int)getVideoLatency;

/*!
 *  Get video frame rate, it's real time changed
 *
 *  @result The frame rate
 */
- (int)getVideoFrameRate;

/*!
 *  Get video package lost rate
 *
 *  @result Package lost rate
 */
- (int)getVideoLostRateInPercent;

/*!
 *  Get video width, fix size, it's not real time changed
 *
 *  @result Video width
 */
- (int)getVideoWidth;

/*!
 *  Get video height, fix size, it's not real time changed
 *
 *  @result Video height
 */
- (int)getVideoHeight;

/*!
 *  Get another peer's bitrate, it's real time changed
 *
 *  @result Another peer's bitrate
 */
- (int)getVideoRemoteBitrate;

/*!
 *  Get bitrate of video call, it's real time changed
 *
 *  @result Bitrate of video
 */
- (int)getVideoLocalBitrate;

/*!
 *  Get snapshot of video, only support jpeg format
 *
 *  @param aPath  Save path of picture
 */
- (void)screenCaptureToFilePath:(NSString *)aPath error:(EMError**)pError;

/*!
 *  Start recording video
 *
 *  @param aPath            File save path
 *  @param aError           The error
 *
 */
- (void)startVideoRecordingToFilePath:(NSString*)aPath
                                error:(EMError**)aError;

/*!
 *  Stop recording video
 *
 *  @param aError           The error
 *
 */
- (NSString *)stopVideoRecording:(EMError**)aError;

/*!
 *  Use front camera or back camera, default use front
 *
 *  @param  aIsFrontCamera    Weather use front camera, YES is front, NO is back
 */
- (void)switchCameraPosition:(BOOL)aIsFrontCamera;

#pragma mark - Deprecated methods

/*!
 *  Get video delay time, in milliseconds, it's real time changed
 *
 *  @result The delay time
 */
- (int)getVideoTimedelay __deprecated_msg("Use -getVideoLatency");

/*!
 *  Get video frame rate, it's real time changed
 *
 *  @result The frame rate
 */
- (int)getVideoFramerate __deprecated_msg("Use -getVideoFrameRate");

/*!
 *  Get video package lost rate
 *
 *  @result Package lost rate
 */
- (int)getVideoLostcnt __deprecated_msg("Use -getVideoLostRateInPercent");

/*!
 *  Get snapshot of video
 *
 *  @param aFullPath  Save path of picture
 */
- (void)takeRemotePicture:(NSString *)aFullPath __deprecated_msg("Use -screenCaptureToFilePath:");

/*!
 *  Start recording video
 *
 *  @param  aPath    File save path
 */
- (BOOL)startVideoRecord:(NSString*)aPath __deprecated_msg("Use startVideoRecordingToFilePath:error:");

/*!
 *  Stop recording video
 *
 *  @result path of record file
 */
- (NSString *)stopVideoRecord __deprecated_msg("Use -stopVideoRecording:");

/*!
 *  Use front camera or back camera,default use front
 *
 *  @param  isFont    Weather use front camera or not,Yes is Front,No is Back
 */
- (void)setCameraBackOrFront:(BOOL)isFont __deprecated_msg("Use -switchCameraPosition:");

@end

/*!
 *  Stream control
 */
typedef enum{
    EMCallStreamControlTypeVoicePause __deprecated_msg("Use EMCallStreamStatusVoicePause") = 0,  /*!  Pause Voice */
    EMCallStreamControlTypeVoiceResume __deprecated_msg("Use EMCallStreamStatusVoiceResume"),     /*!  Resume Voice */
    EMCallStreamControlTypeVideoPause __deprecated_msg("Use EMCallStreamStatusVideoPause"),      /*!  Pause Video */
    EMCallStreamControlTypeVideoResume __deprecated_msg("Use EMCallStreamStatusVideoResume"),     /*!  Resume Video */
}EMCallStreamControlType __deprecated_msg("Use EMCallStreamingStatus");

