#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int gaussianFilter(int path)
{
    VideoCapture cap("./out.avi");
    if (cap.isOpened() == false)
    {
        cout << "Cannot open the video file" << endl;
        cin.get();
        return -1;
    }



    String window_name_of_original_video = "Original Video";
    String window_name_of_video_blurred_with_5x5_kernel = "Video Blurred with 5 x 5 Gaussian Kernel";

    namedWindow(window_name_of_original_video, WINDOW_NORMAL);
    namedWindow(window_name_of_video_blurred_with_5x5_kernel, WINDOW_NORMAL);



    Size S = Size((int) cap.get(CAP_PROP_FRAME_WIDTH),  
                  (int) cap.get(CAP_PROP_FRAME_HEIGHT));
    VideoWriter video("outcpp.avi",CV_FOURCC('M','J','P','G'),25, S);




    while (true)
    {
        Mat frame;
        bool bSuccess = cap.read(frame);
        if (bSuccess == false)
        {
            cout << "Found the end of the video" << endl;
            break;
        }

        Mat frame_blurred_with_5x5_kernel;
        GaussianBlur(frame, frame_blurred_with_5x5_kernel, Size(5, 5), 0);

        video.write(frame_blurred_with_5x5_kernel);
        imshow(window_name_of_original_video, frame);
        imshow(window_name_of_video_blurred_with_5x5_kernel, frame_blurred_with_5x5_kernel);

        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }

    return 0;
}