#ifndef PLANNING_PROCESS_H_ //头文件保护，防止被重复包含
#define PLANNING_PROCESS_H_
#include "rclcpp/rclcpp.hpp"
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