cmake_minimum_required(VERSION 3.22)
project(common)

#设置添加依赖
set(CONFIG_DEPENDS
  "rclcpp"
  "yaml-cpp"
  "ament_index_cpp"
)
set(MATH_DEPENDS
  "rclcpp"
  "base_msgs"
  "geometry_msgs"
  "nav_msgs"
)

#添加动态库

#安装动态库、节点、相关目录
