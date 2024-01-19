#include <behaviortree_cpp/xml_parsing.h>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>


std::string getEmptyTree(std::string name)
{
  // clang-format off
  static const std::string empty_tree_1 =
R"(<root BTCPP_format="4" >
  <BehaviorTree ID=")";
  // clang-format on

  // clang-format off
  static const std::string empty_tree_2 =
R"(">
    <Sequence name="root">
      <AlwaysFailure/>
    </Sequence>
  </BehaviorTree>
</root>)";
  // clang-format on

  return empty_tree_1 + name + empty_tree_2;
}

/*
  argv:
  [1] - path to ros package src
  [...] - tree name
*/
int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  auto factory = std::make_shared<RtcCupFactory>("behaviortree_config");

  if (argc < 2)
    throw std::logic_error("Invalid arguments");

  // Creating models file
  std::string path_to_package = argv[1];
  std::string path_to_folder = path_to_package + "/config/behavior_tree/";

  std::string file_name = path_to_folder + "_models.xml";
  std::fstream models_file;

  models_file.open(file_name, std::fstream::out);

  if (!models_file.is_open())
    throw std::runtime_error("Models file is not opened");

  models_file << BT::writeTreeNodesModelXML(*factory, false);
  models_file.close();

  // Creating trees
  for (int i = 2; i < argc; i++)
  {
    std::string file_name = path_to_folder + argv[i] + ".xml";
    std::fstream tree_file;

    if (std::filesystem::exists(file_name))
      continue;

    tree_file.open(file_name, std::fstream::out);

    if (!tree_file.is_open())
      throw std::runtime_error("Tree file is not opened");
    auto tree = factory->createTreeFromText(getEmptyTree(argv[i]));
    tree_file << BT::WriteTreeToXML(tree, false, false);
    tree_file.close();

    factory->registerBehaviorTreeFromFile(file_name);
  }
  return 0;
}
