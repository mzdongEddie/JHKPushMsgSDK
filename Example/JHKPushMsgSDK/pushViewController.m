//
//  pushViewController.m
//  JHKPushMsgSDK
//
//  Created by mazhendong on 11/05/2018.
//  Copyright (c) 2018 mazhendong. All rights reserved.
//

#import "pushViewController.h"
#import <JHKPushMsgSDK/JHKPushMsg.h>
@interface pushViewController ()

@end

@implementation pushViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    NSLog(@"JHK: My Device ID: %@",[[JHKPushMsg instantedJHKPushMsg] JHKGetAliDeviceId]);
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
