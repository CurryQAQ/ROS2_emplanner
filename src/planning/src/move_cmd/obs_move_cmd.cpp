#include "obs_move_cmd.h"
namespace Planning
{
    ObsMoveCmd::ObsMoveCmd() : Node("obs_move_cmd_node")
    {
        RCLCPP_INFO(this->get_logger(),"obs_move_cmd_node created");
    }
}

int main(int argc,char *argv[])
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<Planning::ObsMoveCmd>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}