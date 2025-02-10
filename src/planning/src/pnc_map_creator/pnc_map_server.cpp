#include "pnc_map_server.h"
namespace Planning
{
    PncMapServer::PncMapServer() : Node("pnc_map_server_node")
    {
        RCLCPP_INFO(this->get_logger(), "pnc_map_server_node created");
        // 地图发布器赋值
        map_pub_ = this->create_publisher<PNCMap>("pnc_map", 10); // 参数:话题名,队列长度
        map_rviz_pub_ = this->create_publisher<MarkerArray>("pnc_map_rviz", 10);
        // 地图服务器赋值
        // 参数：话题名，回调函数
        // bind函数将回调函数绑定到当前对象实例this上，并将参数1和参数2传递给回调函数
        map_server_ = this->create_service<PNCMapService>("pnc_map_server",
                                                          std::bind(&PncMapServer::response_pnc_map_callback, this, _1, _2));
    }
    // 响应并发布地图
    void PncMapServer::response_pnc_map_callback(const std::shared_ptr<PNCMapService::Request> request, const std::shared_ptr<PNCMapService::Response> response)
    {
        // 接受请求，多态
        switch (request->map_type)
        {
        case static_cast<int>(PNCMapType::STRAIGHT)://强制类型转换
            map_creator_ = std::make_shared<PncMapStraight>();//这样就调用了PncMapStraight的构造函数，创建了地图对象
            break;
        case static_cast<int>(PNCMapType::STURN)://强制类型转换
            map_creator_ = std::make_shared<PncMapSturn>();//这样就调用了PncMapSturn的构造函数，创建了地图对象
            break;
        default:
            RCLCPP_ERROR(this->get_logger(), "pnc_map_type error");
            return;
        }
        
        // 创建并响应地图
        const auto pnc_map = map_creator_->create_pnc_map();
        response->pnc_map = pnc_map;
        
        // 发布地图，planning node用
        map_pub_->publish(pnc_map);
        RCLCPP_INFO(this->get_logger(), "pnc_map published");

        // 发布用于rviz显示的地图,会有一个转换函数，把pnc的地图转换成rviz的地图
        const auto pnc_map_markerarray = map_creator_->get_pnc_map_markerarray();
        map_rviz_pub_->publish(pnc_map_markerarray);
        RCLCPP_INFO(this->get_logger(), "pnc_map_rviz published");
    }
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Planning::PncMapServer>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}