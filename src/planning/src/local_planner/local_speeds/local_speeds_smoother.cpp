#include "local_speeds_smoother.h"

namespace Planning
{
    LocalSpeedsSmoother::LocalSpeedsSmoother() //速度平滑器
    {
        RCLCPP_INFO(rclcpp::get_logger("local_speeds"),"local_speeds_smoother created");
    }
}
