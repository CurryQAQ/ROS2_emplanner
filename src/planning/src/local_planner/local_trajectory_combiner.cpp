# include"local_trajectory_combiner.h"

namespace Planning
{
    LocalTrajectoryCombiner::LocalTrajectoryCombiner()//轨迹合成器
    {
        RCLCPP_INFO(rclcpp::get_logger("local_trajectory"),"local_trajectory_combiner created");
    }
}