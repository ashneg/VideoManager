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

// #include <cstdlib>
// #include <iostream>

// #include <ctime> // time header

// using namespace std;

// int main()
// {
//     cout << "Please enter time in seconds: "; //user prompt
//     int input; //int for time input
//     cin >> input; //writes time into input var
//     int timer = clock();
//     while ( (timer / 100000) < input) // while prog reaches inputted time
//     {
//     system("cls"); // Clear All of the text
//     timer = clock();  // Update the timer var
//     cout << "Seconds since started: " << timer / 1000 << endl; // Print the time since the program started in seconds
//     }
//     cout << "Completed in " << input << " seconds" << endl;//completed message
//     system("pause");
//     return 0;
// }