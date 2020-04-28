//
// Created by ninesuns (wangxu298@whu.edu.cn) on 4/12/20.
// Copyright (c) 2020 ninesuns. All rights reserved.
//

#ifndef CEPH2AWS_SRC_RGW_AWS_H_
#define CEPH2AWS_SRC_RGW_AWS_H_

// #include "include/common_fwd.h" // for CephContext

#include <functional>
#include <string>
#include <boost/smart_ptr/intrusive_ptr.hpp>
#include <boost/optional.hpp>

namespace ceph2aws {


struct connection_t;

using connection_ptr_t = boost::intrusive_ptr<connection_t>;

void intrusive_ptr_add_ref(const connection_t* p);
void intrusive_ptr_release(const connection_t* p);

using reply_callback_t = std::function<void(int)>;

bool init(); // TODO

void shutdown();

connection_ptr_t connect(const std::string& url); // TODO

int publish(connection_ptr_t& conn, const std::string& topic, const std::string& message);

int publish_with_confirm(connection_ptr_t& conn, const std::string& topic, const std::string& message, reply_callback_t cb);

std::string status_to_string(int s);

size_t get_connection_count();

size_t get_inflight();

size_t get_queued();

size_t get_dequeued();

size_t get_max_connections();

size_t get_max_inflight();

size_t get_max_queue();

bool disconnect(connection_ptr_t& conn);

std::string to_string(const connection_ptr_t& conn);

}

#endif //CEPH2AWS_SRC_RGW_AWS_H_
