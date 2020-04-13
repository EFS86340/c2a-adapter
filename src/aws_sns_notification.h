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
bool publishToSNS(const std::string& msg_value, const std::string& topic_arn_value) {

  // init setup
  Aws::SDKOptions options;
  // enable logging
  options.loggingOptions.logLevel = Aws::Utils::Logging::LogLevel::Info;
  bool flag = false;
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
      std::cout << "Message published successfully" << std::endl;
      flag = true;
    }
    else {
      std::cout << "Error while publishing message " << ptopic_out.GetError().GetMessage()
        << std::endl;
    }
  }
  Aws::ShutdownAPI(options);
  return flag;
}

bool createTopics(const std::string& topicName) {

  bool debug = false;

  Aws::SDKOptions options;
  Aws::InitAPI(options);
  {
    Aws::String topic_name = topicName;
    Aws::SNS::SNSClient sns;

    Aws::SNS::Model::CreateTopicRequest ct_req;
    ct_req.SetName(topic_name);

    auto ct_out = sns.CreateTopic(ct_req);

    if (ct_out.IsSuccess())
    {
      std::cout << "Successfully created topic " << topic_name << std::endl;
      debug = true;
    }
    else
    {
      std::cout << "Error creating topic " << topic_name << ":" <<
                ct_out.GetError().GetMessage() << std::endl;
    }
  }

  Aws::ShutdownAPI(options);
  return debug;
}

bool listTopics(void) {

  bool debug = false;

  Aws::SDKOptions options;
  Aws::InitAPI(options);
  {
    Aws::SNS::SNSClient sns_client;
    Aws::SNS::Model::ListTopicsRequest lt_req;

    auto lt_out = sns_client.ListTopics(lt_req);

    if (lt_out.IsSuccess())
    {
      debug = true;
      std::cout << "Topics list:" << std::endl;
      for (auto const &topic : lt_out.GetResult().GetTopics())
      {
        std::cout << "  * " << topic.GetTopicArn() << std::endl;
      }
    }
    else
    {
      std::cout << "Error listing topics " << lt_out.GetError().GetMessage() <<
                std::endl;
    }
  }
  Aws::ShutdownAPI(options);
  return debug;
}

#endif //CEPH2AWS_SRC_AWS_SNS_NOTIFICATION_H_
