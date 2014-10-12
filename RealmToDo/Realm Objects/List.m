//
//  List.m
//  RealmToDo
//
//  Created by Neil Unadkat on 05/10/14.
//  Copyright (c) 2014 Appacitive. All rights reserved.
//

#import "List.h"

@implementation List

// Specify default values for properties

+ (NSDictionary *)defaultPropertyValues
{
    return @{@"listId":@"",@"name":@""};
}

// Specify properties to ignore (Realm won't persist these)

//+ (NSArray *)ignoredProperties
//{
//    return @[];
//}

@end
