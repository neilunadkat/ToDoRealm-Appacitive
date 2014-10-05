//
//  NUAppDelegate.m
//  RealmToDo
//
//  Created by Neil Unadkat on 05/10/14.
//  Copyright (c) 2014 Appacitive. All rights reserved.
//

#import "NUAppDelegate.h"
#import <Appacitive/AppacitiveSDK.h>
#import <Realm/Realm.h>

@implementation NUAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{

    //    {Put API Key Here}
    [Appacitive registerAPIKey:@"{Put API Key Here}" useLiveEnvironment:NO];
    [[APLogger sharedLogger] enableLogging:YES];
    [[APLogger sharedLogger] enableVerboseMode:YES];
    [self realmMigration];
    
    // The root view controller is NUListTableViewController
    // Then comes the NUToDoTableViewController
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


//For Realm Migration
- (void) realmMigration{
    RLMMigrationBlock migrationBlock = ^NSUInteger(RLMMigration *migration,
                                                   NSUInteger oldSchemaVersion) {
        // We haven’t migrated anything yet, so oldSchemaVersion == 0
        if (oldSchemaVersion < 1) {
            // Nothing to do!
            // Realm will automatically detect new properties and removed properties
            // And will update the schema on disk automatically
        }
        // Return the latest version number (always set manually)
        // Must be a higher than the previous version or an RLMException is thrown
        return 1;
    };
    
    // Apply the migration block above to the default Realm
    [RLMRealm migrateDefaultRealmWithBlock:migrationBlock];
}

@end
