#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <image_transport/image_transport.h>
#include <sstream>
#include <ros/ros.h>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "webcam2_pub");
    
    ros::NodeHandle nh;
    image_transport::ImageTransport it(nh);
    image_transport::Publisher pub = it.advertise("camera2/image", 1);

    cv::VideoCapture cap(2);
    cv::Mat frame;
    sensor_msgs::ImagePtr msg;
    
    ros::Rate loop_rate(1);
    while(nh.ok())
    {
        cap >> frame;

        if(!frame.empty())
        {
	    cv::imshow("webcam2", frame);
	    msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toImageMsg();
	    pub.publish(msg);
	    cv::waitKey(1);
        }

        ros::spinOnce();
	//loop_rate.sleep();
    }

    return 0;
    
}
