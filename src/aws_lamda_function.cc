//
// Created by ninesuns (wangxu298@whu.edu.cn) on 4/12/20.
// Copyright (c) 2020 ninesuns. All rights reserved.
//

#include "aws_lamda_function.h"

static void CreateFunction(Aws::String functionName, Aws::String handler,
                           Aws::Lambda::Model::Runtime runtime, Aws::String roleARN, Aws::String zipfile) {
  Aws::Lambda::Model::CreateFunctionRequest createFunctionRequest;
  createFunctionRequest.SetHandler(handler);
  createFunctionRequest.SetFunctionName(functionName);
  createFunctionRequest.SetRole(Aws::String(roleARN));
  Aws::Lambda::Model::FunctionCode functionCode;

  std::ifstream fc(zipfile.c_str(), std::ios_base::in | std::ios_base::binary);
  Aws::StringStream buffer;
  buffer << fc.rdbuf();

  functionCode.SetZipFile(Aws::Utils::ByteBuffer((unsigned char*) buffer.str().c_str(),
                                                 buffer.str().length()));
  createFunctionRequest.SetCode(functionCode);
  createFunctionRequest.SetRuntime(runtime);

  bool done = false;

  while (!done) {
    auto result = m_client->CreateFunction(createFunctionRequest);
    if(result.IsSuccess()) {
      done = true;
    }
    else {
      if(result.GetError().GetMessage().find("assume") != std::string::npos) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
      }
      else {
        done = true;
        std::cout <<  "[---]\nCreateFunction Error:\n" << result.GetError().GetMessage() << "\n";
      }
    }
  }
}

bool InvokeFunction(std::shared_ptr<Aws::Lambda::LambdaClient> m_client, Aws::String functionName) {
  Aws::Lambda::Model::InvokeRequest invokeRequest;
  invokeRequest.SetFunctionName(functionName);
  invokeRequest.SetInvocationType(Aws::Lambda::Model::InvocationType::RequestResponse);
  invokeRequest.SetLogType(Aws::Lambda::Model::LogType::Tail);
  std::shared_ptr<Aws::IOStream> payload = Aws::MakeShared<Aws::StringStream>("FunctionTest");
  Aws::Utils::Json::JsonValue jsonPayload;
  // just example
  jsonPayload.WithString("key1", "value1");
  jsonPayload.WithString("key2", "value2");
  jsonPayload.WithString("key3", "value3");
  *payload << jsonPayload.View().WriteReadable();
  invokeRequest.SetBody(payload);
  invokeRequest.SetContentType("application/javascript");
  auto result = m_client->Invoke(invokeRequest);

  if(result.IsSuccess()) {
    auto &resultResult = result.GetResult();
    Aws::IOStream& payload = resultResult.GetPayload();
    Aws::String functionResult;
    std::getline(payload, functionResult);
    std::cout << "\n[+++] Lambda result: " << functionResult << "\n";

    auto byteLogResult = Aws::Utils::HashingUtils::Base64Decode(resultResult.GetLogResult());
    Aws::StringStream logResult;
    for(unsigned i = 0; i < byteLogResult.GetLength(); i++)
      logResult << byteLogResult.GetItem(i);
    std::cout << "\n[+++] Log result: " << logResult.str() << "\n";
    return true;
  }
  else {
    return false;
  }
}

bool ListFunctions(std::shared_ptr<Aws::Lambda::LambdaClient> m_client) {
  Aws::Lambda::Model::ListFunctionsRequest listFunctionsRequest;
  auto listFunctionsOutcome = m_client->ListFunctions(listFunctionsRequest);
  if (!listFunctionsOutcome.IsSuccess()) {
    return false;
  }
  auto functions = listFunctionsOutcome.GetResult().GetFunctions();
  std::cout << functions.size() << " function(s):" << std::endl;
  for (const auto &item : functions)
    std::cout << item.GetFunctionName() << std::endl;
  std::cout << std::endl;
}