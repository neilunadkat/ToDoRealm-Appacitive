//
//  Appacitive.h
//  Appacitive-iOS-SDK
//
//  Created by Kauserali Hafizji on 29/08/12.
//  Copyright (c) 2012 Appacitive Software Pvt. All rights reserved.
//

/**
 Appacitive is the entry point to use the Appacitive SDK.
 Here you set your Appacitive application APIKey and your Appacitive application environment, which will be used to make all network requests to Appacitive back end.
 */

@interface Appacitive: NSObject

@property (nonatomic, readwrite) BOOL enableDebugForEachRequest;

/**
 Returns the current ApiKey
 */
+ (NSString*)getApiKey;

/**
 Sets the APIkey
 @param apiKey APIKey to be used for the app. You can obtain this key from the Appacitive portal.
 @param answer Whether you want to use live environment, default environment is sandbox.
 */
+ (void) registerAPIKey:(NSString*)apiKey useLiveEnvironment:(BOOL)answer;

/**
 Returns the current environment setting. By default the environment is set to sandbox.
 @return The current environment setting.
 */
+ (NSString*)getCurrentEnvironment;

/**
 Method to set application environment to live
 @param answer Whether you want to use live environment.
 */
+ (void) useLiveEnvironment:(BOOL)answer;


@end
