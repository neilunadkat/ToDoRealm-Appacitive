//
//  APFile.h
//  Appacitive-iOS-SDK
//
//  Created by Kauserali Hafizji on 10/09/12.
//  Copyright (c) 2012 Appacitive Software Pvt. Ltd. All rights reserved.
//

#import "APObject.h"

@class APResponceBlocks;

/**
 The APFile class allows you to make file operations on Appacitive.
 You can Upload, Download, Update and Delete files on the Appacitive portal.
 */

@interface APFile : NSObject <NSURLConnectionDelegate, NSURLConnectionDataDelegate>

/** @name Uploading data to Appacitive */

/**
 @see getUploadURLForFileWithName:urlExpiresAfter:contentType:successHandler:failureHandler:
 */
+ (void) getUploadURLForFileWithName:(NSString*)name urlExpiresAfter:(NSNumber*)minutes contentType:(NSString*)contentType successHandler:(APURLSuccessBlock)successBlock;

/**
 Method to fetch the upload URL for a file on Appacitive.
 
 @param name Name of the file you wish to upload to Appacitive.
 @param minutes The time for which the upload url will be valid.
 @param contentType The mimetype of the data being uploaded.
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation fails.
 */
+ (void) getUploadURLForFileWithName:(NSString*)name urlExpiresAfter:(NSNumber*)minutes contentType:(NSString*)contentType successHandler:(APURLSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see uploadFileWithName:data:urlExpiresAfter:contentType:successHandler:failureHandler:
 */
+ (void) uploadFileWithName:(NSString*)name data:(NSData*)fileData urlExpiresAfter:(NSNumber*)minutes;

/**
 @see uploadFileWithName:data:urlExpiresAfter:contentType:successHandler:failureHandler:
 */
+ (void) uploadFileWithName:(NSString*)name data:(NSData*)fileData urlExpiresAfter:(NSNumber*)minutes contentType:(NSString*)contentType;

/**
 @see uploadFileWithName:data:urlExpiresAfter:contentType:successHandler:failureHandler:
 */
+ (void) uploadFileWithName:(NSString *)name data:(NSData *)fileData urlExpiresAfter:(NSNumber*)minutes contentType:(NSString*)contentType successHandler:(APResultSuccessBlock)successBlock;

/**
 Method used to upload data to the remote server
 @param name Name of the file.
 @param data Data that you want to upload.
 @param minutes The time for which the upload url will be valid. If the file size is big make sure to set the value to a large amount.
 @param contentType The mimetype of the data being uploaded.
 @param successBlock Block invoked when upload is successful.
 @param failureBlock Block invoked when upload fails.
 */
+ (void) uploadFileWithName:(NSString *)name data:(NSData *)data urlExpiresAfter:(NSNumber*)minutes contentType:(NSString*)contentType successHandler:(APResultSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Downloading data form Appacitive */

/**
 @see getDownloadURLForFileWithName:urlExpiresAfter:successHandler:failureHandler:
 */
+ (void) getDownloadURLForFileWithName:(NSString*)name urlExpiresAfter:(NSNumber*)minutes successHandler:(APURLSuccessBlock)successBlock;

/**
 Method to fetch the download URL for a file on Appacitive.
 
 @param name Name of the file you wish to download from Appacitive.
 @param minutes The time for which the download url will be valid.
 @param successBlock Block invoked when operation is successful.
 @param failureBlock Block invoked when operation fails.
 */
+ (void) getDownloadURLForFileWithName:(NSString*)name urlExpiresAfter:(NSNumber*)minutes successHandler:(APURLSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;


/**
 @see downloadFileWithName:urlExpiresAfter:successHandler:failureHandler:
 */
+ (void) downloadFileWithName:(NSString*)name urlExpiresAfter:(NSNumber*)minutes successHandler:(APFileDownloadSuccessBlock)successBlock;

/**
 Method used to download data from the remote server.
 
 @param name Name of the file you want to download.
 @param minutes The time for which the download url will be valid.
 @param successBlock Block invoked when download is successful.
 @param failureBlock Block invoked when download fails.
 */
+ (void) downloadFileWithName:(NSString*)name urlExpiresAfter:(NSNumber*)minutes successHandler:(APFileDownloadSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see deleteFileWithName:successHandler:failureHandler:
 */
+ (void) deleteFileWithName:(NSString*)name;

/**
 Method to delete a previously uploaded file from the server.
 
 @param name Name of the file to be deleted.
 @param successBlock Block invoked when opertaion is successful.
 @param failureBlock Block invoked when operation fails.
 */
+ (void) deleteFileWithName:(NSString *)name successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

@end
