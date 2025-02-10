#ifndef PNC_MAP_CREATOR_BASE_H_
#define PNC_MAP_CREATOR_BASE_H_

#include "rclcpp/rclcpp.hpp"
#include "config_reader.h"
#include "geometry_msgs/msg/point.hpp" //引用这个是为了使用Pnc_server中使用Point
#include "base_msgs/msg/pnc_map.hpp" //引用这个是为了使用Pnc_server中使用PNCMap
#include "visualization_msgs/msg/marker.hpp" //引用这个是为了使用Pnc_server中使用Marker
#include "visualization_msgs/msg/marker_array.hpp" //引用这个是为了使用Pnc_server中使用MarkerArray
namespace Planning
{
    using base_msgs::msg::PNCMap;
    using geometry_msgs::msg::Point;
    using visualization_msgs::msg::Marker;
    using visualization_msgs::msg::MarkerArray;

    enum class PNCMapType //地图类型，强枚举类型
    {
        STRAIGHT,//默认值为0
        STURN,//默认值为1
    };

    class PncMapCreatorBase //地图基类
    {
    public:
        virtual PNCMap create_pnc_map() = 0;                                                // 纯虚函数，子类必须实现，生成地图
        inline PNCMap get_pnc_map() const { return pnc_map_; };                             // 获取地图
        inline MarkerArray get_pnc_map_markerarray() const { return pnc_map_markerarray_; };// 获取rviz中的地图
        virtual ~PncMapCreatorBase() {} //虚析构函数，代码规范性
    
    protected:
        std::unique_ptr<ConfigReader> pnc_map_config_;  // 地图的配置文件
        int map_type_ = 0;                              // 地图类型
        PNCMap pnc_map_;                                // 地图
        MarkerArray pnc_map_markerarray_;               // rviz中用的地图

        Point p_mid_,pl_,pr_;                           // 左中右三个点
        double theta_current_ = 0.0;                    // 当前角度
        double len_step_ = 0.0;                         // 长度步长
        double theta_step_ = 0.0;                       // 角度步长
    };
}  // namespace Planning
#endif  // PNC_MAP_CREATOR_BASE_H_
