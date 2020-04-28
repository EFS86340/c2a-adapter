cmake_minimum_required(VERSION 3.15)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

project(ceph2aws)

# pistache requires c++14
set(CMAKE_CXX_STANDARD 14)

# dependency
# find_library(C2A_JSON rapidjson)
find_library(C2A_HTTP pistache)
find_library(C2A_TEST gtest)
find_package(AWSSDK REQUIRED COMPONENTS sns lambda)

link_libraries(${C2A_HTTP} ${C2A_TEST} ${AWSSDK_LINK_LIBRARIES})

#
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/src")

add_executable(ceph2aws main.cpp src/adapter_http_server.h ${PROJECT_SOURCE_DIR}/src/adapter_http_server.cc)

# tests
add_subdirectory(test)