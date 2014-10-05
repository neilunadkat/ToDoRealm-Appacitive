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
    // Do any additional setup after loading the view.
}


- (IBAction)onLogin:(id)sender {
    //This should show the activity indicator since it is set to animating when it is not hidden
    [_activityIndicator setHidden:NO];
    
    [APUser authenticateUserWithUsername:_userName.text password:_password.text sessionExpiresAfter:nil limitAPICallsTo:nil successHandler:^(APUser *user) {
        
    } failureHandler:^(APError *error) {
        
    }];
}
@end
