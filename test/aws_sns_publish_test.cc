//
// Created by ninesuns (wangxu298@whu.edu.cn) on 4/4/20.
// Copyright (c) 2020 ninesuns. All rights reserved.
//

#include "aws_sns_notification.h"
#include "gtest/gtest.h"

TEST(AWS_SNS_TEST, CREATE_TOPIC_TEST) {
  EXPECT_EQ(true, createTopics("xuDev"));
}

TEST(AWS_SNS_TEST, LIST_TOPICS_TEST) {
  EXPECT_EQ(true, listTopics());
}

TEST(AWS_SNS_TEST, PUBLISH_TO_TOPIC_TEST) {
}
