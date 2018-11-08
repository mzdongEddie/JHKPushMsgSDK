//
//  JHKPushMsg.h
//  JHKPushMsgSDK
//
//  Created by Eddie_Ma on 5/11/18.
//

#import <Foundation/Foundation.h>
#import <UserNotifications/UserNotifications.h>// iOS 10 notification
#import <CloudPushSDK/CloudPushSDK.h>

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
-(void)JHKInitCloudPushWithAppKey:(NSString *)appKey withAppSecret:(NSString *)appSecret;
-(void)JHKListenerOnChannelOpened;
-(void)JHKRegisterMessageReceive;
-(void)JHKSendNotificationAck:(NSDictionary *)launchOptions;
-(void)JHKRegisterDevice:(NSData *)deviceToken;
-(void)JHKDidReceiveRemoteNotificationForOldIOSVersion:(NSDictionary*)userInfo application:(UIApplication*)application;
-(int)JHKBindAccount:(NSString *)account; //flag = 0：账号为空，flag= 1：账号绑定成功，flag=2：账号绑定失败
-(int)JHKUnbindAccount; //flag= 1：账号绑定成功，flag=2：账号绑定失败
-(int)JHKBindTagForDevice:(NSString *)tagStr; //flag= 1：账号绑定成功，flag=2：账号绑定失败
-(int)JHKUnbindTagForDevice:(NSString *)tagStr; //flag= 1：账号绑定成功，flag=2：账号绑定失败
-(int)JHKAddAlias:(NSString *)alias;
-(int)JHKRemoveAlias:(NSString *)alias;
@end


