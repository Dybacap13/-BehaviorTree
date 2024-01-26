#include <x_ray_control.h>
#include <nshc.h>
#include <verification_device/verification_device.h>
#include <ready_system.h>
int main()
{
  BT::BehaviorTreeFactory factory;
  factory.registerSimpleCondition("ReadySystem", std::bind(ReadySystem));

  MoveVerifyMode move_verify_mode;
  factory.registerSimpleAction(
      "VerifyMode", std::bind(&MoveVerifyMode ::VerifyMode, &move_verify_mode));

  factory.registerSimpleAction(
      "VerifySet", std::bind(&MoveVerifyMode ::VerifySet, &move_verify_mode));

  factory.registerSimpleAction(
      "VerifyPos1", std::bind(&MoveVerifyMode ::VerifyPos1, &move_verify_mode));
  factory.registerSimpleAction(
      "VerifyPos3", std::bind(&MoveVerifyMode ::VerifyPos3, &move_verify_mode));

  factory.registerSimpleAction(
      "VerifyPos2", std::bind(&MoveVerifyMode ::VerifyPos2, &move_verify_mode));

  factory.registerSimpleAction(
      "Home", std::bind(&MoveVerifyMode ::Home, &move_verify_mode));

  factory.registerSimpleAction(
      "SleepDelay", std::bind(&MoveVerifyMode ::SleepDelay, &move_verify_mode));

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

  factory.registerBehaviorTreeFromFile(move_verify_mode.path_to_pack + move_verify_mode.relative_path_to_xml_verification_device);
  factory.registerBehaviorTreeFromFile(move_verify_mode.path_to_pack + move_verify_mode.relative_path_to_xml_nshc);
  factory.registerBehaviorTreeFromFile(move_verify_mode.path_to_pack + move_verify_mode.relative_path_to_xml_x_ray_control);

  auto tree = factory.createTree("VerificationDevice");
  tree.tickWhileRunning();

  return 0;
}
