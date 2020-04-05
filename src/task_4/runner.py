#!/usr/bin/env python

import rospy
from slam.msg import PointNamed

def runner():
    pub = rospy.Publisher('runner_position', PointNamed, queue_size=10)
    rospy.init_node('runner', anonymous=True)
    rate = rospy.Rate(10)

    runner_list = []

    for i in range(sys.argv[0]):
        msg_position = PointNamed()
        msg_position.runner_id = i
        msg_position.point.x = 0.0
        msg_position.point.y = 0.0
        msg_position.point.z = 0.0

        runner_list[i] = msg_position

    while not rospy.is_shutdown():
        for runner_position in runner_list:
            runner_position.point.x = runner_position.point.x + random.uniform(-5.0, 5.0)
            runner_position.point.y = runner_position.point.y + random.uniform(-5.0, 5.0)
            runner_position.point.z = runner_position.point.z + random.uniform(-5.0, 5.0)

            pub.publish(runner_position)



if __name__ == '__main__':
    try:
        runner()
    except rospy.ROSInterruptException:
        pass
