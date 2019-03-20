//
//  AppDelegate.m
//  PESDKDemo
//
//  Created by oraclechain on 2019/3/18.
//  Copyright © 2019 oraclechain. All rights reserved.
//

#import "AppDelegate.h"
#import <PESDK/PESDK.h>
@interface AppDelegate ()<PEApiDelegate>

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    
    [PEApi registerAppID:@"pesdkDemo"];
    return YES;
}


- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options {
    
    [PEApi handleURL:url delegate:self];

    return YES;
}

- (void)onReceivePEResp:(PEResp *)resp{
    
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"结果" message:[self JSONString:resp.data] preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *action = [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:nil];
    [alert addAction:action];
    [self.window.rootViewController presentViewController:alert animated:YES completion:nil];
}

- (NSString *)JSONString:(id)obj {
    if ([NSJSONSerialization isValidJSONObject:obj]) {
        NSData *data = [NSJSONSerialization dataWithJSONObject:obj options:NSJSONWritingPrettyPrinted error:nil];
        if (data) {
            return [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
        } 
    }
    return nil;
}

@end
