#include "planning_process.h"
namespace Planning
{
  PlanningProcess::PlanningProcess() : Node("planning_node")//规划总流程
  {
    RCLCPP_INFO(this->get_logger(),"planning_node created");
    process_config_ = std::make_unique<ConfigReader>();
    process_config_->read_planning_process_config();//调用一下读取文件，让读取成功
    auto obs_dis = process_config_->process().obs_dis_;//因为没办法在外部调用私有的成员变量
    RCLCPP_INFO(this->get_logger(), "obs_dis=%2.f",obs_dis);
  }
  bool PlanningProcess::process()
  {
    return true;
  }
}
