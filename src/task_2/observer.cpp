#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

#include <geometry_msgs/PointStamped.h>

class ProxyNode {
public:
  ProxyNode() {
    sub = n.subscribe("runner_position", 10, &ProxyNode::proxyCallback, this);

    pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 10);

    initPoints();
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

  void proxyCallback(const geometry_msgs::Point &runner_position) {

    points.header.stamp = ros::Time::now();

    points.points.push_back(runner_position);

    pub.publish(points);

    ROS_INFO("Published: %f, %f", runner_position.x, runner_position.y);
  }

private:
  ros::NodeHandle n;
  ros::Publisher pub;
  ros::Subscriber sub;

  visualization_msgs::Marker points;
};

int main(int argc, char **argv) {

  ros::init(argc, argv, "proxy_node");
  ProxyNode proxyNode;

  ros::spin();
}
