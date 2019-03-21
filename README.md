# pe_wallet_sdk_ios
该SDK用于拉起PocketECO钱包，实现登陆，转账以及其他相关action操作。

## 环境

* iOS最低支持版本为**iOS8**

* PocketECO版本需**大于3.3.0**

## 安装

1. 添加`PESDK.framework`到你的项目

2. 在Build settings -> Other Linker Flags, 加入 **-ObjC**

3. 注册URL Schemes 在Info -> URL types 注册一个scheme

4. 设置白名单 在info.plist -> **LSApplicationQueriesSchemes**中添加**pocketeos**

## 使用

### 导入头文件

``` #import <PESDK/PESDK.h>```

### 注册scheme

`[PEApi registerAppID:@"pesdkDemo"];`

### App调用登陆示例

```objective-c
PEReq *req = [[PEReq alloc] init];
req.dappIcon = @"iconURL";
req.dappName = @"PESDKDemo";
req.expired  = @(1569895200);
req.blockchain = PEBlockChainEOS;
req.action   = @"login";
req.serialNumber   = @"xxxx";
    
[PEApi sendReq:req];
```

### web调用登陆示例

```javascript
/**
* param 值为 url encode后的 json字符串 
*/
window.location.href = "pocketeos://?param='%7B%0A%20%20%22action%22%20:%20%22login%22......'"

```

⚠️：web调用iOS端PE所用参数需与iOSPESDK保持一致

### 回调结果处理

```objective-c

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options {
    
    [PEApi handleURL:url delegate:self];

    return YES;
}
```





