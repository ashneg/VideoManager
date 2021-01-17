#include "convertToRed.h"
#include "videoSavingModule.h"
#include "gaussianFilter.h"


class userFunctionalities{
	public:
		int userFunctionalitiesChoice;
		bool argsSet = false;
		string videoLocation = "./out.avi",outVideoName;
		char videoColor = 'R';
		userFunctionalities(){
			cout<<"Press 1 to display all your current video"<<endl;
			cout<<"Press 2 to record video"<<endl;
			cout<<"Press 3 to convert an exesting vido to it's red channel"<<endl;
			cout<<"Press 4 to apply gaussian filter to an exesting video"<<endl;
			cout<<"Press 5 to apply all 3  functionalities mentioned above"<<endl;
			cin>>userFunctionalitiesChoice;
		}

		//Takes video path
		void videoPath(){
			int inpt;
			string videoName = "";
			cout<<"Press 1 to give the path of video \n";
			cout<<"Press 2 if the video is in the video folder\n";
			cin>>inpt;
			switch(inpt){
				case 1: cin>>videoLocation;break;
				case 2: videoLocation = "./video/";
						cout<<"Enter video name: ";
						cin>>videoName;
						videoLocation.append(videoName);
						break;
				default: cout<<"Invalid please retry";
						videoPath();
			}
		}


		void getvideoName(){
			cout<<"Enter the output video name: ";
			cin>>outVideoName;
		}

		//gets arguments for video
		void convertToColorArgs(){
			videoPath();
			// getvideoColor();
			getvideoName();
		}

		//Converts to diffrent channel
		void convertToColor(int pth,string loggedUserDir){
			if(!argsSet)convertToColorArgs();
			convertToRed(videoLocation,videoColor,outVideoName,pth,loggedUserDir);
		}

		void videoLister(string loggedUserDir){
			// string fileName;
			system(("ls "+ loggedUserDir).c_str());
			// cout<<"Enter a file name to be opened: ";
			// cin>>fileName;
			// cout<<endl;
			// system(("xdg-open "+ loggedUserDir + "/"+ fileName).c_str());
		}

		void allInOne(){
			getvideoName();
			videoSaver(5,NULL);
			argsSet = true;
			convertToColor(5,NULL);
		}

		void choice(string loggedUserDir){
			// cout<<loggedUserDir<<endl;
			char op;
			switch(userFunctionalitiesChoice){
				case 1: videoLister(loggedUserDir);
					break;
				case 2: videoSaver(2,loggedUserDir);
					break;
				case 3:convertToColor(3,loggedUserDir);
					break;
				case 4:gaussianFilter(4);
					break;
				case 5: allInOne();
					break;
				default:cout<<"Wrong Choice please try again"<<endl;
					choice(loggedUserDir);
			}
			// 
		}

};