/*!
 *  @header EMCallOptions.h
 *  @abstract EMCallManager setting options
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMCallEnum.h"

@interface EMCallOptions : NSObject

/*!
 *  When remote is not online, whether to send offline push
 *  default NO
 */
@property (nonatomic, assign) BOOL isSendPushIfOffline;

/*!
 *  Only effective when isSendPushIfOffline is YES.
 *  default “You have incoming call...”
 */
@property (nonatomic, strong) NSString *offlineMessageText;

/*!
 *  Video resolution
 *  default adaptive
 */
@property (nonatomic, assign) EMCallVideoResolution videoResolution;

/*!
 *  Video kbps
 *  range 50 < videoKbps < 5000, default 0 , 0 means adaptive
 *  advice 0
 */
@property (nonatomic, assign) long videoKbps;

@end
