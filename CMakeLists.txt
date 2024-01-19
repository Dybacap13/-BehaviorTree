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
      oko_protocol
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
#  INCLUDE_DIRS include
#  LIBRARIES
  CATKIN_DEPENDS oko_protocol
#  DEPENDS system_lib
)


set( SOURCES
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
#add_executable(test_create_model src/create_model.cpp)


target_link_libraries(verification_device ${catkin_LIBRARIES} BT::behaviortree_cpp)
target_link_libraries(patient ${catkin_LIBRARIES} BT::behaviortree_cpp)
target_link_libraries(phantom ${catkin_LIBRARIES} BT::behaviortree_cpp)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})
#target_link_libraries(test_create_model  ${catkin_LIBRARIES} BT::behaviortree_cpp)

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
