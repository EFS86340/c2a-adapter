//
// Created by ninesuns (wangxu298@whu.edu.cn) on 3/24/20.
// Copyright (c) 2020 ninesuns. All rights reserved.
//

#ifndef CEPH2AWS_SRC_HTTP_SERVER_H_
#define CEPH2AWS_SRC_HTTP_SERVER_H_

#include <pistache/endpoint.h>
#include <rapidjson/document.h>

#include <iostream>

class HelloHandler : public Pistache::Http::Handler {
 public:
  HTTP_PROTOTYPE(HelloHandler)

  void onRequest(const Pistache::Http::Request &request, Pistache::Http::ResponseWriter response) override {
    // UNUSED(request);
    //
    std::cout << "http server got: " << request.body() << std::endl;

    response.send(Pistache::Http::Code::Ok, "hello, ceph\n");

    // parse the JSON
    rapidjson::Document document;
    document.Parse(request.body().c_str());
    // print some basic notification info
    assert(document.HasMember("Records"));
    rapidjson::Value& recordArray = document["Records"];
    assert(recordArray.IsArray());
    rapidjson::Value& field = recordArray[0];
    assert(field.IsObject());
    for(auto& info : field.GetObject()) {
      std::cout << "[+] field: " << info.name.GetString() << std::endl;
    }


  }

};

class BucketNotificationHandler : public Pistache::Http::Handler {
 public:
  HTTP_PROTOTYPE(BucketNotificationHandler);

  void onRequest(const Pistache::Http::Request &request, Pistache::Http::ResponseWriter response) override {

  }
};
#endif //CEPH2AWS_SRC_HTTP_SERVER_H_
