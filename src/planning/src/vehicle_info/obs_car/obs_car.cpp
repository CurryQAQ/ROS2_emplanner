#include "obs_car.h"
namespace Planning
{
    ObsCar::ObsCar()
    {
        RCLCPP_INFO(rclcpp::get_logger("vehicle"),"obs_car created");
    }
}