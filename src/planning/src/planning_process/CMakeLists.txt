cmake_minimum_required(VERSION 3.22)
project(planning_process)

#设置添加依赖
set(DEPENDS
  "rclcpp"
  "nav_msgs"
  "base_msgs"
  "tf2"
  "tf2_ros"
)


# 添加节点/可执行文件
add_executable(planning_node
  ${CMAKE_CURRENT_SOURCE_DIR}/planning_node.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/planning_process.cpp

)

set(target
  planning_node
)

# 绑定依赖
ament_target_dependencies(${target}
  ${DEPENDS}
)

target_link_libraries(${target}
  config_reader
  decision_center
  reference_line
  local_planner
  vehicle_info
)


#添加依赖

#安装节点/可执行文件
install(TARGETS
  ${target}
  DESTINATION lib/${PLANNING_PACKAGE_NAME}
)