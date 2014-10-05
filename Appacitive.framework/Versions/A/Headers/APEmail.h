//
//  APEmail.h
//  Appacitive-iOS-SDK
//
//  Created by Pratik on 16-12-13.
//  Copyright (c) 2013 Appacitive Software Pvt. Ltd. All rights reserved.
//

#import "APResponseBlocks.h"

/**
 The APEmail class allows you to send requests to the appactive API to send out emails.
 Appacitive offers two types of emails. 
 The simple email is a type of an email where you create the email body content on you own.
 The templated email is a type of an email where you create an email template on the Appacitive portal with placeholders and then use tht template name to send the email to recipients by customizing the placeholders of the template.
 Appacitive also provides you with an option to use your own SMTP server configuration if you wish top use an SMTP server that is different than the one provided by Appacitive.
 */

@interface APEmail : NSObject

@property (nonatomic, strong) NSDictionary* templateBody;
@property (nonatomic, strong) NSArray* toRecipients;
@property (nonatomic, strong) NSArray* ccRecipients;
@property (nonatomic, strong) NSArray* bccRecipients;
@property (nonatomic, strong) NSString* fromSender;
@property (nonatomic, strong) NSString* replyToEmail;
@property (nonatomic, strong) NSString* subjectText;
@property (nonatomic, strong) NSString* bodyText;
@property (nonatomic) BOOL isHTMLBody;

/**
 Method to instantiate an email object with minimum number of requierd properties.
 @param recipients An array of email addresses of the recipients of the email.
 @param subject Subject for the email.
 @param body Content of the email.
 */
- (instancetype) initWithRecipients:(NSArray*)recipients subject:(NSString*)subject body:(NSString*)body;

/**
 @see sendEmailWithSuccessHandler:failureHandler:
 */
- (void) sendEmail;

/**
 @see sendEmailUsingSMTPConfig:successHandler:failureHandler:
 */
- (void) sendEmailWithSuccessHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see sendEmailUsingSMTPConfig:successHandler:failureHandler:
 */
- (void) sendEmailUsingSMTPConfig:(NSDictionary*)smtpConfig;

/**
 Method to send a simple email
 @param smtpConfig A dictionary with smtp configuration parameters.
 @param successBlock Block invoked when the email sending operation is successful.
 @param failureBlock Block invoked when the email sending operation is unsuccessful.
 @note To send an email the following properties of the email object MUST be set: toRecipients, subjectText, bodyText.
 
 To make a SMTP configuration dictionary, use the 'makeSMTPConfigurationDictionaryWithUsername:password:host:port:enableSSL:' method.
 */
- (void) sendEmailUsingSMTPConfig:(NSDictionary*)smtpConfig successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see sendTemplatedEmailUsingTemplate:usingSMTPConfig:successHandler:failureHandler:
 */
- (void) sendTemplatedEmailUsingTemplate:(NSString *)templateName usingSMTPConfig:(NSDictionary*)smtpConfig;

/**
 @see sendTemplatedEmailUsingTemplate:usingSMTPConfig:successHandler:failureHandler:
 */
- (void) sendTemplatedEmailUsingTemplate:(NSString *)templateName;

/**
 @see sendTemplatedEmailUsingTemplate:usingSMTPConfig:successHandler:failureHandler:
 */
- (void) sendTemplatedEmailUsingTemplate:(NSString *)templateName successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 Mehtod to send a templated email.
 @param templateName name of the template configured on the Appacitive portal.
 @param smtpConfig A dictionary with smtp configuration parameters.
 @param successBlock Block invoked when the email sending operation is successful.
 @param failureBlock Block invoked when the email sending operation is unsuccessful.
 */
- (void) sendTemplatedEmailUsingTemplate:(NSString *)templateName usingSMTPConfig:(NSDictionary*)smtpConfig successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 Helper method to create a dictionary object with SMTP Configuration parameters
 @param username Username for the account on SMTP server.
 @param password Password for the account on SMTP server.
 @param host SMTP server host url.
 @param port SMTP server port.
 @param enableSSL Whether to user SSL or not.
 */
+ (NSDictionary*)makeSMTPConfigurationDictionaryWithUsername:(NSString*)username password:(NSString*)password host:(NSString*)host port:(NSNumber*)port enableSSL:(BOOL)enableSSL;


@end
