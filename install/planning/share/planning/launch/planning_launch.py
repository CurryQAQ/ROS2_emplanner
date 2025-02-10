from launch import LaunchDescription
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from launch.substitutions import Command
from launch.actions import GroupAction
from launch_ros.actions import PushRosNamespace
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    # 路径设置，获取planning目录的位置
    # workspace/install/planning/share/planning
    
    planning_path = get_package_share_directory("planning")
    
    # 主车模型的位置
    car_path = os.path.join(planning_path,"urdf/main_car","car.xacro")

    #xacro命令行指令，封装成参数，用于启动urdf文件,注意空格
    car_para = ParameterValue(Command(["xacro ", car_path]))
    
    #启动robot_state_publisher节点，以参数的方式加载urdf文件
    car_state_pub = Node(
        package = "robot_state_publisher",
        executable = "robot_state_publisher",
        name = "car_state_pub",
        output = "screen",
        parameters=[{"robot_description":car_para}]
    )

    #启动joint_state_publisher节点
    #手动控制关节运动
    car_joint_state_pub_gui = Node(
        package = "joint_state_publisher_gui",
        executable = "joint_state_publisher_gui",
        name = "car_joint_state_pub",
    )

    #启动rviz节点,加载配置文件
    rviz2 = Node(
        package = "rviz2",
        executable = "rviz2",   
    )

    #启动绘图的节点

    #启动地图服务器的节点
    pnc_map_server = Node(
        package = "planning",
        executable="pnc_map_server",
        name="pnc_map_server",
    )
    #启动全局路径服务器的节点
    global_path_server = Node(
        package="planning",
        executable="global_path_server",
        name="global_path_server",
    )
    #启动规划节点
    planning_node = Node(
        package = "planning",
        executable = "planning_node",
        name = "planning_node",
    )

    #节点分组
    car_main = GroupAction(
        actions = [
            PushRosNamespace("car"), #命名空间，可防止重名
            car_state_pub,
            car_joint_state_pub_gui,
    ])

    planning = GroupAction(
        actions = [
            PushRosNamespace("planning"), #命名空间，可防止重名
            planning_node,
            pnc_map_server,
            global_path_server,
        ]
    )
    return LaunchDescription(
        [car_main,
        rviz2,
        planning,]
    )