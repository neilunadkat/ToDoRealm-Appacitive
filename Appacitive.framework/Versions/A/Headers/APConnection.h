//
//  APConnection.h
//  Appacitive-iOS-SDK
//
//  Created by Kauserali Hafizji on 03/09/12.
//  Copyright (c) 2012 Appacitive Software Pvt. Ltd.. All rights reserved.
//

#import "APResponseBlocks.h"
#import "APObject.h"
#import "APQuery.h"

@class APObject;

/**
 A Connection is represents an edge in a graph and is used to connect two APObjects.
 A Connection itself can store data in its properties and attributes fields.
 */

@interface APConnection : NSObject <APObjectPropertyMapping> {
    NSMutableDictionary *_snapShot;
}

@property (nonatomic, strong) NSString *createdBy;
@property (nonatomic, strong) NSString *objectAId;
@property (nonatomic, strong) NSString *objectBId;
@property (nonatomic, strong) APObject *objectA;
@property (nonatomic, strong) APObject *objectB;
@property (nonatomic, strong) NSString *objectId;
@property (nonatomic, strong) NSString *labelA;
@property (nonatomic, strong) NSString *labelB;
@property (nonatomic, strong) NSString *typeA;
@property (nonatomic, strong) NSString *typeB;
@property (nonatomic, strong) NSString *relationId;
@property (nonatomic, strong) NSString *relationType;
@property (nonatomic, strong, readonly) NSString *lastModifiedBy;
@property (nonatomic, strong, readonly) NSDate *utcDateCreated;
@property (nonatomic, strong, readonly) NSDate *utcLastModifiedDate;
@property (nonatomic, strong, readonly) NSNumber *revision;
@property (nonatomic, strong, readonly) NSMutableArray *properties;
@property (nonatomic, strong, readonly) NSMutableDictionary *attributes;
@property (nonatomic, strong) NSArray *tags;
@property (nonatomic, strong) NSMutableSet *tagsToAdd;
@property (nonatomic, strong) NSMutableSet *tagsToRemove;

/** @name Initializing an APConnection instance*/

/**
 Initialize and return an APConnection for the provided relation type.
 
 @param relationType The name of the relation. This is specified while creating the type.
 */
+ (instancetype) connectionWithRelationType:(NSString*)relationType;

/**
 Initialize and return an APConnection for the provided relation type.
 
 @param relationType The name of the relation. This is specified while creating the type.
 */
- (instancetype) initWithRelationType:(NSString*)relationType;


/** @name Creating APConnection */

/**
 @see createConnectionWithSuccessHandler:failureHandler:
 */
- (void) create;

/**
 @see createConnectionWithSuccessHandler:failureHandler:
 */
- (void) createConnectionWithFailureHandler:(APFailureBlock)failureBlock;

/**
 Create an APConnection between two APObjects on the remote server.
 
 This method requires the objectAId, objectBId, labelA and labelB properties to be set.
 
 @param successBlock Block invoked when the create operation is successful.
 @param failureBlock Block invoked when the create operation fails.
 */
- (void) createConnectionWithSuccessHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see createConnectionWithObjectA:objectB:successHandler:failureHandler:
 */
- (void) createConnectionWithObjectA:(APObject*)objectA objectB:(APObject*)objectB;

/**
 @see createConnectionWithObjectA:objectB:successHandler:failureHandler:
 */
- (void) createConnectionWithObjectA:(APObject*)objectA objectB:(APObject*)objectB failureHandler:(APFailureBlock)failureBlock;

/**
 Creates an APConnection between two APObjects.
 
 This method will set labelA and labelB as the typeName of objectA and objectB.
 
 @param objectA The object to create a connection from.
 @param objectB The object to create a connection to.
 @param successBlock Block invoked when the create operation is successful.
 @param failureBlock Block invoked when the create operation fails.
 */
- (void) createConnectionWithObjectA:(APObject*)objectA objectB:(APObject*)objectB successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see createConnectionWithObjectA:objectB:labelA:labelB:successHandler:failureHandler:
 */
- (void) createConnectionWithObjectA:(APObject*)objectA objectB:(APObject*)objectB labelA:(NSString*)labelA labelB:(NSString*)labelB;

/**
 @see createConnectionWithObjectA:objectB:labelA:labelB:successHandler:failureHandler:
 */
- (void) createConnectionWithObjectA:(APObject*)objectA objectB:(APObject*)objectB labelA:(NSString*)labelA labelB:(NSString*)labelB failureHandler:(APFailureBlock)failureBlock;

/**
 Creates an APConnection between two APObjects. The labels on either side of the connection are specified as parameters.
 
 @param objectA The object to create a connection from.
 @param objectB The object to create a connection to.
 @param labelA The label at the starting vertex of the connection.
 @param labelB The label at the end vertex of the connection.
 @param successBlock Block invoked when the create operation is successful.
 @param failureBlock Block invoked when the create operation fails.
 */
- (void) createConnectionWithObjectA:(APObject*)objectA objectB:(APObject*)objectB labelA:(NSString*)labelA labelB:(NSString*)labelB successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see createConnectionWithObjectA:objectB:labelA:labelB:successHandler:failureHandler:
 */
- (void) createConnectionWithObjectAId:(NSString*)objectAId objectBId:(NSString*)objectBId labelA:(NSString*)labelA labelB:(NSString*)labelB;

/**
 @see createConnectionWithObjectA:objectB:labelA:labelB:successHandler:failureHandler:
 */
- (void) createConnectionWithObjectAId:(NSString*)objectAId objectBId:(NSString*)objectBId labelA:(NSString*)labelA labelB:(NSString*)labelB failureHandler:(APFailureBlock)failureBlock;

/**
 Creates an APConnection between two APObjects. The labels on either side of the connection are specified as parameters.
 
 @param objectAId Object Id of the object to create a connection from.
 @param objectBId Object Id of the object to create a connection to.
 @param labelA The label at the starting vertex of the connection.
 @param labelB The label at the end vertex of the connection.
 @param successBlock Block invoked when the create operation is successful.
 @param failureBlock Block invoked when the create operation fails.
 */
- (void) createConnectionWithObjectAId:(NSString*)objectAId objectBId:(NSString*)objectBId labelA:(NSString*)labelA labelB:(NSString*)labelB successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see createConnectionWithObjectA:objectBId:labelA:labelB:successHandler:failureHandler:
 */
- (void) createConnectionWithObjectA:(APObject*)objectA objectBId:(NSString*)objectBId labelA:(NSString*)labelA labelB:(NSString*)labelB;

/**
 @see createConnectionWithObjectA:objectBId:labelA:labelB:successHandler:failureHandler:
 */
- (void) createConnectionWithObjectA:(APObject*)objectA objectBId:(NSString*)objectBId labelA:(NSString*)labelA labelB:(NSString*)labelB failureHandler:(APFailureBlock)failureBlock;

/**
 Creates an APConnection between a new and an existing objects. The labels on either side of the connection are specified as parameters.
 
 @param objectA The object to create a connection from.
 @param objectBId Object Id of the object to create a connection to.
 @param labelA The label at the starting vertex of the connection.
 @param labelB The label at the end vertex of the connection.
 @param successBlock Block invoked when the create operation is successful.
 @param failureBlock Block invoked when the create operation fails.
 */
- (void) createConnectionWithObjectA:(APObject*)objectA objectBId:(NSString*)objectBId labelA:(NSString*)labelA labelB:(NSString*)labelB successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see createConnectionWithObjectA:objectBId:labelA:labelB:successHandler:failureHandler:
 */
- (void) createConnectionWithObjectAId:(NSString*)objectAId objectB:(APObject*)objectB labelA:(NSString*)labelA labelB:(NSString*)labelB;

/**
 @see createConnectionWithObjectA:objectBId:labelA:labelB:successHandler:failureHandler:
 */
- (void) createConnectionWithObjectAId:(NSString*)objectAId objectB:(APObject*)objectB labelA:(NSString*)labelA labelB:(NSString*)labelB failureHandler:(APFailureBlock)failureBlock;

/**
 Creates an APConnection between a new and an existing objects. The labels on either side of the connection are specified as parameters.
 
 @param objectAId Object Id of the object to create a connection from.
 @param objectB The object to create a connection to.
 @param labelA The label at the starting vertex of the connection.
 @param labelB The label at the end vertex of the connection.
 @param successBlock Block invoked when the create operation is successful.
 @param failureBlock Block invoked when the create operation fails.
 */
- (void) createConnectionWithObjectAId:(NSString*)objectAId objectB:(APObject*)objectB labelA:(NSString*)labelA labelB:(NSString*)labelB successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Updating APConnection */

/**
 @see updateConnectionWithRevisionNumber:successHandler:failureHandler:
 */
- (void) updateConnection;

/**
 @see updateConnectionWithRevisionNumber:successHandler:failureHandler:
 */
- (void) updateConnectionWithFailureHandler:(APFailureBlock)failureBlock;

/**
 @see updateConnectionWithRevisionNumber:successHandler:failureHandler:
 */
- (void) updateConnectionWithSuccessHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;


/**
 Method used to update an APConnection.
 
 @param revision Revision number to use for update
 @param successBlock Block invoked when the update operation is successful.
 @param failureBlock Block invoked when the update operation fails.
 */
- (void) updateConnectionWithRevisionNumber:(NSNumber*)revision successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Fetching APConnection */

/**
 @see fetchConnectionWithPropertiesToFetch:successHandler:failureHandler:
 */
- (void) fetchConnection;

/**
 @see fetchConnectionWithPropertiesToFetch:successHandler:failureHandler:
 */
- (void) fetchConnectionWithFailureHandler:(APFailureBlock)failureBlock;

/**
 @see fetchConnectionWithPropertiesToFetch:successHandler:failureHandler:
 */
- (void) fetchConnectionWithSuccessHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 Fetch a connection. This method will use the objectId property to fetch the connection.
 
 @param propertiesToFetch Array of properties to be fetched excluding all other.
 @param successBlock Block invoked when the connection is fetched
 @param failureBlock Block invoked when the fetch call fails
 */
- (void) fetchConnectionWithPropertiesToFetch:(NSArray*)propertiesToFetch successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Deleting APConnection */

/**
 @see deleteConnectionWithSuccessHandler:failureHandler:
 */
- (void) deleteConnection;

/**
 @see deleteConnectionWithSuccessHandler:failureHandler:
 */
- (void) deleteConnectionWithFailureHandler:(APFailureBlock)failureBlock;

/**
 Deletes an APConnection.
 
 This method requires the relationType and objectId to be set.
 
 @param successBlock Block invoked when delete is successful.
 @param failureBlock Block invoked when delete fails.
 */
- (void) deleteConnectionWithSuccessHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Setting and Getting properties, attributes and tags of APObject */

/**
 Method used to add a property to the APObject.
 
 @param keyName key of the data item to be stored.
 @param object Corresponding value to the key.
 */
- (void) addPropertyWithKey:(NSString*)keyName value:(id) object;

/**
 Method used to update an existing property.
 Call update after this method call to persist the update.
 
 @param keyName key of the data item to be updated.
 @param object Corresponding value to the key.
 */
- (void) updatePropertyWithKey:(NSString*)keyName value:(id) object;

/**
 Method used to delete a property.
 Call update after this method call to persist the change.
 
 @param keyName key of the data item to be removed.
 */
- (void) removePropertyWithKey:(NSString*)keyName;

/**
 Method used to retrieve a property using its key.
 
 @param keyName key of the date item to be removed.
 */
- (instancetype) getPropertyWithKey:(NSString*)keyName;

/**
 Method used to add an attibute to the APObject. Attributes are used to store extra information.
 
 @param keyName key of the data item to be stored.
 @param object Corresponding value to the key.
 */
- (void) addAttributeWithKey:(NSString*)keyName value:(id) object;

/**
 Method used to update an attribute.
 Call update after this method call to persist the change
 
 @param keyName key of the attribute to be updated.
 @param object Corresponding value to the key.
 */
- (void) updateAttributeWithKey:(NSString*)keyName value:(id) object;

/**
 Method used to remove an attribute.
 Call update after this method call to persist the change
 
 @param keyName key of the attribute to be removed.
 */
- (void) removeAttributeWithKey:(NSString*)keyName;
@end

/**
 Helper class for APConnection performing class level operations.
 */

@interface APConnections : NSObject

/** @name Searching for APConnection */

/**
 @see searchAllConnectionsWithRelationType:successHandler:failureHandler:
 */
+ (void) searchAllConnectionsWithRelationType:(NSString*)relationType successHandler:(APPagedResultSuccessBlock)successBlock;

/**
 Search for all APConnections of a particular relation type.
 
 @param relationType The relation type that the connections should belong to.
 @param successBlock Block invoked when the search call is successful.
 @param failureBlock Block invoked when the search call fails.
 */
+ (void) searchAllConnectionsWithRelationType:(NSString*)relationType successHandler:(APPagedResultSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see searchAllConnectionsWithRelationType:withQuery:successHandler:failureHandler:
 */
+ (void) searchAllConnectionsWithRelationType:(NSString*)relationType withQuery:(NSString*)query successHandler:(APPagedResultSuccessBlock)successBlock;

/**
 Searches for APConnections and filters the result according to the query provided.
 
 @param relationType The relation type that the connections should belong to.
 @param query String representation of an APQuery instance.
 @param successBlock Block invoked when the search call is successful.
 @param failureBlock Block invoked when the search call fails.
 */
+ (void) searchAllConnectionsWithRelationType:(NSString*)relationType withQuery:(NSString*)query successHandler:(APPagedResultSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see searchAllConnectionsWithRelationType:byObjectId:withLabel:withQuery:successHandler:failureHandler:
 */
+ (void) searchAllConnectionsWithRelationType:(NSString*)relationType byObjectId:(NSString*)objectId withLabel:(NSString*)label withQuery:(NSString*)query successHandler:(APPagedResultSuccessBlock)successBlock;

/**
 Searches for APConnections of a particular relation type by endpoint.
 
 @param relationType The relation type that the connections should belong to.
 @param objectId The object Id of the object of the connection.
 @param label The label of the endpoint of the connection.
 @param query String representation of an APQuery instance.
 @param successBlock Block invoked when the search call is successful.
 @param failureBlock Block invoked when the search call fails.
 */
+ (void) searchAllConnectionsWithRelationType:(NSString*)relationType byObjectId:(NSString*)objectId withLabel:(NSString*)label withQuery:(NSString*)query successHandler:(APPagedResultSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see searchAllConnectionsWithRelationType:fromObjectId:toObjectId:labelB:withQuery:successHandler:failureHandler:
 */
+ (void) searchAllConnectionsWithRelationType:(NSString*)relationType fromObjectId:(NSString *)objectAId toObjectId:(NSString *)objectBId labelB:(NSString*)labelB withQuery:(NSString*)query successHandler:(APPagedResultSuccessBlock)successBlock;

/**
 Searches for APConnections and from a specific object to a specific object.
 
 @param relationType The relation type that the connections should belong to.
 @param objectAId The object Id of the object the connection is from.
 @param objectBId The object Id of the object the connection is to.
 @param labelB The label for objectB endpoint, only required if objectA and objectB are both of the same type.
 @param query String representation of an APQuery instance.
 @param successBlock Block invoked when the search call is successful.
 @param failureBlock Block invoked when the search call fails.
 */
+ (void) searchAllConnectionsWithRelationType:(NSString*)relationType fromObjectId:(NSString *)objectAId toObjectId:(NSString *)objectBId labelB:(NSString*)labelB withQuery:(NSString*)query successHandler:(APPagedResultSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see searchAllConnectionsFromObjectId:toObjectId:withQuery:successHandler:failureHandler:
 */
+ (void) searchAllConnectionsFromObjectId:(NSString *)objectAId toObjectId:(NSString *)objectBId withQuery:(NSString*)query successHandler:(APPagedResultSuccessBlock)successBlock;

/**
 Searches for Connections between the single object and any of the objects in the list and returns the paginated list of all connections .
 
 @param objectAId - ID of the APObject from which the connections are to be retrieved.
 @param objectBId - ID of the APObject to which the connections are to be retrieved.
 @param query String representation of an APQuery instance.
 @param successBlock Block invoked when the search call is successful.
 @param failureBlock Block invoked when the search call fails.
 */
+ (void) searchAllConnectionsFromObjectId:(NSString *)objectAId toObjectId:(NSString *)objectBId withQuery:(NSString*)query successHandler:(APPagedResultSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;


/**
 @see searchAllConnectionsFromObjectId:toObjectIds:withQuery:successHandler:failureHandler:
 */
+ (void) searchAllConnectionsFromObjectId:(NSString *)objectId toObjectIds:(NSArray *)objectIds withQuery:(NSString*)query successHandler:(APPagedResultSuccessBlock)successBlock;

/**
 Searches for Connections between the single object and any of the objects in the list and returns the paginated list of all connections .
 
 @param objectId  The id of the APObject for which the connections are to be retrieved.
 @param objectIds An array of objectIds.
 @param query String representation of an APQuery instance.
 @param successBlock Block invoked when the search call is successful.
 @param failureBlock Block invoked when the search call fails.
 */
+ (void) searchAllConnectionsFromObjectId:(NSString *)objectId toObjectIds:(NSArray *)objectIds withQuery:(NSString*)query successHandler:(APPagedResultSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Fetching APConnection */

/**
 @see fetchConnectionWithRelationType:connectionObjectId:propertiesToFetch:successHandler:failureHandler:
 */
+ (void) fetchConnectionWithRelationType:(NSString*)relationType connectionObjectId:(NSString*)objectId successHandler:(APObjectsSuccessBlock)successBlock;


/**
 @see fetchConnectionWithRelationType:connectionObjectId:propertiesToFetch:successHandler:failureHandler:
 */
+ (void) fetchConnectionWithRelationType:(NSString*)relationType connectionObjectId:(NSString*)objectId successHandler:(APObjectsSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 Fetch an APConnection of a particular relation type.
 
 @param relationType The name of the relation. A connection of this relation name is retrieved.
 @param objectId The id of the connection to retrieve.
 @param propertiesToFetch Array of properties to be fetched excluding all other.
 @param successBlock Block invoked when the fetch call is successful. The block returns the results in the form of an array of objects.
 @param failureBlock Block invoked when the fetch call operation fails.
 */
+ (void) fetchConnectionWithRelationType:(NSString*)relationType connectionObjectId:(NSString*)objectId propertiesToFetch:(NSArray*)propertiesToFetch successHandler:(APObjectsSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see fetchConnectionsWithRelationType:connectionObjectIds:propertiesToFetch:successHandler:failureHandler:
 */
+ (void) fetchConnectionsWithRelationType:(NSString*)relationType connectionObjectIds:(NSArray*)objectIds successHandler:(APObjectsSuccessBlock)successBlock;

/**
 @see fetchConnectionsWithRelationType:connectionObjectIds:propertiesToFetch:successHandler:failureHandler:
 */
+ (void) fetchConnectionsWithRelationType:(NSString*)relationType connectionObjectIds:(NSArray*)objectIds successHandler:(APObjectsSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 Fetches multiple APConnections from the remote server.
 
 @param relationType The name of the relation. Connections of this relation are retrieved.
 @param objectIds An array of objectIds. Connections with these object ids are fetched.
 @param propertiesToFetch Array of properties to be fetched excluding all other.
 @param successBlock Block invoked when the fetch call is successful. The block returns the results in the form of an array of objects.
 @param failureBlock Block invoked when the fetch call operation fails.
 */
+ (void) fetchConnectionsWithRelationType:(NSString*)relationType connectionObjectIds:(NSArray*)objectIds propertiesToFetch:(NSArray*)propertiesToFetch successHandler:(APObjectsSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see fetchObjectsConnectedToObjectOfType:withObjectId:withRelationType:fetchConnections:successHandler:failureHandler:
 */
+ (void) fetchObjectsConnectedToObjectOfType:(NSString*)objectType withObjectId:(NSString*)objectId withRelationType:(NSString*)relationType fetchConnections:(BOOL)fetchConnections successHandler:(APObjectsSuccessBlock)successBlock;

+ (void) fetchObjectsConnectedToObjectOfType:(NSString*)objectType withObjectId:(NSString*)objectId withRelationType:(NSString*)relationType fetchConnections:(BOOL)fetchConnections successHandler:(APObjectsSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 Fetches nodes of coonected objects with connections.
 
 @param objectType Type of the object to fetch the connected objects from.
 @param objectId Object Id of the object to fetch the connected objects from.
 @param relationType The name of the relation. Connections of this relation are retrieved.
 @param fetchConnections BOOL value indicating whether the connections between the objects need to be fetched.
 @param propertiesToFetch Array of properties to be fetched excluding all other.
 @param successBlock Block invoked when the fetch call is successful. The block returns the results in the form of an array of APGraphNodes.
 @param failureBlock Block invoked when the fetch call operation fails.
 */
+ (void) fetchObjectsConnectedToObjectOfType:(NSString*)objectType withObjectId:(NSString*)objectId withRelationType:(NSString*)relationType fetchConnections:(BOOL)fetchConnections propertiesToFetch:(NSArray*)propertiesToFetch successHandler:(APObjectsSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Deleting APConnection */

/**
 @see deleteConnectionsWithRelationType:objectIds:successHandler:failureHandler:
 */
+ (void) deleteConnectionsWithRelationType:(NSString*)relationType objectIds:(NSArray*)objectIds;

/**
 @see deleteConnectionsWithRelationType:objectIds:successHandler:failureHandler:
 */
+ (void) deleteConnectionsWithRelationType:(NSString*)relationType objectIds:(NSArray*)objectIds failureHandler:(APFailureBlock)failureBlock;

/**
 Deletes multiple APConnections.
 
 @param relationType The name of the relation. Connections of this relation name will be deleted.
 @param objectIds An array of objectIds. APConnections having these object ids will be deleted.
 @param successBlock Block invoked when the delete call is successful.
 @param failureBlock Block invoked when the delete call fails.
 */
+ (void) deleteConnectionsWithRelationType:(NSString*)relationType objectIds:(NSArray*)objectIds successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

@end

