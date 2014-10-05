//
//  APObject.h
//  Appacitive-iOS-SDK
//
//  Created by Kauserali Hafizji on 29/08/12.
//  Copyright (c) 2012 Appacitive Software Pvt. Ltd. All rights reserved.
//

#import "APResponseBlocks.h"
#import "APQuery.h"
#import "APAccessControl.h"

@class APError;

extern NSString *const OBJECT_PATH;

@protocol APObjectPropertyMapping <NSObject>

@required

- (void) setPropertyValuesFromDictionary:(NSDictionary*)dictionary;

@end
/**
 An APObject is a basic unit to store information in.
 It represents an instance of a type.
 Data can be stored in key-value pairs in the properties and attributes fields.
 */
@interface APObject : NSObject <APObjectPropertyMapping> {
    
@protected
    NSString *_objectId;
    NSString *_lastModifiedBy;
    NSDate *_utcDateCreated;
    NSDate *_utcLastUpdatedDate;
    NSNumber *_revision;
    NSMutableArray *_properties;
    APAccessControl *_acl;
    NSMutableDictionary *_attributes;
    NSMutableDictionary *_snapShot;
}

@property (nonatomic, strong) NSString *createdBy;
@property (nonatomic, strong, readonly) NSString *objectId;
@property (nonatomic, strong, readonly) NSString *lastModifiedBy;
@property (nonatomic, strong, readonly) NSDate *utcDateCreated;
@property (nonatomic, strong, readonly) NSDate *utcLastUpdatedDate;
@property (nonatomic, strong, readonly) NSNumber *revision;
@property (nonatomic, strong, readonly) NSMutableArray *properties;
@property (nonatomic, strong, readonly) NSMutableDictionary *attributes;
@property (nonatomic, strong) NSString *type;
@property (nonatomic, strong) NSArray *tags;
@property (nonatomic, strong) NSMutableSet *tagsToAdd;
@property (strong, nonatomic) NSMutableSet *tagsToRemove;
@property (strong, nonatomic) NSMutableDictionary *propertiesToAdd;
@property (strong, nonatomic) NSMutableDictionary *propertiesToAddUnique;
@property (strong, nonatomic) NSMutableDictionary *propertiesToRemove;
@property (strong, nonatomic) NSMutableDictionary *propertiesToIncrement;
@property (strong, nonatomic) NSMutableDictionary *propertiesToDecrement;
@property (strong, nonatomic) APAccessControl *acl;
@property (nonatomic, weak) id <APObjectPropertyMapping> delegate;

#pragma mark - APObject Methods

/** @name Initializing an APObject instance */

/**
 Initialize and return an autoreleased APObject for the provided type name.
 @param typeName The type this object represents.
 */
- (instancetype) initWithTypeName:(NSString*)typeName;

/**
 Initialize and return an autoreleased APObject for the provided type name and objectId.
 @param typeName The type this object represents.
 @param objectId objectId of the object
 */
- (instancetype) initWithTypeName:(NSString*)typeName objectId:(NSString*)objectId;

/**
 Initialize and return an autoreleased APObject for the provided type name.
 @param typeName The type this object represents.
 */
+ (APObject*)objectWithTypeName:(NSString*)typeName;

/**
 Initialize and return an autoreleased APObject for the provided type name and objectId.
 @param typeName The type this object represents.
 @param objectId objectId of the object
 */
+ (APObject*)objectWithTypeName:(NSString*)typeName objectId:(NSString*)objectId;

/** @name Fetching APObject */

/**
 @see fetchWithPropertiesToFetch:successHandler:failureHandler:
 */
- (void) fetch;

/**
 @see fetchWithPropertiesToFetch:successHandler:failureHandler:
 */
- (void) fetchWithFailureHandler:(APFailureBlock)failureBlock;

/**
 @see fetchWithPropertiesToFetch:successHandler:failureHandler:
 */
- (void) fetchWithSuccessHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 Method used to fetch an APObject.
 This method will use the type and objectId properties to fetch the object. If the objectId and type is not set, results are unexpected.
 @param propertiesToFetch Array of properties to be fetched excluding all other.
 @param successBlock Block invoked when the fetch operation is successful.
 @param failureBlock Block invoked when the fetch operation fails.
 */
- (void) fetchWithPropertiesToFetch:(NSArray*)propertiesToFetch successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see fetchObjectsWithObjectIds:typeName:propertiesToFetch:successHandler:failureHandler:
 */
+ (void) fetchObjectWithObjectId:(NSString*)objectId typeName:(NSString*)typeName successHandler:(APObjectsSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see fetchObjectsWithObjectIds:typeName:propertiesToFetch:successHandler:failureHandler:
 */
+ (void) fetchObjectsWithObjectIds:(NSArray*)objectIds typeName:(NSString *)typeName successHandler:(APObjectsSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 Retrieves multiple APObjects of a particular type.
 @param objectIds The ids of the objects.
 @param typeName The type name the objects belong to.
 @param propertiesToFetch Array of properties to be fetched excluding all other.
 @param successBlock Block invoked when the retrieve operation succeeds.
 @param failureBlock Block invoked when the failure operation succeeds.
 */
+ (void) fetchObjectsWithObjectIds:(NSArray*)objectIds typeName:(NSString *)typeName propertiesToFetch:(NSArray*)propertiesToFetch successHandler:(APObjectsSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Saving APObject */

/**
 @see saveObjectWithSuccessHandler:failureHandler:
 */
- (void) saveObject;

/**
 @see saveObjectWithSuccessHandler:failureHandler:
 */
- (void) saveObjectWithFailureHandler:(APFailureBlock)failureBlock;

/**
 Save the object on the remote server.
 This method will save an object in the background. If save is successful the properties will be updated and the successBlock will be invoked. If not the failure block is invoked.
 @param successBlock Block invoked when the save operation is successful
 @param failureBlock Block invoked when the save operation fails.
 
 */
- (void) saveObjectWithSuccessHandler:(APResultSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Updating APObject */

/**
 @see updateObjectWithRevisionNumber:successHandler:failureHandler:
 */
- (void) updateObject;

/**
 @see updateObjectWithRevisionNumber:successHandler:failureHandler:
 */
- (void) updateObjectWithFailureHandler:(APFailureBlock)failureBlock;

/**
 @see updateObjectWithRevisionNumber:successHandler:failureHandler:
 */
- (void) updateObjectWithSuccessHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 Method used to update an APObject.
 @param revision the current revision number of the object on Appacitive.
 @param successBlock Block invoked when the update operation is successful.
 @param failureBlock Block invoked when the update operation fails.
 */
- (void) updateObjectWithRevisionNumber:(NSNumber*)revision successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Searching for APObject */

/**
 @see searchAllObjectsWithTypeName:successHandler:failureHandler:
 */
+ (void) searchAllObjectsWithTypeName:(NSString*)typeName successHandler:(APPagedResultSuccessBlock)successBlock;

/**
 Searches for all APObjects of a particular type.
 @param typeName The type that the objects should belong to.
 @param successBlock Block invoked when the search call is successful.
 @param failureBlock Block invoked when search call fails.
 */
+ (void) searchAllObjectsWithTypeName:(NSString*)typeName successHandler:(APPagedResultSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see searchAllObjectsWithTypeName:withQuery:successHandler:failureHandler:
 */
+ (void) searchAllObjectsWithTypeName:(NSString*)typeName withQuery:(NSString*)query successHandler:(APPagedResultSuccessBlock)successBlock;

/**
 Searches for APObjects and filters the results according to the query string.
 @param typeName The type of the objects you want to search.
 @param query String representation of an APQuery instance.
 @param successBlock Block invoked when the search call is successful.
 @param failureBlock Block invoked when the search call fails.
 */
+ (void) searchAllObjectsWithTypeName:(NSString*)typeName withQuery:(NSString*)query successHandler:(APPagedResultSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;


/** @name Deleting APObject */
 
 /**
 @see deleteObjectWithSuccessHandler:failureHandler:
 */
- (void) deleteObject;

/**
 @see deleteObjectWithSuccessHandler:failureHandler:
 */
- (void) deleteObjectWithFailureHandler:(APFailureBlock)failureBlock;

/**
 Deletes and APObject.
 This method will delete the object on the remote server. It will not nullify the current properties or attributes.
 @param successBlock Block invoked when delete operation is successful
 @param failureBlock Block invoked when delete operation fails.
 */
- (void) deleteObjectWithSuccessHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/**
 @see deleteObjectWithConnectingConnectionsSuccessHandler:failureHandler:
 */
- (void) deleteObjectWithConnectingConnections;

/**
 @see deleteObjectWithConnectingConnectionsSuccessHandler:failureHandler:
 */
- (void) deleteObjectWithConnectingConnections:(APFailureBlock)failureBlock;

/**
 Deletes an APObject along with any connections it has.
 @param successBlock Block invoked when delete operation is successful
 @param failureBlock Block invoked when delete operation is unsuccessful
 */
- (void) deleteObjectWithConnectingConnectionsSuccessHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

/** @name Setting and Getting properties, attributes and tags of APObject */

/**
 Method used to add a property to the APObject.
 @param keyName key of the data item to be stored.
 @param object Corresponding value to the key.
 */
- (void) addPropertyWithKey:(NSString*)keyName value:(id)object;

/**
 Method used to update an existing property.
 Call update after this method call to persist the update.
 @param keyName key of the data item to be updated.
 @param object Corresponding value to the key.
 */
- (void) updatePropertyWithKey:(NSString*)keyName value:(id)object;

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
- (id) getPropertyWithKey:(NSString*)keyName;

/**
 Method to add values to a multivalued property.
 @param propertyName key/name of the multivalued property.
 @param values array of values to be added to the multivalued property.
 */
- (void) addValues:(NSArray*)values toMultivaluedProperty:(NSString*)propertyName;

/**
 Method to add unique values to a multivalued property.
 @param propertyName key/name of the multivalued property.
 @param values array of values to be added to the multivalued property.
 */
- (void) addUniqueValues:(NSArray*)values toMultivaluedProperty:(NSString*)propertyName;

/**
 Method to remove values from a multivalued property.
 @param propertyName key/name of the multivalued property.
 @param values array of values to be removed from the multivalued property.
 */
- (void) removeValues:(NSArray*)values fromMultivaluedProperty:(NSString*)propertyName;

/**
 Method to increment value of a numeric property.
 @param propertyName key/name of the property.
 @param value the value that the property should be inceremneted by.
 */
- (void) incrementValueOfProperty:(NSString*)propertyName byValue:(NSNumber*)value;

/**
 Method to decrement value of a numeric property.
 @param propertyName key/name of the property.
 @param value the value that the property should be decremented by.
 */
- (void) decrementValueOfProperty:(NSString*)propertyName byValue:(NSNumber*)value;

/**
 Method used to add an attibute to the APObject.
 Attributes are used to store extra information.
 @param keyName key of the data item to be stored.
 @param object Corresponding value to the key.
 */
- (void) addAttributeWithKey:(NSString*)keyName value:(id)object;

/**
 Method used to update an attribute.
 Call update after this method call to persist the change
 @param keyName key of the attribute to be updated.
 @param object Corresponding value to the key.
 */
- (void) updateAttributeWithKey:(NSString*)keyName value:(id)object;

/**
 Method used to remove an attribute.
 Call update after this method call to persist the change
 @param keyName key of the attribute to be removed.
 */
- (void) removeAttributeWithKey:(NSString*)keyName;

/**
 Method to add tags to object.
 @param tag The tag you wish to add.
 */
- (void) addTag:(NSString*)tag;

/**
 Method to remove tags from object.
 @param tag The tag you wish to remove.
 */
- (void) removeTag:(NSString*)tag;

@end

#pragma mark - APOBjects Interface

/**
 Helper class for APObject performing class level operations.
 */
@interface APObjects : NSObject

/** @name Deleting APObject */

/**
 @see deleteObjectsWithIds:typeName:successHandler:failureHandler:
 */
+ (void) deleteObjectsWithIds:(NSArray*)objectIds typeName:(NSString*)typeName failureHandler:(APFailureBlock)failureBlock;

/**
 Deletes multiple APObjects.
 @param objectIds The ids of the objects to delete.
 @param typeName The type that the objects belong to.
 @param successBlock Block invoked when the multi delete operation succeeds.
 @param failureBlock Block invoked when the multi delete operation fails.
 */
+ (void) deleteObjectsWithIds:(NSArray*)objectIds typeName:(NSString*)typeName successHandler:(APSuccessBlock)successBlock failureHandler:(APFailureBlock)failureBlock;

@end

