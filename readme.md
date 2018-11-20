# Walker
This is the Week 12 exercise related to simulation of a simple walker algorithm for turtlebot in gazebo world.

## Overview
The operation principle of the turtlebot walker is as follows. The turtlebot keeps moving in a forward direction until its laser scan identifies an obstacle in a threshold range. When the obstacle is detected it makes a turning manuevre at constant velocity to evade the obstacle. Once the obstacle is evaded, it proceeds to move again in the forward direction. This cycle repeats indefinitely.

## License
This software is released under the MIT License. For details check [License information](/LICENSE)

## Assumptions
This project assumes the following: 

 - the user has ROS Version Kinetic Installed on an Ubuntu desktop/ laptop
 - the user has CMake installed on the same desktop/ laptop
 - the user has C++ 11 compatible GCC compiler installed on the same desktop/ laptop
 - the user also has the tf library as part of their ROS distribution

If your computer does not already have a turtlebot stack installation, do the following.
In a new terminal
```
sudo apt-get install ros-kinetic-turtlebot-gazebo ros-kinetic-turtlebot-apps ros-kinetic-turtlebot-rviz-launchers
source /opt/ros/kinetic/setup.bash
```

## Standard install via command-line

**Cloning the repository and integrating in your workspace**

```
mkdir catkin_ws
cd catkin_ws
mkdir src
catkin_make
cd src
git clone https://github.com/arunumd/walker.git
cd..
catkin_make
```

**Running the simulation WITHOUT bag file recording using the launch file**

In a new terminal
```
cd ~/catkin_ws
source ./devel/setup.bash
roslaunch walker walker.launch
```

**Running the simulation WITH bag file recording using the launch file**

In a new terminal
```
cd ~/catkin_ws
source ./devel/setup.bash
roslaunch walker walker.launch rec:=1
```
After this step, you will find a bag file in /results folder

**Playing the bag file**

In a new terminal
```
roscore
```

In a new terminal
```
cd ~/catkin_ws
source ./devel/setup.bash
cd src/walker/results
rosbag play recording.bag
```
