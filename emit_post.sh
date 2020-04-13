#!/bin/zsh

post_payload='{"Records":[
  {
    "eventVersion":"2.1",
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
        "id":""
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
    "opaqueData":"wangxu298@foxmail.com"
  }
]}'

payload_filled='{"Records":[{"eventVersion":"2.2","eventSource":"ceph:s3","awsRegion":"","eventTime":"2020-03-24T09:49:37.318851Z","eventName":"s3:ObjectCreated:Put","userIdentity":{"principalId":"testid"},"requestParameters":{"sourceIPAddress":""},"responseElements":{"x-amz-request-id":"ee4b7f46-dacf-4faf-a1e1-6914d082ed83.4135.6","x-amz-id-2":"1027-default-default"},"s3":{"s3SchemaVersion":"1.0","configurationId":"topic","bucket":{"name":"mybucket","ownerIdentity":{"principalId":"testid"},"arn":"arn:aws:s3:::mybucket","id":"ee4b7f46-dacf-4faf-a1e1-6914d082ed83.4137.1"},"object":{"key":"README.md","size":2247,"etag":"f7985d578d7469a176418762e89d020f","versionId":"","sequencer":"B1D7795E21054216","metadata":[{"key":"x-amz-content-sha256","val":"17457cb1837978ee146b40830c2e535bddf5e8c6bc99c1517d191e47ff924cc0"},{"key":"x-amz-date","val":"20200324T094935Z"},{"key":"x-amz-meta-s3cmd-attrs","val":"atime:1584989483/ctime:1584097909/gid:1000/gname:ninesuns/md5:f7985d578d7469a176418762e89d020f/mode:33188/mtime:1584097909/uid:1000/uname:ninesuns"},{"key":"x-amz-storage-class","val":"STANDARD"}],"tags":[]}},"eventId":"1585043377.373425.f7985d578d7469a176418762e89d020f","opaqueData":"wilyxerus@gmail.com"}]}'

wget --post-data ${payload_filled} http://localhost:9080

resp_filename='index.html'
if [ -e ${resp_filename} ]; then
  echo "[+] Received response" && rm `pwd`/${resp_filename};
else
  echo "[-] Not receive response file"
fi