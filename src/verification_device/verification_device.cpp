#include <verification_device/verification_device.h>


// Работа с устройством верификации

MoveVerifyMode::MoveVerifyMode()
{
       path_to_pack = ros::package::getPath("oko_behavior_tree");
}

//*************************************************************************
BT::NodeStatus MoveVerifyMode::readySystem(){
  // if (robot_controller.status == Messages::Values::Status::ok) {
  //   while (robot_controller.status != Messages::Values::Status::moving) {
  //       std::cout << "Не получен флаг о начале движения, sleep..." << std::endl;
  //       std::this_thread::sleep_for(std::chrono::milliseconds(100));
  //     }
  // }
  // while (robot_controller.status == Messages::Values::Status::moving) {
  //     std::this_thread::sleep_for(std::chrono::milliseconds(100));
  //   }
  // if (robot_controller.status != Messages::Values::Status::ok) {
  //     std::cout << "Произошла ошибка при движении в позицию: -> FAILURE " << robot_controller.status
  //               << std::endl;
  //     return BT::NodeStatus::FAILURE;
  //   }
  std::cout << "ReadySystem -> SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}
//*************************************************************************


//*************************************************************************
BT::NodeStatus MoveVerifyMode::verifyMode()
{
  //   responce = robot_controller.setMode("verify_mode");
  // if (robot_controller.getMode == responce ){
  //   std::cout << "Команда:verify_mode -> SUCCESS" << std::endl;
  //   return BT::NodeStatus::SUCCESS;
  // }
  std::cout << "Команда: verify_mode -> FAILURE" << std::endl;
  return BT::NodeStatus::FAILURE;
}
//*************************************************************************



//*************************************************************************
BT::NodeStatus MoveVerifyMode::verifySet()
{
  std::cout << "Вторая ветка move:verify_set SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}


// все позиции в одной функции реализуются? 
// какую функцию использовать moveToVerifyPos() или moveToPose(...)?
//*************************************************************************
BT::NodeStatus MoveVerifyMode::verifyPos1()
{
  // robot_controller.moveToVerifyPos();
  std::cout << "Команда move:verify_pos1 -> SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}
//*************************************************************************


BT::NodeStatus MoveVerifyMode::verifyPos2()
{
  std::cout << "Шестая ветка move verify_pos2 SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}



BT::NodeStatus MoveVerifyMode::verifyPos3()
{
  std::cout << "Седьмая ветка move verify_pos3 SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}


//*************************************************************************
BT::NodeStatus MoveVerifyMode::home()
{
  //Json::Value move_home(Messages::Values::Move::home);
  //robot_controller.moveToPose(move_home);
  std::cout << "Команда: move home -> SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}
//*************************************************************************


//Время задержки меняется в дереве
BT::NodeStatus MoveVerifyMode::sleepDelay()
{
  std::cout << "Работает медработник- задержка SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}
