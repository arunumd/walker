/************************************************************************************************
* @file      : main file for Week 12 turtlebot walker exercise
* @author    : Arun Kumar Devarajulu
* @date      : November 20, 2018
* @copyright : 2018, Arun Kumar Devarajulu
* @license   : MIT License
*
*              Permission is hereby granted, free of charge, to any person obtaining a copy
*              of this software and associated documentation files (the "Software"), to deal
*              in the Software without restriction, including without limitation the rights
*              to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*              copies of the Software, and to permit persons to whom the Software is
*              furnished to do so, subject to the following conditions:
*
*              The above copyright notice and this permission notice shall be included in all
*              copies or substantial portions of the Software.
*
*              THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*              IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*              FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*              AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*              LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*              OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*              SOFTWARE.
*
* @brief     : The main.cpp contains the implementation walker node and laser scan subscription
**************************************************************************************************/
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/LaserScan.h"
#include "geometry_msgs/Twist.h"
#include "walker/walker.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "walker");
    ros::NodeHandle n;
    ros::Duration(5).sleep();
    Walker turtle;
    ros::Subscriber scanData;
    ros::Publisher pub;
    geometry_msgs::Twist msg;
    // Subscribe to the laser scan topic using our callback function
    scanData = n.subscribe("/scan", 1000, &Walker::rangeCallback, &turtle);
    pub = n.advertise < geometry_msgs::Twist
          > ("/mobile_base/commands/velocity", 100);
    ros::Rate loop_rate(2);
    while (n.ok()) {
        // Initially all the linear and angular velocities are set as zero
        msg.angular.x = 0.0;
        msg.linear.x = 0.0;
        msg.angular.y = 0.0;
        msg.linear.y = 0.0;
        msg.angular.z = 0.0;
        msg.linear.z = 0.0;
        if (turtle.findObstacleRange() > .9) {
            // When there is no obstacle, we move forward
            msg.linear.x = 0.15;
            ROS_INFO_STREAM("Heading in forward direction");
        } else {
            // When we encounter an obstacle, we make a manuevre
            msg.angular.z = -0.5;
            ROS_WARN_STREAM("Obstacle found ahead."
                            " Making an avoidance manuevre");
        }
        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
}
