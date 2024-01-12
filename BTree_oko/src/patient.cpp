#include <x_ray_control.h>
#include <nshc.h>

using namespace std;
// Работа с пациентом


/* Проблемки

  Пункт 10 хз, ничего не понятно, здесь нет
  Пункт 5 нужно ли в дерево передавать значения?
  Пункт 8 там вопрос стоит в мануале - здесь нет

 */


BT::NodeStatus ReadySystem()
{
  std::cout << "System OK" << std::endl;
  return BT::NodeStatus::SUCCESS;
}


class PatientWork
{
    public:
    PatientWork(){
    }

    BT::NodeStatus patientMode(){
        std::cout << "Подаётся команда cmd patient_mode - режим работы с пациентом. SUCCESS" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

    BT::NodeStatus patientSet(){
        std::cout << "Подаётся команда move patient_set. SUCCESS" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

    BT::NodeStatus patientSize(){
        std::cout << "Подаётся команда move patient_size. SUCCESS" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

    BT::NodeStatus patientPos(){
        std::cout << " PatientPos SUCCESS" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

    BT::NodeStatus sleepDelay(){
        std::cout << "задержка SUCCESS" << std::endl;
        //std::this_thread::sleep_for(5s);
        return BT::NodeStatus::SUCCESS;
    }


};


class MoveWithSetCommands
{
public:
    MoveWithSetCommands(){
    }

    BT::NodeStatus manual(){
        std::cout << "Включается ручной режим командой move manual. SUCCESS" << std::endl;
        return BT::NodeStatus::SUCCESS;
    }

// сюда ещё включение лазеров, пункт 10 хз как писать


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


    MoveWithSetCommands move_with_set_commands;

    factory.registerSimpleAction(
          "Manual",
          std::bind(&MoveWithSetCommands ::manual, &move_with_set_commands));

    MovementAllowed movement_allowed;

    factory.registerSimpleAction(
          "MovementAllowedEnable",
          std::bind(& MovementAllowed ::movementEnable, &movement_allowed));

    factory.registerSimpleAction(
          "MovementAllowedDisenable",
          std::bind(& MovementAllowed ::movementDisenable, &movement_allowed));



    PatientWork patient_work;

    factory.registerSimpleAction(
          "PatientMode",
          std::bind(&PatientWork ::patientMode, &patient_work));

    factory.registerSimpleAction(
          "PatientSet",
          std::bind(&PatientWork ::patientSet, &patient_work));

    factory.registerSimpleAction(
          "PatientSize",
          std::bind(&PatientWork ::patientSize, &patient_work));

    factory.registerSimpleAction(
          "PatientPos",
          std::bind(&PatientWork ::patientPos, &patient_work));

    factory.registerSimpleAction(
          "SleepDelay",
          std::bind(&PatientWork ::sleepDelay, &patient_work));


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


     //factory.registerBehaviorTreeFromFile("./../verification_device.xml");
       auto tree = factory.createTree("WorkPatient");
  tree.tickWhileRunning();


    return 0;
}
