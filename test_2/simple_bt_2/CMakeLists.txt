cmake_minimum_required(VERSION 3.5)

project(sample_bt_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}  test.cpp)

find_package(ament_cmake QUIET)

if(ament_cmake_FOUND)

    find_package(behaviortree_cpp REQUIRED)
    ament_target_dependencies(${PROJECT_NAME} behaviortree_cpp)

elseif( CATKIN_DEVEL_PREFIX OR CATKIN_BUILD_BINARY_PACKAGE)

    find_package(catkin REQUIRED COMPONENTS behaviortree_cpp)
    catkin_package(CATKIN_DEPENDS behaviortree_cpp)
    target_include_directories(${PROJECT_NAME} PRIVATE ${catkin_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})

else()

    find_package(behaviortree_cpp REQUIRED)
    target_link_libraries(${PROJECT_NAME} BT::behaviortree_cpp)

endif()