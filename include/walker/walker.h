/************************************************************************************************
* @file      : Header file for Week 12 turtlebot walker exercise
* @author    : Arun Kumar Devarajulu
* @date      : November 19, 2018
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
* @brief     : The walker.h will be the header file for walker class which will handle the
*              movement of turtlebot in an unknown environment by responding to presence of
*              obstacles in the path
**************************************************************************************************/
#pragma once
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/LaserScan.h"

/**
* @brief : Class declaration for Walker class
*/
class Walker {
 public:
    /**
    *@brief  : Callback function for minimum range subscriber
    *@param  : Messages received from laser scan topic
    *@return : None
    */
    void rangeCallback(const sensor_msgs::LaserScan::ConstPtr& scanInfo);

    /*
    *@brief  : Method for finding the obstacle distance
    *@return : ObstacleRange
    */
    float findObstacleRange();
 private:
    float ObstacleRange;  //< Variable to store obstacle range
};

