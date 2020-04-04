#include <geometry_msgs/Point.h>
#include <ros/ros.h>

#include <cmath>

int main(int argc, char **argv) {

  ros::init(argc, argv, "runner");
  ros::NodeHandle n;

  ros::Publisher publisher =
      n.advertise<geometry_msgs::Point>("runner_position", 1000);

  ros::Rate loop_rate(1);

  geometry_msgs::Point position_msg;

  double angle_radians = 0.0;

  while (ros::ok()) {

    position_msg.x = sin(angle_radians);
    position_msg.y = cos(angle_radians);

    publisher.publish(position_msg);

    ROS_INFO("x and y are: %f, %f", position_msg.x, position_msg.y);

    angle_radians = angle_radians + 0.1;
  }
}
