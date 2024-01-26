
#include <behaviortree_cpp/xml_parsing.h>


#include <tree_ros.h>



#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>

int main(int argc, char **argv) {
      ros::init(argc, argv, "behavior_tree_main");
      ros::NodeHandle nh;

      TreeWithRos tree_with_ros(nh);

      tree_with_ros.man_mode_str = "VERIFY_MODE"; // для теста

      BT::BehaviorTreeFactory factory;
      tree_with_ros.registerNodes(factory);
      factory.registerBehaviorTreeFromFile(tree_with_ros.path_to_pack + tree_with_ros.path_to_main_xml );
      auto tree = factory.createTree("MainTree");

       //tree.rootBlackboard()->set("system_status", tree_with_ros.system_status);
      tree.rootBlackboard()->set("man_mode", tree_with_ros.man_mode_str);


       // std::string path_to_folder = tree_with_ros.path_to_pack + "/xml/";

       // std::string file_name = path_to_folder + "_main_tree.xml";
       // std::fstream models_file;

       // models_file.open(file_name, std::fstream::out);

       // if (!models_file.is_open())
       //   throw std::runtime_error("Models file is not opened");

       // models_file << BT::writeTreeNodesModelXML(factory, false);
       // models_file.close();
       tree.tickWhileRunning();
      // ros::spin();
       return 0;
}
