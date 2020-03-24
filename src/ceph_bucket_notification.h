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

class CephBucketNotification {

};

#endif //CEPH2AWS__CEPH_BUCKET_NOTIFICATION_H_
