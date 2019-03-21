//
//  PEApi.h
//  PESDK
//
//  Created by oraclechain on 2019/3/11.
//  Copyright © 2019 oraclechain. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PEReq.h"
#import "PEResp.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - PEApiDelegate
/*! @brief 接收并处理来自PE的事件
 *
 * PEApiDelegate 会在handleURL:delegate:中使用并触发。
 */
@protocol PEApiDelegate <NSObject>


/*! @brief 发送一个sendReq后，收到PE的回应
 *
 * 收到一个来自PE的处理结果。
 * @param resp 具体的回应内容
 */
-(void)onReceivePEResp:(PEResp*)resp;

@end

@interface PEApi : NSObject


/*!
 * @brief 注册ID
 * @param AppID 为info->URL types中注册的url schemes
 */
+ (void)registerAppID:(NSString *)AppID;

/*! @brief 发送请求到PE
 *
 * @param req 具体的发送请求。
 * @return 成功返回YES，失败返回NO。
 */
+(BOOL)sendReq:(PEReq*)req;

/*!
 * @brief   处理PE的回调跳转
 * @discuss 在AppDelegate -(application:openURL:options:)方法里调用
 */
+ (BOOL)handleURL:(NSURL *)url delegate:(id<PEApiDelegate>)delegate;

/*! @brief 检查PE是否已被用户安装
 *
 * @return PE已安装返回YES，未安装返回NO。
 */
+(BOOL)isPEAppInstalled;

@end

NS_ASSUME_NONNULL_END
