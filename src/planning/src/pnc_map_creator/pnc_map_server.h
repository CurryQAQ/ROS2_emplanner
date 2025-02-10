#ifndef PNC_MAP_SERVER_H_
#define PNC_MAP_SERVER_H_

#include "rclcpp/rclcpp.hpp"
#include "pnc_map_straight.h"
#include "base_msgs/srv/pnc_map_service.hpp" //引用这个是为了使用Pnc_server中使用PNCMapService
#include "pnc_map_sturn.h"

namespace Planning
{
    using base_msgs::srv::PNCMapService; // 这样就可以直接使用PNCMapService了
    using std::placeholders::_1;// 这里面是回调函数参数的占位符
    using std::placeholders::_2;
    
    class PncMapServer : public rclcpp::Node
    {
    public:
        PncMapServer();

    private:
        // 响应并发布地图的回调函数,回调函数的参数是请求和响应
        void response_pnc_map_callback(const std::shared_ptr<PNCMapService::Request> request,
                                       const std::shared_ptr<PNCMapService::Response> response);

    private:
        std::shared_ptr<PncMapCreatorBase> map_creator_;         // 地图创建器,涉及到多态
        rclcpp::Publisher<PNCMap>::SharedPtr map_pub_;           // 地图发布器
        rclcpp::Publisher<MarkerArray>::SharedPtr map_rviz_pub_; // 地图markerarray发布器，在rviz中显示地图
        rclcpp::Service<PNCMapService>::SharedPtr map_server_;   // 地图服务器
    };
} // namespace Planning
#endif // PNC_MAP_SERVER_H_
