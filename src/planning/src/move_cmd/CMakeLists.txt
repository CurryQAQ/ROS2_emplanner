cmake_minimum_required(VERSION 3.22)
project(move_cmd)

#设置添加依赖
set(DEPENDS
  "rclcpp"
  "geometry_msgs"
  "base_msgs"
  "tf2"
  "tf2_ros"
)

#添加节点/可执行文件
add_executable(car_move_cmd
  ${CMAKE_CURRENT_SOURCE_DIR}/car_move_cmd.cpp
)

add_executable(obs_move_cmd
  ${CMAKE_CURRENT_SOURCE_DIR}/obs_move_cmd.cpp
)

set(MOVE_TARGETS
  car_move_cmd
  obs_move_cmd
)

#循环添加依赖
foreach(target ${MOVE_TARGETS})
  ament_target_dependencies(${target}
    ${DEPENDS}
  )
  target_link_libraries(${target}
    config_reader
    vehicle_info
  )
endforeach()


#安装节点/可执行文件
install(TARGETS
  ${MOVE_TARGETS}
  DESTINATION lib/${PLANNING_PACKAGE_NAME}
)
