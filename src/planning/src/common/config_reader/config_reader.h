#ifndef CONFIG_READER_H_
#define CONFIG_READER_H_

#include "rclcpp/rclcpp.hpp"
#include <yaml-cpp/yaml.h> //获取yaml文件
#include <ament_index_cpp/get_package_share_directory.hpp> //获取文件路径
#include <unordered_map>

namespace Planning
{
    struct VehicleStruct
    {
        int id_ = 0;//序号
        std::string frame_ = "";     //坐标系
        double length_ = 0.0;        //长度
        double width_ = 0.0;         //宽度
        double pose_x_ =0.0;        //x
        double pose_y_ = 0.0;        //y
        double pose_theta_ = 0.0;    //航向角
        double speed_ori_ = 0.0;     //初速度
    };

    struct PNCMapStruct // 地图
    {
        std::string frame_ = "";       // 坐标系
        int type_ = 0;                 // 类型
        double road_length_ = 0.0;     // 道路长度
        double road_half_width_ = 0.0; // 车道半宽
        double segment_len_ = 0.0;     // 道路分段长度
        double speed_limit_ = 0.0;     // 限速
    };

    struct GlobalPathStruct // 全局路径
    {
        int type_ = 0; // 类型
    };

    struct ReferLineStruct // 参考线
    {
        int type_ = 0;       // 类型
        int front_size_ = 0; // 前方点数
        int back_size_ = 0;  // 后方点数
    };

    struct LocalPathStruct // 局部路径
    {
        int curve_type_ = 0; // 曲线类型
        int path_size_ = 0;  // 路径点数
    };

    struct LocalSpeedsStruct // 速度
    {
        int speed_size_ = 0; // 速度点数
    };

    struct DecisionStruct // 决策
    {
        double safe_dis_l_ = 0.0; // 侧向安全距离
        double safe_dis_s_ = 0.0; // 纵向安全距离
    };

    struct ProcessStruct // 总流程
    {
        double obs_dis_ = 0.0; // 考虑障碍物的距离
    };


    class ConfigReader
    {
    public:
        ConfigReader(); //配置文件读取器
        
        //写成员函数的声明
        //车辆
        void read_vehicle_config(VehicleStruct &vehicle,const std::string name);
        void read_vehicles_config();
        inline VehicleStruct main_car() const {return main_car_;}//获取成员变量的值
        inline VehicleStruct obs_car1() const {return obs_car1_;}
        inline VehicleStruct obs_car2() const {return obs_car2_;}
        inline VehicleStruct obs_car3() const {return obs_car3_;}
        inline std::unordered_map<int,VehicleStruct> obs_pair() const {return obs_pair_;}

        // pnc_map
        void read_pnc_map_config();
        inline PNCMapStruct pnc_map() const { return pnc_map_; }

        // global_path
        void read_global_path_config();
        inline GlobalPathStruct global_path() const { return global_path_; }

        // reference_line
        void read_reference_line_config();
        inline ReferLineStruct refer_line() const { return reference_line_; }

        // local_path
        void read_local_path_config();
        inline LocalPathStruct local_path() const { return local_path_; }

        // local_speed
        void read_local_speeds_config();
        inline LocalSpeedsStruct local_speeds() const { return local_speeds_; }

        // decision
        void read_decision_config();
        inline DecisionStruct decision() const { return decision_; }

        // planning_process
        void read_planning_process_config();
        inline ProcessStruct process() const { return process_; }

        // move_cmd
        void read_move_cmd_config();
    private:
        YAML::Node planning_config;//构造函数实现时会用到，获取yaml文件

        //车辆
        VehicleStruct main_car_;
        VehicleStruct obs_car1_;
        VehicleStruct obs_car2_;
        VehicleStruct obs_car3_;
        std::unordered_map<int,VehicleStruct> obs_pair_;//键值对，内部实现是哈希表
        //pnc地图
        PNCMapStruct pnc_map_;
        //全局路径
        GlobalPathStruct global_path_;
        //局部路径
        LocalPathStruct local_path_;
        //局部速度
        LocalSpeedsStruct local_speeds_;
        //参考线
        ReferLineStruct reference_line_;
        //决策中心
        DecisionStruct decision_;
        //规划流程
        ProcessStruct process_;
    };
}  //namespace Planning
#endif  // CONFIG_READER_H_
