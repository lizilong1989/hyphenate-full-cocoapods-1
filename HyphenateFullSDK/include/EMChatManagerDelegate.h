/*!
 *  @header EMChatManagerDelegate.h
 *  @abstract This protocol defined the callbacks of chat
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

@class EMMessage;
@class EMError;

/*!
 *  Chat related callbacks
 */
@protocol EMChatManagerDelegate <NSObject>

@optional

#pragma mark - Conversation

/*!
 *  The conversation list has changed
 *
 *  @param aConversationList  Conversation list<EMConversation>
 */
- (void)conversationListDidUpdate:(NSArray *)aConversationList;

#pragma mark - Message

/*!
 *  Received messages
 *
 *  @param aMessages  Message list<EMMessage>
 */
- (void)messagesDidReceive:(NSArray *)aMessages;

/*!
 *  Received cmd messages
 *
 *  @param aCmdMessages  Cmd message list<EMMessage>
 */
- (void)cmdMessagesDidReceive:(NSArray *)aCmdMessages;

/*!
 *  Received read acks
 *
 *  @param aMessages  Read acked message list<EMMessage>
 */
- (void)messagesDidRead:(NSArray *)aMessages;

/*!
 *  Received deliver acks
 *
 *  @param aMessages  Deliver acked message list<EMMessage>
 */
- (void)messagesDidDeliver:(NSArray *)aMessages;

/*!
 *  Message status has changed
 *
 *  @param aMessage  Message whose status changed
 *  @param aError    Error info
 */
- (void)messageStatusDidChange:(EMMessage *)aMessage
                         error:(EMError *)aError;

/*!
 *  Attachment status has changed
 *
 *  @param aMessage  Message whose attachment status changed
 *  @param aError    Error
 */
- (void)messageAttachmentStatusDidChange:(EMMessage *)aMessage
                                   error:(EMError *)aError;

#pragma mark - Deprecated methods

/*!
 *  The conversation list has changed
 *
 *  @param aConversationList  Conversation list<EMConversation>
 */
- (void)didUpdateConversationList:(NSArray *)aConversationList __deprecated_msg("Use -conversationListDidUpdate:");

/*!
 *  Received messages
 *
 *  @param aMessages  Message list<EMMessage>
 */
- (void)didReceiveMessages:(NSArray *)aMessages __deprecated_msg("Use -messagesDidReceive:");

/*!
 *  Received cmd messages
 *
 *  @param aCmdMessages  Cmd message list<EMMessage>
 */
- (void)didReceiveCmdMessages:(NSArray *)aCmdMessages __deprecated_msg("Use -cmdMessagesDidReceive:");

/*!
 *  Received read acks
 *
 *  @param aMessages  Read acked message list<EMMessage>
 */
- (void)didReceiveHasReadAcks:(NSArray *)aMessages __deprecated_msg("Use -messagesDidRead:");

/*!
 *  Received deliver acks
 *
 *  @param aMessages  Deliver acked message list<EMMessage>
 */
- (void)didReceiveHasDeliveredAcks:(NSArray *)aMessages __deprecated_msg("Use -messagesDidDeliver:");

/*!
 *  Message status has changed
 *
 *  @param aMessage  Message whose status changed
 *  @param aError    Error info
 */
- (void)didMessageStatusChanged:(EMMessage *)aMessage
                          error:(EMError *)aError __deprecated_msg("Use -messageStatusDidChange:error");

/*!
 *  Attachment status has changed
 *
 *  @param aMessage  Message whose attachment status changed
 *  @param aError    Error
 */
- (void)didMessageAttachmentsStatusChanged:(EMMessage *)aMessage
                                     error:(EMError *)aError __deprecated_msg("Use -messageAttachmentStatusDidChange:error");
@end
