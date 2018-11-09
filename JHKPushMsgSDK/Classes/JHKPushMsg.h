//
//  JHKPushMsg.h
//  JHKPushMsgSDK
//
//  Created by Eddie_Ma on 5/11/18.
//

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>// iOS 10 notification

@protocol JHKPushMsgDelegate <NSObject>
@required
-(void)pushNotificationValues:(NSMutableDictionary *)dic;
-(void)pushMsgValues:(NSMutableDictionary *)dic;
@end

@interface JHKPushMsg : NSObject
@property (nonatomic,weak) id<JHKPushMsgDelegate> jhkPushMsgDelegate;
+ (JHKPushMsg *)instantedJHKPushMsg;
-(void)JHKRegisterAPNS:(UIApplication * ) application notificationCenter:(UNUserNotificationCenter *) nc API_AVAILABLE(ios(10.0));
-(void)JHKRegistereISOLessThan10APNS:(UIApplication * ) application;
-(NSString *)JHKInitCloudPushWithAppKey:(NSString *)appKey withAppSecret:(NSString *)appSecret; //返回值: Ali Device ID
-(void)JHKListenerOnChannelOpened;
-(void)JHKRegisterMessageReceive;
-(void)JHKSendNotificationAck:(NSDictionary *)launchOptions;// 点击通知将App从关闭状态启动时，将通知打开回执上报
//APNs注册成功回调，将返回的deviceToken上传到CloudPush服务器。 用在 UIApplicationDelegate: didRegisterForRemoteNotificationsWithDeviceToken里面
-(void)JHKRegisterDevice:(NSData *)deviceToken;
-(void)JHKDidReceiveRemoteNotificationForOldIOSVersion:(NSDictionary*)userInfo application:(UIApplication*)application;
-(int)JHKBindAccount:(NSString *)account; //返回值：flag(int)，flag = 0：账号为空，flag= 1：账号绑定成功，flag=2：账号绑定失败
-(int)JHKUnbindAccount; //返回值：flag(int)，账号解除绑定 flag= 1：账号绑定成功，flag=2：账号绑定失败
-(int)JHKBindTagForDevice:(NSString *)tagStr; //返回值：flag(int)，flag= 1：tag绑定成功，flag=2：tag绑定失败
-(int)JHKUnbindTagForDevice:(NSString *)tagStr; //返回值：flag(int)，flag= 1：tag解绑成功，flag=2：tag解绑失败
-(int)JHKAddAlias:(NSString *)alias; //返回值：flag(int)，flag= 1：别名绑定成功，flag=2：别名绑定失败
-(int)JHKRemoveAlias:(NSString *)alias; //返回值：flag(int)，flag= 1：别名解绑成功，flag=2：别名解绑失败
-(NSString *)JHKGetSDKVersion;
-(NSString *)JHKGetAliDeviceId;//推送SDK初始化结束后调用有效，否则为空
-(void)JHKRegisterToHsSystem: (NSDictionary *)dic;//上报Ali DeviceId，绑定的海信账号等信息给系统端，供后续推送使用
@end


