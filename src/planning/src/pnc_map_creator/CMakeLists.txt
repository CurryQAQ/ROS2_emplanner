cmake_minimum_required(VERSION 3.22)
project(pnc_map_creator)

#设置添加依赖
set(DEPENDS
  "rclcpp"
  "geometry_msgs"
  "visualization_msgs"
  "base_msgs"
)

#添加动态库
add_library(pnc_map SHARED
  ${CMAKE_CURRENT_SOURCE_DIR}/pnc_map_straight/pnc_map_straight.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/pnc_map_sturn/pnc_map_sturn.cpp
)
set(LIB_TARGETS
  pnc_map
)
#添加节点/可执行文件
add_executable(pnc_map_server
  ${CMAKE_CURRENT_SOURCE_DIR}/pnc_map_server.cpp
)
set(NODE_TARGETS
  pnc_map_server
)
set(PROJECT_TARGETS
  ${LIB_TARGETS}
  ${NODE_TARGETS}
)
#绑定依赖
foreach(target ${PROJECT_TARGETS})
  ament_target_dependencies(${target}
    ${DEPENDS}
  )  
endforeach()

#绑定第三方库
target_link_libraries(${NODE_TARGETS}
  config_reader
  ${LIB_TARGETS}
)
#安装动态库、节点、相关目录
install(TARGETS
  pnc_map
  LIBRARY DESTINATION lib
)
install(TARGETS
  pnc_map_server
  DESTINATION lib/${PLANNING_PACKAGE_NAME}
)