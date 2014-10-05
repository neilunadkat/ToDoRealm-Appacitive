//
//  NUSyncEngine.m
//  RealmToDo
//
//  Created by Neil Unadkat on 05/10/14.
//  Copyright (c) 2014 Appacitive. All rights reserved.
//

#import "NUSyncEngine.h"
#import "List.h"
#import "ToDo.h"

@implementation NUSyncEngine

bool initalised = NO;

+(instancetype) sharedNUSyncEngine{
    static dispatch_once_t once;
    static NUSyncEngine *sharedInstance;
    dispatch_once(&once, ^{
        sharedInstance = [[self alloc] init];
    });
    
    return sharedInstance;
}

-(void ) startSync{
    
}


//This is to setup notification changes for Realm
- (void) initialiseSyncEngine{
    if(initalised == YES)
        return;
    
}
@end
