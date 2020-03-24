//
// Created by ninesuns (wangxu298@whu.edu.cn) on 3/24/20.
// Copyright (c) 2020 ninesuns. All rights reserved.
//

#include <gtest/gtest.h>
//#include <rapidjson/document.h>
#include "../src/ceph_bucket_notification.h"

//using namespace rapidjson;

TEST(ParseTest, ParseEvent) {
  EXPECT_EQ(tttest(), 1);

  const std::string s = "{\"Records\":[\n"
                        "  {\n"
                        "    \"eventVersion\":\"2.1\",\n"
                        "    \"eventSource\":\"aws:s3\",\n"
                        "    \"awsRegion\":\"\",\n"
                        "    \"eventTime\":\"\",\n"
                        "    \"eventName\":\"\",\n"
                        "    \"userIdentity\":{\n"
                        "      \"principalId\":\"\"\n"
                        "    },\n"
                        "    \"requestParameters\":{\n"
                        "      \"sourceIPAddress\":\"\"\n"
                        "    },\n"
                        "    \"responseElements\":{\n"
                        "      \"x-amz-request-id\":\"\",\n"
                        "      \"x-amz-id-2\":\"\"\n"
                        "    },\n"
                        "    \"s3\":{\n"
                        "      \"s3SchemaVersion\":\"1.0\",\n"
                        "      \"configurationId\":\"\",\n"
                        "      \"bucket\":{\n"
                        "        \"name\":\"\",\n"
                        "        \"ownerIdentity\":{\n"
                        "          \"principalId\":\"\"\n"
                        "        },\n"
                        "        \"arn\":\"\",\n"
                        "        \"id\":\"\"\n"
                        "      },\n"
                        "      \"object\":{\n"
                        "        \"key\":\"\",\n"
                        "        \"size\":\"\",\n"
                        "        \"eTag\":\"\",\n"
                        "        \"versionId\":\"\",\n"
                        "        \"sequencer\": \"\",\n"
                        "        \"metadata\":[],\n"
                        "        \"tags\":[]\n"
                        "      }\n"
                        "    },\n"
                        "    \"eventId\":\"\",\n"
                        "    \"opaqueData\":\"\"\n"
                        "  }\n"
                        "]}";

  EXPECT_EQ(parseNotificationJSON(s), "aws:s3");
}

