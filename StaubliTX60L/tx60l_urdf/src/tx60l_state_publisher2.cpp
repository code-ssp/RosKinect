#include <string>
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "state_publisher");
    ros::NodeHandle n;
    ros::Publisher joint_pub = n.advertise<sensor_msgs::JointState>("joint_states_node", 1);
    ros::Rate loop_rate(30);

    const double degree = M_PI/180;
    

    // robot state
    double angle_a1=0 , angle_a2=0, angle_a3=0 , angle_a4=0 , angle_a5=0 , angle_a6=0 , d_a1=degree, d_a2=degree, d_a3=degree, d_a4=degree , d_a5=degree, d_a6=degree;

    //give rviz time to start up
    sleep(20.0);
    // message declarations
    sensor_msgs::JointState joint_state;

    while (ros::ok()) {
        //update joint_state
        joint_state.header.stamp = ros::Time::now();
        joint_state.name.resize(6);
        joint_state.position.resize(6);
        joint_state.name[0] ="a1";
        joint_state.position[0] = angle_a1;
        joint_state.name[1] ="a2";
        joint_state.position[1] = angle_a2;
        joint_state.name[2] ="a3";
        joint_state.position[2] = angle_a3;
        joint_state.name[3] ="a4";
        joint_state.position[3] = angle_a4;
        joint_state.name[4] ="a5";
        joint_state.position[4] = angle_a5;
        joint_state.name[5] ="a6";
        joint_state.position[5] = angle_a6;

        //send the joint state and transform
        joint_pub.publish(joint_state);

        // Create new robot state
        angle_a1 += d_a1;
        if (angle_a1<-1 || angle_a1>1) d_a1 *= -1;
        angle_a2 += d_a2;
        if (angle_a2<-2 || angle_a2>2) d_a2 *= -1;
        angle_a3 += d_a3;
        if (angle_a3<-5 || angle_a1>5) d_a3 *= -1;
        angle_a4 += d_a4;
        if (angle_a4<-4 || angle_a4>4) d_a4 *= -1;
        angle_a5 += d_a5;
        if (angle_a5<-1 || angle_a5>1) d_a5 *= -1;
        angle_a6 += d_a6;
        if (angle_a6<-4 || angle_a6>4) d_a6 *= -1;

        // This will adjust as needed per iteration
        loop_rate.sleep();
    }


    return 0;
}
