#include <tree_ros.h>

BT::NodeStatus TreeWithRos::VerifyMode()
{
  std::cout << "Первая ветка  cmd:verify_mode SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}
