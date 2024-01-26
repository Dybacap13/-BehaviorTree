#include <tree_ros.h>

BT::NodeStatus TreeWithRos::PatientMode()
{
  std::cout << "Подаётся команда cmd patient_mode - режим работы с пациентом. "
               "SUCCESS"
            << std::endl;
  return BT::NodeStatus::SUCCESS;
}

