//
// Created by ninesuns (wangxu298@whu.edu.cn) on 3/24/20.
// Copyright (c) 2020 ninesuns. All rights reserved.
//

#ifndef CEPH2AWS_SRC_HTTP_SERVER_H_
#define CEPH2AWS_SRC_HTTP_SERVER_H_

#include "aws_sns_notification.h"
#include "aws_lamda_function.h"
// #include "rgw_aws.h"

#include <pistache/endpoint.h>
#include <pistache/router.h>

#include <iostream>

Pistache::Rest::Router makeAdapterHandler(void);

int test(int x);

#endif //CEPH2AWS_SRC_HTTP_SERVER_H_
