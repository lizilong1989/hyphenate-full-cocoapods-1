/*!
 *  @header IEMChatroomManager.h
 *  @abstract This protocol defined the chatroom operations
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMChatroomManagerDelegate.h"
#import "EMChatroom.h"

@class EMError;

/*!
 *  Chatroom operations
 */
@protocol IEMChatroomManager <NSObject>

@required

#pragma mark - Delegate

/*!
 *  Add delegate
 *
 *  @param aDelegate  Delegate
 *  @param aQueue     The queue of call delegate method
 */
- (void)addDelegate:(id<EMChatroomManagerDelegate>)aDelegate
      delegateQueue:(dispatch_queue_t)aQueue;

/*!
 *  Add delegate
 *
 *  @param aDelegate  Delegate
 */
- (void)addDelegate:(id<EMChatroomManagerDelegate>)aDelegate;

/*!
 *  Remove delegate
 *
 *  @param aDelegate  Delegate
 */
- (void)removeDelegate:(id<EMChatroomManagerDelegate>)aDelegate;

#pragma mark - Sync method

/*!
 *  Get all the chatrooms from server
 *
 *  Synchronization method will block the current thread
 *
 *  @param pError   Error
 *
 *  @return Chat room list<EMChatroom>
 */
- (NSArray *)getAllChatroomsFromServerWithError:(EMError **)pError;

/*!
 *  Join a chatroom
 *
 *  Synchronization method will block the current thread
 *
 *  @param aChatroomId  Chatroom id
 *  @param pError       Error
 *
 *  @result Joined chatroom
 */
- (EMChatroom *)joinChatroom:(NSString *)aChatroomId
                       error:(EMError **)pError;

/*!
 *  Leave a chatroom
 *
 *  Synchronization method will block the current thread
 *
 *  @param aChatroomId  Chatroom id
 *  @param pError       Error
 *
 *  @result Leaved chatroom
 */
- (EMChatroom *)leaveChatroom:(NSString *)aChatroomId
                        error:(EMError **)pError;

/*!
 *  Fetch chatroom's specification
 *
 *  Synchronization method, will block the current thread
 *
 *  @param aChatroomId           Chatroom id
 *  @param aIncludeMembersList   Whether get member list
 *  @param pError                Error
 *
 *  @return    Chatroom instance
 */
- (EMChatroom *)fetchChatroomInfo:(NSString *)aChatroomId
               includeMembersList:(BOOL)aIncludeMembersList
                            error:(EMError **)pError;

#pragma mark - Async method

/*!
 *  Get all the chatrooms from server
 *
 *  @param aCompletionBlock     The callback block of completion
 *
 */
- (void)getAllChatroomsFromServerWithCompletion:(void (^)(NSArray *aList, EMError *aError))aCompletionBlock;

/*!
 *  Join a chatroom
 *
 *  @param aChatroomId      Chatroom id
 *  @param aCompletionBlock     The callback block of completion
 *
 */
- (void)joinChatroom:(NSString *)aChatroomId
          completion:(void (^)(EMChatroom *aChatroom, EMError *aError))aCompletionBlock;

/*!
 *  Leave a chatroom
 *
 *  @param aChatroomId      Chatroom id
 *  @param aCompletionBlock     The callback block of completion
 *
 */
- (void)leaveChatroom:(NSString *)aChatroomId
           completion:(void (^)(EMChatroom *aChatroom, EMError *aError))aCompletionBlock;

/*!
 *  Fetch chatroom's specification
 *
 *  @param aChatroomId           Chatroom id
 *  @param aIncludeMembersList   Whether get member list
 *  @param aCompletionBlock      The callback block of completion
 *
 */
- (void)getChatroomSpecificationFromServerByID:(NSString *)aChatroomId
                            includeMembersList:(BOOL)aIncludeMembersList
                                    completion:(void (^)(EMChatroom *aChatroom, EMError *aError))aCompletionBlock;

#pragma mark - Deprecated methods

/*!
 *  Get all the chatrooms from server
 *
 *  @param aSuccessBlock         The callback block of success
 *  @param aFailureBlock         The callback block of failure
 *
 */
- (void)asyncGetAllChatroomsFromServer:(void (^)(NSArray *aList))aSuccessBlock
                               failure:(void (^)(EMError *aError))aFailureBlock __deprecated_msg("Use -getAllChatroomsFromServerWithCompletion:");

/*!
 *  Join a chatroom
 *
 *  @param aChatroomId      Chatroom id
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncJoinChatroom:(NSString *)aChatroomId
                  success:(void (^)(EMChatroom *aRoom))aSuccessBlock
                  failure:(void (^)(EMError *aError))aFailureBlock __deprecated_msg("Use -joinChatroom:completion:");

/*!
 *  Leave a chatroom
 *
 *  @param aChatroomId      Chatroom id
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 *  @result Leaved chatroom
 */
- (void)asyncLeaveChatroom:(NSString *)aChatroomId
                   success:(void (^)(EMChatroom *aRoom))aSuccessBlock
                   failure:(void (^)(EMError *aError))aFailureBlock __deprecated_msg("Use -leaveChatroom:completion:");

/*!
 *  Fetch chatroom's specification
 *
 *  @param aChatroomId           Chatroom id
 *  @param aIncludeMembersList   Whether get member list
 *  @param aSuccessBlock         The callback block of success
 *  @param aFailureBlock         The callback block of failure
 *
 */
- (void)asyncFetchChatroomInfo:(NSString *)aChatroomId
            includeMembersList:(BOOL)aIncludeMembersList
                       success:(void (^)(EMChatroom *aChatroom))aSuccessBlock
                       failure:(void (^)(EMError *aError))aFailureBlock __deprecated_msg("Use -getChatroomSpecificationFromServerByID:includeMembersList:completion:");
@end
