//
// Created by ninesuns (wangxu298@whu.edu.cn) on 4/12/20.
// Copyright (c) 2020 ninesuns. All rights reserved.
//

#include "aws_lamda_function.h"
#include <gtest/gtest.h>

TEST(AWS_LAMBDA_API, CreateFunction) {
  Aws::SDKOptions options;
  Aws::InitAPI(options);
  {
    Aws::Client::ClientConfiguration clientConfig;
    auto m_client = Aws::MakeShared<Aws::Lambda::LambdaClient>(ALLOCATION_TAG, clientConfig);


  }
  Aws::ShutdownAPI(options);
}

TEST(AWS_LAMBDA_TEST, LIST_FUNCTION_TEST) {
  Aws::SDKOptions options;
  Aws::InitAPI(options);
  {
    Aws::Client::ClientConfiguration clientConfig;
    auto m_client = Aws::MakeShared<Aws::Lambda::LambdaClient>(ALLOCATION_TAG, clientConfig);
    EXPECT_EQ(true, ListFunctions(m_client));
  }
  Aws::ShutdownAPI(options);
}

TEST(AWS_LAMBDA_TEST, INVOKE_FUNCTION_TEST) {
  Aws::SDKOptions options;
  Aws::InitAPI(options);
  {
    Aws::Client::ClientConfiguration clientConfig;
    auto m_client = Aws::MakeShared<Aws::Lambda::LambdaClient>(ALLOCATION_TAG, clientConfig);
    EXPECT_EQ(true, InvokeFunction(m_client, "gsoc20"));
  }
}