//
//  PEResp.h
//  PESDK
//
//  Created by oraclechain on 2019/3/11.
//  Copyright © 2019 oraclechain. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, PERespResult){
    PERespResultCanceled = 0,
    PERespResultSuccess,
    PERespResultFailure,
};

@interface PEResp : NSObject

/**
 操作执行状态
 */
@property (assign, nonatomic) PERespResult result;

/**
 返回的信息
 */
@property (copy, nonatomic) NSString *message;
/**
 返回的其他数据
 */
@property (strong, nonatomic) id data;
@end

