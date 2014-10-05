//
//  APHelperMethods.h
//  Appacitive-iOS-SDK
//
//  Created by Kauserali Hafizji on 03/09/12.
//  Copyright (c) 2012 Appacitive Software Pvt. Ltd. All rights reserved.
//

//#import "MKNetworkKit.h"

@class APError;

/**
 This class contains all the helper methods used internally by the SDK.
 */
@interface APHelperMethods : NSObject

#define NSStringFromBOOL(aBOOL) aBOOL ? @"YES" : @"NO"
#define BooleanStringFromBOOL(aBOOL) aBOOL ? @"true" : @"false"
#ifdef DEBUG
#   define DLog(fmt, ...) {NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);}
#   define ELog(err) {if(err) DLog(@"%@", err)}
#else
#   define DLog(...)
#   define ELog(err)
#endif

/**
 Helper method used to check for any errors.
 
 @param response Response received from the server.
 @return APError represnetation of error from response.
 */
+ (APError*)checkForErrorStatus:(id)response;

/**
 Helper method to parse the properties from a json response
 
 @param response Response received from the server.
 @return An array of properties
 */
+ (NSArray*)arrayOfPropertiesFromJSONResponse:(id)response;

/**
 Helper method to parse the properties from a json response
 
 @param response Response received from the server.
 @return A dictionary of properties
 */
+ (NSMutableDictionary*)dictionaryOfPropertiesFromJSONResponse:(id)response;

/**
 Helper method to parse json response to NSDate
 
 @param jsonDateString Date in JSON string format.
 @return date as NSDate object.
 */
+ (NSDate*)deserializeJsonDateString:(NSString*)jsonDateString;

/**
 Helper method to parse NSDate to NSString.
 
 @param date NSDate to parse.
 @return String from NSDate.
 */
+ (NSString*)jsonDateStringFromDate:(NSDate*)date;


/**
 Method to get error info from non 200 HTTP response codes
 
 @param response Response received from the server.
 @return APError represnetation of error from response.
 */
+ (APError*)getErrorInfo:(NSURLResponse*)response;

@end
