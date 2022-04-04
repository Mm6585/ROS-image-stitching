#include <ros/ros.h>
#include "openCV_stitching/image_stitcher.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ImageStitcher", ros::init_options::AnonymousName);
  
  ros::NodeHandle nh_("~");

  while(true) {
  	ImageStitcher ic("camera1/image", "camera2/image", 10, true);
  	// pub = "/stitched_images/output"
  	ros::spinOnce();
  }
}
