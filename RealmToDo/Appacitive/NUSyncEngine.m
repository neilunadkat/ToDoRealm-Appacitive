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

+(instancetype) sharedNUSyncEngine{
    static dispatch_once_t once;
    static NUSyncEngine *sharedInstance;
    dispatch_once(&once, ^{
        sharedInstance = [[self alloc] init];
    });
    
    return sharedInstance;
}

@end
