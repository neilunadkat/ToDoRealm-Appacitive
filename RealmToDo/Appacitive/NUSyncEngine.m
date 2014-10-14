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
#import <Realm/Realm.h>
#import <Appacitive/AppacitiveSDK.h>

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

- (void) addedList:(List *)list{
    
    //This call creates a new list object and connects it to the user
    
    APConnection * userList = [[APConnection alloc] initWithRelationType:@"owner"];
    
    NSString * userID = [APUser currentUser].objectId;
    
    APObject * appacitiveList = [[APObject alloc] initWithTypeName:@"list"];
    
    
    [appacitiveList addPropertyWithKey:@"name" value:list.name];
    
    [userList createConnectionWithObjectA:appacitiveList objectBId:userID labelA:@"list" labelB:@"user" successHandler:^{
        
        NSString * listId = appacitiveList.objectId;
        RLMRealm * realm = [RLMRealm defaultRealm];
        [realm beginWriteTransaction];
        list.listId = listId;
        list.isSyncd = 0;
        [realm commitWriteTransaction];
    }
    failureHandler:^(APError *error) {
        
    }];
}

-(void) addedTodo:(ToDo *) todo ToList:(List *) list{

    //This call creates a new todo object and connects it to the list
    
    APConnection * listTodo = [[APConnection alloc] initWithRelationType:@"list_todo"];
    
    NSString * listId = list.listId;
    
    APObject * appacitiveToDo = [[APObject alloc] initWithTypeName:@"todo"];
    
    
    [appacitiveToDo addPropertyWithKey:@"text" value:todo.text];
    
    [appacitiveToDo addPropertyWithKey:@"completed" value:todo.completed ? @"true" : @"false" ];
    
    
    
    [listTodo createConnectionWithObjectA:appacitiveToDo objectBId:listId labelA:@"todo" labelB:@"list" successHandler:^{
        
        NSString * todoId = appacitiveToDo.objectId;
        RLMRealm * realm = [RLMRealm defaultRealm];
        [realm beginWriteTransaction];
        todo.toDoId = todoId;
        todo.isSyncd = 0;
        list.isSyncd = 0;
        [realm commitWriteTransaction];
    }
                           failureHandler:^(APError *error) {
                               
                           }];
    
}

- (void) updatedTodo:(ToDo *)todo{
    //If you specify the object id then the sdk makes an update call
    APObject * appacitiveToDo = [[APObject alloc] initWithTypeName:@"todo" objectId:todo.toDoId];
    
    NSString * completed = todo.completed ? @"true" : @"false";
    
    [appacitiveToDo addPropertyWithKey:@"completed" value:completed ];
    
    [appacitiveToDo updateObjectWithSuccessHandler:^(NSDictionary *result) {
        RLMRealm * realm = [RLMRealm defaultRealm];
        [realm beginWriteTransaction];
        todo.isSyncd = 0;
        [realm commitWriteTransaction];
        
    } failureHandler:^(APError *error) {
        NSLog(@"%@",error);
    }];
}

@end
