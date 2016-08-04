/*!
 *  @header EMChatroom.h
 *  @abstract Chatroom
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

/*!
 *  Chatroom
 */
@interface EMChatroom : NSObject

/*!
 *  Chatroom id
 */
@property (nonatomic, copy, readonly) NSString *chatroomId;

/*!
 *  Subject of chatroom
 */
@property (nonatomic, copy, readonly) NSString *subject;

/*!
 *  Description of chatroom
 */
@property (nonatomic, copy, readonly) NSString *description;

/*!
 *  Chatroom‘s owner, need to fetch chatroom's specification
 *
 *  A chatroom only has one owner
 */
@property (nonatomic, copy, readonly) NSString *owner;

/*!
 *  The current number of members, will return 0 if have not ever fetched chatroom's specification
 */
@property (nonatomic, readonly) NSInteger occupantsCount __deprecated_msg("Use - membersCount");
@property (nonatomic, readonly) NSInteger membersCount;

/*!
 *  The maximum number of members, will return 0 if have not ever fetched chatroom's specification
 */
@property (nonatomic, readonly) NSInteger maxOccupantsCount __deprecated_msg("Use - membersCount");
@property (nonatomic, readonly) NSInteger maxMembersCount;

/*!
 *  Member list of chatroom, need to fetch chatroom's specification
 */
@property (nonatomic, copy, readonly) NSArray *occupants __deprecated_msg("Use - members");
@property (nonatomic, copy, readonly) NSArray *members;

/*!
 *  Initialize chatroom instance
 *
 *  Please use [+chatroomWithId:]
 *
 *  @result nil
 */
- (instancetype)init __deprecated_msg("Use +chatroomWithId:");

/*!
 *  Create chatroom instance
 *
 *  @param aChatroomId   Chatroom id
 *
 *  @result Chatroom instance
 */
+ (instancetype)chatroomWithId:(NSString *)aChatroomId;

@end
