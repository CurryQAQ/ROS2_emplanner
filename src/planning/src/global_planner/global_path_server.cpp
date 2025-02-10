#include "global_path_server.h"
namespace Planning
{
    GlobalPathServer::GlobalPathServer() : Node("global_path_server_node")
    {
        RCLCPP_INFO(this->get_logger(), "global_path_server_node created");
        // 创建两个发布器
        global_path_pub_ = this->create_publisher<Path>("global_path", 10);             // 给planning用的
        global_path_rviz_pub_ = this->create_publisher<Marker>("global_path_rviz", 10); // 给rviz用的
        // 创建服务
        global_path_server_ = this->create_service<GlobalPathService>("global_path_server",
                                                                      std::bind(&GlobalPathServer::response_global_path_callback, this,
                                                                                std::placeholders::_1, std::placeholders::_2));
    }

    // 全局路径回调
    void GlobalPathServer::response_global_path_callback(const std::shared_ptr<GlobalPathService::Request> request,
                                                         const std::shared_ptr<GlobalPathService::Response> response)
    {
        // 接受请求，用多态
        switch(request->global_planner_type)
        {
        case static_cast<int>(GlobalPathType::NORMAL):
            global_planner_base_ = std::make_shared<GlobalPlannerNormal>(); ///创建了一个普通全局路径规划器
            break;
        default:
            RCLCPP_ERROR(this->get_logger(), "global_planner_type error");
            return;
        }
        // 判断请求是否为空,这个points是一个vector
        if(request->pnc_map.midline.points.empty())
        {
            RCLCPP_ERROR(this->get_logger(), "pnc_map empty");
            return;
        }

        // 接受请求并响应全局路径
        const auto global_path = global_planner_base_->search_global_path(request->pnc_map);
        response->global_path = global_path;
        
        // 发布planning用的全局路径
        // 只发布一次，并且path中没有frame_lock，所以不能固定在rviz中,所以需要转换成marker
        global_path_pub_->publish(global_path);
        RCLCPP_INFO(this->get_logger(), "global_path published");
        
        // 发布rviz用的全局路径
        const auto global_path_rviz = path2marker(global_path);
        global_path_rviz_pub_->publish(global_path_rviz);
        RCLCPP_INFO(this->get_logger(), "global_path_rviz published");

    }

    // 路径转标记
    Marker GlobalPathServer::path2marker(const Path &path)
    {
        Marker path_rviz_;
        return path_rviz_;
    }
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Planning::GlobalPathServer>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}