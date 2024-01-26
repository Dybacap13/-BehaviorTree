#include <patient/patient.h>

// Работа с пациентом

/* Проблемки

  Пункт 10 хз, ничего не понятно, здесь нет
  Пункт 5 нужно ли в дерево передавать значения?
  Пункт 8 там вопрос стоит в мануале - здесь нет

 */
PatientWork::PatientWork(){
       path_to_pack = ros::package::getPath("oko_behavior_tree");
}

BT::NodeStatus PatientWork::patientMode()
{
  std::cout << "Подаётся команда cmd patient_mode - режим работы с пациентом. "
               "SUCCESS"
            << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus PatientWork::patientSet()
{
  std::cout << "Подаётся команда move patient_set. SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus PatientWork::patientSize()
{
  std::cout << "Подаётся команда move patient_size. SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus PatientWork::patientPos()
{
  std::cout << " PatientPos SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus PatientWork::sleepDelay()
{
  std::cout << "задержка SUCCESS" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

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
