#include <x_ray_control.h>
#include <nshc.h>

using namespace std;
// Работа с устройством верификации


BT::NodeStatus ReadySystem()
{
  std::cout << "System OK" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

class MoveVerifyMode
{
    public:
    MoveVerifyMode(){
    }

    BT::NodeStatus VerifyMode(){
        std::cout << "Первая ветка  cmd:verify_mode SUCCESS" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

    BT::NodeStatus VerifySet(){
        std::cout << "Вторая ветка move:verify_set SUCCESS" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

    BT::NodeStatus VerifyPos1(){
        std::cout << "Четвертая ветка move:verify_pos1 SUCCESS" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

    BT::NodeStatus VerifyPos2(){
        std::cout << "Шестая ветка move verify_pos2 SUCCESS" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

    BT::NodeStatus VerifyPos3(){
        std::cout << "Седьмая ветка move verify_pos3 SUCCESS" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

    BT::NodeStatus Home(){
        std::cout << "Десятая ветка move:home SUCCESS" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

    BT::NodeStatus SleepDelay(){
        std::cout << "Работает медработник- задержка SUCCESS" << std::endl;
        //std::this_thread::sleep_for(5s);
        return BT::NodeStatus::SUCCESS;
    }
};




int main()
{

    BT::BehaviorTreeFactory factory;

    factory.registerSimpleCondition("ReadySystem", std::bind(ReadySystem));

    MoveVerifyMode move_verify_mode;

    factory.registerSimpleAction(
          "VerifyMode",
          std::bind(&MoveVerifyMode ::VerifyMode, &move_verify_mode));

    factory.registerSimpleAction(
          "VerifySet",
          std::bind(&MoveVerifyMode ::VerifySet, &move_verify_mode));


    factory.registerSimpleAction(
          "VerifyPos1",
          std::bind(&MoveVerifyMode ::VerifyPos1, &move_verify_mode));
    factory.registerSimpleAction(
          "VerifyPos3",
          std::bind(&MoveVerifyMode ::VerifyPos3, &move_verify_mode));

    factory.registerSimpleAction(
          "VerifyPos2",
          std::bind(&MoveVerifyMode ::VerifyPos2, &move_verify_mode));

    factory.registerSimpleAction(
          "Home",
          std::bind(&MoveVerifyMode ::Home, &move_verify_mode));

    factory.registerSimpleAction(
          "SleepDelay",
          std::bind(&MoveVerifyMode ::SleepDelay, &move_verify_mode));


     X_rayControl x_ray_control;

     factory.registerSimpleAction(
           "Control_ray",
           std::bind(&X_rayControl ::Control, &x_ray_control));
     factory.registerSimpleAction(
           "CoordOffset",
           std::bind(&X_rayControl ::CoordOffset, &x_ray_control));
     factory.registerSimpleAction(
           "AutoExecute",
           std::bind(&X_rayControl ::AutoExecute, &x_ray_control));

     NShC nshc;

     factory.registerSimpleAction(
           "CheckNShC",
           std::bind(&NShC ::CheckNShC, &nshc));

     std::string search_directory = "../xml";

      using std::filesystem::directory_iterator;
      for (auto const& entry : directory_iterator(search_directory))
      {
        if( entry.path().extension() == ".xml")
        {
          factory.registerBehaviorTreeFromFile(entry.path().string());
        }
      }


factory.registerBehaviorTreeFromFile("../verification_device.xml");
       auto tree = factory.createTree("VerificationDevice");
  tree.tickWhileRunning();


    return 0;
}
