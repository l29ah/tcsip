//
//  TXSipReg.h
//  Texr
//
//  Created by Ilya Petrov on 8/26/12.
//  Copyright (c) 2012 Ilya Petrov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TXBaseOp.h"

struct tcp_conn;

typedef enum {
    REG_NONE,
    REG_START=1,
    REG_AUTH=2,
    REG_ONLINE=4
} reg_state_t;

@interface TXSipReg : TXBaseOp {
    struct sipreg *reg;
    struct tcp_conn *upstream;
    CFReadStreamRef upstream_ref;
    reg_state_t rstate;
    NSString* instance_id;
}

- (void) setup;

- (void) send;

- (void) response: (int) status phrase:(const char*)phrase;
- (void) setInstanceId: (NSString*) pUUID;
- (void) voipDest:(struct tcp_conn *)conn;

@end
