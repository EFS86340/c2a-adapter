# ceph2aws
---
Adapter to convert ceph notification to aws

Dependency:
1.aws-cpp-sdk
2.rapidjson
3.gtest
4.pistache

Message format:
1.Create A Topic
```
POST
Action=CreateTopic
&Name=<topic-name>
&push-endpoint=<endpoint>
[&Attributes.entry.1.key=aws-sns&Attributes.entry.1.value=<topicArn>]
[&Attributes.entry.2.key=aws-lambda&Attributes.entry.2.value=<functionName>]
```
Request parameters:
- push-endpoint: [<sns-topic-arn/lambda-funcion-arn>][:<user>:<password>]