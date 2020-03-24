project(c2a_test)

# below cause SIGSEGV segment fault error TODO:
# add_subdirectory(lib)
# include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(parse_run parse_test.cpp)

target_link_libraries(parse_run gtest gtest_main)
