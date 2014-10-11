//
//  ToDo.h
//  RealmToDo
//
//  Created by Neil Unadkat on 05/10/14.
//  Copyright (c) 2014 Appacitive. All rights reserved.
//

#import <Realm/Realm.h>

@interface ToDo : RLMObject
@property NSString * text;
@property bool  completed;

@end

// This protocol enables typed collections. i.e.:
// RLMArray<ToDo>
RLM_ARRAY_TYPE(ToDo)
