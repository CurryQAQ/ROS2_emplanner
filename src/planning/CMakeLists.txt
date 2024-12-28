cmake_minimum_required(VERSION 3.22)
project(planning)

#设置C和C++格式
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

#在新版Cmake中已经废弃了，改用CMAKE_CXX_COMPILER_ID
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

#兼容旧版本的cmake
if(POLICY_CMP0148)
  cmake_policy(SET CMP0148 OLD)
endif()

#设置预编译命令，生成compile_commands.json
#然后让c_cpp_properties.json读取这个文件，防止预编译找不到cmake中定义的宏而报错
#c_cpp_properties.json中加上"compileCommands“：”${workspaceFolder}/build/compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#设置包名，让子目录节点安装时使用
set(PLANNING_PACKAGE_NAME ${PROJECT_NAME})

# 包含头文件的目录

include_directories(
  /usr/local/include/eigen
  src/common/config_reader
  src/common/math
  src/decision_center
  src/global_planner
  src/global_planner/global_planner_normal
  src/local_planner
  src/local_planner/local_path
  src/local_planner/local_speeds
  src/move_cmd
  src/planning_process
  src/pnc_map_creator
  src/pnc_map_creator/pnc_map_straight
  src/pnc_map_creator/pnc_map_sturn
  src/reference_line
  src/vehicle_info
  src/vehicle_info/main_car
  src/vehicle_info/obs_car
)


# 查找依赖
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(base_msgs REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(ament_index_cpp REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(OsqpEigen REQUIRED)

# 添加子目录，找子目录里面的cmakelist
add_subdirectory(src/common)
add_subdirectory(src/decision_center)
add_subdirectory(src/global_planner)
add_subdirectory(src/local_planner)
add_subdirectory(src/move_cmd)
add_subdirectory(src/planning_process)
add_subdirectory(src/pnc_map_creator)
add_subdirectory(src/reference_line)
add_subdirectory(src/vehicle_info)


# 安装辅助目录
install(DIRECTORY config launch rviz urdf
  DESTINATION share/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
