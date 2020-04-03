#include <geometry_msgs/PointStamped.h>
#include <ros/ros.h>

int main(int argc, char **argv) {

  ros::init(argc, argv, "runner");
  ros::NodeHandle n;

  ros::Publisher publisher =
      n.advertise<geometry_msgs::PointStamped>("runner_position", 1000);

  ros::Rate loop_rate(10);

  geometry_msgs::PointStamped position_msg;

  position_msg.point.x = 1.0;
  position_msg.point.y = 1.0;
  position_msg.point.z = 1.0;

  while (ros::ok()) {

    position_msg.header.stamp = ros::Time::now();
    position_msg.point.x = position_msg.point.x + 1;
    position_msg.point.y = position_msg.point.y + 1;
    position_msg.point.z = position_msg.point.z + 1;

    publisher.publish(position_msg);
  }

  return 0;
}