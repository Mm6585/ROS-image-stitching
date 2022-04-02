cmake_minimum_required(VERSION 2.8.3)
project(openCV_stitching)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  sensor_msgs
  std_msgs
)

find_package (OpenCV 3 REQUIRED)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES openCV_stitching
#  CATKIN_DEPENDS cv_bridge image_transport roscpp sensor_msgs std_msgs
# DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(webcam1_pub src/webcam1_pub.cpp)
target_link_libraries(webcam1_pub ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

add_executable(webcam2_pub src/webcam2_pub.cpp)
target_link_libraries(webcam2_pub ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

add_executable(webcam_stitching src/webcam_stitching.cpp)
target_link_libraries(webcam_stitching ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

