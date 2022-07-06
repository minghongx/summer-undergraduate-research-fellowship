cmake_minimum_required(VERSION 3.0.2)
project(go1)

find_package(catkin REQUIRED)
find_package(pinocchio REQUIRED)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES go1
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

include_directories(
# include
# ${catkin_INCLUDE_DIRS}
)

set(PINOCCHIO_MODEL_DIR "${PROJECT_SOURCE_DIR}/models")
add_definitions('-DPINOCCHIO_MODEL_DIR=\"${PINOCCHIO_MODEL_DIR}\"')
add_executable(load_urdf src/load_urdf.cpp)
target_link_libraries(load_urdf PUBLIC pinocchio::pinocchio)
