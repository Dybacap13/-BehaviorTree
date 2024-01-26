#include <tree_ros.h>



TreeWithRos::TreeWithRos(ros::NodeHandle nh_)
            : nh(nh_) {

    //  Subscriber
    //*************************************************************************************************************
    // Общие команды
    cmd_shutdown_sub = nh_.subscribe("/oko_protocol/cmd_shutdown", 5,  &TreeWithRos::cmdShutdownCallback, this);
    cmd_restart_sub = nh_.subscribe("/oko_protocol/cmd_restart", 5,  &TreeWithRos::cmdRestartCallback, this);
    cmd_reset_sub = nh_.subscribe("/oko_protocol/cmd_reset", 5,  &TreeWithRos::cmdResetCallback, this);
    cmd_clear_error_sub = nh_.subscribe("/oko_protocol/cmd_clear_error", 5,  &TreeWithRos::cmdClearErrorCallback, this);

    // Управление манипулятором
    man_movement_allowed_sub = nh_.subscribe("/oko_protocol/man_movement_allowed", 5,  &TreeWithRos::manMovementAllowedCallback, this);
    man_mode_sub = nh_.subscribe("/oko_protocol/man_mode", 5,  &TreeWithRos::manModeCallback, this);
    //man_target_sub = nh_.subscribe("/oko_protocol/man_target", 5,  &TreeWithRos::manTargetCallback, this);
    man_auto_velocity_sub = nh_.subscribe("/oko_protocol/man_auto_velocity", 5,  &TreeWithRos::manAutoVelocityCallback , this);
    man_manual_sub = nh_.subscribe("/oko_protocol/man_manual", 5,  &TreeWithRos::manManualCallback , this);
    man_manual_velocity_sub = nh_.subscribe("/oko_protocol/man_manual_velocity", 5,  &TreeWithRos::manManualVelocitylCallback , this);
    man_manual_movement_sub = nh_.subscribe("/oko_protocol/man_manual_movement", 5,  &TreeWithRos::manManualMovementCallback , this);
    man_displacement_sub = nh_.subscribe("/oko_protocol/man_displacement", 5,  &TreeWithRos::manDisplacementCallback , this);
    man_patient_offset_sub = nh_.subscribe("/oko_protocol/man_patient_offset", 5,  &TreeWithRos::manPatientOffsetCallback , this);
    man_auto_execute_sub = nh_.subscribe("/oko_protocol/man_auto_execute", 5,  &TreeWithRos::manAutoExecuteCallback , this);
    man_update_instrument_point_sub = nh_.subscribe("/oko_protocol/man_update_instrument_point", 5,  &TreeWithRos::manUpdateInstrumentPointCallback , this);
    man_patient_size_sub = nh_.subscribe("/oko_protocol/man_patient_size", 5,  &TreeWithRos::manPatientSizeCallback , this);
    man_stop_sub = nh_.subscribe("/oko_protocol/man_stop", 5,  &TreeWithRos::manStopCallback , this);
    man_pause_sub = nh_.subscribe("/oko_protocol/man_pause", 5,  &TreeWithRos::manPauseCallback , this);
    man_resume_sub = nh_.subscribe("/oko_protocol/man_resume", 5,  &TreeWithRos::manResumeCallback , this);

    // Другие устройства
    lasers_sub = nh_.subscribe("/oko_protocol/lasers", 5,  &TreeWithRos::lasersCallback , this);
    barriers_sub = nh_.subscribe("/oko_protocol/barriers", 5,  &TreeWithRos::barriersCallback , this);
    accelerometer_block_sub = nh_.subscribe("/oko_protocol/accelerometer_block", 5,  &TreeWithRos::accelerometerBlockCallback , this);
    //*************************************************************************************************************


    //  Publisher
    //*************************************************************************************************************
    // Общие данные
    fault_button_pub = nh_.advertise<std_msgs::Bool>("/oko_protocol/telemetry/fault_button", 1000);
    pedal_pub =  nh_.advertise<std_msgs::Bool>("/oko_protocol/telemetry/pedal", 1000);

    // Манипулятор
    man_movement_allowed_pub =  nh_.advertise<std_msgs::Bool>("/oko_protocol/telemetry/man_movement_allowed", 1000);
    //man_mode_pub =  nh_.advertise<oko_msgs::ManMode>("/oko_protocol/telemetry/man_mode", 1000);
    man_status_pub = nh_.advertise<oko_msgs::ManStatus>("/oko_protocol/telemetry/man_status", 1000);
    //man_target_pub = nh_.advertise<oko_msgs::ManTarget>("/oko_protocol/telemetry/man_target", 1000);
    man_patient_size_pub = nh_.advertise<geometry_msgs::Point>("/oko_protocol/telemetry/man_patient_size", 1000);

    // Другие устройства
    lasers_pub = nh_.advertise<oko_msgs::MultipleObjectsStates>("/oko_protocol/telemetry/lasers", 1000);
    barriers_triggered_pub = nh_.advertise<oko_msgs::MultipleObjectsStates>("/oko_protocol/telemetry/barriers_triggered", 1000);
    barriers_block_pub = nh_.advertise<oko_msgs::MultipleObjectsStates>("/oko_protocol/telemetry/barriers_block", 1000);
    acceleration_exceeded_pub = nh_.advertise<std_msgs::Bool>("/oko_protocol/telemetry/acceleration_exceeded", 1000);
    accelerometer_block_pub = nh_.advertise<std_msgs::Bool>("oko_protocol/telemetry/accelerometer_block", 1000);
    //*************************************************************************************************************
}

void TreeWithRos::registerNodes(BT::BehaviorTreeFactory& factory){
    factory.registerSimpleCondition(
         "PatientMode", std::bind(&TreeWithRos::PatientMode, this));
    factory.registerSimpleCondition(
         "VerifyMode", std::bind(&TreeWithRos::VerifyMode, this));
    factory.registerSimpleCondition(
         "HydroPhantomMode", std::bind(&TreeWithRos::HydroPhantomMode, this));
    factory.registerSimpleAction(
         "ReadySystem", std::bind(&TreeWithRos::ReadySystem, this));



    factory.registerSimpleAction(
         "VerifySet", std::bind(&TreeWithRos::VerifySet, this));
    factory.registerSimpleAction(
         "VerifyPos1", std::bind(&TreeWithRos::VerifyPos1, this));
    factory.registerSimpleAction(
         "VerifyPos2", std::bind(&TreeWithRos::VerifyPos2, this));
    factory.registerSimpleAction(
         "VerifyPos3", std::bind(&TreeWithRos::VerifyPos3, this));
    factory.registerSimpleAction(
         "Home", std::bind(&TreeWithRos::Home, this));




    factory.registerSimpleAction(
         "PatientSet", std::bind(&TreeWithRos::PatientSet, this));
    factory.registerSimpleAction(
         "PatientSize", std::bind(&TreeWithRos::PatientSize, this));
    factory.registerSimpleAction(
         "PatientPos", std::bind(&TreeWithRos::PatientPos, this));

    factory.registerSimpleAction(
         "PhantomSet2", std::bind(&TreeWithRos::PhantomSet2, this));
    factory.registerSimpleAction(
         "PhantomSet3", std::bind(&TreeWithRos::PhantomSet3, this));
    factory.registerSimpleAction(
         "PhantomPos", std::bind(&TreeWithRos::PhantomPos, this));

    factory.registerSimpleAction(
         "MovementEnable", std::bind(&TreeWithRos::MovementEnable, this));
    factory.registerSimpleAction(
         "MovementDisenable", std::bind(&TreeWithRos::MovementDisenable, this));

    factory.registerSimpleAction(
         "Manual", std::bind(&TreeWithRos::Manual, this));


}


void TreeWithRos::cmdShutdownCallback (std_msgs::Bool msg){
    cmd_shutdown = msg.data;
}


void TreeWithRos::cmdRestartCallback (std_msgs::Bool msg){
    cmd_restart = msg.data;

}

void TreeWithRos::cmdResetCallback(std_msgs::Bool msg){
    cmd_reset = msg.data;

}

void TreeWithRos::cmdClearErrorCallback (std_msgs::Bool msg){
    cmd_clear_error = msg.data;
}


void TreeWithRos::manMovementAllowedCallback (std_msgs::Bool msg){
    man_movement_allowed = msg.data;
}


void TreeWithRos::manModeCallback (oko_msgs::ManMode msg){
    switch ( msg.mode )
          {
             case 0:
                man_mode_str = "TEST_MODE";
                break;
             case 1:
                man_mode_str = "EMPTY_CHAIR_MODE";
                break;

            case 2:
               man_mode_str = "HYDRO_PHANTOM_MODE";
               break;
            case 3:
               man_mode_str = "VERIFY_MODE";
               break;
            case 4:
               man_mode_str = "PATIENT_MODE";
               break;
            default:
                std::cout << "Unknown mode -> " << msg.mode << std::endl;
          }

}

// void TreeWithRos::manTargetCallback (oko_msgs::ManTarget msg){
//     man_target = msg;
// }


void TreeWithRos::manAutoVelocityCallback (oko_msgs::ManVelocity msg){
    man_auto_velocity = msg;
}

void TreeWithRos::manManualCallback (std_msgs::Bool msg){
    man_manual = msg.data;
}

void TreeWithRos::manManualVelocitylCallback (oko_msgs::ManVelocity msg){
    man_manual_velocity =  msg;
}

void TreeWithRos::manManualMovementCallback (geometry_msgs::TwistStamped msg){
    man_manual_movement = msg;
}

void TreeWithRos::manDisplacementCallback (geometry_msgs::TransformStamped msg){
    man_displacement = msg;
}
void TreeWithRos::manPatientOffsetCallback (geometry_msgs::TransformStamped msg){
    man_patient_offset = msg;
}


void TreeWithRos::manAutoExecuteCallback (std_msgs::Bool msg){
    man_auto_execute = msg.data;
}
void TreeWithRos::manUpdateInstrumentPointCallback (std_msgs::Bool msg){
    man_update_instrument_point = msg.data;
}



void TreeWithRos::manPatientSizeCallback (geometry_msgs::Point msg){
    man_patient_size = msg;
}

void TreeWithRos::manStopCallback (std_msgs::Bool msg){
    man_stop = msg.data;
}
void TreeWithRos::manPauseCallback (std_msgs::Bool msg){
    man_pause = msg.data;
}
void TreeWithRos::manResumeCallback (std_msgs::Bool msg){
    man_resume = msg.data;
}

void TreeWithRos::lasersCallback (oko_msgs::MultipleObjectsStates msg){
    lasers = msg;
}
void TreeWithRos::barriersCallback (oko_msgs::MultipleObjectsStates msg){
    barriers = msg;
}
void TreeWithRos::accelerometerBlockCallback (std_msgs::Bool msg){
    accelerometer_block =  msg.data;
}
