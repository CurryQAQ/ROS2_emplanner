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
🕑增加ROS自带消息接口的依赖<br>


## 修改data_plot功能包  
1、在XML文件中增加依赖base_msgs
2、修改data_plot.py文件，添加节点的基本结构


## 修改planning功能包<br>
1、增加文件夹config launch urdf(main_car和obs_car)<br>
2、src目录下增加文件夹common(config_reader/math) vehicle_info(main_car和obs_car)<bar>
pnc_map_creator global_planner(global_normal) reference_line() decision_center local_planner(local_path/local_speeds) move_cmd<br>
### planning下cmakelist编写<br>
1、首先进行xml依赖的添加<br>
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

2、总目录下的cmakelist编写<br>
🕐设置预编译命令，生成compile_commands.json,然后让c_cpp_properties.json读取这个文件，防止预编译找不到cmake中定义的宏而报错<br>
命令---c_cpp_properties.json中加上"compileCommands“：”${workspaceFolder}/build/compile_commands.json<br>
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)<br>
#设置包名，让子目录节点安装时使用<br>
set(PLANNING_PACKAGE_NAME ${PROJRCT_NAME})<br>
🕑包含头文件的目录include_directories(),把planning/src模块里的所有目录 包括子目录都放进来
🕒添加依赖find_package,添加子目录，找子目录下的cmake add_subdirectory
🍀安装辅助目录，planning下的config launch rviz urdf放进share文件夹下

3、子目录下的cmakelist编写<br>
给src下的每一个子文件都加一个cmakelist------设置依赖添加、添加动态库/节点、安装动态库/节点/相关目录<br>

4、planning_process下.cpp文件编写,plannig_node入口文件，cmakelist添加执行文件、绑定依赖、安装可执行文件

5、common文件下.cpp/.h编写，均未继承节点,cmakelist编写，添加成动态库/绑定依赖/链接第三方库/安装动态库到指定位置<br>
6、decision_center文件下.cpp/.h文件编写,未继承节点,cmakelist编写，添加成动态库/绑定依赖/链接第三方库/安装动态库到指定位置<br>
7、<br>
🕐global_planner----基类的.h文件创建，noraml.h/.cpp文件创建（继承基类，做成动态库），服务节点.cpp/.h文件创建(可执行文件),cmakelist编写<br>
🕑local_planner----path/speeds/combiner都做成动态库，cmakelist编写<br>
🕒pnc_map-------同global，基类的.h文件创建，两种道路类型.h/.cpp文件创建（继承基类，做成动态库），服务节点.cpp/.h文件<br>
🍀reference_line----creater/smoother 都是动态库<br>
🕔vehicle_info----车辆基类创建,main/obs都是继承基类的动态库<br>

8、planning中各个模块头文件包含

### 配置文件.h的编写
1、config目录下的.yaml文件编写<br>
2、config_reader.h下写结构体，去初始化.yaml文件中出现的东西<br>
3、config_reader.h类中声明结构体类型的变量,obs障碍物用键值对来表示unordered_map，利用(const auto& [key, value] : obs_pair_)可去遍历这个键值对<br>
4、yaml::Node 

### 配置文件.h的读取
1、车辆信息/全局路径/局部路径等等 这些东西的读取成员函数 （读取配置+获取变量）<br>
2、inline（函数体不复杂的时候可以用，以提高运行性能） 内联函数用于返回成员变量，const表示函数改变不了成员变量<br>

### config_reader.cpp编写
1、构造函数----ament_index_cpp路径读取,YAML::loadfile得到config中.yaml文件<br>
2、read_config函数编写，主要就是把.yaml中的数据读取出来

### 车辆模型和launch文件
1、车辆xacro文件<br>
2、planning_launch文件编写(套路编写即可)<br>

## base_msgs消息
对话题消息类型和服务消息类型进行编写，msgs和srv<br>
注意在cmakelists上要添加上依赖<br>

## pnc_map服务器编写
1、.h写地图的回调函数和成员变量(创建器、发布器、服务器)
2、在server.cpp文件中，构造函数(地图发布器赋值，服务器赋值)，回调函数（创建/发布地图），其中在基类里写强枚举类型，创建地图的具体实现在直道和弯道的.cpp文件中实现
3、