## ROS image stitching
reference: https://github.com/sumitbinnani/ros-realtime-image-stitching <br>
<br>
T1: roscore <br>
T2: rosrun openCV_stitching webcam1_pub <br>
T3: rosrun openCV_stitching webcam2_pub <br>
T4: rosrun openCV_stitching webcam_stitching <br>
<br>
![webcam_stitching_rosgraph](https://user-images.githubusercontent.com/101806955/161366238-e377a466-e701-43c6-8e23-cf91af27353a.png)


## ERROR : opencv2/xfeatures2d.hpp: No such file or directory.

$ git clone -b 3.4.1 https://github.com/opencv/opencv.git <br>
$ git clone -b 3.4.1 https://github.com/opencv/opencv_contrib.git <br>
$ cd opencv <br>
$ mkdir build <br>
$ cd build <br>
$ cmake -D CMAKE_BUILD_TYPE=RELEASE -D OPENCV_ENABLE_NONFREE=ON -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules -D WITH_GTK=ON .. <br>
$ make <br>
$ sudo make install <br>
