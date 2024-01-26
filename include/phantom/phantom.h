
#include <iostream>
#include <chrono>
#include "behaviortree_cpp/bt_factory.h"
#include "behaviortree_cpp/action_node.h"

#include <ros/package.h>
#include <ros/ros.h>



class PhantomMode
{
public:
  PhantomMode();

  BT::NodeStatus hydroPhantomMode();
  BT::NodeStatus phantomSet2();
  BT::NodeStatus phantomSet3();
  BT::NodeStatus phantomPos();
  BT::NodeStatus Home();
  BT::NodeStatus SleepDelay();


  std::string path_to_pack;
  std::string relative_path_to_xml_phantom = "/xml/phantom.xml";
  std::string relative_path_to_xml_nshc = "/xml/NShC.xml";
private:


};


  class MovementAllowed
  {
  public:
    MovementAllowed();
    BT::NodeStatus movementEnable();
    BT::NodeStatus movementDisenable();
    // сюда ещё включение лазеров, пункт 10 хз как писать
  };
