#include <pinocchio/parsers/urdf.hpp>

#include <iostream>
#include <string>

int main() {

  const std::string path2urdf4go1 = std::string("/catkin_ws/src/unitree_ros/robots/go1_description/urdf/go1.urdf");
  const std::string path2urdf4anymal = std::string("/catkin_ws/src/ocs2_robotic_assets/resources/anymal_c/urdf/anymal.urdf");
  // const std::string path2urdf = PINOCCHIO_MODEL_DIR + std::string("/simple_humanoid.urdf");
  pinocchio::Model model4go1, model4anymal;
  pinocchio::urdf::buildModel(path2urdf4go1, pinocchio::JointModelFreeFlyer(), model4go1);
  pinocchio::urdf::buildModel(path2urdf4anymal, pinocchio::JointModelFreeFlyer(), model4anymal);

  std::cout << model4go1;
  std::cout << model4anymal;
  // std::cout << "model.nq: " << model.nq << std::endl;
  // std::cout << "model.nv: " << model.nv << std::endl;
}
