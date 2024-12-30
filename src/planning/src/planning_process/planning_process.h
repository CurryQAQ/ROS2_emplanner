#ifndef PLANNING_PROCESS_H_ //头文件保护，防止被重复包含
#define PLANNING_PROCESS_H_

#include "rclcpp/rclcpp.hpp"
#include "config_reader.h"
#include "main_car.h"
#include "obs_car.h"
#include "reference_line_creator.h"
#include "decision_center.h"
#include "local_path_planner.h"
#include "local_speeds_planner.h"
#include "local_trajectory_combiner.h"

#include <vector>
#include <cmath>
#include <algorithm>


namespace Planning //命名空间，将相关定义放到planning的命名空间下
{
class PlanningProcess: public rclcpp::Node
{
public:
  PlanningProcess();

  bool process();//规划总流程
};
}  // namespace Planning
#endif  //PLANNING_PROCESS_H_ 