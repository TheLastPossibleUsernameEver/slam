#!/usr/bin/env python

import rospy
import sys
from slam.msg import PointNamed
import random

def runner():
    pub = rospy.Publisher('runner_position', PointNamed, queue_size=10)
    rospy.init_node('runner', anonymous=True)

    rospy.loginfo("Node initializated")

    rate = rospy.Rate(10)

    runner_list = []

    runner_list_size = sys.argv[1]

    rospy.loginfo("static fields initialized")

    for i in range(int(runner_list_size)):
        msg_position = PointNamed()
        msg_position.runner_id = str(i)
        msg_position.position.x = 0.0
        msg_position.position.y = 0.0
        msg_position.position.z = 0.0

        runner_list.append(msg_position)

        rospy.loginfo("Instantiated runner: %f", i)

    while not rospy.is_shutdown():
        for runner_position in runner_list:
            runner_position.position.x = runner_position.position.x + random.uniform(-5.0, 5.0)
            runner_position.position.y = runner_position.position.y + random.uniform(-5.0, 5.0)
            runner_position.position.z = runner_position.position.z + random.uniform(-5.0, 5.0)

            pub.publish(runner_position)


if __name__ == '__main__':
    try:
        runner()
    except rospy.ROSInterruptException:
        pass
