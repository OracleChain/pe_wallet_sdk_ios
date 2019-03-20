//
//  PEReq.h
//  PESDK
//
//  Created by oraclechain on 2019/3/11.
//  Copyright © 2019 oraclechain. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger,PEBlockChain){
    PEBlockChainEOS = 0,
    PEBlockChainBOS
};

/*! @class   PEReq
 * @abstract 发起请求的基本数据
 * @discuss 发起请求时只发送SDK内部的PEReq子类;
 */
@interface PEReq : NSObject


/**
 协议名，钱包用来区分不同协议，本协议为 SimpleWallet
 */
@property (nonatomic, copy, readonly) NSString *protocol;

/**
 协议版本信息，如1.0
 */
@property (nonatomic, copy, readonly) NSString *version;
/**
 过期时间 时间戳 默认不过期
 */
@property (strong, nonatomic) NSNumber *expired;
/**
 dapp名字，用于在钱包APP中展示
 */
@property (nonatomic, copy) NSString *dappName;

/**
 dapp图标Url，用于在钱包APP中展示
 */
@property (nonatomic, copy) NSString *dappIcon;

/**
 底层
 */
@property (nonatomic, assign) PEBlockChain blockchain;

/**
 action 可选login，sign,transfer ,pushActions
 */
@property (nonatomic, copy) NSString *action;

/**
 本次操作的唯一标志
 */
@property (nonatomic, copy) NSString *serialNumber;

/**
 回调url，通过此url 将txId和actionId通过post请求告诉dappServer
 */
@property (nonatomic, copy) NSString *callback;

/**
 * 转账时:
 * @abstract 由dapp生成的业务参数信息，需要钱包在转账时附加在memo中发出去;
 * @discuss  格式为:k1=v1&k2=v2; 钱包转账时还可附加ref参数标明来源;   <可选>
 *           如:k1=v1&k2=v2&ref=walletname
 * 登录时:
 *      作为附加展示信息
 */
@property (nonatomic, copy) NSString *desc;

@end


/*!
 * @class PEPushActionReq
 * @brief 交易/转账数据
 */
@interface PEPushActionReq : PEReq


/**
 EOS,BOS标准action内容
 */
@property (strong, nonatomic) NSArray *actions;

@end

/*!
 * @class PETransferReq
 * @brief 交易/转账数据
 */
@interface PETransferReq : PEReq
/**
 付款人的EOS账号
 */
@property (nonatomic, copy) NSString *from;

/**
 收款人的EOS账号
 */
@property (nonatomic, copy) NSString *to;

/**
 转账数额
 */
@property (nonatomic, copy) NSString *amount;

/**
 转账的token精度，小数点后面的位数
 */
@property (nonatomic, copy) NSString *precision;

/**
 转账的token名称
 */
@property (nonatomic, copy) NSString *symbol;

/**
 转账的token所属的contract
 */
@property (nonatomic, copy) NSString *contract;

/*!
 * @abstract 交易的说明信息，钱包在付款UI展示给用户
 * @discuss  最长不要超过128个字节;
 */
@property (nonatomic, copy) NSString *memo;

@end

