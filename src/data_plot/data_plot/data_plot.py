import rclpy
from rclpy.node import Node
import numpy as np
import matplotlib.pyplot as plt

class PlotData(Node):
    def __init__(self):
        super().__init__("data_plot_node")
        self.get_logger().info("data_plot_node created")#ROS2自带的打印


def main():
    rclpy.init()
    plot_node = PlotData()
    #按ctrl可以关掉节点
    try:
        rclpy.spin(plot_node)
    except KeyboardInterrupt:
        print("Interrupted by user")
    finally:
        rclpy.shutdown() #防止按ctrl+c无法推出0



if __name__ == '__main__':
    main()