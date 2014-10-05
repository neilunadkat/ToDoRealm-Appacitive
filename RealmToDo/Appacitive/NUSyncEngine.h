//
//  NUSyncEngine.h
//  RealmToDo
//
//  Created by Neil Unadkat on 05/10/14.
//  Copyright (c) 2014 Appacitive. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NUSyncEngine : NSObject

+ (instancetype) sharedNUSyncEngine;

- (void) startSync;

- (void) initialiseSyncEngine;

@end
