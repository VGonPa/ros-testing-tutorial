rosbuild_add_library(sample1 sample1.cc)
#rosbuild_add_library(sample2 sample2.cc)

rosbuild_add_library(sample4 sample4.cc)

rosbuild_add_executable(counter_node counter_node.cpp)
target_link_libraries(counter_node sample4)

add_subdirectory(test)
