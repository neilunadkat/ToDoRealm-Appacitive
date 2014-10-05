//
//  User.h
//  RealmToDo
//
//  Created by Neil Unadkat on 05/10/14.
//  Copyright (c) 2014 Appacitive. All rights reserved.
//

#import <Realm/Realm.h>

@interface User : RLMObject
@property NSString * userId;
@property NSString * name;
@property NSString * username;

@end

// This protocol enables typed collections. i.e.:
// RLMArray<User>
RLM_ARRAY_TYPE(User)
