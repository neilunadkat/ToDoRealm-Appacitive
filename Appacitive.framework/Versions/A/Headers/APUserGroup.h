//
//  APUserGroup.h
//  Appacitive-iOS-SDK
//
//  Created by Pratik on 19-05-14.
//  Copyright (c) 2014 Appacitive Software Pvt. Ltd. All rights reserved.
//

#import "APResponseBlocks.h"

/**
 Interface to add or remove users from user groups.
 */

@interface APUserGroup : NSObject

/**
 @see addUsers:toUserGroup:successHandler:failureHandler:
 */
+ (void) addUsers:(NSArray*)users toUserGroup:(NSString*)userGroup;

/**
 @see addUsers:toUserGroup:successHandler:failureHandler:
 */
+ (void) addUsers:(NSArray *)users toUserGroup:(NSString *)userGroup failureHandler:(APFailureBlock)failureBlock;

/**
 Method to add users to a user group.
 
 @param users        an array of usernames, userIDs or APUserObjects or any of the combinations of the three.
 @param userGroup    name or id of the usergroup.
 @param successBlock block executed when the operation is successful.
 @param failureBlock block executed when the operation fails.
 */
+ (void) addUsers:(NSArray *)users toUserGroup:(NSString *)userGroup successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see removeUsers:fromUserGroup:successHandler:failureHandler:
 */
+ (void) removeUsers:(NSArray*)users fromUserGroup:(NSString*)userGroup;

/**
 @see removeUsers:fromUserGroup:successHandler:failureHandler:
 */
+ (void) removeUsers:(NSArray *)users fromUserGroup:(NSString *)userGroup failureHandler:(APFailureBlock)failureBlock;

/**
 Method to remove users from a user group.
 
 @param users        an array of usernames, userIDs or APUserObjects or any of the combinations of the three.
 @param userGroup    name or id of the usergroup.
 @param successBlock block executed when the operation is successful.
 @param failureBlock block executed when the operation fails.
 */
+ (void) removeUsers:(NSArray *)users fromUserGroup:(NSString *)userGroup successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

@end
