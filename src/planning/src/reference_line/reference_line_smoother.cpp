#include "reference_line_smoother.h"
namespace Planning
{
    ReferenceLineSmoother::ReferenceLineSmoother()
    {
        RCLCPP_INFO(rclcpp::get_logger("reference_line"),"reference_line_smoother created");
    }
}