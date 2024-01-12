#include <nshc.h>

using namespace std;
// Работа с устройством верификации


BT::NodeStatus ReadySystem()
{
  std::cout << "System OK" << std::endl;
  return BT::NodeStatus::SUCCESS;
}

class PhantomMode
{
    public:
    PhantomMode(){
    }

    BT::NodeStatus hydroPhantomMode(){
        std::cout << "Подаётся команда cmd hydro_phantom_mode SUCCESS" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

    BT::NodeStatus phantomSet2(){
        std::cout << "phantomSet2 SUCCESS" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

    BT::NodeStatus phantomSet3(){
        std::cout << "phantomSet3 SUCCESS" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

    BT::NodeStatus phantomPos(){
        std::cout << "phantomPos SUCCESS" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

    BT::NodeStatus Home(){
        std::cout << " move:home SUCCESS" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

    BT::NodeStatus SleepDelay(){
        std::cout << "Работает медработник- задержка SUCCESS" << std::endl;
        //std::this_thread::sleep_for(5s);
        return BT::NodeStatus::SUCCESS;
    }
};

class MovementAllowed
{
public:
    MovementAllowed(){
    }

    BT::NodeStatus movementEnable(){
        std::cout << "Включается ручной режим командой move manual. SUCCESS" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
    BT::NodeStatus movementDisenable(){
        std::cout << "Включается ручной режим командой move manual. SUCCESS" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

// сюда ещё включение лазеров, пункт 10 хз как писать


};


int main()
{

    BT::BehaviorTreeFactory factory;

    factory.registerSimpleCondition("ReadySystem", std::bind(ReadySystem));

    PhantomMode phantom_mode ;

    factory.registerSimpleAction(
          "HydroPhantomMode",
          std::bind(&PhantomMode ::hydroPhantomMode, &phantom_mode ));

    factory.registerSimpleAction(
          "PhantomSet2",
          std::bind(&PhantomMode ::phantomSet2, &phantom_mode ));


    factory.registerSimpleAction(
          "PhantomSet3",
          std::bind(&PhantomMode ::phantomSet3, &phantom_mode ));


    factory.registerSimpleAction(
          "PhantomPos",
          std::bind(&PhantomMode ::phantomPos, &phantom_mode ));

    factory.registerSimpleAction(
          "Home",
          std::bind(&PhantomMode ::Home, &phantom_mode ));

    factory.registerSimpleAction(
          "SleepDelay",
          std::bind(&PhantomMode ::SleepDelay, &phantom_mode ));

    MovementAllowed movement_allowed;

    factory.registerSimpleAction(
          "MovementAllowedEnable",
          std::bind(& MovementAllowed ::movementEnable, &movement_allowed));

    factory.registerSimpleAction(
          "MovementAllowedDisenable",
          std::bind(& MovementAllowed ::movementDisenable, &movement_allowed));



     NShC nshc;

     factory.registerSimpleAction(
           "CheckNShC",
           std::bind(&NShC ::CheckNShC, &nshc));



    factory.registerBehaviorTreeFromFile("../phantom.xml");
    factory.registerBehaviorTreeFromFile("../xml/NShC.xml");
    auto tree = factory.createTree("Phantom");
    tree.tickWhileRunning();


    return 0;
}
