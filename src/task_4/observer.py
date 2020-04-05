#!/usr/bin/env python

import rospy
from slam.msg import PointNamed

def callback(runner_message):
    rospy.loginfo("Runner's name is: %s, x: %f, y: %f, z: %f", 
            runner_message.runner_id, 
            runner_message.position.x, 
            runner_message.position.y, 
            runner_message.position.z)
            
def observer():
    rospy.init_node('observer', anonymous=True)
    rospy.Subscriber("runner_position", PointNamed, callback)

    rospy.spin()

if __name__ == '__main__':
    observer()
