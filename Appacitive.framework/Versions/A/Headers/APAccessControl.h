//
//  Acl.h
//  Appacitive-iOS-SDK
//
//  Created by Pratik on 28-04-14.
//  Copyright (c) 2014 Appacitive Software Pvt. Ltd. All rights reserved.
//

#define kPermissionRead @"read"
#define kPermissionDelete @"delete"
#define kPermissionUpdate @"update"
#define kPermissionManageAccess @"manageaccess"

/**
 Acl stands for access control list. This class provides methods to manage access permissions to users and user groups on your objects.
 */

@interface APAccessControl : NSObject {
    NSMutableDictionary *_userAccessDict;
    NSMutableDictionary *_groupAccessDict;
}

/**
 Method to set allow permission(s) on user objects.
 
 @param users       An array of users' username or objectId.
 @param permissions Array of strings with possible valid values - kPermissionRead, kPermissionDelete, kPermissionManageAccess, kPermissionUpdate.
 */
- (void) allowUsers:(NSArray*)users permissions:(NSArray*)permissions;

/**
 Method to set allow permission(s) on user group objects.
 
 @param userGroups  An array of usergroup ids or usergroup names.
 @param permissions Array of strings with possible valid values - kPermissionRead, kPermissionDelete, kPermissionManageAccess, kPermissionUpdate.
 */
- (void) allowUserGroups:(NSArray*)userGroups permissions:(NSArray*)permissions;

/**
 Method to set deny permissions on user objects.
 
 @param users       An array of users' username or objectId.
 @param permissions Array of strings with possible valid values - kPermissionRead, kPermissionDelete, kPermissionManageAccess, kPermissionUpdate.
 */
- (void) denyUsers:(NSArray*)users permissions:(NSArray*)permissions;

/**
 Method to set deny permission(s) on user group objects.
 
 @param userGroups  An array of usergroup ids or usergroup names.
 @param permissions Array of strings with possible valid values - kPermissionRead, kPermissionDelete, kPermissionManageAccess, kPermissionUpdate.
 */
- (void) denyUserGroups:(NSArray*)userGroups permissions:(NSArray*)permissions;


/**
 Method to reset permissions on user objects.
 
 @param users       An array of users' username or objectId.
 @param permissions Array of strings with possible valid values - kPermissionRead, kPermissionDelete, kPermissionManageAccess, kPermissionUpdate.
 */
- (void) resetUsers:(NSArray*)users permissions:(NSArray*)permissions;

/**
 Method to reset permission(s) on user group objects.
 
 @param userGroups  An array of usergroup ids or usergroup names.
 @param permissions Array of strings with possible valid values - kPermissionRead, kPermissionDelete, kPermissionManageAccess, kPermissionUpdate.
 */
- (void) resetUserGroups:(NSArray*)userGroups permissions:(NSArray*)permissions;


/**
 Method to get a NSArray formatted access list.
 
 @return An array of formatted access list.
 */
- (NSArray*)getFormattedAccessList;

@end
