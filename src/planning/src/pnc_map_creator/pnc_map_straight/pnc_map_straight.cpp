#include "pnc_map_straight.h"
namespace Planning
{
    PncMapStraight::PncMapStraight() //pnc直道地图
    {
        RCLCPP_INFO(rclcpp::get_logger("pnc_map"),"pnc_map_straight created");
    }
    PNCMap PncMapStraight::create_pnc_map()
    {
        return pnc_map_;
    }
}