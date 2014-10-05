//
//  APDevice.h
//  Appacitive-iOS-SDK
//
//  Created by Pratik on 23-12-13.
//  Copyright (c) 2013 Appacitive Software Pvt. Ltd. All rights reserved.
//

#import "APObject.h"
#import "APResponseBlocks.h"

#pragma mark - APDevice Interface

/**
 An APDevice class helps you in managing the devices that use your app on Appacitive.
 */

@interface APDevice : APObject <APObjectPropertyMapping, NSCoding>

@property (nonatomic, strong) NSString *deviceToken;
@property (nonatomic, strong) NSString *deviceType;
@property (nonatomic, strong) NSString *deviceLocation;
@property (nonatomic, strong) NSMutableArray *channels;
@property (nonatomic, strong) NSString *timeZone;
@property (nonatomic, strong) NSString* isActive;
@property (nonatomic, strong) NSString* badge;

/** @name Initializing an APDevice instance */

- (instancetype) init;

/** Create a basic instance of an APDevice Object with deviceToken and deviceType.
 @param deviceToken Device token provided by Appacitive.
 @param deviceType Type of device voz. iOS/Android/WindowsPhone
*/
- (instancetype) initWithDeviceToken:(NSString*)deviceToken deviceType:(NSString*)deviceType;

/**
 Method to get the currentDevice object
 
 @return currentDevice instance
 */
+ (APDevice*) currentDevice;

/** Registering an APDevice */

/**
 @see registerCurrentDeviceWithPushDeviceToken:enablePushNotifications:successHandler:failureHandler:
 */
+ (void) registerCurrentDeviceWithPushDeviceToken:(NSData*)token enablePushNotifications:(BOOL)answer;

/**
 @see registerCurrentDeviceWithPushDeviceToken:enablePushNotifications:successHandler:failureHandler:
 */
+ (void) registerCurrentDeviceWithPushDeviceToken:(NSData*)token enablePushNotifications:(BOOL)answer failureHandler:(APFailureBlock)failureBlock;

/**
 Method to register your device for Push Notifications.
 
 @param token        device token for Push Notifications.
 @param answer whether Push notifications should be enabled on current device.
 @param successBlock block executed when the operation is successful.
 @param failureBlock block executed when the operation fails.
 */
+ (void) registerCurrentDeviceWithPushDeviceToken:(NSData*)token enablePushNotifications:(BOOL)answer successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;


/**
 @see deregisterCurrentDeviceWithSuccessHandler:failureHandler:
 */
+ (void) deregisterCurrentDevice;

/**
 @see deregisterCurrentDeviceWithSuccessHandler:failureHandler:
 */
+ (void) deregisterCurrentDeviceWithFailureHandler:(APFailureBlock)failureBlock;

/**
 Method to deregister your device from Push Notifications.
 
 @param successBlock block executed when the operation is successful.
 @param failureBlock block executed when the operation fails.
 */
+ (void) deregisterCurrentDeviceWithSuccessHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;


/** @name Saving APDevice */

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
 @param successBlock Block invoked when the save operation is successful.
 @param failureBlock Block invoked when the save operation fails.
 */
- (void) saveObjectWithSuccessHandler:(APResultSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Deleting APDevice */

/**
 @see deleteObjectWithSuccessHandler:failureHandler:
 */
- (void) deleteObject;

/**
 @see deleteObjectWithSuccessHandler:failureHandler:
 */
- (void) deleteObjectWithSuccessHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see deleteObjectWithSuccessHandler:failureHandler:
 */
- (void) deleteObjectWithFailureHandler:(APFailureBlock)failureBlock;


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
 @param successBlock Block invoked when the delete operation is successful.
 @param failureBlock Block invoked when the delete operation is unsuccessful.
 */
- (void) deleteObjectWithConnectingConnectionsSuccessHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** Updating APDevice */

/**
 @see updateObjectWithRevisionNumber:successHandler:failureHandler:
*/
- (void) updateObject;

/**
 @see updateObjectWithRevisionNumber:successHandler:failureHandler:
 */
- (void) updateObjectWithFailureHandler:(APFailureBlock)failureBlock;

/**
 @see updateObjectWithRevisionNumber:successHandler:failureHandler:
 */
- (void) updateObjectWithSuccessHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 Method to update the device object.
 @param revision The last revision number for the object.
 @param successBlock Block invoked when the update operation is successful.
 @param failureBlock Block invoked when the update operation is unsuccessful.
 */
- (void) updateObjectWithRevisionNumber:(NSNumber*)revision successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Fetching APDevice */

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
 @param successBlock Block invoked when the fetch operation is successful.
 @param failureBlock Block invoked when the fetch operation fails.
 */
- (void) fetchWithPropertiesToFetch:(NSArray*)propertiesToFetch successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 Method to fetch a reference to the current device object.
 
 @return a reference to the static current device object.
 */
+ (void)restoreCurrentDevice;

@end
