//
//  ViewController.m
//  PESDKDemo
//
//  Created by oraclechain on 2019/3/18.
//  Copyright © 2019 oraclechain. All rights reserved.
//

#import "ViewController.h"
#import <PESDK/PESDK.h>

@interface ViewController ()

@end

@implementation ViewController

- (IBAction)loginAction:(id)sender {
    PEReq *req = [[PEReq alloc] init];
    req.dappIcon = @"https://pic4.zhimg.com/80/v2-f49c0e9b51f0ed31a683da5e60b8b52b_hd.jpg";
    req.dappName = @"PESDKDemo";
    req.expired  = @(13333333333);
    req.blockchain = PEBlockChainEOS;
    req.action   = @"login";
    req.serialNumber   = @"10001";
    req.callback = @"https://www.baidu.com?a=b&v=c";
    req.desc = @"上链备注";
    
    [PEApi sendReq:req];
}
- (IBAction)transferAction:(id)sender {
    PETransferReq *req = [[PETransferReq alloc] init];
    req.dappIcon = @"https://pic4.zhimg.com/80/v2-f49c0e9b51f0ed31a683da5e60b8b52b_hd.jpg";
    req.dappName = @"PESDKDemo";
    req.expired  = @(13333333333);
    req.blockchain = PEBlockChainEOS;
    req.action   = @"transfer";
    req.serialNumber   = @"10002";
    req.desc = @"上链备注";
    
    req.from = @"zhoiyingbind";
    req.to   = @"zhouyingbinc";
    req.amount = @"0.0001";
    req.precision = @"4";
    req.symbol = @"EOS";
    req.contract = @"eosio.token";
    req.memo = @"转账";
    
    [PEApi sendReq:req];
}
- (IBAction)pushTransactionAction:(id)sender {
    PEPushActionReq *req = [[PEPushActionReq alloc] init];
    req.dappIcon = @"https://pic4.zhimg.com/80/v2-f49c0e9b51f0ed31a683da5e60b8b52b_hd.jpg";
    req.dappName = @"PESDKDemo";
    req.expired  = @(13333333333);
    req.blockchain = PEBlockChainEOS;
    req.action   = @"pushTransactions";
    req.serialNumber   = @"10003";
    req.desc = @"上链备注";
    
    req.actions = @[@{@"account": @"eosio.token",
                             @"name": @"transfer",
                             @"authorization": @[@{@"actor": @"zhoiyingbind",
                                                   @"permission": @"active"}],
                             @"data": @{@"from": @"zhoiyingbind",
                                        @"to": @"zhouyingbinc",
                                        @"quantity": @"0.0001 EOS",
                                        @"memo": @"memomemomemomemo"}
                             }];
    
    [PEApi sendReq:req];
}

@end
