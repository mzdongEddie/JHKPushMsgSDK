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
-(void)JHKInitCloudPushWithAppKey:(NSString *)appKey withAppSecret:(NSString *)appSecret;
-(void)JHKListenerOnChannelOpened;
-(void)JHKRegisterMessageReceive;
-(void)JHKSendNotificationAck:(NSDictionary *)launchOptions;
-(void)JHKRegisterDevice:(NSData *)deviceToken;
-(void)JHKDidReceiveRemoteNotificationForOldIOSVersion:(NSDictionary*)userInfo application:(UIApplication*)application;
@end


