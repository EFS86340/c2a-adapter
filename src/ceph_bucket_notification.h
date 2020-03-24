//
// Created by ninesuns (wangxu298@whu.edu.cn) on 3/24/20.
// Copyright (c) 2020 ninesuns. All rights reserved.
//

#ifndef CEPH2AWS__CEPH_BUCKET_NOTIFICATION_H_
#define CEPH2AWS__CEPH_BUCKET_NOTIFICATION_H_

/***
 * the JSON format of bucket notification
 * {"Records":[
    {
        "eventVersion":"2.1"
        "eventSource":"aws:s3",
        "awsRegion":"",
        "eventTime":"",
        "eventName":"",
        "userIdentity":{
            "principalId":""
        },
        "requestParameters":{
            "sourceIPAddress":""
        },
        "responseElements":{
            "x-amz-request-id":"",
            "x-amz-id-2":""
        },
        "s3":{
            "s3SchemaVersion":"1.0",
            "configurationId":"",
            "bucket":{
                "name":"",
                "ownerIdentity":{
                    "principalId":""
                },
                "arn":"",
                "id:""
            },
            "object":{
                "key":"",
                "size":"",
                "eTag":"",
                "versionId":"",
                "sequencer": "",
                "metadata":[],
                "tags":[]
            }
        },
        "eventId":"",
        "opaqueData":"",
    }
]}
 */

#include <rapidjson/document.h>

using namespace rapidjson;

int tttest(void) {
  return 1;
}


std::string parseNotificationJSON(std::string raw) {
  rapidjson::Document document;
  document.Parse(raw.c_str());
  // print some basic notification info
  assert(document.IsObject());
  // std::string s =  document["Records"][0]["eventSource"].GetString();
  return document["Records"][0]["eventSource"].GetString();
  // rapidjson::Value& recordArray = document["Records"];
  // assert(recordArray.IsArray());
  // rapidjson::Value& field = recordArray[0];
  // assert(field.IsObject());
  // return field["eventSource"].GetString();
  // for(auto& info : field.GetObject()) {
  //   std::cout << "[+] field: " << info.name.GetString() << std::endl;
  // }

}

#endif //CEPH2AWS__CEPH_BUCKET_NOTIFICATION_H_
