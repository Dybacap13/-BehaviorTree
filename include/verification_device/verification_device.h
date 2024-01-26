#include <iostream>
#include <chrono>
#include "behaviortree_cpp/bt_factory.h"
#include "behaviortree_cpp/action_node.h"

#include <ros/package.h>
#include <ros/ros.h>


class MoveVerifyMode
{
public:
  MoveVerifyMode();
  BT::NodeStatus VerifyMode();
  BT::NodeStatus VerifySet();
  BT::NodeStatus VerifyPos1();
  BT::NodeStatus VerifyPos2();
  BT::NodeStatus VerifyPos3();
  BT::NodeStatus Home();
  BT::NodeStatus SleepDelay();

  std::string path_to_pack;
  std::string relative_path_to_xml_nshc = "/xml/NShC.xml";
  std::string relative_path_to_xml_x_ray_control = "/xml/X_rayControl.xml";
  std::string relative_path_to_xml_verification_device = "/xml/verification_device.xml";
};
