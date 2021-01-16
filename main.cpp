#include <opencv2/opencv.hpp>
#include <iostream>
#include<fstream>
#include "login.h"
#include "userFunctionalities.h"

using namespace cv;
using namespace std;

int main(){
	Login user;
	cout<<"Hey there welcome to video saver project\n";
	cout<<"\n\nEnter your choice\n";
	while(!user.loggedIN){
		switch(user.choice()){
		case 'r' : user.userRegistration();
				break;
		case 'l' : user.userLogin();
				break;
		default:
			cout<<"Unexpected Error occured please try re-running the program";
		} 
	}
	if(user.loggedIN){
		userFunctionalities operations;
		cout<<"\nEnter your choice "<<user.loggedUser<<endl;
		operations.choice("./users/"+user.loggedUser);
		system(("mv out.avi ./users/"+user.loggedUser).c_str());
	}
	return 0;
}
