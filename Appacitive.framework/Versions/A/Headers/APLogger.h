//
//  APLogger.h
//  Appacitive-iOS-SDK
//
//  Created by Pratik on 13-05-14.
//  Copyright (c) 2014 Appacitive Software Pvt. Ltd. All rights reserved.
//

typedef enum {
    APMessageTypeError,
    APMessageTypeDebug
} APMessageType;

/**
 An interface that logs the details of all the network calls that the SDK makes. All messages will be logged to the console.
 */

@interface APLogger : NSObject

@property (nonatomic) BOOL isVerbose;
@property (nonatomic) BOOL isLoggingEnabled;

/**
 Method to instantiate a logger instance. This logger logs in the default error mode.
 
 @return A new APlogger instance.
 */
- (instancetype) init;

/**
 Method to instantiate a logger in verbose mode.
 
 @param logEnabled  Whether logging should be enabled.
 @param verboseMode Whether logging in verbose mode should be enabled.
 
 @return A new APLogger instance with specified settings.
 */

- (instancetype) initWithLoggingEnabled:(BOOL)logEnabled verboseMode:(BOOL)verboseMode;

/**
 Method to instantiate a logger instance. This logger logs in the default error mode.
 
 @return A new APlogger instance.
 */
+ (instancetype) logger;

/**
 Method to instantiate a logger in verbose mode.
 
 @param logEnabled  Whether logging should be enabled.
 @param verboseMode Whether logging in verbose mode should be enabled.
 
 @return A new APLogger instance with specified settings.
 */
+ (instancetype) loggerWithLoggingEnabled:(BOOL)logEnabled verboseMode:(BOOL)verboseMode;;

/**
 Method to instantiate and return a static logger instance. This logger logs in the default error mode.
 
 @return static instance of a logger.
 */
+ (instancetype) sharedLogger;

/**
 Method to instantiate and return a static logger instance in verbose mode.
 
 @param logEnabled  Whether logging should be enabled.
 @param verboseMode Whether logging in verbose mode should be enabled.
 
 @return static instance of a logger with specified settings.
 */
+ (instancetype) sharedLoggerWithLoggingEnabled:(BOOL)logEnabled verboseMode:(BOOL)verboseMode;;

/**
 Method to enable logging, which is disabled by default.
 
 @param answer Whether you want to enable logging.
 */
- (void) enableLogging:(BOOL)answer;

/**
 The default logging mode is set to error that will only log error. Use this method to enable logging everything i.e. in debug mode.
 
 @param answer Whether you want  to enable verbose mode logging.
 */
- (void) enableVerboseMode:(BOOL)answer;

/**
 Method to log message with specified message type.
 
 @param message     Message string to be logged.
 @param messageType Message type i.e. APMessageTypeError or APMessageTypeDebug.
 */
- (void) log:(NSString*)message withType:(APMessageType)messageType;

@end

