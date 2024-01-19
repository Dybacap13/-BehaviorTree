#include "ros/ros.h"

//#include <behavior_tree.h>
//#include "behaviortree_cpp/behavior_tree.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "behavior_tree");
  if (!ros::master::check()) {
    ROS_ERROR("No master started!");

}


  ros::NodeHandle nh("~");
  return EXIT_SUCCESS;
}
