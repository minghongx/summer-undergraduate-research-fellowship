cmake_minimum_required(VERSION 3.0.2)
project(go1)

set(CATKIN_PACKAGE_DEPENDENCIES
  ocs2_core
)

find_package(catkin REQUIRED COMPONENTS
  ${CATKIN_PACKAGE_DEPENDENCIES}
)
find_package(pinocchio REQUIRED)

catkin_package(
  INCLUDE_DIRS include
#   LIBRARIES go1
  CATKIN_DEPENDS
    ${CATKIN_PACKAGE_DEPENDENCIES}
  DEPENDS 
    pinocchio
)

include_directories(
  include
  ${pinocchio_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
)

install(DIRECTORY include/${PROJECT_NAME}/
        DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION})

set(PINOCCHIO_MODEL_DIR "${PROJECT_SOURCE_DIR}/models")
add_definitions('-DPINOCCHIO_MODEL_DIR=\"${PINOCCHIO_MODEL_DIR}\"')
add_executable(load_urdf src/load_urdf.cpp)
target_link_libraries(load_urdf PUBLIC pinocchio::pinocchio)
