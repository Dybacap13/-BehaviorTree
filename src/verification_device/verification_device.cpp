#include <verification_device/verification_device.h>


// Работа с устройством верификации

MoveVerifyMode::MoveVerifyMode()
{
       path_to_pack = ros::package::getPath("oko_behavior_tree");
}

BT::NodeStatus MoveVerifyMode::VerifyMode()
{
  std::cout << "Первая ветка  cmd:verify_mode SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus MoveVerifyMode::VerifySet()
{
  std::cout << "Вторая ветка move:verify_set SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus MoveVerifyMode::VerifyPos1()
{
  std::cout << "Четвертая ветка move:verify_pos1 SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus MoveVerifyMode::VerifyPos2()
{
  std::cout << "Шестая ветка move verify_pos2 SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus MoveVerifyMode::VerifyPos3()
{
  std::cout << "Седьмая ветка move verify_pos3 SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus MoveVerifyMode::Home()
{
  std::cout << "Десятая ветка move:home SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus MoveVerifyMode::SleepDelay()
{
  std::cout << "Работает медработник- задержка SUCCESS" << std::endl;
  // std::this_thread::sleep_for(5s);
  return BT::NodeStatus::SUCCESS;
}
