#include "pnc_map_server.h"
namespace Planning
{
    PncMapServer::PncMapServer(): Node("pnc_map_server_node")
    {
        RCLCPP_INFO(this->get_logger(),"pnc_map_server_node created");
    }
}

int main(int argc,char* argv[])
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<Planning::PncMapServer>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}