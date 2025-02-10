#include "pnc_map_sturn.h"
namespace Planning
{
    PncMapSturn::PncMapSturn() //pnc弯道地图
    {
        RCLCPP_INFO(rclcpp::get_logger("pnc_map"),"pnc_map_sturn created");
    }
    PNCMap PncMapSturn::create_pnc_map()
    {
        return pnc_map_;
    }
}