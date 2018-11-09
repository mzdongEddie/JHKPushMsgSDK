//
//  pushAppDelegate.m
//  JHKPushMsgSDK
//
//  Created by mazhendong on 11/05/2018.
//  Copyright (c) 2018 mazhendong. All rights reserved.
//

#import "pushAppDelegate.h"
#import <JHKPushMsgSDK/JHKPushMsg.h>
@interface pushAppDelegate ()<JHKPushMsgDelegate>

@end
@implementation pushAppDelegate
{
    // iOS 10通知中心
    UNUserNotificationCenter *_notificationCenter API_AVAILABLE(ios(10.0));
}

static NSString * const appKey = @"24992448";
static NSString * const appSecret = @"683eb25f81fbcdb677e0d837e9338f01";
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch.
    if (@available(iOS 10.0, *)) {
        [[JHKPushMsg instantedJHKPushMsg] JHKRegisterAPNS:application notificationCenter:_notificationCenter];
    } else {
        [[JHKPushMsg instantedJHKPushMsg] JHKRegistereISOLessThan10APNS:application];
    }
    [[JHKPushMsg instantedJHKPushMsg] JHKInitCloudPushWithAppKey:appKey withAppSecret:appSecret];
    [[JHKPushMsg instantedJHKPushMsg] JHKListenerOnChannelOpened];
    [[JHKPushMsg instantedJHKPushMsg] JHKRegisterMessageReceive];
    [[JHKPushMsg instantedJHKPushMsg] JHKSendNotificationAck:launchOptions];
    [JHKPushMsg instantedJHKPushMsg].jhkPushMsgDelegate = self;	
    return YES;
}

/*
 *  APNs注册成功回调，将返回的deviceToken上传到CloudPush服务器
 */
- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    [[JHKPushMsg instantedJHKPushMsg] JHKRegisterDevice:deviceToken];
}

/*
 *  APNs注册失败回调
 */
- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
    NSLog(@"JHK: didFailToRegisterForRemoteNotificationsWithError %@", error);
}
#pragma mark Notification Open
/*
 *   App处于启动状态时，通知打开回调(IOS < 10)
 */
- (void)application:(UIApplication*)application didReceiveRemoteNotification:(NSDictionary*)userInfo {
    [[JHKPushMsg instantedJHKPushMsg] JHKDidReceiveRemoteNotificationForOldIOSVersion:userInfo application:application];
}

#pragma mark JHKPushMsgDelegate callback
- (void)pushMsgValues:(NSMutableDictionary *)dic {
    NSLog(@"JHK DELEGATE: Receive message title: %@, content: %@.", dic[@"title"], dic[@"body"]);
}

- (void)pushNotificationValues:(NSMutableDictionary *)dic {
    NSLog(@"JHK DELEGATE: Receive notification body: %@.", dic[@"body"]);
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}



@end
