//
//  ReWrap.h
//  libresip
//
//  Created by Ilya Petrov on 1/11/13.
//  Copyright (c) 2013 enodev. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MProxy;
struct reapp;

@interface ReWrap : NSObject {
    struct reapp *app;
    MProxy *proxy;
}

- (id)wrap:(id)ob;
+ (void*)app;

@property (readonly) id proxy;
@property (readonly) void* app;

@end