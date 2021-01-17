#include "opencv2/opencv.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace cv;

int videoSaver(int path, string loggedUserDir){
	int duration;
	cout<<"Enter the duration of video\n";
	cin>>duration;
    VideoCapture vcap(0); 
      if(!vcap.isOpened()){
             cout << "Error opening video stream or file" << endl;
             return -1;
      }

   int frame_width=   vcap.get(CV_CAP_PROP_FRAME_WIDTH);
   int frame_height=   vcap.get(CV_CAP_PROP_FRAME_HEIGHT);
   VideoWriter video("out.avi",CV_FOURCC('M','J','P','G'),25, Size(frame_width,frame_height),true);
   int counter = duration*26.5; //fps of camera*time
   while (counter){
    	Mat frame;
    	counter--;
    	vcap >> frame;
        video.write(frame);
        imshow( "Frame", frame );
        char c = (char)waitKey(33);
    }
    if(path == 2) system(("mv out.avi "+loggedUserDir).c_str());
    cout << "\nSuccessful\n";
  return 0;
}