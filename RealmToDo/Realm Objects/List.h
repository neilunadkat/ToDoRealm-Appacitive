//
//  List.h
//  RealmToDo
//
//  Created by Neil Unadkat on 05/10/14.
//  Copyright (c) 2014 Appacitive. All rights reserved.
//

#import <Realm/Realm.h>
#import "User.h"
#import "ToDo.h"

@interface List : RLMObject
@property NSString * listId;
@property NSString * name;
@property RLMArray<User> * sharedUsers;
@property User * owner;
@property RLMArray<ToDo> * toDos;

// 0 means that there is not update
// 1 means that the object has been updated
// 2 means that it is deleted
@property NSInteger isSyncd;
@end

// This protocol enables typed collections. i.e.:
// RLMArray<List>
RLM_ARRAY_TYPE(List)
