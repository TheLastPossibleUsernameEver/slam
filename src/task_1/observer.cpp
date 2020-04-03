#include <geometry_msgs/PointStamped.h>
#include <ros/ros.h>

void poseCallback(const geometry_msgs::PointStamped &msg) {

  ROS_INFO("Point coords are: x:%f y:%f z:%f\n", msg.point.x, msg.point.y,
           msg.point.z);
}

int main(int argc, char **argv) {

  ros::init(argc, argv, "observer");
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("runner_position", 1000, poseCallback);

  ros::spin();

  return 0;
}
