//
//  ToDo.h
//  RealmToDo
//
//  Created by Neil Unadkat on 05/10/14.
//  Copyright (c) 2014 Appacitive. All rights reserved.
//

#import <Realm/Realm.h>

@interface ToDo : RLMObject
@property NSString * toDoId;
@property NSString * text;
@property bool  completed;

// 0 means that there is not update
// 1 means that the object has been updated
// 2 means that it is deleted
@property NSInteger isSyncd;

@end

// This protocol enables typed collections. i.e.:
// RLMArray<ToDo>
RLM_ARRAY_TYPE(ToDo)
