#include <pinocchio/parsers/urdf.hpp>

#include <iostream>
#include <string>

int main() {

  const std::string path2urdf = PINOCCHIO_MODEL_DIR + std::string("/simple_humanoid.urdf");
  pinocchio::Model model;
  pinocchio::urdf::buildModel(path2urdf, pinocchio::JointModelFreeFlyer(), model);

  std::cout << "model.nq: " << model.nq << std::endl;
  std::cout << "model.nv: " << model.nv << std::endl;
}
