#include "local_speeds_planner.h"
namespace Planning
{
    LocalSpeedsPlanner::LocalSpeedsPlanner() //速度规划器
    {
        RCLCPP_INFO(rclcpp::get_logger("local_speeds"),"local_speeds_planner created");
    }
}