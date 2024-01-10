cmake_minimum_required(VERSION 3.5)

project(BTree_oko LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(behaviortree_cpp)


add_executable(BTree_oko main.cpp)
target_link_libraries(${PROJECT_NAME} BT::behaviortree_cpp)
include(GNUInstallDirs)
install(TARGETS BTree_oko
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
