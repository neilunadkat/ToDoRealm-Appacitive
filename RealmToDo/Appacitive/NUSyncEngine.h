//
//  NUSyncEngine.h
//  RealmToDo
//
//  Created by Neil Unadkat on 05/10/14.
//  Copyright (c) 2014 Appacitive. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "List.h"

@interface NUSyncEngine : NSObject

+ (instancetype) sharedNUSyncEngine;

// Have added these separate calls because Realm notification currently does not support
// the ability to know what changed

- (void) addedList:(List *)list;

-(void) addedTodo:(ToDo *) todo ToList:(List *) list;

- (void) updatedTodo:(ToDo *)todo;

@end
