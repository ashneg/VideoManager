#include <iostream> 
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int convertToRed(string path,char color,string outputVideoName,int pth,string loggedUserDir)
{
    VideoCapture inputVideo(path);
    if (!inputVideo.isOpened())
    {
        cout  << "Could not open the input video: " << path << endl;
        return -1;
    }
    const string NAME = outputVideoName + ".avi";   
    int ex = static_cast<int>(inputVideo.get(CAP_PROP_FOURCC));
    char EXT[] = {(char)(ex & 0XFF) , (char)((ex & 0XFF00) >> 8),(char)((ex & 0XFF0000) >> 16),(char)((ex & 0XFF000000) >> 24), 0};
    Size S = Size((int) inputVideo.get(CAP_PROP_FRAME_WIDTH),  
                  (int) inputVideo.get(CAP_PROP_FRAME_HEIGHT));
    VideoWriter outputVideo;
    outputVideo.open(NAME, ex, inputVideo.get(CAP_PROP_FPS), S, true);
    if (!outputVideo.isOpened())
    {
        cout  << "Could not open the output video for write: " << path << endl;
        return -1;
    }
    int channel = 2;
    Mat src, res;
    vector<Mat> spl;
    while(1){
        inputVideo >> src;             
        if (src.empty()) break;        
        split(src, spl);               
        for (int i =0; i < 3; ++i)
            if (i != channel)
                spl[i] = Mat::zeros(S, spl[0].type());
       merge(spl, res);
       outputVideo << res;
    }
    if(pth == 3)system(("mv "+outputVideoName+".avi "+loggedUserDir).c_str());
    return 0;
}
