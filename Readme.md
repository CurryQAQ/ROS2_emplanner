# ROS2实现在RVIZ2中实现EMPlanner<br>
## 创建功能包<br>
1、三个功能包 base_msgs data_plot planning<br>
2、修改.vscode中的json文件增加两个路径 /opt/ros/${ROS_DISTRO}/include/** 和 /usr/local/include/**


## base_msgs功能包修改


1、在.xml文件中增加依赖说明<br>
  <buildtool_depned>rosidl_default_generators</buildtool_depend> 编译依赖<br>
  <build_depend>rosidl_default_generators</build_depend> 编译依赖<br>
  <exec_depend>rosidl_default_runtime</exec_depend> 执行依赖<br>

  <depend>visualization_msgs</depend> <br>
  <depend>std_msgs</depend> <br>
  <depend>geometry_msgs</depend> <br>
  <depend>nav_msgs</depend> ROS2自带消息类型的依赖<br>
  <member_of_group>rosidl_interface_packages</member_of_group> 消息打包依赖<br>
2、修改cmakelist文件<br>
🕐把cmake版本修改成自己的<br>
    设置C和C++格式<br>
    
    if(NOT CMAKE_C_STANDARD)<br>  
        set(CMAKE_C_STANDARD 99)<br>  
    endif()<br>

    if(NOT CMAKE_CXX_STANDARD)<br>  
        set(CMAKE_CXX_STANDARD 17)  
    endif()  

    在新版Cmake中已经废弃了，改用CMAKE_CXX_COMPILER_ID  
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")  
        add_compile_options(-Wall -Wextra -Wpedantic)  
    endif()  

    兼容旧版本的cmake  
    if(POLICY_CMP0148)  
        cmake_policy(SET CMP0148 OLD)  
    endif()  
🕑增加ROS自带消息接口的依赖


## 修改data_plot功能包  
1、在XML文件中增加依赖base_msgs
2、修改data_plot.py文件，添加节点的基本结构


## 修改planning功能包<br>
1、增加文件夹config launch urdf(main_car和obs_car)<br>
2、src目录下增加文件夹common(config_reader/math) vehicle_info(main_car和obs_car)<bar>
pnc_map_creator global_planner(global_normal) reference_line() decision_center local_planner(local_path/local_speeds) move_cmd<br>
### planning下cmakelist编写<br>
1、首先进行xml依赖的添加
<depend>rclcpp</depend>
  <depend>tf2</depend>
  <depend>tf2_ros</depend>
  <depend>geometry_msgs</depend>
  <depend>nav_msgs</depend>
  <depend>visualization_msgs</depend>
  <depend>base_msgs</depend>
  <depend>yaml-cpp</depend> 配置文件时用到
  <depend>ament_index_cpp</depend> 配置文件时用到

  <exec_depend>ros2launch</exec_depend>可执行文件的依赖
  <exec_depend>xacro</exec_depend>
  <exec_depend>robot_state_publisher</exec_depend>
  <exec_depend>joint_state_publisher</exec_depend>
  <exec_depend>rviz2</exec_depend>

