#ifndef GLOBAL_PLANNER_BASE_H_
#define GLOBAL_PLANNER_BASE_H_

#include "rclcpp/rclcpp.hpp"
#include "config_reader.h"
#include "geometry_msgs/msg/pose_stamped.hpp"//位姿消息
#include "nav_msgs/msg/path.hpp" //路径消息
#include "base_msgs/msg/pnc_map.hpp" //地图消息
 
namespace Planning
{
    using PoseStamped = geometry_msgs::msg::PoseStamped;
    using Path = nav_msgs::msg::Path;
    using PncMap = base_msgs::msg::PNCMap;

    enum class GlobalPathType
    {
        NORMAL, //普通路径规划
    };

    class GlobalPathBase //全局路径规划器基类
    {
    public:
        virtual Path search_global_path(const PncMap &pnc_map) = 0; //搜索全局路径
        inline Path get_global_path() const { return global_path_; } //获取全局路径
        virtual ~GlobalPathBase() {}

    protected:
        Path global_path_; //全局路径
        int global_path_type_ = 0; //全局路径类型
        std::unique_ptr<ConfigReader> global_planner_config_; //配置文件读取器

    };
}  // namespace Planning
#endif  // GLOBAL_PLANNER_BASE_H_
