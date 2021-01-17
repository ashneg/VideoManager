#include "opencv2/opencv.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace cv;

int main(){
    int time = 30; //respective to frame rate
    int timer = clock();
    VideoCapture vcap(0); 
      if(!vcap.isOpened()){
             cout << "Error opening video stream or file" << endl;
             return -1;
      }

   int frame_width=   vcap.get(CV_CAP_PROP_FRAME_WIDTH);
   int frame_height=   vcap.get(CV_CAP_PROP_FRAME_HEIGHT);
   VideoWriter video("out.avi",CV_FOURCC('M','J','P','G'),25, Size(frame_width,frame_height),true);

   while ( (timer / 100000) < time) // while prog reaches inputted time
    {
    timer = clock();
       Mat frame;
       vcap >> frame;
       video.write(frame);
       imshow( "Frame", frame );
       char c = (char)waitKey(33);
       // if( c == 27 ) break;
    }
    cout << "Completed in " << time << " seconds" << endl;//completed message
  return 0;
}
