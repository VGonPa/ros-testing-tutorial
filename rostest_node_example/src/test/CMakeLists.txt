# add the test executable,
# keep it from being built by "make all"
rosbuild_add_executable(test/test_counter_node EXCLUDE_FROM_ALL
                                          test_counter_node.cpp)
# Link test_mynode against gtest
# and add a dependency to the "test" target
rosbuild_add_gtest_build_flags(test/test_counter_node)

## Make sure rostest launches test/counter_node.test during "make test"
rosbuild_add_rostest(${PROJECT_SOURCE_DIR}/test/counter_node.test)
