# Hbut_LC_sentry
湖北工业大学力创RM关于哨兵的工作开源
- 2月7日新增：初步适配官方开源
(所有RMUS均为RMUC，打错了没有修改)
## 开源1（见文件夹23对抗赛场地）
- 对2023RMUC地图solidworks文件进行开源，该项工作由湖北工业大学力创RM战队机械组**陈思强、侯宇飞**共同完成。(solidworks为2022sp5)
- 该项工作趋于完善，目标主要是为了在仿真中实现Lidar-SLAM和Lidar定位导航
- 该项工作还剩下的主要任务是前哨站没有进行建模
- 为了保证后续在仿真中不卡，秉持着保证最明显特征的原则，并没有作图出红蓝装饰带、视觉定位标签。请后面的贡献者务必遵守这条要求，尽可能的避免非必要特征。
## 开源2
- 使用2023RMUC地图，利用solidworks开源插件[SolidWorks to URDF Exporter](https://github.com/ros/solidworks_urdf_exporter.git)获得和ros兼容的包，包括了stl文件以及urdf文件。
**见RMUS_map_ws**
- 通过Gazebo导入stl文件，获得world文件。
**见rmus_map_gazebo**
## 开源3
- 使用前述的stl文件和urdf文件，利用urdf2webots插件，获得proto文件。
- 一并开源简化的麦轮底盘，麦轮的配置完善，并附带了c的控制脚本。（webots为R2020a）
**见webots**
## ===========2023年2月7日============

对于官方开源的仿真器，可以使用本开源的地图（rmus_map_gazebo/world/2023_v_4_1.world）,使用方法为：

1. 下载本开源文件，尝试编译运行rmus_map_gazebo/launch/gazebo_show.launch。
2. 将本开源文件的rmus_map_gazebo/world/2023_v_4_1.world复制到修改官方开源文件夹${workspace}/src/vechicle_simulator/world下
3. 修改livox_rm.launch文件中四个参数

    name="world_name" default="2023_v_4_1"
    
    name="vehicleX" default="7.5"
    
    name="vehicleY" default="4"
    
    name="terrainZ" default="0.1"
    
(Tips
  1. 官方文件livox_rm.launch中包含了实地建图得来的点云downsampled_rm_pt.pcd文件:
  
    <include file="$(find visualization_tools)/launch/visualization_tools.launch" >
      <arg name="world_name" value="$(arg world_name)"/>
    </include>
    也就是rviz中看到的彩色点云
  2. 官方仿真有问题，小车在gazebo中是上不了坡的，这个大家仔细观察

)

## TODO
1. 获得带有表面特征的地图的dae文件，包括定位标签等特征。
2. 完善在webots中的仿真环境搭建
