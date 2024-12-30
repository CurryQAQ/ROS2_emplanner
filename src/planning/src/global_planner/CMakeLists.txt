cmake_minimum_required(VERSION 3.22)
project(global_planner)

#设置添加依赖
set(DEPENDS
  "rclcpp"
  "geometry_msgs"
  "nav_msgs"
  "visualization_msgs"
  "base_msgs"
)


#添加动态库
add_library(global_planner SHARED
  ${CMAKE_CURRENT_SOURCE_DIR}/global_planner_normal/global_planner_normal.cpp
)

#添加节点/可执行文件
add_executable(global_path_server
  ${CMAKE_CURRENT_SOURCE_DIR}/global_path_server.cpp
)

set(PROJECT_TARGETS
  global_planner
  global_path_server
)

#循环添加依赖
foreach(target ${PROJECT_TARGETS})
  ament_target_dependencies(${target}
    ${DEPENDS}
  )
endforeach()

#安装动态库、节点/可执行文件
install(TARGETS
  global_planner
  LIBRARY DESTINATION lib)

install(TARGETS
  global_path_server
  DESTINATION lib/${PLANNING_PACKAGE_NAME}

)