project(c2a_test)

# add_subdirectory(lib)
# include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(parse_run parse_test.cpp aws_sns_publish_test.cc aws_lambda_test.cc)

target_link_libraries(parse_run gtest gtest_main)
