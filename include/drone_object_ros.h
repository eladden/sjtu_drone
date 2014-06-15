#ifndef ARDRONE_ROS_H
#define ARDRONE_ROS_H

#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/Bool.h>
#include <geometry_msgs/Twist.h>

class DroneObjectROS{
protected:
    DroneObjectROS(){}
public:
    
    DroneObjectROS(ros::NodeHandle& node){
        initROSVars(node);
    }

    bool isFlying;
    bool isPosctrl;
    
    ros::Publisher pubTakeOff;
    ros::Publisher pubLand;
    ros::Publisher pubReset;
    ros::Publisher pubCmd;
    ros::Publisher pubPosCtrl;
    
    geometry_msgs::Twist twist_msg;
    
    void initROSVars(ros::NodeHandle& node);
    
    bool takeOff();
    bool land();
    bool hover();
    bool posCtrl(bool on);
    
    // commands for controling ARDrone
    // pitch_lr = left-right tilt		(-1) to right		(+1)
    // roll_fb = front-back tilt 		(-1) to backwards	(+1)
    // v_du = velocity downwards	(-1) to upwards		(+1)
    // w_lr = angular velocity left (-1) to right		(+1)

    bool move(float v_lr, float v_fb, float v_du, float w_lr);
    bool moveTo(float x, float y, float z);
    bool pitch(float speed = 0.2);
    bool roll(float speed = 0.2);
    bool rise(float speed = 0.1);
    bool yaw(float speed = 0.1);
};

#endif // ARDRONE_ROS_H