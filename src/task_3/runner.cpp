#include <geometry_msgs/Point.h>
#include <ros/ros.h>

#include <cmath>
#include <random>

int main(int argc, char **argv) {

  ros::init(argc, argv, "runner");
  ros::NodeHandle n;

  ros::Publisher publisher =
      n.advertise<geometry_msgs::Point>("runner_position", 1000);

  ros::Rate loop_rate(1);

  geometry_msgs::Point position_msg;

  double angle_radians = 0.0;

  double lower_bound = 0.95;
  double upper_bound = 1.05;

  std::uniform_real_distribution<double> uniform(lower_bound, upper_bound);
  std::default_random_engine re;

  while (ros::ok()) {

    position_msg.x = sin(angle_radians) * uniform(re);
    position_msg.y = cos(angle_radians) * uniform(re);

    publisher.publish(position_msg);

    ROS_INFO("x and y are: %f, %f", position_msg.x, position_msg.y);

    /*Here we increment angle by 4 degrees so observer can affirm "trajectory
     * loop closing" fact exactly once */

    angle_radians += 0.0698123;
  }
}
