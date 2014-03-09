# add gtest
rosbuild_add_gtest(test/test_sample1 sample1_unittest.cc)
# link required libraries
target_link_libraries(test/test_sample1 sample1)
