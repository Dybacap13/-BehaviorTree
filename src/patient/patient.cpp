#include <patient/patient.h>

// Работа с пациентом

/* Проблемки

  Пункт 10 хз, ничего не понятно, здесь нет
  Пункт 5 нужно ли в дерево передавать значения?
  Пункт 8 там вопрос стоит в мануале - здесь нет

 */


PatientWork::PatientWork(ros::NodeHandle &nh_): nh(nh_){

  path_to_pack = ros::package::getPath("oko_behavior_tree");
   
  status_mode_pub = nh.advertise<std_msgs::String>("/status_mode", 1000);
  command_move_patient_to_pos_pub = nh.advertise<std_msgs::String>("/command_move_patient_to_pos", 1000);


  status_system_sub = nh.subscribe("/status_system", 1000, &PatientWork::statusSystemCallback, this);
  movement_allowed = nh.subscribe("/movement_allowed", 1000, &PatientWork::movementAllowedCallback, this);


}
//*************************************************************************
//Callback
void PatientWork::statusSystemCallback (std_msgs::String msg_status){
  status_system = msg_status.data;
}


void PatientWork::movementAllowedCallback (std_msgs::Bool msg_movement_allowed){
  movement_allowed_status = msg_movement_allowed.data;
}



//*************************************************************************
BT::NodeStatus PatientWork::readySystem(){
  if (status_system == "Messages::Values::Status::ok") {
    while (status_system  != "Messages::Values::Status::moving") {
        std::cout << "Не получен флаг о начале движения, sleep..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
      }
  }
  while (status_system  == "Messages::Values::Status::moving") {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  if (status_system  != "Messages::Values::Status::ok") {
      std::cout << "Произошла ошибка при движении в позицию: -> FAILURE "
                << std::endl;
      return BT::NodeStatus::FAILURE;
    }
  std::cout << "ReadySystem -> SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}
//*************************************************************************


//*************************************************************************
// BT::NodeStatus PatientWork::patientMode()
// {
//    // короче, здесь нужен сервис

//    std::cout << "Команда:patient_mode -> SUCCESS" << std::endl;
//    return BT::NodeStatus::SUCCESS;


//   // responce = robot_controller.setMode("patient_mode");
//   // if (robot_controller.getMode("??????") == responce ){     // что передавать в телеметрию?
//   //   std::cout << "Команда:patient_mode -> SUCCESS" << std::endl;
//   //   return BT::NodeStatus::SUCCESS;
//   // }

//   // }
//   // std::cout << "Команда:patient_mode -> FAILURE" << std::endl;
//   // return BT::NodeStatus::FAILURE;

// }
// //*************************************************************************


//*************************************************************************
BT::NodeStatus PatientWork::patientSet()
{
  std_msgs::String patient_set_pose;
  patient_set_pose.data = "Messages::Values::Move::patientSet";
  command_move_patient_to_pos_pub.publish(patient_set_pose);
  std::this_thread::sleep_for(std::chrono::milliseconds(100));  //  "Время на передачу гоала и изменение флагов"
  std::cout << "Команда: move patient_set  ->  SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}
//*************************************************************************


//нужно ли прям в дерево передавать значения?
BT::NodeStatus PatientWork::patientSize()
{
  std::cout << "Подаётся команда move patient_size. SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}


//*************************************************************************
BT::NodeStatus PatientWork::patientPos()
{
  std_msgs::String patient_pos_pose;
  patient_pos_pose.data = "Messages::Values::Move::patientPos";
  command_move_patient_to_pos_pub.publish(patient_pos_pose);
  std::this_thread::sleep_for(std::chrono::milliseconds(100));  //  "Время на передачу гоала и изменение флагов"
  std::cout << "Команда: move_patient_pos -> SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}
//*************************************************************************


//*************************************************************************
//Задержка для работы медработника ( время задержки задается в дереве patient.xml)
BT::NodeStatus PatientWork::sleepDelay()
{
  std::cout << "Задержка  SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}
//*************************************************************************






MoveWithSetCommands::MoveWithSetCommands()
{
}

BT::NodeStatus MoveWithSetCommands::manual()
{
  std::cout << "Включается ручной режим командой move manual. SUCCESS"
            << std::endl;
  return BT::NodeStatus::SUCCESS;
}

// сюда ещё включение лазеров, пункт 10 хз как писать




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

// сюда ещё включение лазеров, пункт 10 хз как писать
