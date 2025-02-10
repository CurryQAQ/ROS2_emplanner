#include "planning_process.h"
namespace Planning
{
  // 构造函数实现
  PlanningProcess::PlanningProcess() : Node("planning_process")//规划总流程
  {
    RCLCPP_INFO(this->get_logger(),"planning_process created");

    process_config_ = std::make_unique<ConfigReader>();
    process_config_->read_planning_process_config();//调用一下读取文件，让读取成功
    obs_dis_ = process_config_->process().obs_dis_;//因为没办法在外部调用私有的成员变量

    // 两个客户端赋值
    map_client_ = this->create_client<PNCMapService>("pnc_map_server");
    global_path_client_ = this->create_client<GlobalPathService>("global_path_server");

  }

  // 总流程实现
  bool PlanningProcess::process()
  {
    // 阻塞1s，让rviz和xacros启动
    rclcpp::Rate rate(1.0); // 不带单位指的是1Hz,可传时间间隔/频率
    rate.sleep();

    // 规划初始化
    if(!planning_init())
    {
      RCLCPP_ERROR(this->get_logger(),"planning init error");
      return false;
    }

    // 进入规划总流程

    return true;
  }

  // 规划初始化
  bool PlanningProcess::planning_init()
  {
    // 生成车辆

    // 连接地图服务器
    if(!connect_server(map_client_))
    {
      RCLCPP_ERROR(this->get_logger(),"connect map server error");
      return false;
    }

    // 获取地图
    if(!map_request())
    {
      RCLCPP_ERROR(this->get_logger(),"map request error");
      return false;
    }

    // 连接全局路径服务器
    if(!connect_server(global_path_client_))
    {
      RCLCPP_ERROR(this->get_logger(),"connect global path server error");
      return false;
    }

    // 获取全局路径
    if(!global_path_request())
    {
      RCLCPP_ERROR(this->get_logger(),"global path request error");
      return false;
    }
    return true;
  }

  // 连接服务器
  template <typename T>
  bool PlanningProcess::connect_server(const T &client)
  {
      // 判断客户端类型
      // C++17的if constexpr语句，编译时判断模板参数类型
      std::string server_name;
      if constexpr (std::is_same<T, rclcpp::Client<PNCMapService>::SharedPtr>::value)
      {
          server_name = "pnc_map_server";
      }
      else if constexpr (std::is_same<T, rclcpp::Client<GlobalPathService>::SharedPtr>::value)
      {
          server_name = "global_path_server";
      }
      else
      {
          RCLCPP_ERROR(this->get_logger(), "client type error");
          return false;
      }
      
      // 等待服务器启动
      while (!client->wait_for_service(1s)) {
        if (!rclcpp::ok()) {
          RCLCPP_ERROR(this->get_logger(), "Interruped while waiting for the %s server.",server_name.c_str());
          return false;
        }
        RCLCPP_INFO(this->get_logger(), "%s Server not available, waiting again...",server_name.c_str());
      }
      // 服务器启动后返回true
      return true;
  }

  // 地图请求
  bool PlanningProcess::map_request()
  {
    RCLCPP_INFO(this->get_logger(),"Sending map request");
    
    // 生成请求
    auto request = std::make_shared<PNCMapService::Request>();
    request->map_type = process_config_->pnc_map().type_;//获取地图
    // 接受响应
    auto result_future = map_client_->async_send_request(request);
    // 判断响应是否成功
    if(rclcpp::spin_until_future_complete(this->get_node_base_interface(),result_future) == rclcpp::FutureReturnCode::SUCCESS)
    {
      RCLCPP_INFO(this->get_logger(),"Map reponse success");
      pnc_map_ = result_future.get()->pnc_map;
      return true;
    }
    else
    {
      RCLCPP_ERROR(this->get_logger(),"Map reponse error");
      return false;
    }
    // 
    return false;
  }

  bool PlanningProcess::global_path_request()
  {
    RCLCPP_INFO(this->get_logger(),"Sending global path request");
    // 生成请求
    auto request = std::make_shared<GlobalPathService::Request>();
    request->pnc_map = pnc_map_;
    request->global_planner_type = process_config_->global_path().type_;
    // 获取响应
    auto result_future = global_path_client_->async_send_request(request);
    // 判断响应是否成功
    if(rclcpp::spin_until_future_complete(this->get_node_base_interface(),result_future) == rclcpp::FutureReturnCode::SUCCESS)
    {
      RCLCPP_INFO(this->get_logger(),"Global path reponse success");
      global_path_ = result_future.get()->global_path;
      return true;
    }
    else
    {
      RCLCPP_ERROR(this->get_logger(),"Global path reponse error");
      return false;
    }

    return false;
  }

}
