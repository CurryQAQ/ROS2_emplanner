#ifndef PLANNING_PROCESS_H_ // 头文件保护，防止被重复包含
#define PLANNING_PROCESS_H_

#include "rclcpp/rclcpp.hpp"
#include "config_reader.h"
#include "main_car.h"
#include "obs_car.h"
#include "reference_line_creator.h"
#include "decision_center.h"
#include "local_path_planner.h"
#include "local_speeds_planner.h"
#include "local_trajectory_combiner.h"

#include "base_msgs/msg/pnc_map.hpp"
#include "base_msgs/srv/global_path_service.hpp"
#include "base_msgs/srv/pnc_map_service.hpp"
#include "nav_msgs/msg/path.hpp"

#include <vector>
#include <cmath>
#include <algorithm>

namespace Planning // 命名空间，将相关定义放到planning的命名空间下
{
  using namespace std::chrono_literals; // planning阻塞时间用
  using PNCMap = base_msgs::msg::PNCMap;
  using Path = nav_msgs::msg::Path;
  using GlobalPathService = base_msgs::srv::GlobalPathService;
  using PNCMapService = base_msgs::srv::PNCMapService;

  class PlanningProcess : public rclcpp::Node
  {
  public:
    PlanningProcess();

    bool process(); // 规划总流程

  public:
    inline const PNCMap pnc_map() const { return pnc_map_; }       // 获取地图
    inline const Path global_path() const { return global_path_; } // 获取全局路径

  private:
    bool planning_init(); // 规划初始化

    // 此处使用模板,因为client可能是PNCMapService或者GlobalPathService，T是模板参数
    template <typename T>
    bool connect_server(const T &client); // 连接服务
    bool map_request();                   // 发送请求地图
    bool global_path_request();           // 发送请求全局路径

  private:
    double obs_dis_ = 0.0;
    std::unique_ptr<ConfigReader> process_config_;                    // 智能指针，流程配置
    PNCMap pnc_map_;                                                  // 地图
    Path global_path_;                                                // 全局路径
    rclcpp::Client<PNCMapService>::SharedPtr map_client_;             // 地图请求客户端,接受地图服务
    rclcpp::Client<GlobalPathService>::SharedPtr global_path_client_; // 全局路径请求客户端
  };
} // namespace Planning
#endif // PLANNING_PROCESS_H_