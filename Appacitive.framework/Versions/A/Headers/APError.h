//
//  APError.h
//  Appacitive-iOS-SDK
//
//  Created by Kauserali Hafizji on 29/08/12.
//  Copyright (c) 2012 Appacitive Software Pvt. Ltd. All rights reserved.
//

@interface APError : NSError
@property (nonatomic, strong) NSString *referenceId;
@property (nonatomic, strong) NSString *version;
@property (nonatomic, strong) NSString *statusCode;
@end

