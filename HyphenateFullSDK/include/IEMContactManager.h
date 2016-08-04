/*!
 *  @header IEMContactManager.h
 *  @abstract This protocol defined the operations of contact
 *  @author Hyphenate
 *  @version 3.00
 */

#import <Foundation/Foundation.h>

#import "EMContactManagerDelegate.h"

@class EMError;

/*!
 *  Operations of contact
 */
@protocol IEMContactManager <NSObject>

@required

#pragma mark - Delegate

/*!
 *  Add delegate
 *
 *  @param aDelegate  Delegate
 *  @param aQueue     The queue of call delegate method
 */
- (void)addDelegate:(id<EMContactManagerDelegate>)aDelegate
      delegateQueue:(dispatch_queue_t)aQueue;

/*!
 *  Add delegate
 *
 *  @param aDelegate  Delegate
 */
- (void)addDelegate:(id<EMContactManagerDelegate>)aDelegate;

/*!
 *  Remove delegate
 *
 *  @param aDelegate  Delegate
 */
- (void)removeDelegate:(id)aDelegate;

/*!
 *  Get all friends from memory
 *
 *  @result Contact list<EMGroup>
 */
- (NSArray *)getContacts;

/*!
 *  Get the blacklist from memory
 *
 *  @result Blacklist<EMGroup>
 */
- (NSArray *)getBlackList;

#pragma mark - Sync method

/*!
 *  Get all the friends from the server
 *
 *  Synchronization method will block the current thread
 *
 *  @param pError Error
 *
 *  @return Contact list<NSString>
 */
- (NSArray *)getContactsFromServerWithError:(EMError **)pError;

/*!
 *  Add a contact
 *
 *  Synchronization method will block the current thread
 *
 *  @param aUsername  The user to add
 *  @param aMessage   Friend invitation message
 *
 *  @return Error
 */
- (EMError *)addContact:(NSString *)aUsername
                message:(NSString *)aMessage;

/*!
 *  Delete friend
 *
 *  Synchronization method will block the current thread
 *
 *  @param aUsername The user to delete
 *
 *  @return Error
 */
- (EMError *)deleteContact:(NSString *)aUsername;

#pragma mark - Black List

/*!
 *  Get the blacklist from the server
 *
 *  Synchronization method will block the current thread
 *
 *  @param pError Error
 *
 *  @return Blacklist<NSString>
 */
- (NSArray *)getBlackListFromServerWithError:(EMError **)pError;

/*!
 *  Add user to blacklist
 *
 *  Synchronization method will block the current thread
 *
 *  @param aUsername The user to add
 *  @param aBoth     Whether block messages from me to the user which is added to the black list
 *
 *  @return Error
 */
- (EMError *)addUserToBlackList:(NSString *)aUsername
               relationshipBoth:(BOOL)aBoth;

/*!
 *  Remove user from blacklist
 *
 *  Synchronization method will block the current thread
 *
 *  @param aUsername The user to remove from blacklist
 *
 *  @return Error
 */
- (EMError *)removeUserFromBlackList:(NSString *)aUsername;

/*!
 *  Agree invitation
 *
 *  Synchronization method will block the current thread
 *
 *  @param aUsername Applicants
 *
 *  @return Error
 */
- (EMError *)acceptInvitationForUsername:(NSString *)aUsername;

/*!
 *  Decline invitation
 *
 *  Synchronization method will block the current thread
 *
 *  @param aUsername Applicants
 *
 *  @return Error
 */
- (EMError *)declineInvitationForUsername:(NSString *)aUsername;

#pragma mark - Async method

/*!
 *  Get all the friends from the server
 *
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)getContactsFromServerWithCompletion:(void (^)(NSArray *aList, EMError *aError))aCompletionBlock;

/*!
 *  Add a contact
 *
 *  @param aUsername        The user to add
 *  @param aMessage         Friend invitation message
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)addContact:(NSString *)aUsername
           message:(NSString *)aMessage
        completion:(void (^)(NSString *aUsername, EMError *aError))aCompletionBlock;

/*!
 *  Delete friend
 *
 *  @param aUsername        The user to delete
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)deleteContact:(NSString *)aUsername
           completion:(void (^)(NSString *aUsername, EMError *aError))aCompletionBlock;

/*!
 *  Get the blacklist from the server
 *
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)getBlackListFromServerWithCompletion:(void (^)(NSArray *aList, EMError *aError))aCompletionBlock;

/*!
 *  Add user to blacklist
 *
 *  @param aUsername        The user to add
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)addUserToBlackList:(NSString *)aUsername
                completion:(void (^)(NSString *aUsername, EMError *aError))aCompletionBlock;

/*!
 *  Remove user from blacklist
 *
 *  @param aUsername        The user to remove from blacklist
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)removeUserFromBlackList:(NSString *)aUsername
                     completion:(void (^)(NSString *aUsername, EMError *aError))aCompletionBlock;

/*!
 *  Agree invitation
 *
 *  @param aUsername        Applicants
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)approveFriendRequestFromUser:(NSString *)aUsername
                          completion:(void (^)(NSString *aUsername, EMError *aError))aCompletionBlock;

/*!
 *  Decline invitation
 *
 *  @param aUsername        Applicants
 *  @param aCompletionBlock The callback block of completion
 *
 */
- (void)declineFriendRequestFromUser:(NSString *)aUsername
                          completion:(void (^)(NSString *aUsername, EMError *aError))aCompletionBlock;

#pragma mark - Deprecated methods

/*!
 *  Get all the friends from the DB
 *
 *  @return Contact list<NSString>
 */
- (NSArray *)getContactsFromDB __deprecated_msg("Use -getContacts");

/*!
 *  Get the blacklist from the DB
 *
 *  @return Blacklist<NSString>
 */
- (NSArray *)getBlackListFromDB __deprecated_msg("Use -getBlackList");

/*!
 *  Get all the friends from the server
 *
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncGetContactsFromServer:(void (^)(NSArray *aList))aSuccessBlock
                           failure:(void (^)(EMError *aError))aFailureBlock __deprecated_msg("Use -getContactsFromServerWithCompletion:");

/*!
 *  Add a contact
 *
 *  @param aUsername        The user to add
 *  @param aMessage         Friend invitation message
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncAddContact:(NSString *)aUsername
                message:(NSString *)aMessage
                success:(void (^)())aSuccessBlock
                failure:(void (^)(EMError *aError))aFailureBlock __deprecated_msg("Use -addContact:message:completion:");

/*!
 *  Delete friend
 *
 *  @param aUsername        The user to delete
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncDeleteContact:(NSString *)aUsername
                   success:(void (^)())aSuccessBlock
                   failure:(void (^)(EMError *aError))aFailureBlock __deprecated_msg("Use -deleteContact:completion:");

/*!
 *  Get the blacklist from the server
 *
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncGetBlackListFromServer:(void (^)(NSArray *aList))aSuccessBlock
                            failure:(void (^)(EMError *aError))aFailureBlock __deprecated_msg("Use -getBlackListFromServerWithCompletion:");

/*!
 *  Add user to blacklist
 *
 *  @param aUsername        The user to add
 *  @param aBoth            Whether block messages from me to the user which is added to the black list
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncAddUserToBlackList:(NSString *)aUsername
               relationshipBoth:(BOOL)aBoth
                        success:(void (^)())aSuccessBlock
                        failure:(void (^)(EMError *aError))aFailureBlock __deprecated_msg("Use -addUserToBlackList:completion:");

/*!
 *  Remove user from blacklist
 *
 *  @param aUsername        The user to remove from blacklist
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncRemoveUserFromBlackList:(NSString *)aUsername
                             success:(void (^)())aSuccessBlock
                             failure:(void (^)(EMError *aError))aFailureBlock __deprecated_msg("Use -removeUserFromBlackList:completion:");

/*!
 *  Agree invitation
 *
 *  @param aUsername        Applicants
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncAcceptInvitationForUsername:(NSString *)aUsername
                                 success:(void (^)())aSuccessBlock
                                 failure:(void (^)(EMError *aError))aFailureBlock __deprecated_msg("Use -approveFriendRequestFromUser:completion:");

/*!
 *  Decline invitation
 *
 *  @param aUsername        Applicants
 *  @param aSuccessBlock    The callback block of success
 *  @param aFailureBlock    The callback block of failure
 *
 */
- (void)asyncDeclineInvitationForUsername:(NSString *)aUsername
                                  success:(void (^)())aSuccessBlock
                                  failure:(void (^)(EMError *aError))aFailureBlock __deprecated_msg("Use -declineFriendRequestFromUser:completion:");
@end
