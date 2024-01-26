
#include <iostream>
#include <chrono>
#include "behaviortree_cpp/bt_factory.h"
#include "behaviortree_cpp/action_node.h"

BT::NodeStatus ReadySystem()
{
  std::cout << "System OK" << std::endl;
  return BT::NodeStatus::SUCCESS;
}
