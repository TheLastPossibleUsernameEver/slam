#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

#include <geometry_msgs/Point.h>

class ProxyNode {
public:
  ProxyNode() {
    sub = n.subscribe("runner_position", 10, &ProxyNode::proxyCallback, this);

    pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 10);

    initPoints();

    smoothed_position.x = 1.0;
    smoothed_position.y = 0.0;
  }

  void initPoints() {
    points.id = 1;
    points.ns = "runner";
    points.header.frame_id = "runner_frame";
    points.action = visualization_msgs::Marker::ADD;
    points.type = visualization_msgs::Marker::POINTS;

    points.scale.x = 1;
    points.scale.y = 1;

    points.color.r = 1.0;
    points.color.a = 1.0;

    points.ns = "position";
  }

  void proxyCallback(const geometry_msgs::Point &current_position) {

    points.header.stamp = ros::Time::now();

    // Here we assign the new position the mean of the previous smoothed
    // position and current runner's position
    smoothed_position.x = (smoothed_position.x + current_position.x) / 2;
    smoothed_position.y = (smoothed_position.y + current_position.y) / 2;

    points.points.push_back(smoothed_position);

    if (smoothed_position.x > 0.95 && smoothed_position.x < 1.05) {
      pub.publish(points);
      ROS_INFO("Published: %f, %f", smoothed_position.x, smoothed_position.y);
    }

  }

private:
  ros::NodeHandle n;
  ros::Publisher pub;
  ros::Subscriber sub;

  visualization_msgs::Marker points;
  geometry_msgs::Point smoothed_position;
};

int main(int argc, char **argv) {

  ros::init(argc, argv, "proxy_node");
  ProxyNode proxyNode;

  ros::spin();
}
