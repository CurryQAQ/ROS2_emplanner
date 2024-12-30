#ifndef PNC_MAP_SERVER_H_
#define PNC_MAP_SERVER_H_

#include "rclcpp/rclcpp.hpp"
#include "pnc_map_straight.h"
#include "pnc_map_sturn.h"

namespace Planning
{
    class PncMapServer: public rclcpp::Node
    {
    public:
        PncMapServer();

    private:

    };
}  // namespace Planning
#endif  // PNC_MAP_SERVER_H_
