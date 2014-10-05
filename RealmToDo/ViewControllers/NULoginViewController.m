//
//  NULoginViewController.m
//  RealmToDo
//
//  Created by Neil Unadkat on 05/10/14.
//  Copyright (c) 2014 Appacitive. All rights reserved.
//

#import "NULoginViewController.h"
#import <Appacitive/AppacitiveSDK.h>
#import "User.h"

@interface NULoginViewController ()
@property (weak, nonatomic) IBOutlet UITextField *userName;
@property (weak, nonatomic) IBOutlet UITextField *password;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicator;
- (IBAction)onLogin:(id)sender;

@end

@implementation NULoginViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    [_activityIndicator setHidden:YES];
    // Do any additional setup after loading the view.
}


- (IBAction)onLogin:(id)sender {

    [_activityIndicator setHidden:NO];
    [_activityIndicator startAnimating];
    
    [APUser authenticateUserWithUsername:_userName.text password:_password.text sessionExpiresAfter:nil limitAPICallsTo:nil successHandler:^(APUser *user) {
        [_activityIndicator stopAnimating];
//        [_activityIndicator setHidden:YES];
        [self dismissViewControllerAnimated:YES completion:nil];
        
    } failureHandler:^(APError *error) {
        [_activityIndicator setHidden:YES];
        [_activityIndicator stopAnimating];
        UIAlertView * alert  = [[UIAlertView alloc] initWithTitle:@"Login error"
                                                          message:@"Error on login"
                                                         delegate:self
                                                cancelButtonTitle:@"OK"
                                                otherButtonTitles:nil];
        [alert show];
    }];
}
@end
