
#include <iostream>
#include <chrono>
#include "behaviortree_cpp/bt_factory.h"
#include "behaviortree_cpp/action_node.h"

using namespace std;

class X_rayControl
{
public:
  X_rayControl()
  {
  }
  int attemp = 0;
  BT::NodeStatus Control()
  {
    std::cout << "Выполняется рентген-контроль положения устройства верификации"
              << std::endl;

    if (attemp == 0)
    {
      std::cout << "Попытка 1 - FAILURE" << std::endl;
      attemp = 1;
      return BT::NodeStatus::FAILURE;
    }
    std::cout << "Control SUCCESS" << std::endl;
    return BT::NodeStatus::SUCCESS;
  }

  BT::NodeStatus CoordOffset()
  {
    std::cout << "CoordOffset SUCCESS" << std::endl;
    return BT::NodeStatus::SUCCESS;
  }

  BT::NodeStatus AutoExecute()
  {
    std::cout << "AutoExecute  SUCCESS" << std::endl;
    return BT::NodeStatus::SUCCESS;
  }
};
