cmake_minimum_required(VERSION 3.5)

project(BTree_oko LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(behaviortree_cpp)






include_directories(
 include
 ${catkin_INCLUDE_DIRS}
)

#add_executable(verification_device src/verification_device.cpp)

add_executable(patient src/patient.cpp)


#target_link_libraries(verification_device BT::behaviortree_cpp)
target_link_libraries(patient BT::behaviortree_cpp)


# target_link_libraries(verification_device
#  ${catkin_LIBRARIES}
# )

# target_link_libraries(patient
#  ${catkin_LIBRARIES}
# )

include(GNUInstallDirs)

# install(TARGETS verification_device
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

install(TARGETS patient
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
