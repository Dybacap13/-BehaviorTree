#include <phantom/phantom.h>


PhantomMode::PhantomMode()
{
   path_to_pack = ros::package::getPath("oko_behavior_tree");

}

BT::NodeStatus PhantomMode::hydroPhantomMode()
{
  std::cout << "Подаётся команда cmd hydro_phantom_mode SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus PhantomMode::phantomSet2()
{
  std::cout << "phantomSet2 SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus PhantomMode::phantomSet3()
{
  std::cout << "phantomSet3 SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus PhantomMode::phantomPos()
{
  std::cout << "phantomPos SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus PhantomMode::Home()
{
  std::cout << " move:home SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus PhantomMode::SleepDelay()
{
  std::cout << "Работает медработник- задержка SUCCESS" << std::endl;
  // std::this_thread::sleep_for(5s);
  return BT::NodeStatus::SUCCESS;
}

MovementAllowed::MovementAllowed()
{
}

BT::NodeStatus MovementAllowed::movementEnable()
{
  std::cout << "Включается ручной режим командой move manual. SUCCESS"
            << std::endl;
  return BT::NodeStatus::SUCCESS;
}
BT::NodeStatus MovementAllowed::movementDisenable()
{
  std::cout << "Включается ручной режим командой move manual. SUCCESS"
            << std::endl;
  return BT::NodeStatus::SUCCESS;
}
