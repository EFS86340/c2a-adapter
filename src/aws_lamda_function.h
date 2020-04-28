//
// Created by ninesuns (wangxu298@whu.edu.cn) on 3/24/20.
// Copyright (c) 2020 ninesuns. All rights reserved.
//

#ifndef CEPH2AWS_SRC_AWS_LAMDA_FUNCTION_H_
#define CEPH2AWS_SRC_AWS_LAMDA_FUNCTION_H_

// follow the example code from aws

#include <aws/core/Aws.h>
#include <aws/core/utils/Outcome.h>
#include <aws/core/utils/logging/DefaultLogSystem.h>
#include <aws/core/utils/logging/AWSLogging.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/lambda/LambdaClient.h>
#include <aws/lambda/model/CreateFunctionRequest.h>
#include <aws/lambda/model/DeleteFunctionRequest.h>
#include <aws/lambda/model/InvokeRequest.h>
#include <aws/lambda/model/ListFunctionsRequest.h>

#include <fstream>
#include <iostream>

static const char* ALLOCATION_TAG = "helloLambdaWorld";
static std::shared_ptr<Aws::Lambda::LambdaClient> m_client;


static void CreateFunction(Aws::String functionName, Aws::String handler,
    Aws::Lambda::Model::Runtime runtime, Aws::String roleARN, Aws::String zipfile);

// void DeleteFunction(Aws::String functionName) {
//   Aws::Lambda::Model::DeleteFunctionRequest deleteFunctionRequest;
//   deleteFunctionRequest.SetFunctionName(functionName);
//   auto result = m_client->DeleteFunction(deleteFunctionRequest);
//   if(!result.IsSuccess()) {
//     std::cout << "[---]\nDeleteFunction Error:\n" << result.GetError().GetMessage() << "\n";
//   }
// }

bool InvokeFunction(std::shared_ptr<Aws::Lambda::LambdaClient> m_client, Aws::String functionName);

bool ListFunctions(std::shared_ptr<Aws::Lambda::LambdaClient> m_client);

#endif //CEPH2AWS_SRC_AWS_LAMDA_FUNCTION_H_
