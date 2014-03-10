// Date: 2014-03
// Modified version to adapt the code to ROS structure
//
// Author: victor.gonzalez@uc3m.es (Victor Gonzalez-Pacheco)

#include "gtest/gtest.h"
#include "../sample4.h"
#include "../counter_node.hpp"
#include "ros/ros.h"
#include "std_msgs/Int16.h"


class CallbackCounter : public testing::Test {
 protected:
  // Remember that SetUp() is run immediately before a test starts.
  virtual void SetUp() {
    count_msgs_ = 0;
    counter_pub_ = nh_.advertise<std_msgs::Int16>("increment", 1000);
    sub_ = nh_.subscribe("counter", 1, &CallbackCounter::callback, this);
  }

  // TearDown() is invoked immediately after a test finishes.
  virtual void TearDown() {
  }

  ros::NodeHandle nh_;
  int count_msgs_;
  ros::Publisher counter_pub_;
  ros::Subscriber sub_;

 public:
  void callback(const std_msgs::Int16ConstPtr& message){
    count_msgs_++;
  }

  int get_count(){
      return count_msgs_;
  }
};

// Tests the Increment() method.
TEST_F(CallbackCounter, TestCounter_Node) {

    std_msgs::Int16 msg;
    ros::Rate loop_rate(1);
    msg.data = 0;

    counter_pub_.publish(msg);
    loop_rate.sleep();      // Give some time the message to arrive
    ros::spinOnce();
    EXPECT_EQ(0, this->get_count());

    counter_pub_.publish(msg);
    loop_rate.sleep();
    ros::spinOnce();
    EXPECT_EQ(1, this->get_count());

    counter_pub_.publish(msg);
    loop_rate.sleep();
    ros::spinOnce();
    EXPECT_EQ(2, this->get_count());

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "counter_node_test");

  return RUN_ALL_TESTS();
}

