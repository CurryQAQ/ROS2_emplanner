#ifndef GLOBAL_PATH_SERVER_H_
#define GLOBAL_PATH_SERVER_H_

#include "rclcpp/rclcpp.hpp"
#include "global_planner_normal.h"
#include "base_msgs/srv/global_path_service.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "visualization_msgs/msg/marker.hpp"

namespace Planning
{
    using Point = geometry_msgs::msg::Point;
    using Marker = visualization_msgs::msg::Marker;
    using GlobalPathService = base_msgs::srv::GlobalPathService;

    class GlobalPathServer: public rclcpp::Node
    {
    public:
        GlobalPathServer();
    private:
        //回调函数
        void response_global_path_callback(const std::shared_ptr<GlobalPathService::Request> request,
                                           std::shared_ptr<GlobalPathService::Response> response);
        Marker path2marker(const Path &path); //路径转标记
    private:
        std::shared_ptr<GlobalPathBase> global_planner_base_;               //全局路径创建器
        rclcpp::Publisher<Path>::SharedPtr global_path_pub_;                //全局路径发布器
        rclcpp::Publisher<Marker>::SharedPtr global_path_rviz_pub_;         //全局路径可视化发布器
        rclcpp::Service<GlobalPathService>::SharedPtr global_path_server_;  //全局路径服务
    };
}  // namespace Planning
#endif  // GLOBAL_PATH_SERVER_H_
