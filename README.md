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

⚠️：**web调用iOS端PE所用参数需与iOSPESDK保持一致 具体参数说明请查看PESDK注释**

### 回调结果处理

```objective-c

- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options {
    
    [PEApi handleURL:url delegate:self];

    return YES;
}
```

### 回调结果示例

#### 取消/失败

```
{
    //根据action判断行为
	"action": "login/transfer/pushTransactions",
	"message": "Cancel/Failre",
	"protocol": "pe_sdk",
	"ref": "PocketECO",
	"serialNumber": "app_123452312121",
	"version": "1.0"
}
```



#### login成功

```objective-c
{
	account = "zhoiyingbind",
	ref = "PocketECO",
	protocol = "pe_sdk",
	action = "login",
    result = 1,
	serialNumber = "10001",
	public_key = "EOS5T4N5nMpV6hR8BctkAFoL3mZyyuRrW6dpZVdBA8t3MkByB3ouV",
	version = "1.0",
	sign = "SIG_K1_KknA1Lq8YrpP3GBgSd8vXyihxvgdgipwC4y3kKp3MraWKXqaj5fJs8cza3fsQ5yUzy2PfTpEWKoJoZNw55qdYS1KrVS5TZ",
	timestamp = 1553223454310,
}
```



#### transfer成功

```objective-c
{
	action = "transfer",
	ref = "PocketECO",
	protocol = "pe_sdk",
	serialNumber = "10002",
	result = 1,
	message = "ok",
	version = "1.0",
	timestamp = 1553223694214,
	txID = "62d14716681197f80950001b22522a00202427d216d25c4725da3ea44427f486",
}
```



#### pushTransactions成功

```objective-c
{
	action = "pushTransactions",
	ref = "PocketECO",
	protocol = "pe_sdk",
	serialNumber = "10003",
	result = 1,
	message = "ok",
	version = "1.0",
	timestamp = 1553223802747,
	txID = "7849fd2d77c063b0bdc3a73c9f1472eaf83e3a00cd7eae4cdef4461ef2e30093",
}
```

