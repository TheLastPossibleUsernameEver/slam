#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Point

def callback(position):
    rospy.loginfo("I heard x: %f, y: %f, z: %f", position.x, position.y, position.z)

def observer():

    rospy.init_node('observer', anonymous=True)
    rospy.Subscriber("runner_position", Point, callback)

    rospy.spin()

if __name__ == '__main__':
    observer()
