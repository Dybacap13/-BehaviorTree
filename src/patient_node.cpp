#include <x_ray_control.h>
#include <nshc.h>
#include <patient/patient.h>
#include <behaviortree_cpp/xml_parsing.h>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>


int main(int argc, char **argv)
{
  ros::init(argc, argv, "behavior_tree_patient");
  ros::NodeHandle nh;

  BT::BehaviorTreeFactory factory;

  //factory.registerSimpleCondition("ReadySystem", std::bind(ReadySystem));

  MoveWithSetCommands move_with_set_commands;

  factory.registerSimpleAction(
      "Manual",
      std::bind(&MoveWithSetCommands ::manual, &move_with_set_commands));

  MovementAllowed movement_allowed;

  factory.registerSimpleAction(
      "MovementAllowedEnable",
      std::bind(&MovementAllowed ::movementEnable, &movement_allowed));

  factory.registerSimpleAction(
      "MovementAllowedDisenable",
      std::bind(&MovementAllowed ::movementDisenable, &movement_allowed));

  PatientWork patient_work(nh);

  // factory.registerSimpleAction(
  //     "PatientMode", std::bind(&PatientWork ::patientMode, &patient_work));

  factory.registerSimpleAction(
      "PatientSet", std::bind(&PatientWork ::patientSet, &patient_work));

  factory.registerSimpleAction(
      "PatientSize", std::bind(&PatientWork ::patientSize, &patient_work));

  factory.registerSimpleAction(
      "PatientPos", std::bind(&PatientWork ::patientPos, &patient_work));

  factory.registerSimpleAction(
      "SleepDelay", std::bind(&PatientWork ::sleepDelay, &patient_work));

factory.registerSimpleAction(
      "ReadySystem", std::bind(&PatientWork ::readySystem, &patient_work));

  X_rayControl x_ray_control;

  factory.registerSimpleAction(
      "Control_ray", std::bind(&X_rayControl ::Control, &x_ray_control));
  factory.registerSimpleAction(
      "CoordOffset", std::bind(&X_rayControl ::CoordOffset, &x_ray_control));
  factory.registerSimpleAction(
      "AutoExecute", std::bind(&X_rayControl ::AutoExecute, &x_ray_control));

  NShC nshc;

  factory.registerSimpleAction("CheckNShC",
                               std::bind(&NShC ::CheckNShC, &nshc));


  factory.registerBehaviorTreeFromFile(patient_work.path_to_pack + patient_work.relative_path_to_xml_patient);
  factory.registerBehaviorTreeFromFile(patient_work.path_to_pack + patient_work.relative_path_to_xml_nshc);
  factory.registerBehaviorTreeFromFile(patient_work.path_to_pack + patient_work.relative_path_to_xml_x_ray_control);
  auto tree = factory.createTree("WorkPatient");

  // std::string path_to_folder = patient_work.path_to_pack + "/xml/";

  // std::string file_name = path_to_folder + "_models.xml";
  // std::fstream models_file;

  // models_file.open(file_name, std::fstream::out);

  // if (!models_file.is_open())
  //   throw std::runtime_error("Models file is not opened");

  // models_file << BT::writeTreeNodesModelXML(factory, false);
  // models_file.close();

  tree.tickWhileRunning();

  return 0;
}
