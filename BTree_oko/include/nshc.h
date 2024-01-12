
#include <iostream>
#include <chrono>
#include "behaviortree_cpp/bt_factory.h"
#include "behaviortree_cpp/action_node.h"

using namespace std;

class NShC
    {
public:
    NShC()
    {
    }

    BT::NodeStatus CheckNShC(){
        std::cout << "CheckNShC SUCCESS" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

};

