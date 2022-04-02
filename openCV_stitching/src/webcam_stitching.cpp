#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <vector>
#include <std_msgs/UInt8MultiArray.h>
#include "openCV_stitching/image_stitcher.h"

void connectCallback(const std_msgs::UInt8MultiArray::ConstPtr& array) {
	ROS_INFO("connecting");
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "webcam_stitching");

  ros::NodeHandle nh;

  ImageStitcher ic("camera1/image", "camera2/image", 10, true);
  // pub = "/stitched_images/output"

  ros::spin();
}
