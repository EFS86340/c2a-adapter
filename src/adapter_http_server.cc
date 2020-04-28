//
// Created by ninesuns (wangxu298@whu.edu.cn) on 4/27/20.
// Copyright (c) 2020 ninesuns. All rights reserved.
//

#include "adapter_http_server.h"

#include <rapidjson/document.h>

void adapter_publish(const Pistache::Rest::Request&, Pistache::Http::ResponseWriter);
void adapter_invoke(const Pistache::Rest::Request&, Pistache::Http::ResponseWriter);

int test(int x) {
  return x+1;
}

// sample handler
class BucketNotificationHandler : public Pistache::Http::Handler {
 public:
 HTTP_PROTOTYPE(BucketNotificationHandler)

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

    // call aws sns publish with hard-coded arn
    publishToSNS(request.body(), "arn:aws:sns:us-east-1:125341253834:gsoc20-ceph");
  }

};

// dynamic handler
Pistache::Rest::Router makeAdapterHandler(void) {
  Pistache::Rest::Router router;

  // register callbacks
  Pistache::Rest::Routes::Post(router, "/publish/:id", Pistache::Rest::Routes::bind(&adapter_publish));
  Pistache::Rest::Routes::Post(router, "/invoke/:id", Pistache::Rest::Routes::bind(&adapter_invoke));

  return router;
}

void adapter_publish(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response) {
  response.send(Pistache::Http::Code::Ok, "hello, sns!\n");

}

void adapter_invoke(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response) {
  response.send(Pistache::Http::Code::Ok, "hello, lambda!\n");

}
