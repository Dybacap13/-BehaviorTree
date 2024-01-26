#include <tree_ros.h>

BT::NodeStatus TreeWithRos::ReadySystem()
{
    if (cmd_shutdown == true) {
        system_status = false;
        return BT::NodeStatus::FAILURE;
    }
    if (cmd_restart == true) {
        system_status = false;
        return BT::NodeStatus::FAILURE;
    }
    if (cmd_reset == true) {
        system_status = false;
        return BT::NodeStatus::FAILURE;
    }
    if (cmd_clear_error == true) {
        system_status = false;
        return BT::NodeStatus::FAILURE;
    }
    if (man_stop == true) {
        system_status = false;
        return BT::NodeStatus::FAILURE;
    }
    if (man_pause == true) {
        system_status = false;
        return BT::NodeStatus::FAILURE;
    }
  system_status = true;
  std::cout << "System OK" << std::endl;
  return BT::NodeStatus::SUCCESS;
}
