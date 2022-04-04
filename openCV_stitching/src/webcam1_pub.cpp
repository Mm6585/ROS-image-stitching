#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <image_transport/image_transport.h>
#include <sstream>
#include <ros/ros.h>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "webcam1_pub");
    
    ros::NodeHandle nh;
    image_transport::ImageTransport it(nh);
    image_transport::Publisher pub = it.advertise("camera1/image", 1);

    cv::VideoCapture cap(0);
    cv::Mat frame;
    sensor_msgs::ImagePtr msg;
    
    ros::Rate loop_rate(5);
    while(nh.ok())
    {
        cap >> frame;

        if(!frame.empty())
        {
	    cv::imshow("webcam1", frame);
	    msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toImageMsg();
	    pub.publish(msg);
	    cv::waitKey(1);
        }

        ros::spinOnce();
	loop_rate.sleep();
    }

    return 0;
    
}
