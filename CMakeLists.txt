cmake_minimum_required(VERSION 2.8.3)
project(slam)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  geometry_msgs
  message_generation
)

################################################
## Declare ROS messages, services and actions ##
################################################

## Generate messages in the 'msg' folder
add_message_files(
   FILES
   PointNamed.msg
#   Message2.msg
 )

## Generate added messages and services with any dependencies listed here
generate_messages(
   DEPENDENCIES
   geometry_msgs  # Or other packages containing msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES slam
#  CATKIN_DEPENDS roscpp rospy tf2 tf2_ros turtlesim
  DEPENDS message_runtime
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(task2_runner src/task_2/runner.cpp)
target_link_libraries(task2_runner
        ${catkin_LIBRARIES}
        )
add_executable(task2_observer src/task_2/observer.cpp)
target_link_libraries(task2_observer
        ${catkin_LIBRARIES}
        )
add_executable(task3_runner src/task_3/runner.cpp)
target_link_libraries(task3_runner
	${catkin_LIBRARIES}
	)
add_executable(task3_observer src/task_3/observer.cpp)
target_link_libraries(task3_observer
	${catkin_LIBRARIES}
	)

