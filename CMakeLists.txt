cmake_minimum_required(VERSION 3.16)
project(oko_behavior_tree)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

find_package(catkin REQUIRED
    COMPONENTS
      roscpp
      std_msgs
      roslib
      oko_msgs
      geometry_msgs

 )
find_package(behaviortree_cpp REQUIRED)

    ##Generate messages in the 'msg' folder
#add_message_files(
#FILES
#Message1.msg
#Message2.msg
#)

    ##Generate services in the 'srv' folder
#add_service_files(
#FILES
#Service1.srv
#Service2.srv
#)

    ##Generate actions in the 'action' folder
#add_action_files(
#FILES
#Action1.action
#Action2.action
#)

    ##Generate added messages and services with any dependencies listed here
#generate_messages(
#DEPENDENCIES
#std_msgs
#)

catkin_package(
  INCLUDE_DIRS
  LIBRARIES
  CATKIN_DEPENDS geometry_msgs oko_msgs
  DEPENDS
)


set( SOURCES
        src/leaves/hydro_phantom_mode.cpp
        src/leaves/patient_mode.cpp
        src/leaves/ready_system.cpp
        src/leaves/verify_mode.cpp
        src/leaves/verify_set.cpp
        src/leaves/verify_pos1.cpp
        src/leaves/verify_pos2.cpp
        src/leaves/verify_pos3.cpp
        src/leaves/home.cpp
        src/leaves/manual.cpp
        src/leaves/movement_disenable.cpp
        src/leaves/movement_enable.cpp
        src/leaves/patient_pos.cpp
        src/leaves/patient_set.cpp
        src/leaves/patient_size.cpp  
        src/leaves/phantom_set2.cpp
        src/leaves/phantom_set3.cpp
        src/leaves/phantom_pos.cpp
        src/tree_ros.cpp
        src/main.cpp
        )

set( SRC_VERIFICATION_DEVICE
        src/verification_device_node.cpp
        src/verification_device/verification_device.cpp
        )

set( SRC_PHANTOM
        src/phantom_node.cpp
        src/phantom/phantom.cpp
        )

set(SRC_PATIENT
        src/patient_node.cpp
        src/patient/patient.cpp
        )


include_directories(
 include
 xml
  ${catkin_INCLUDE_DIRS}
)

add_executable(verification_device ${SRC_VERIFICATION_DEVICE})
add_executable(patient ${SRC_PATIENT})
add_executable(phantom ${SRC_PHANTOM})
add_executable(${PROJECT_NAME} ${SOURCES})


target_link_libraries(verification_device ${catkin_LIBRARIES} BT::behaviortree_cpp)
target_link_libraries(patient ${catkin_LIBRARIES} BT::behaviortree_cpp)
target_link_libraries(phantom ${catkin_LIBRARIES} BT::behaviortree_cpp)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} BT::behaviortree_cpp)

include(GNUInstallDirs)

install(TARGETS verification_device
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(TARGETS patient
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(TARGETS phantom
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
