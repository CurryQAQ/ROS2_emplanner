cmake_minimum_required(VERSION 3.22)
project(vehicle_info)

#设置添加依赖
set(DEPENDS
  "rclcpp"
  "geometry_msgs"
  "visualization_msgs"
  "base_msgs"
)


#添加动态库
add_library(vehicle_info SHARED
  ${CMAKE_CURRENT_SOURCE_DIR}/main_car/main_car.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/obs_car/obs_car.cpp
)
set(target
  vehicle_info
)
#添加依赖
ament_target_dependencies(${target}
  ${DEPENDS}
)
#添加第三库
target_link_libraries(${target}
  config_reader
  mathlibs
)
#安装动态库
install(TARGETS
  vehicle_info
  LIBRARY DESTINATION lib
)
