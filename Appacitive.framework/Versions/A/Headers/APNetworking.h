//
//  APNetworking.h
//  Appacitive-iOS-SDK
//
//  Created by Pratik on 31-12-13.
//  Copyright (c) 2013 Appacitive Software Pvt. Ltd. All rights reserved.
//

#import "APResponseBlocks.h"

#define HOST_NAME @"https://apis.appacitive.com/v1.0/"

/**
 The APNetworking class is the networking API for the appacitive SDK that allows the SDK to make network requests to the Appacitive API and receive a response from the server. 
 @note All the network requests are asynchronous.
 */

@interface APNetworking : NSObject <NSURLConnectionDelegate, NSURLConnectionDataDelegate>

/**
 Method to get a shared NSURLSession for network data tasks.
 
 @return NSURLSession object
 */
+ (NSURLSession*)getSharedNSURLSession;

/**
 Method to add additional HTTP headers to the shared NSURLSession
 
 @param value HTTP header value
 @param key   HTTP header key
 */
+ (void) addHTTPHeaderValue:(NSString*)value forKey:(NSString*)key;

/**
 Resets the HTTP headers to the default values removing any additional headers.
 */
+ (void) resetDefaultHTTPHeaders;

/**
 Method to make a network request
 
 @param urlRequest NSURLRequest object for the request that needs to be made.
 @param callingSelector The selector/method that calls this selector to make a request.
 @param requestSuccessBlock Block invoked when the network request operation is successful.
 @param requestFailureBlock Block invoked when the network request operation is unsuccessful.
 */
+ (void) makeAsyncURLRequest:(NSMutableURLRequest*)urlRequest callingSelector:(const char*)callingSelector successHandler:(APResultSuccessBlock)requestSuccessBlock failureHandler:(APFailureBlock)requestFailureBlock;

@end
