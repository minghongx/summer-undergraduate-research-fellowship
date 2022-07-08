// Mimic ocs2_legged_robot/common/ModelSettings.h

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <ocs2_core/Types.h>

namespace ocs2 {
namespace legged_robot {

struct ModelSettings {
  scalar_t positionErrorGain = 0.0;

  scalar_t phaseTransitionStanceTime = 0.4;

  bool verboseCppAd = true;
  bool recompileLibrariesCppAd = true;
  std::string modelFolderCppAd = "/tmp/ocs2";

  // This is only used to get names for the knees and to check urdf for extra joints that need to be fixed.
//   std::vector<std::string> jointNames{"LF_HAA", "LF_HFE", "LF_KFE", "RF_HAA", "RF_HFE", "RF_KFE",
//                                       "LH_HAA", "LH_HFE", "LH_KFE", "RH_HAA", "RH_HFE", "RH_KFE"};
  std::vector<std::string> jointNames{"FL_hip_joint:", "FL_thigh_joint:", "FL_calf_joint", "FR_hip_joint", "FR_thigh_joint", "FR_calf_joint", "RL_hip_joint", "RL_thigh_joint", "RL_calf_joint", "RR_hip_joint", "RR_thigh_joint", "RR_calf_joint"};
  std::vector<std::string> contactNames6DoF{};
//   std::vector<std::string> contactNames3DoF{"LF_FOOT", "RF_FOOT", "LH_FOOT", "RH_FOOT"};
  std::vector<std::string> contactNames3DoF{"FL_foot", "FR_foot", "RL_foot", "RR_foot"};
};

ModelSettings loadModelSettings(const std::string& filename, const std::string& fieldName = "model_settings", bool verbose = "true");

}  // namespace legged_robot
}  // namespace ocs2
