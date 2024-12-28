#ifndef PLANNING_PROCESS_H_
#define PLANNING_PROCESS_H_
#include "rclcpp/rclcpp.hpp"
namespace Planning
{
class PlanningProcess: public rclcpp::Node
{
public:
  PlanningProcess();

  bool process();
};
}  // namespace Planning
#endif  //PLANNING_PROCESS_H_ 