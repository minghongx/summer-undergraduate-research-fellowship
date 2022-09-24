# SURF on Optimal Control for Switched Systems (OCS2)

OCS2 is a toolbox provides:
- implementation of four algos: SLQ, iLQR, SQP, and PISOC
- utilties for setting up kinematic/dynamic/centroidal models
- a differentiation tool to calculate derivatives
- ROS interfaces

w/ six robotic examples.

## Objectives:
- [x] Deploy OCS2 on Unitree Go1 (simulation only).
- [ ] Understand OCS2.
- [ ] Sim2Real.
- [ ] Modify/Improve to best suit Go1 in real.

---

# Hindrance
```c++
LeggedRobotInterface.cpp
------------------------
void 
LeggedRobotInterface::setupOptimalConrolProblem(...) {
  [...]
  centroidalModelInfo_ = centroidal_model::createCentroidalModelInfo(
      *pinocchioInterfacePtr_,
      centroidal_model::loadCentroidalType(taskFile),
      centroidal_model::loadDefaultJointState(pinocchioInterfacePtr_->getModel().nq - 6, referenceFile),
      modelSettings_.contactNames3DoF,
      modelSettings_.contactNames6DoF);
  [...]
```

*nq*: Dimension of the configuration vector representation.

`pinocchioInterfacePtr_->getModel().nq - 6` returns incorrect number of joint state; expect 18, got 0.

---

# Hindrance
```c++
void
LeggedRobotInterface::setupOptimalConrolProblem(...) {
  // PinocchioInterface
  pinocchioInterfacePtr_.reset(new PinocchioInterface(centroidal_model::createPinocchioInterface(urdfFile, modelSettings_.jointNames)));

  centroidalModelInfo_ = centroidal_model::createCentroidalModelInfo(
  [...]
```

```c++
PinocchioInterface
createPinocchioInterface(const std::string& urdfFilePath, const std::vector<std::string>& jointNames) {
  // remove extraneous joints from urdf
  ::urdf::ModelInterfaceSharedPtr newModel = std::make_shared<::urdf::ModelInterface>(*urdfTree);
  for (joint_pair_t& jointPair : newModel->joints_) {
    if (std::find(jointNames.begin(), jointNames.end(), jointPair.first) == jointNames.end()) {
      jointPair.second->type = urdf::Joint::FIXED;
    }
  }
```

---

# Hindrance
```c++
ModelSettings.h
---------------
//   std::vector<std::string> jointNames{"LF_HAA", "LF_HFE", "LF_KFE", "RF_HAA", "RF_HFE", "RF_KFE",
//                                       "LH_HAA", "LH_HFE", "LH_KFE", "RH_HAA", "RH_HFE", "RH_KFE"};
std::vector<std::string> jointNames{"FL_hip_joint"  , "FL_thigh_joint", "FL_calf_joint" , "FR_hip_joint",
                                    "FR_thigh_joint", "FR_calf_joint" , "RL_hip_joint"  , "RL_thigh_joint",
                                    "RL_calf_joint" , "RR_hip_joint"  , "RR_thigh_joint", "RR_calf_joint"};
```
Joint names are hard coded.

---

# Tuning parameters
- command/reference.info
- mpc/task.info
- ocs2_centroidal_model/test/definitions.h
- testEndEffectorLinearConstraint.cpp

