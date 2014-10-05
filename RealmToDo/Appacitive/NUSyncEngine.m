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

-(void ) startSync{
    [self getListsForUser];
    
    //Next method can be to update the server with all those lists or todos whose isSynced is not 1
    //i.e. maybe their update called failed
}

- (void) getListsForUser{
    NSString * lastUpdateTime = [self getStringForAPICallFromDate:[self getLastUpdatedTime]];
    NSString * userID = [APUser currentUser].objectId;
    NSDictionary * placeholders = [NSDictionary dictionaryWithObject:lastUpdateTime forKey:@"datetime"];
    
    //Make a call to graph query
    
    [APGraphNode applyProjectionGraphQuery:@"user_list_get" usingPlaceHolders:placeholders forObjectsIds:@[userID] successHandler:^(NSArray *objects) {
    
        //Since we have sent across only one id, the first object will have lists
        APGraphNode * user = [objects objectAtIndex:0];
        [self processLists:[user.map objectForKey:@"list_owned"]];
        
    } failureHandler:^(APError *error) {
        
    }];
    
}

- (void) processLists:(NSArray *) lists{
    
    RLMRealm * realm = [RLMRealm defaultRealm];
    [realm beginWriteTransaction];
    
    for (int i =0; i < [lists count]; i++) {
        APGraphNode * remoteList = [lists objectAtIndex:i];
        
        List * localList = [self getLocallyStoredListsWithId:remoteList.object.objectId];
        if(localList == nil){
            localList = [self createNewListInRealm:realm withName:[remoteList.object getPropertyWithKey:@"name"] andListId:remoteList.object.objectId];
        }
        
        //Get the todos
        NSArray * listTodos = [remoteList.map objectForKey:@"list_todo"];
        
        for (int j =0 ; j< [listTodos count] ; j++) {
            APGraphNode * remoteTodo = [listTodos objectAtIndex:j];
            
            ToDo * localTodo = [self getLocallyStoredTodoWithId:remoteTodo.object.objectId inList:localList];
            if(localTodo == nil){
                localTodo = [self createNewToDoWithToDoId:remoteTodo.object.objectId inList:localList];
            }
            localTodo.text = [remoteTodo.object getPropertyWithKey:@"text"];
            localTodo.completed = [[remoteTodo.object getPropertyWithKey:@"completed"] isEqualToString:@"true"] ? YES : NO;
            
        }
        
    };
    [realm commitWriteTransaction];
    
}

- (List *) createNewListInRealm:(RLMRealm *) realm withName:(NSString *) name andListId:(NSString *) listId{
    List * newList = [[List alloc] init];
    newList.name = name;
    newList.listId = listId;
    [realm addObject:newList];
    return newList;
}

- (ToDo *) createNewToDoWithToDoId:(NSString *)todoId inList:(List *) list{
        ToDo * td = [[ToDo alloc] init];
        td.toDoId = todoId;
        [list.toDos addObject:td];
        return td;
}

- (List *) getLocallyStoredListsWithId:(NSString *) listId{
    NSPredicate *predicate;
    
    predicate = [NSPredicate predicateWithFormat:@"listId == %@", listId];
    
    RLMArray * lists = [List objectsWithPredicate:predicate];
    if([lists count] == 0){
        return nil;
    }
    return (List *)[lists objectAtIndex:0];
}

- (ToDo * ) getLocallyStoredTodoWithId: (NSString *) todoId inList:(List *) list{
    ToDo * td = nil;
    for (int i =0; i < [list.toDos count]; i++) {
        if( [((ToDo *)[list.toDos objectAtIndex:i]).toDoId isEqualToString:todoId]){
            td =(ToDo *)[list.toDos objectAtIndex:i];
            
            break;
        }
    }
    return td;
}

- (NSDate *) getLastUpdatedTime{
    NSDate * time =(NSDate *)[[NSUserDefaults standardUserDefaults] valueForKey:@"lastUpdatedTime"];
    if(time == nil){
        //In case making this call the frst time
        time = [NSDate distantPast];
    }
    return time;
}

- (void) setLastUpdatedDate:(NSDate *) date{
    [[NSUserDefaults standardUserDefaults] setObject:[NSDate date] forKey:@"lastUpdatedTime"];
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

-(NSString *) getStringForAPICallFromDate:(NSDate *)date{
    NSString * dateStr = nil;
    NSDateFormatter *dateFormatter =[[NSDateFormatter alloc]init];
    [dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss.SSSSSSS'Z'"];
    [dateFormatter setTimeZone:[NSTimeZone timeZoneWithName:@"GMT"]];
    [dateFormatter setLocale:[[NSLocale alloc] initWithLocaleIdentifier:@"en_US_POSIX"]];
    dateStr = [dateFormatter stringFromDate:date];
    return dateStr;
    
}
@end
