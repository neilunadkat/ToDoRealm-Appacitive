//
//  APUser.h
//  Appacitive-iOS-SDK
//
//  Created by Kauserali on 07/01/13.
//  Copyright (c) 2013 Appacitive Software Pvt. Ltd. All rights reserved.
//

#import "APResponseBlocks.h"
#import "APObject.h"

/**
 An APUser is a user registerd for using your app. This class helps you to manage the details of the users of your app.
 */

@interface APUser : APObject <APObjectPropertyMapping, NSCoding>

@property (nonatomic, strong, readonly) NSString *userToken;
@property (nonatomic, readonly) BOOL loggedInWithFacebook;
@property (nonatomic, readonly) BOOL loggedInWithTwitter;

@property (nonatomic, strong) NSString *username;
@property (nonatomic, strong) NSString *password;
@property (nonatomic, strong) NSString *birthDate;
@property (nonatomic, strong) NSString *firstName;
@property (nonatomic, strong) NSString *lastName;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *location;
@property (nonatomic, strong) NSString *phone;
@property (nonatomic, strong) NSString *isEmailVerified;
@property (nonatomic, strong) NSString *isEnabled;
@property (nonatomic, strong) NSString *isOnline;

/** @name Initializing an APUser instance */

- (instancetype)init;

/** @name Setting/Getting the currentUser instance */
 
/**
 Returns the current authenticated user.
 
 @return APUser or nil
 */
+ (APUser*)currentUser;

/** @name Authenticating APUser */

/**
 @see authenticateUserWithUsername:password:sessionExpiresAfter:limitAPICallsTo:successHandler:failureHandler:
 */
+ (void) authenticateUserWithUsername:(NSString*)username password:(NSString*)password sessionExpiresAfter:(NSNumber*)minutes limitAPICallsTo:(NSNumber*)calls;

/**
 @see authenticateUserWithUsername:password:sessionExpiresAfter:limitAPICallsTo:successHandler:failureHandler:
 */
+ (void) authenticateUserWithUsername:(NSString*)username password:(NSString*)password sessionExpiresAfter:(NSNumber*)minutes limitAPICallsTo:(NSNumber*)calls failureHandler:(APFailureBlock)failureBlock;

/**
 Method to authenticate a user
 
 If successful the currentUser is set to the authenticated user.
 
 @param username The username of the user to authenticate.
 @param password The password of the user to authenticate.
 @param minutes Timeout for token in minutes.
 @param calls The number of API calls that can be made using the authentication token.
 @param successBlock Block invoked when authentication is successful.
 @param failureBlock Block invoked when authentication is unsuccessful.
 */
+ (void) authenticateUserWithUsername:(NSString*)username password:(NSString*)password sessionExpiresAfter:(NSNumber*)minutes limitAPICallsTo:(NSNumber*)calls successHandler:(APUserSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see authenticateUserWithFacebook:signUp:sessionExpiresAfter:limitAPICallsTo:successHandler:failureHandler:
 */
+(void) authenticateUserWithFacebook:(NSString *) accessToken signUp:(BOOL)signUp;


/**
 @see authenticateUserWithFacebook:signUp:sessionExpiresAfter:limitAPICallsTo:successHandler:failureHandler:
 */
+(void) authenticateUserWithFacebook:(NSString *) accessToken signUp:(BOOL)signUp successHandler:(APUserSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see authenticateUserWithFacebook:signUp:sessionExpiresAfter:limitAPICallsTo:successHandler:failureHandler:
 */
+(void) authenticateUserWithFacebook:(NSString *) accessToken signUp:(BOOL)signUp failureHandler:(APFailureBlock)failureBlock;

/**
 @see authenticateUserWithFacebook:signUp:sessionExpiresAfter:limitAPICallsTo:successHandler:failureHandler:
 */
+ (void) authenticateUserWithFacebook:(NSString *)accessToken signUp:(BOOL)signUp sessionExpiresAfter:(NSNumber*)minutes limitAPICallsTo:(NSNumber*)calls;


/**
 @see authenticateUserWithFacebook:signUp:sessionExpiresAfter:limitAPICallsTo:successHandler:failureHandler:
 */
+ (void) authenticateUserWithFacebook:(NSString *)accessToken signUp:(BOOL)signUp sessionExpiresAfter:(NSNumber*)minutes limitAPICallsTo:(NSNumber*)calls failureHandler:(APFailureBlock)failureBlock;

/**
 Method to authenticate a user with facebook.
 
 If successful the currentUser is set to the authenticated user.
 
 @param accessToken The access token retrieved after a successful facebook login.
 @param signUp Should create a new user in case the user does not exist on Appacitive.
 @param minutes Timeout for token in minutes.
 @param calls The number of API calls that can be made using the authentication token.
 @param successBlock Block invoked when authentication with facebook is successful.
 @param failureBlock Block invoked when authentication with facebook is unsuccessful.
 */
+ (void) authenticateUserWithFacebook:(NSString *)accessToken signUp:(BOOL)signUp sessionExpiresAfter:(NSNumber*)minutes limitAPICallsTo:(NSNumber*)calls successHandler:(APUserSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see authenticateUserWithTwitter:oauthSecret:signUp:sessionExpiresAfter:limitAPICallsTo:successHandler:failureHandler:
 */
+ (void) authenticateUserWithTwitter:(NSString*)oauthToken oauthSecret:(NSString*)oauthSecret signUp:(BOOL)signUp;

/**
 @see authenticateUserWithTwitter:oauthSecret:signUp:sessionExpiresAfter:limitAPICallsTo:successHandler:failureHandler:
 */
+ (void) authenticateUserWithTwitter:(NSString*)oauthToken oauthSecret:(NSString*)oauthSecret signUp:(BOOL)signUp failureHandler:(APFailureBlock)failureHandler;

/**
 @see authenticateUserWithTwitter:oauthSecret:signUp:sessionExpiresAfter:limitAPICallsTo:successHandler:failureHandler:
 */
+ (void) authenticateUserWithTwitter:(NSString*)oauthToken oauthSecret:(NSString*)oauthSecret signUp:(BOOL)signUp successHandler:(APUserSuccessBlock)successBlock failureHandler:(APFailureBlock)failureHandler;


/**
 @see authenticateUserWithTwitter:oauthSecret:signUp:sessionExpiresAfter:limitAPICallsTo:successHandler:failureHandler:
 */
+ (void) authenticateUserWithTwitter:(NSString*)oauthToken oauthSecret:(NSString*)oauthSecret signUp:(BOOL)signUp sessionExpiresAfter:(NSNumber*)minutes limitAPICallsTo:(NSNumber*)calls;


/**
 @see authenticateUserWithTwitter:oauthSecret:signUp:sessionExpiresAfter:limitAPICallsTo:successHandler:failureHandler:
 */
+ (void) authenticateUserWithTwitter:(NSString*)oauthToken oauthSecret:(NSString*)oauthSecret signUp:(BOOL)signUp sessionExpiresAfter:(NSNumber*)minutes limitAPICallsTo:(NSNumber*)calls failureHandler:(APFailureBlock)failureHandler;

/**
 Method to authenticate a user with Twitter.
 
 If successful the currentUser is set to the authenticated user.
 
 @param oauthToken The oauth token retrieved after twitter login.
 @param oauthSecret The oauth secret.
 @param minutes Timeout for token in minutes.
 @param calls The number of API calls that can be made using the authentication token.
 @param successBlock Block invoked when login with twitter is successful.
 @param failureBlock Block invoked when login with twitter is unsuccessful.
 */
+ (void) authenticateUserWithTwitter:(NSString*)oauthToken oauthSecret:(NSString*)oauthSecret signUp:(BOOL)signUp sessionExpiresAfter:(NSNumber*)minutes limitAPICallsTo:(NSNumber*)calls successHandler:(APUserSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see authenticateUserWithTwitter:oauthSecret:consumerKey:consumerSecret:signUp:sessionExpiresAfter:limitAPICallsTo:successHandler:failureHandler:
 */
+ (void) authenticateUserWithTwitter:(NSString *)oauthToken oauthSecret:(NSString *)oauthSecret consumerKey:(NSString*)consumerKey consumerSecret:(NSString*)consumerSecret signUp:(BOOL)signUp;

/**
 @see authenticateUserWithTwitter:oauthSecret:consumerKey:consumerSecret:signUp:sessionExpiresAfter:limitAPICallsTo:successHandler:failureHandler:
 */
+ (void) authenticateUserWithTwitter:(NSString *)oauthToken oauthSecret:(NSString *)oauthSecret consumerKey:(NSString*)consumerKey consumerSecret:(NSString*)consumerSecret signUp:(BOOL)signUp failureHandler:(APFailureBlock)failureBlock;

/**
 @see authenticateUserWithTwitter:oauthSecret:consumerKey:consumerSecret:signUp:sessionExpiresAfter:limitAPICallsTo:successHandler:failureHandler:
 */
+ (void) authenticateUserWithTwitter:(NSString *)oauthToken oauthSecret:(NSString *)oauthSecret consumerKey:(NSString*)consumerKey consumerSecret:(NSString*)consumerSecret signUp:(BOOL)signUp successHandler:(APUserSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see authenticateUserWithTwitter:oauthSecret:consumerKey:consumerSecret:signUp:sessionExpiresAfter:limitAPICallsTo:successHandler:failureHandler:
 */
+ (void) authenticateUserWithTwitter:(NSString *)oauthToken oauthSecret:(NSString *)oauthSecret consumerKey:(NSString*)consumerKey consumerSecret:(NSString*)consumerSecret signUp:(BOOL)signUp sessionExpiresAfter:(NSNumber*)minutes limitAPICallsTo:(NSNumber*)calls;

/**
 @see authenticateUserWithTwitter:oauthSecret:consumerKey:consumerSecret:signUp:sessionExpiresAfter:limitAPICallsTo:successHandler:failureHandler:
 */
+ (void) authenticateUserWithTwitter:(NSString *)oauthToken oauthSecret:(NSString *)oauthSecret consumerKey:(NSString*)consumerKey consumerSecret:(NSString*)consumerSecret signUp:(BOOL)signUp sessionExpiresAfter:(NSNumber*)minutes limitAPICallsTo:(NSNumber*)calls failureHandler:(APFailureBlock)failureBlock;

/**
 Method to authenticate a user with Twitter.
 
 If successful the currentUser is set to the authenticated user.
 
 @param oauthToken The oauth token retrieved after twitter login.
 @param oauthSecret The oauth secret.
 @param consumerKey The consumer key of the application created on twitter.
 @param consumerSecret The consumer secret of the application created on twitter.
 @param minutes Timeout for token in minutes.
 @param calls The number of API calls that can be made using the authentication token.
 @param successBlock Block invoked when authentication with twitter is successful.
 @param failureBlock Block invoked when authentication with twitter is unsuccessful.
 */
+ (void) authenticateUserWithTwitter:(NSString *)oauthToken oauthSecret:(NSString *)oauthSecret consumerKey:(NSString*)consumerKey consumerSecret:(NSString*)consumerSecret signUp:(BOOL)signUp sessionExpiresAfter:(NSNumber*)minutes limitAPICallsTo:(NSNumber*)calls successHandler:(APUserSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Linking external identities with APUser */

/**
 @see linkFacebookAccountWithAccessToken:successHandler:failureHandler:
 */
- (void) linkFacebookAccountWithAccessToken:(NSString*)facebookAcessToken;

/**
 @see linkFacebookAccountWithAccessToken:successHandler:failureHandler:
 */
- (void) linkFacebookAccountWithAccessToken:(NSString*)facebookAcessToken failureHandler:(APFailureBlock)failureBlock;

/**
 Method to link a user's account to his Facebook account.
 
 @param facebookAcessToken user's access token obtained from facebook.
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation is unsuccessful.
 */
- (void) linkFacebookAccountWithAccessToken:(NSString*)facebookAcessToken successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see linkTwitterAccountWithOauthToken:oauthSecret:successHandler:failureHandler:
 */
- (void) linkTwitterAccountWithOauthToken:(NSString*)oauthToken oauthSecret:(NSString*)oauthSecret;

/**
 @see linkTwitterAccountWithOauthToken:oauthSecret:successHandler:failureHandler:
 */
- (void) linkTwitterAccountWithOauthToken:(NSString*)oauthToken oauthSecret:(NSString*)oauthSecret failureHandler:(APFailureBlock)failureBlock;

/**
 Method to link a user's account to his Twitter account.
 
 @param oauthToken The oauth token retrieved after twitter login.
 @param oauthSecret The oauth secret.
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation is unsuccessful.
 */
- (void) linkTwitterAccountWithOauthToken:(NSString*)oauthToken oauthSecret:(NSString*)oauthSecret successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see linkTwitterAccountWithOauthToken:oauthSecret:consumerKey:consumerSecret:successHandler:failureHandler:
 */
- (void) linkTwitterAccountWithOauthToken:(NSString*)oauthToken oauthSecret:(NSString*)oauthSecret consumerKey:(NSString*)consumerKey consumerSecret:(NSString*)consumerSecret;

/**
 @see linkTwitterAccountWithOauthToken:oauthSecret:consumerKey:consumerSecret:successHandler:failureHandler:
 */
- (void) linkTwitterAccountWithOauthToken:(NSString*)oauthToken oauthSecret:(NSString*)oauthSecret consumerKey:(NSString*)consumerKey consumerSecret:(NSString*)consumerSecret failureHandler:(APFailureBlock)failureBlock;

/**
 Method to link a user's account to his Twitter account.
 @param oauthToken The oauth token retrieved after twitter login.
 @param oauthSecret The oauth secret.
 @param consumerKey The consumer key of the application created on twitter.
 @param consumerSecret The consumer secret of the application created on twitter.
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation is unsuccessful.
 */
- (void) linkTwitterAccountWithOauthToken:(NSString*)oauthToken oauthSecret:(NSString*)oauthSecret consumerKey:(NSString*)consumerKey consumerSecret:(NSString*)consumerSecret successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Delinking external identities from APUser */

/**
 @see delinkAccountWithServiceName:successHandler:failureHandler:
 */
- (void) delinkAccountWithServiceName:(NSString*)serviceName;

/**
 @see delinkAccountWithServiceName:successHandler:failureHandler:
 */
- (void) delinkAccountWithServiceName:(NSString*)serviceName failureHandler:(APFailureBlock)failureBlock;

/**
 Method to delink a user's account from his Twitter or Facebook account.
 
 @param serviceName name of the service whose account needs to be delinked eg: @"facebook" OR @"twitter"
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation is unsuccessful.
 */
- (void) delinkAccountWithServiceName:(NSString*)serviceName successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Fetching linked external identities of an APUser */

/**
 @see getLinkedAccountWithServiceName:successHandler:failureHandler:
 */
- (void) getLinkedAccountWithServiceName:(NSString*)serviceName successHandler:(APResultSuccessBlock)successBlock;

/**
 Method to fetch a user's linked account.
 
 @param serviceName name of the service whose linked account needs to be fetched eg: @"facebook" OR @"twitter"
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation is unsuccessful.
 */
- (void) getLinkedAccountWithServiceName:(NSString*)serviceName successHandler:(APResultSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see getAllLinkedAccountsWithSuccessHandler:failureHandler:
 */
- (void) getAllLinkedAccountsWithSuccessHandler:(APResultSuccessBlock)successBlock;

/**
 Method to fetch all of the user's linked accounts.
 
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation is unsuccessful.
 */

- (void) getAllLinkedAccountsWithSuccessHandler:(APResultSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Creating APUser */

/**
 @see createUserWithSuccessHandler:failureHandler:
 */
- (void) createUser;

/**
 @see createUserWithSuccessHandler:failureHandler:
 */
- (void) createUserWithSuccessHandler:(APSuccessBlock)successBlock;

/**
 Method to create a new user
 
 If successful the an object of APUser is returned in the successBlock.
 
 @note This method does not set the current user as the new user.
 
 @param successBlock Block invoked when the create request is successful.
 @param failureBlock Block invoked when the create request is unsuccessful.
 */
- (void) createUserWithSuccessHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see createUserWithFacebook:successHandler:failureHandler:
 */
- (void) createUserWithFacebook:(NSString*)token;

/**
 @see createUserWithFacebook:successHandler:failureHandler:
 */
- (void) createUserWithFacebook:(NSString*)token failureHandler:(APFailureBlock)failureBlock;

/**
 Method to create a user with Facebook.
 
 @param token The access token retrieved after a successful facebook login.
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation is unsuccessful.
 */
- (void) createUserWithFacebook:(NSString*)token successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see createUserWithTwitter:oauthSecret:consumerKey:consumerSecret:successHandler:failureHandler:
 */
- (void) createUserWithTwitter:(NSString*)oauthToken oauthSecret:(NSString *)oauthSecret consumerKey:(NSString*)consumerKey consumerSecret:(NSString*)consumerSecret;

/**
 @see createUserWithTwitter:oauthSecret:consumerKey:consumerSecret:successHandler:failureHandler:
 */
- (void) createUserWithTwitter:(NSString*)oauthToken oauthSecret:(NSString *)oauthSecret consumerKey:(NSString*)consumerKey consumerSecret:(NSString*)consumerSecret failureHandler:(APFailureBlock)failureBlock;

/**
 Method to create a user with twitter token and secret.
 
 @param oauthToken The oauth token retrieved after twitter login.
 @param oauthSecret The oauth secret.
 @param consumerKey The consumer key of the application created on twitter.
 @param consumerSecret The consumer secret of the application created on twitter.
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation is unsuccessful.
 */
- (void) createUserWithTwitter:(NSString*)oauthToken oauthSecret:(NSString *)oauthSecret consumerKey:(NSString*)consumerKey consumerSecret:(NSString*)consumerSecret successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Saving APUser */

/**
 @see saveObjectWithSuccessHandler:failureHandler:
 */
- (void) saveObject;

/**
 @see saveObjectWithSuccessHandler:failureHandler:
 */
- (void) saveObjectWithFailureHandler:(APFailureBlock)failureBlock;

/**
 Save the object on the remote server.
 
 This method will save an object in the background. If save is successful the properties will be updated and the successBlock will be invoked. If not the failure block is invoked.
 
 @param successBlock Block invoked when the save operation is successful
 @param failureBlock Block invoked when the save operation fails.
 
 */
- (void) saveObjectWithSuccessHandler:(APResultSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Fetching APUser */

/**
 @see fetchUserById:propertiesToFetch:successHandler:failureHandler:
 */
- (void) fetchUserById:(NSString *)userId;

/**
 @see fetchUserById:propertiesToFetch:successHandler:failureHandler:
 */
- (void) fetchUserById:(NSString *)userId successHandler:(APSuccessBlock)successBlock;

- (void) fetchUserById:(NSString *)userId successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 Method to retrieve User by ID
 
 @param userId The user Id of an existing user whose details need to be retrieved.
 @param propertiesToFetch Array of properties to be fetched excluding all other.
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation is unsuccessful.
 */
- (void) fetchUserById:(NSString *)userId propertiesToFetch:(NSArray*)propertiesToFetch successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see fetchUserByUsername:propertiesToFetch:successHandler:failureHandler:
 */
- (void) fetchUserByUsername:(NSString *)username;

/**
 @see fetchUserByUsername:propertiesToFetch:successHandler:failureHandler:
 */
- (void) fetchUserByUsername:(NSString *)username successHandler:(APSuccessBlock)successBlock;

/**
 @see fetchUserByUsername:propertiesToFetch:successHandler:failureHandler:
 */
- (void) fetchUserByUsername:(NSString *)username successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 Method to retrieve User by username
 
 @param username The user name of an existing user  whose details need to be retrieved.
 @param propertiesToFetch Array of properties to be fetched excluding all other.
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation is unsuccessful.
 */
- (void) fetchUserByUsername:(NSString *)username propertiesToFetch:(NSArray*)propertiesToFetch successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see fetchUserWithUserToken:propertiesToFetch:successHandler:failureHandler:
 */
- (void) fetchUserWithUserToken:(NSString *)userToken;

/**
 @see fetchUserWithUserToken:propertiesToFetch:successHandler:failureHandler:
 */
- (void) fetchUserWithUserToken:(NSString *)userToken successHandler:(APSuccessBlock)successBlock;

/**
 @see fetchUserWithUserToken:propertiesToFetch:successHandler:failureHandler:
 */
- (void) fetchUserWithUserToken:(NSString *)userToken successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 Method to retrieve of currently logged-in User
 
 @param userToken user token for the user you wish to fetch.
 @param propertiesToFetch Array of properties to be fetched excluding all other.
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation is unsuccessful.
 */
- (void) fetchUserWithUserToken:(NSString *)userToken propertiesToFetch:(NSArray*)propertiesToFetch successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see fetchWithPropertiesToFetch:successHandler:failureHandler:
 */
- (void) fetch;

/**
 @see fetchWithPropertiesToFetch:successHandler:failureHandler:
 */
- (void) fetchWithFailureHandler:(APFailureBlock)failureBlock;

/**
 @see fetchWithPropertiesToFetch:successHandler:failureHandler:
 */
- (void) fetchWithSuccessHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 Method used to fetch an APObject.
 
 This method will use the type and objectId properties to fetch the object. If the objectId and type is not set, results are unexpected.
 
 @param propertiesToFetch Array of properties to be fetched excluding all other.
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation is unsuccessful.
 */
- (void) fetchWithPropertiesToFetch:(NSArray*)propertiesToFetch successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Updating APUser */

/**
 @see updateObjectWithRevisionNumber:successHandler:failureHandler:
 */
- (void) updateObject;

/**
 @see updateObjectWithRevisionNumber:successHandler:failureHandler:
 */
- (void) updateObjectWithSuccessHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 Method to update a User
 
 @param revision The the last revision number of the object.
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation is unsuccessful.
 */
- (void) updateObjectWithRevisionNumber:(NSNumber*)revision successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Deleting APUser */

/**
 @see deleteObjectWithSuccessHandler:failureHandler:
 */
- (void) deleteObject;

/**
 Method to delete a User
 
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation is unsuccessful.
 */
- (void) deleteObjectWithSuccessHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see deleteObjectWithConnectingConnectionsSuccessHandler:failureHandler:
 */
- (void) deleteObjectWithConnectingConnections;

/**
 @see deleteObjectWithConnectingConnectionsSuccessHandler:failureHandler:
 */
- (void) deleteObjectWithConnectingConnections:(APFailureBlock)failureBlock;

/**
 Deletes an APObject along with any connections it has.
 
 @param successBlock Block invoked when delete operation is successful.
 @param failureBlock Block invoked when delete operation is unsuccessful.
 */
- (void) deleteObjectWithConnectingConnectionsSuccessHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see deleteObjectWithUsername:successHandler:failureHandler:
 */
- (void) deleteObjectWithUsername:(NSString*)username;

/**
 Method to delete a User
 
 @param username The username of the user whose details need to be deleted.
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation is unsuccessful.
 */
- (void) deleteObjectWithUsername:(NSString*)username successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see deleteCurrentlyLoggedInUserWithSuccessHandler:failureHandler:
 */
+ (void) deleteCurrentlyLoggedInUser;

/**
 Method to delete the currently logged-in User
 
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation is unsuccessful.
 */
+ (void) deleteCurrentlyLoggedInUserWithSuccessHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Checking-in a user to a location */

/**
 @see setUserLocationToLatitude:longitude:forUserWithUserId:successHandler:failureHandler:
 */
+ (void) setUserLocationToLatitude:(NSString*)latitude longitude:(NSString*)longitude forUserWithUserId:(NSString*)userId;

/**
 @see setUserLocationToLatitude:longitude:forUserWithUserId:successHandler:failureHandler:
 */
+ (void) setUserLocationToLatitude:(NSString*)latitude longitude:(NSString*)longitude forUserWithUserId:(NSString*)userId failureHandler:(APFailureBlock)failureBlock;

/**
 Method to set user's location
 
 @param latitude Latitude of the user's current location coordinate.
 @param longitude Longitude of the user's current location coordinate.
 @param userId the id of the user whose location needs to be set.
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation is unsuccessful.
 */
+ (void) setUserLocationToLatitude:(NSString*)latitude longitude:(NSString*)longitude forUserWithUserId:(NSString*)userId successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Validating APUser session*/

/**
 @see validateCurrentUserSessionWithSuccessHandler:failureHandler:
 */
+ (void) validateCurrentUserSessionWithSuccessHandler:(APResultSuccessBlock)successBlock;

/**
 Method to validate user's session
 
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation is unsuccessful.
 */
+ (void) validateCurrentUserSessionWithSuccessHandler:(APResultSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** Logging-out an APUser */

/**
 @see logOutCurrentUserWithSuccessHandler:failureHandler:
 */
+ (void) logOutCurrentUser;

/**
 @see logOutCurrentUserWithSuccessHandler:failureHandler:
 */
+ (void) logOutCurrentUserWithFailureHandler:(APFailureBlock)failureBlock;

/**
 Method to invalidate user's session
 
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation is unsuccessful.
 */
+ (void) logOutCurrentUserWithSuccessHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** Password management for APUser */

/**
 @see changePasswordFromOldPassword:toNewPassword:successHandler:failureHandler:
 */
- (void) changePasswordFromOldPassword:(NSString*)oldPassword toNewPassword:(NSString*)newPassword;

/**
 @see changePasswordFromOldPassword:toNewPassword:successHandler:failureHandler:
 */
- (void) changePasswordFromOldPassword:(NSString*)oldPassword toNewPassword:(NSString*)newPassword failureHandler:(APFailureBlock)failureBlock;

/**
 Method to change Password for the currently logged-in user
 
 @param oldPassword The current/old password of the logged-in user.
 @param newPassword The new password of the logged-in user.
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation is unsuccessful.
 */
- (void) changePasswordFromOldPassword:(NSString *)oldPassword toNewPassword:(NSString *)newPassword successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see sendResetPasswordEmailForUserWithUsername:withSubject:successHandler:failureHandler:
 */
+ (void) sendResetPasswordEmailForUserWithUsername:(NSString*)username withSubject:(NSString*)emailSubject;

/**
 @see sendResetPasswordEmailForUserWithUsername:withSubject:successHandler:failureHandler:
 */
+ (void) sendResetPasswordEmailForUserWithUsername:(NSString*)username withSubject:(NSString*)emailSubject failureHandler:(APFailureBlock)failureBlock;

/**
 Method to send a reset password email for the currently logged-in user
 
 @param username username of the user whose password needs to be reset.
 @param emailSubject text for the subject field of the reset password email.
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation is unsuccessful.
 */
+ (void) sendResetPasswordEmailForUserWithUsername:(NSString*)username withSubject:(NSString *)emailSubject successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 Method to restore the current user object persisted in the local data store.
 @return APUser instance of the saved user object.
 */
+ (void) restoreCurrentUser;

@end
