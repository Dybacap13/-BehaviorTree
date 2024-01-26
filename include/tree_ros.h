#include <iostream>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <memory>


#include "behaviortree_cpp/bt_factory.h"
#include "behaviortree_cpp/action_node.h"

#include <ros/package.h>
#include <ros/ros.h>

#include <std_msgs/Bool.h>
#include <oko_msgs/ManMode.h>
//#include <oko_msgs/ManTarget.h>
#include <oko_msgs/ManVelocity.h>
#include <geometry_msgs/TwistStamped.h>
#include <geometry_msgs/Point.h>
#include <oko_msgs/MultipleObjectsStates.h>
#include <geometry_msgs/TransformStamped.h>
#include <oko_msgs/ManStatus.h>


class TreeWithRos {

public:
    TreeWithRos(ros::NodeHandle nh_);

    bool system_status = true;

    // states
    bool cmd_shutdown;
    bool cmd_restart;
    bool cmd_clear_error;
    bool cmd_reset;

    bool man_movement_allowed;
    //oko_msgs::ManMode man_mode;
    //oko_msgs::ManTarget man_target;
    oko_msgs::ManVelocity man_auto_velocity;
    bool man_manual;
    oko_msgs::ManVelocity man_manual_velocity;
    geometry_msgs::TwistStamped man_manual_movement;
    geometry_msgs::TransformStamped man_displacement;
    geometry_msgs::TransformStamped man_patient_offset;
    bool man_auto_execute;
    bool man_update_instrument_point;
    geometry_msgs::Point man_patient_size;
    bool man_stop;
    bool man_pause;
    bool man_resume;
    oko_msgs::MultipleObjectsStates lasers;
    oko_msgs::MultipleObjectsStates barriers;
    bool accelerometer_block;



    std::string man_mode_str;
private:

    ros::NodeHandle nh;

    // Topic Pub
    ros::Publisher fault_button_pub; // топик состояния авраийной кнопки
    ros::Publisher pedal_pub; // топик состояния педали

    ros::Publisher man_movement_allowed_pub; // топик состояния разрешения движения манипулятора
    ros::Publisher man_mode_pub; // tопик текущего режима работы (объект, висящий на манипуляторе)
    ros::Publisher man_status_pub; // топик текущего состояния робота (движемся, збс, ошибка ...)
    ros::Publisher man_target_pub; // топик текущей цели движения робота
    ros::Publisher man_patient_size_pub; //топик текущего положения глаза пациента относительно ASS

    ros::Publisher lasers_pub; // топик состояния питания лазеров
    ros::Publisher barriers_triggered_pub; // топик текущего срабатывания световых барьеров (сработал/не сработал).
    ros::Publisher barriers_block_pub; // топик для состояния световых барьеров (заблокирован/не заблокирован).
    ros::Publisher acceleration_exceeded_pub; // топик для уведомления о превышении допустимого ускорения
    ros::Publisher accelerometer_block_pub; // топик состояния блокировки сигнала акселерометра


    // Topic Sub
    ros::Subscriber cmd_shutdown_sub;  // выключение всей системы
    ros::Subscriber cmd_restart_sub;   // перезагрузка
    ros::Subscriber cmd_reset_sub;  //  сброса АСУ УППП в начальное состояние
    ros::Subscriber cmd_clear_error_sub; // топик для сброса ошибок

    ros::Subscriber man_movement_allowed_sub; // топик для разрешения движения манипулятора
    ros::Subscriber man_target_sub; // отправки манипуятора в какую-либо цель
    ros::Subscriber man_mode_sub; // топик для задания режима работы
    ros::Subscriber man_auto_velocity_sub; // топик для задания скорости перемещения рабочей точки в автоматическом режиме
    ros::Subscriber man_manual_sub; // топик для включения ручного режима
    ros::Subscriber man_manual_velocity_sub; // топик для задания скорости перемещения рабочей точки в ручном режиме
    ros::Subscriber man_manual_movement_sub; //топик для передачи команды ручного перемещения
    ros::Subscriber man_displacement_sub; // топик для задания рассогласования верификационного устройства и изоцентра по резултатам рентгена
    ros::Subscriber man_patient_offset_sub; // топик для задания рассогласования пациента (его глаза) и изоцентра по резултатам рентгена (в ИЛС - point_offset)
    ros::Subscriber man_auto_execute_sub; //топик для начала отработки рассогласования после рентгена (для верификатора и глаза пациента)
    ros::Subscriber man_update_instrument_point_sub; //топик для обновления рабочей точки текщего инструмента из текущих координат
    ros::Subscriber man_patient_size_sub; // топик для задания положения глаза пациента, относительно его ASS

    ros::Subscriber man_stop_sub; // для остановки робота
    ros::Subscriber man_pause_sub; // топик для приостановки робота (остановка с запоминанием предыдущей цели)
    ros::Subscriber man_resume_sub; // топик для продолжения движения робота (из текущей точки отправляем в ранее заданную)

    ros::Subscriber lasers_sub; // топик для вкл/выкл питания лазеров
    ros::Subscriber barriers_sub; // топик для вкл/выкл блокировки световых барьеров
    ros::Subscriber accelerometer_block_sub; // топик для вкл/выкл блокировки сигнала акселерометра


    // Callback
    void cmdShutdownCallback (std_msgs::Bool msg);
    void cmdRestartCallback (std_msgs::Bool msg);
    void cmdResetCallback(std_msgs::Bool msg);
    void cmdClearErrorCallback (std_msgs::Bool msg);
    void manMovementAllowedCallback (std_msgs::Bool msg);
    void manModeCallback (oko_msgs::ManMode msg);
    //void manTargetCallback (oko_msgs::ManTarget msg);
    void manAutoVelocityCallback (oko_msgs::ManVelocity msg);
    void manManualCallback (std_msgs::Bool msg);
    void manManualVelocitylCallback (oko_msgs::ManVelocity msg);
    void manManualMovementCallback (geometry_msgs::TwistStamped msg);
    void manDisplacementCallback (geometry_msgs::TransformStamped msg);
    void manPatientOffsetCallback (geometry_msgs::TransformStamped msg);
    void manAutoExecuteCallback (std_msgs::Bool msg);
    void manUpdateInstrumentPointCallback (std_msgs::Bool msg);
    void manPatientSizeCallback (geometry_msgs::Point msg);
    void manStopCallback (std_msgs::Bool msg);
    void manPauseCallback (std_msgs::Bool msg);
    void manResumeCallback (std_msgs::Bool msg);
    void lasersCallback (oko_msgs::MultipleObjectsStates msg);
    void barriersCallback (oko_msgs::MultipleObjectsStates msg);
    void accelerometerBlockCallback (std_msgs::Bool msg);



public:
    void registerNodes(BT::BehaviorTreeFactory& factory);

    //leaves
    BT::NodeStatus HydroPhantomMode();
    BT::NodeStatus VerifyMode();
    BT::NodeStatus ReadySystem();
    BT::NodeStatus PatientMode();

    BT::NodeStatus VerifySet();
    BT::NodeStatus VerifyPos1();
    BT::NodeStatus VerifyPos2();
    BT::NodeStatus VerifyPos3();
    BT::NodeStatus Home();


    BT::NodeStatus PatientSet();
    BT::NodeStatus PatientSize();
    BT::NodeStatus PatientPos();

    BT::NodeStatus PhantomSet2();
    BT::NodeStatus PhantomSet3();
    BT::NodeStatus PhantomPos();

    BT::NodeStatus MovementEnable();
    BT::NodeStatus MovementDisenable();

    BT::NodeStatus Manual();
public:
    // path
    std::string path_to_pack = ros::package::getPath("oko_behavior_tree");
    std::string path_to_main_xml = "/xml/_main_tree.xml";

};












