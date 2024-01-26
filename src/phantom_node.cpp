#include <nshc.h>
#include <phantom/phantom.h>
#include <ready_system.h>


int main()
{
  BT::BehaviorTreeFactory factory;

  factory.registerSimpleCondition("ReadySystem", std::bind(ReadySystem));

  PhantomMode phantom_mode;

  factory.registerSimpleAction(
      "HydroPhantomMode",
      std::bind(&PhantomMode ::hydroPhantomMode, &phantom_mode));

  factory.registerSimpleAction(
      "PhantomSet2", std::bind(&PhantomMode ::phantomSet2, &phantom_mode));

  factory.registerSimpleAction(
      "PhantomSet3", std::bind(&PhantomMode ::phantomSet3, &phantom_mode));

  factory.registerSimpleAction(
      "PhantomPos", std::bind(&PhantomMode ::phantomPos, &phantom_mode));

  factory.registerSimpleAction("Home",
                               std::bind(&PhantomMode ::Home, &phantom_mode));

  factory.registerSimpleAction(
      "SleepDelay", std::bind(&PhantomMode ::SleepDelay, &phantom_mode));

  MovementAllowed movement_allowed;

  factory.registerSimpleAction(
      "MovementAllowedEnable",
      std::bind(&MovementAllowed ::movementEnable, &movement_allowed));

  factory.registerSimpleAction(
      "MovementAllowedDisenable",
      std::bind(&MovementAllowed ::movementDisenable, &movement_allowed));

  NShC nshc;

  factory.registerSimpleAction("CheckNShC",
                               std::bind(&NShC ::CheckNShC, &nshc));

  factory.registerBehaviorTreeFromFile(phantom_mode.path_to_pack + phantom_mode.relative_path_to_xml_phantom);
  factory.registerBehaviorTreeFromFile(phantom_mode.path_to_pack + phantom_mode.relative_path_to_xml_nshc);

  auto tree = factory.createTree("Phantom");
  tree.tickWhileRunning();

  return 0;
}
