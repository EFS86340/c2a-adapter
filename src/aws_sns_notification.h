//
// Created by ninesuns (wangxu298@whu.edu.cn) on 3/24/20.
// Copyright (c) 2020 ninesuns. All rights reserved.
//

#ifndef CEPH2AWS_SRC_AWS_SNS_NOTIFICATION_H_
#define CEPH2AWS_SRC_AWS_SNS_NOTIFICATION_H_

// follow the example code from aws
#include <aws/core/Aws.h>
#include <aws/sns/SNSClient.h>
#include <aws/sns/model/CreateTopicRequest.h>
#include <aws/sns/model/CreateTopicResult.h>
#include <aws/sns/model/ListTopicsRequest.h>
#include <aws/sns/model/ListTopicsResult.h>
#include <aws/sns/model/PublishRequest.h>
#include <aws/sns/model/PublishResult.h>

#include <iostream>

// callback
bool publishToSNS(const std::string& msg_value, const std::string& topic_arn_value);

bool createTopics(const std::string& topicName);

bool listTopics(void);

#endif //CEPH2AWS_SRC_AWS_SNS_NOTIFICATION_H_
