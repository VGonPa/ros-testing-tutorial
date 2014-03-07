# Gtest Sample1
# add gtest
rosbuild_add_gtest(test/test_sample1 sample1_unittest.cc)
# link required libraries
target_link_libraries(test/test_sample1 sample1)

# Gtest Sample2
rosbuild_add_gtest(test/test_sample2 sample2_unittest.cc)
target_link_libraries(test/test_sample2 sample2)

# Gtest Sample3
rosbuild_add_gtest(test/test_sample3 sample3_unittest.cc ../sample3-inl.h)

# Gtest Sample4
rosbuild_add_gtest(test/test_sample4 sample4_unittest.cc)
target_link_libraries(test/test_sample4 sample4)

# Gtest Sample5
rosbuild_add_gtest(test/test_sample5 sample5_unittest.cc ../sample3-inl.h)
target_link_libraries(test/test_sample5 sample1)

# Gtest Sample6
rosbuild_add_gtest(test/test_sample6 sample6_unittest.cc)

# Gtest Sample7
rosbuild_add_gtest(test/test_sample7 sample7_unittest.cc)

# Gtest Sample8
rosbuild_add_gtest(test/test_sample8 sample8_unittest.cc)

## Gtest Sample9
#rosbuild_add_gtest(test/test_sample9 sample9_unittest.cc)

## Gtest Sample10
#rosbuild_add_gtest(test/test_sample10 sample10_unittest.cc)

