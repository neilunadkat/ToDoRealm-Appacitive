//
//  APBaseQuery.h
//  Appacitive-iOS-SDK
//
//  Created by Kauserali Hafizji on 05/09/12.
//  Copyright (c) 2012 Appacitive Software Pvt. Ltd. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

typedef enum {
    kKilometers,
    kMiles
} DistanceMetric;

typedef enum {
    kAnd,
    kOr
} BooleanOperator;

#pragma mark - APBaseQuery

/**
 APBaseQuery abstract base class
 */

@interface APBaseQuery : NSObject

/**
 Helper method to cast the query object into an appropriate string query that can be interpreted by the Appacitive API
 */
- (NSString*)stringValue;

@end


#pragma mark - SimpleQuery

/**
 An APSimpleQuery is a query string on properties, attributes and aggragates.
 */
@interface APSimpleQuery : APBaseQuery

@property (strong, nonatomic) NSString *fieldName;
@property (strong, nonatomic) NSString *fieldType;
@property (strong, nonatomic) NSString *operation;
@property (strong, nonatomic) NSString *value;

/**
 Method to generate a formatted string from the query object.
 @return NSString representation of query formatted for Appacitive query string standards.
 */
- (NSString*)stringValue;

@end

#pragma mark - CompoundQuery

/**
 An APCompoundQuery is a query formed by compounding multiple instances of APSimpleQuery by either booleanAnd operator or the booleanOR operator.
 */
@interface APCompoundQuery : APSimpleQuery

@property (nonatomic) BooleanOperator boolOperator;
@property (nonatomic, strong, readonly) NSMutableArray *innerQueries;

/**
 Method to initialize an APCompoundQuery object.
 */
- (instancetype)init;

/**
 Method to generate a formatted string from the query object.
 @return NSString representation of query formatted for Appacitive query string standards.
 */
- (NSString*)stringValue;

@end

/**
 An APQueryExpression is a query in the form of an expression depicting the operator, operator type and the operands.
 */
#pragma mark - QueryExpression

@interface APQueryExpression : APSimpleQuery {
    NSString *_name;
    NSString *_type;
}

/**
 Helper method to generate an equal to query string.
 @param value The value of the property to equate to.
*/
- (APSimpleQuery *)isEqualTo:(NSString*)value;

/**
 Helper method to generate an equal to query string for Date type.
 @param date The date to equate to.
 */
- (APSimpleQuery *)isEqualToDate:(NSDate*)date;

/**
 Helper method to generate a not equal to query string.
 @param value the value of the property to equate to.
  */
- (APSimpleQuery *)isNotEqualTo:(NSString*)value;

/**
 Helper method to generate a not equal to query string.
 @param date the date to equate to.
 */
- (APSimpleQuery *)isNotEqualToDate:(NSDate*)date;

/**
 Helper method to generate a greater than query string.
 @param value value that the property should be greater than.
 */
- (APSimpleQuery *)isGreaterThan:(NSString*)value;

/**
 Helper method to generate a less than query string.
 @param value the value the property should be less than.
 */
- (APSimpleQuery *)isLessThan:(NSString*)value;

/**
 Helper method to generate a greater than or eqal to query string.
 @param value value that the property should be greater than or equal to.
 */
- (APSimpleQuery *)isGreaterThanOrEqualTo:(NSString*)value;

/**
 Helper method to generate a less than or equal to query string.
 @param value the value the property should be less than or equal to.
 */
- (APSimpleQuery *)isLessThanOrEqualTo:(NSString*)value;

/**
 Helper method to generate a greater than query string.
 @param date The date that the property should be greater than.
 */
- (APSimpleQuery *)isGreaterThanDate:(NSDate*)date;

/**
 Helper method to generate a less than query string.
 @param date The date the property should be less than.
 */
- (APSimpleQuery *)isLessThanDate:(NSDate*)date;

/**
 Helper method to generate a greater than or eqal to query string.
 @param date The date that the property should be greater than or equal to.
 */
- (APSimpleQuery *)isGreaterThanOrEqualToDate:(NSDate*)date;

/**
 Helper method to generate a less than or equal to query string.
 @param date The date the property should be less than or equal to.
 */
- (APSimpleQuery *)isLessThanOrEqualToDate:(NSDate*)date;

/**
 Helper method to generate a query string for like condition.
 @param value the value of the property.
 */
- (APSimpleQuery *)isLike:(NSString*)value;

/**
 Helper method to generate a query string for like condition.
 @param value the value of the property.
 */
- (APSimpleQuery *)startsWith:(NSString*)value;

/**
 Helper method to generate a query string for like condition.
 @param value the value of the property.
 */
- (APSimpleQuery *)endsWith:(NSString*)value;

/**
 Helper method to generate a query string for match condition.
 @param value the value of the property.
 */
- (APSimpleQuery *)matches:(NSString*)value;

/**
 Helper method to generate a between query string.
 @param value1 the lower end value of the property
 @param value2 the higher end value of the property
 */
- (APSimpleQuery *)isBetweenValue:(NSString*)value1 andValue:(NSString*)value2;

/**
 Helper method to generate a between query string.
 @param date1 the lower end date value of the property
 @param date2 the higher end date value of the property
 */
- (APSimpleQuery *)isBetweenDate:(NSDate*)date1 andDate:(NSDate*)date2;

/**
 Method to initialize a queryExpression object with property name and type.
 @param name Name of the property to be used as an operand of the query expression.
 @param type Type of property.
 */
- (instancetype) initWithProperty:(NSString*)name ofType:(NSString*)type;

@end

#pragma mark - QueryString

/**
 An APBaseQuery is the generic form of query for query string parameters.
 */
@interface APQuery : APBaseQuery

@property (strong, nonatomic) NSString *freeText;
@property (strong, nonatomic) NSString *orderBy;
@property (nonatomic) NSInteger pageNumber;
@property (nonatomic) NSInteger pageSize;
@property (nonatomic) BOOL isAsc;
@property (nonatomic) APBaseQuery *filterQuery;
@property (nonatomic) NSArray* propertiesToFetch;

/**
 Method to crete a query expression with query operand as a property of an APObject.
 @param property Property to be used an operand of the query expression.
 */
+ (APQueryExpression*)queryExpressionWithProperty:(NSString*)property;

/**
 Method to crete a query expression with query operand as an attribute of an APObject.
 @param attribute Attribute to be used an operand of the query expression.
 */
+ (APQueryExpression*)queryExpressionWithAttribute:(NSString*)attribute;

/**
 Method to crete a query expression with query operand as an aggregate of an APObject.
 @param aggregate Aggregate to be used an operand of the query expression.
 */
+ (APQueryExpression*)queryExpressionWithAggregate:(NSString*)aggregate;

/**
 Method to crete a compound query by boolean ANDing all the operands in the queries array.
 @param queries Array of operands for the boolean AND operation.
 */
+ (APCompoundQuery *)booleanAnd:(NSArray*)queries;

/**
 Method to crete a compound query by boolean ORing all the operands in the queries array.
 @param queries Array of operands for the boolean OR operation.
 */
+ (APCompoundQuery *)booleanOr:(NSArray*)queries;

/**
 Helper method to generate a query string for geocode search.
 @param propertyName name of the property to search for.
 @param location the geocode to search for
 @param distanceMetric the distance either in km or miles
 @param radius the radios around the location to look for
 Example query would be +[APBaseQuery queryForGeoCodeProperty:@"location" nearLocation:{123, 123} distanceMetric:kilometers radius:12]
 This would return "*location within_circle 123,123,12" which is the format Appacitive understands.
 */
+ (APSimpleQuery*)queryWithRadialSearchForProperty:(NSString*)propertyName  nearLocation:(CLLocation*)location withinRadius:(NSNumber*)radius usingDistanceMetric:(DistanceMetric)distanceMetric;

/**
 Helper method to generate a query string for polygon search.
 @param propertyName name of the property to search for.
 @param coordinates an array of CLLocation coordinates. The array needs to have a minimum of three coordinates.
 Example query would be +[APBaseQuery queryForPolygonSearch:@"location" withPolygonCoordinates:coordinates]
 This would return "*location within_polygon {lat,long} | {lat,long} | {lat,long}" which is the format Appacitive understands.
 */
+ (APSimpleQuery*)queryWithPolygonSearchForProperty:(NSString*)propertyName withPolygonCoordinates:(NSArray*)coordinates;

/**
 Helper method to generate a query string for search with tags.
 @param tags An array of tags to search for.
 */
+ (APSimpleQuery*)queryWithSearchUsingOneOrMoreTags:(NSArray*)tags;

/**
 Helper method to generate a query string for search with tags.
 @param tags An array of tags to search for.
 */
+ (APSimpleQuery*)queryWithSearchUsingAllTags:(NSArray*)tags;

/**
 Helper method to generate a query string to search for free text.
 @param freeTextTokens free text tokens for the query.
 */
- (void) queryWithSearchUsingFreeText:(NSArray*)freeTextTokens;

/**
 Helper method to cast the query object into an appropriate string query that can be interpreted by the Appacitive API
 */
- (NSString*)stringValue;

@end

