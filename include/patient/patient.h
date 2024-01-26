
#include <iostream>
#include <chrono>
#include "behaviortree_cpp/bt_factory.h"
#include "behaviortree_cpp/action_node.h"

#include <ros/package.h>
#include <ros/ros.h>

class PatientWork
{
public:
  PatientWork();

  BT::NodeStatus patientMode();
  BT::NodeStatus patientSet();
  BT::NodeStatus patientSize();
  BT::NodeStatus patientPos();
  BT::NodeStatus sleepDelay();
  std::string path_to_pack;
  std::string relative_path_to_xml_patient = "/xml/patient.xml";
  std::string relative_path_to_xml_nshc = "/xml/NShC.xml";
  std::string relative_path_to_xml_x_ray_control = "/xml/X_rayControl.xml";
};

class MoveWithSetCommands
{
public:
  MoveWithSetCommands();
  BT::NodeStatus manual();

  // сюда ещё включение лазеров, пункт 10 хз как писать
};

class MovementAllowed
{
public:
  MovementAllowed();

  BT::NodeStatus movementEnable();
  BT::NodeStatus movementDisenable();
};
