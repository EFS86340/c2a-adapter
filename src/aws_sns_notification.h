//
// Created by ninesuns (wangxu298@whu.edu.cn) on 3/24/20.
// Copyright (c) 2020 ninesuns. All rights reserved.
//

#ifndef CEPH2AWS_SRC_AWS_SNS_NOTIFICATION_H_
#define CEPH2AWS_SRC_AWS_SNS_NOTIFICATION_H_

// follow the example code from aws
#include <aws/core/Aws.h>
#include <aws/sns/SNSClient.h>
#include <aws/sns/model/PublishRequest.h>
#include <aws/sns/model/PublishResult.h>

#include <iostream>

// callback
void publishToSNS(const std::string& msg_value, const std::string& topic_arn_value) {

  // init setup
  Aws::SDKOptions options;
  Aws::InitAPI(options);
  {
    // enter the aws part
    Aws::SNS::SNSClient snsClient;
    Aws::String message = msg_value;
    Aws::String topic_arn = topic_arn_value;

    Aws::SNS::Model::PublishRequest ptopic_req;
    ptopic_req.SetMessage(message);
    ptopic_req.SetTopicArn(topic_arn);

    auto ptopic_out = snsClient.Publish(ptopic_req);

    if(ptopic_out.IsSuccess()) {
      std::cout << "Message publiched successfully" << std::endl;
    }
    else {
      std::cout << "Error while publishing message " << ptopic_out.GetError().GetMessage()
        << std::endl;

    }

  }
  Aws::ShutdownAPI(options);

}

#endif //CEPH2AWS_SRC_AWS_SNS_NOTIFICATION_H_
