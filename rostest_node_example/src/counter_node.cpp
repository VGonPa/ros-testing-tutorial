#include "counter_node.hpp"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "counter");
  CounterNode cnode;

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }
 return 0;
}
