//
// Created by ninesuns (wangxu298@whu.edu.cn) on 4/12/20.
// Copyright (c) 2020 ninesuns. All rights reserved.
//

#include "rgw_aws.h"

#include <aws/core/Aws.h>
#include <aws/core/utils/Outcome.h>
#include <aws/core/utils/logging/DefaultLogSystem.h>
#include <aws/core/utils/logging/AWSLogging.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/sns/SNSClient.h>
#include <aws/sns/model/CreateTopicRequest.h>
#include <aws/sns/model/CreateTopicResult.h>
#include <aws/sns/model/ListTopicsRequest.h>
#include <aws/sns/model/ListTopicsResult.h>
#include <aws/sns/model/PublishRequest.h>
#include <aws/sns/model/PublishResult.h>
#include <aws/lambda/LambdaClient.h>
#include <aws/lambda/model/CreateFunctionRequest.h>
#include <aws/lambda/model/DeleteFunctionRequest.h>
#include <aws/lambda/model/InvokeRequest.h>
#include <aws/lambda/model/ListFunctionsRequest.h>

#include <vector>
#include <atomic>
#include <thread>
#include <mutex>
#include <boost/lockfree/queue.hpp>

namespace ceph2aws {

struct reply_callback_with_tag_t {
  uint64_t tag;
  reply_callback_t cb;

  reply_callback_with_tag_t(uint64_t _tag, reply_callback_t _cb) : tag(_tag), cb(_cb) { }

  bool operator==(uint64_t rhs) {
    return tag == rhs;
  }
};

using CallbackList = std::vector<reply_callback_with_tag_t>;

class aws_client {
 protected:
  std::string user;
  std::string password;

 public:
  aws_client(const string& _user,
      const std::string& _password) : user(_user), password(_password) { };
  virtual ~aws_client() { };
};

class aws_sns_client : public aws_client {

};

class  aws_lambda_client : public aws_client {

};

struct connection_t {
  std::vector<Aws::String> awsTarget;
  bool marked_for_deletion = false;
  uint64_t delivery_tag;
  int status;
  mutable std::atomic<int> ref_count;
  // CephContext* cct;
  CallbackList callbacks;

  std::string user;
  std::string password;

  void destroy(int s) {
    status = s;

  }

  connection_t();

  virtual ~connection_t() { };

};

std::string to_string(const connection_ptr_t& conn) {

}

void intrusive_ptr_add_ref(const connection_t* p) {

}

void intrusive_ptr_release(const connection_t* p) {

}

connection_ptr_t& create_connection(connection_ptr_t& conn) {

}

connection_ptr_t create_new_connection(); // TODO

struct message_wrapper_t {
  connection_ptr_t  conn;
  std::string topic;
  std::string message;
  reply_callback_t cb;

  message_wrapper_t(connection_ptr_t& _conn,
      const std::string& _topic,
      const std::string& _message,
      reply_callback_t _cb) : conn(_conn), topic(_topic), message(_message), cb(_cb) { }
};

using ConnectionList = std::unordered_map<std::string, connection_ptr_t>;
using MessageQueue = boost::lockfree::queue<message_wrapper_t*, boost::lockfree::fixed_sized<true>>;

// TODO macros

class Manager {
 public:
  const size_t max_connections;
  const size_t max_inflight;
  const size_t max_queue;

 private:
  std::atomic<size_t> connection_count;
  bool stopped;
  int read_timeout_ms;
  ConnectionList connections;
  MessageQueue messages;

  std::atomic<size_t> queued;
  std::atomic<size_t> dequeued;
  // TODO: ceph context
  mutable std::mutex connections_lock;
  std::thread runner;

  void publish_internal();

  void run();

  static void delete_message();

 public:
  Manager(size_t _max_connections,
      size_t _max_inflight,
      size_t _max_queue,
      int _read_timeout_ms //, ceph context
      ) {
    // TODO
  }

  // non copyable
  Manager(const Manager&) = delete;
  const Manager& operator=(const Manager&) = delete;

  void stop() {
    stopped = true;
  }

  // is_connected

  connection_ptr_t connect(const std::string& url)
};

static Manager* s_manager = nullptr;

static const size_t MAX_CONNECTIONS_DEFAULT = 256;
static const size_t MAX_INFLIGHT_DEFAULT = 8192;
static const size_t MAX_QUEUE_DEFAULT = 8192;
static const int READ_TIMEOUT_MS_DEFAULT = 500;

bool init(); // TODO

void shutdown(); // TODO

connection_ptr_t connect(const std::string& url);

int publish();

int publish_with_confirm();

size_t get_connection_count() {
  if (!s_manager) return 0;
  return s_manager->get_connection_count();
}

size_t get_inflight() {

}

size_t get_queued();

size_t get_dequeued();

size_t get_max_connections();

size_t get_max_inflight();

size_t get_max_queue();

bool disconnect(connection_ptr_t& conn);

}