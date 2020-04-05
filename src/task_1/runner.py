#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Point

def runner():
    pub = rospy.Publisher('runner_position', Point, queue_size = 10)
    rospy.init_node('runner', anonymous=True)
    rate = rospy.Rate(10)

    position = Point()

    position.x = 1.0;
    position.y = 1.0;
    position.z = 1.0;

    while not rospy.is_shutdown():
        pub.publish(position)
        position.x = position.x + 1
        position.y = position.y + 1
        position.z = position.z + 1
        rate.sleep()


if __name__ == '__main__':
    try:
        runner()
    except rospy.ROSInterruptException:    
        pass
