//
//  APGraphNode.h
//  Appacitive-iOS-SDK
//
//  Created by Pratik on 07-01-14.
//  Copyright (c) 2014 Appacitive Software Pvt. Ltd. All rights reserved.
//

#import "APResponseBlocks.h"
#import "APObject.h"
#import "APConnection.h"

/**
 An APGraphNode is a hierarchical representation of the APObjects along with their connections.
 */
@interface APGraphNode : NSObject {
    APObject *_object;
    APConnection *_connection;
    NSDictionary *_map;
}

@property (strong, nonatomic) APObject* object;
@property (strong, nonatomic) APConnection* connection;
@property (strong, nonatomic) NSDictionary* map;

- (NSArray*)getChildrenOf:(NSString*)objectId;

/** @name Apply graph queries */

/**
 @see applyFilterGraphQuery:usingPlaceHolders:successHandler:failureHandler:
 */
+ (void) applyFilterGraphQuery:(NSString*)query usingPlaceHolders:(NSDictionary*)placeHolders successHandler:(APObjectsSuccessBlock)successBlock;

/**
 Searches for APObjects that satisfy the filter graph query.
 
 A filter query is a kind that does not have a starting point in the graph. All the APObjects that satisfy the query will be returned. To know more visit http://wwww.appacitive.com
 
 @param query A string representing the filter graph query or name of a saved projection query from the Appacitive portal.
 @param placeHolders placeHolders for the query.
 @param successBlock Block invoked when query is successfully executed.
 @param failureBlock Block invoked when query execution fails.
 */
+ (void) applyFilterGraphQuery:(NSString*)query usingPlaceHolders:(NSDictionary*)placeHolders successHandler:(APObjectsSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see applyProjectionGraphQuery:usingPlaceHolders:forObjectsIds:successHandler:failureHandler:
 */
+ (void) applyProjectionGraphQuery:(NSString *)query usingPlaceHolders:(NSDictionary*)placeHolders forObjectsIds:(NSArray*)objectIds successHandler:(APObjectsSuccessBlock)successBlock;

/**
 Searches for APObjects that satisfy the projection graph query.
 
 A projection query will search for results from a starting node in the graph. To know more visit http://wwww.appacitive.com
 
 @param query A string representing the projection graph query or name of a saved projection query from the Appacitive portal.
 @param placeHolders placeHolders for the query.
 @param objectIds objectIds for query.
 @param successBlock Block invoked when query is successfully executed.
 @param failureBlock Block invoked when query execution fails.
 */
+ (void) applyProjectionGraphQuery:(NSString *)query usingPlaceHolders:(NSDictionary*)placeHolders forObjectsIds:(NSArray*)objectIds successHandler:(APObjectsSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

@end
