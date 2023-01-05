# Hbut_LC_sentry
湖北工业大学力创RM关于哨兵的工作开源
## 开源1（见文件夹23对抗赛场地）
- 对2023RMUS地图solidworks文件进行开源，该项工作由湖北工业大学力创RM战队机械组**陈sq、侯yf**共同完成。
- 该项工作趋于完善，目标主要是为了在仿真中实现Lidar-SLAM和Lidar定位导航
- 该项工作还剩下的主要任务是前哨站没有进行建模
- 为了保证后续在仿真中不卡，秉持着保证最明显特征的原则，并没有作图出红蓝装饰带、视觉定位标签。请后面的贡献者务必遵守这条要求，尽可能的避免非必要特征。
## 开源2
- 使用2023RMUS地图，利用solidworks开源插件[SolidWorks to URDF Exporter](https://github.com/ros/solidworks_urdf_exporter.git)获得和ros兼容的包，包括了stl文件以及urdf文件。
- 通过Gazebo导入stl文件，获得world文件。
## 开源3
- 使用前述的stl文件和urdf文件，利用urdf2webots插件，获得proto文件。

## TODO
1. 获得带有表面特征的地图的dae文件，包括定位标签等特征。
2. 完善在webots中的仿真环境搭建
