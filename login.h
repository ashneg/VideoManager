#include<iostream>

using namespace std;



class Login{
public:
// private:
	unordered_map<string,string> userData;
	bool loggedIN = false;
	string loggedUser;

	// reads the passwords and usernames from the file
	Login(){
			ifstream file("./password/password.txt");
		    if ( file )
		    {
		        std::stringstream buffer;

		        buffer << file.rdbuf();

		        file.close();
		    string word;
		    while(buffer >> word) {
		    	string memUsr,mempass;
		    	memUsr = word;
		    	buffer>>word;
		    	mempass = word;
		    	userData[memUsr]  = mempass;
		    }
		}
	}
// public:
	bool userRegistration(){
		string userName,userPassword;
		cout<<"\n\n Register Yourself \n\n";
		cout<<"Enter your new user name: ";
		cin>>userName;
		if((userData.find(userName) == userData.end())){
			cout<<"\n Enter your Password: ";
			cin>>userPassword;
			userData[userName] = userPassword;
			cout<<"Successfully registered"<<endl;
			string createDir = "mkdir ./users/";
			createDir.append(userName);
			system((createDir).c_str());
			ofstream file("./password/password.txt",ios::app);
			if(file){
				file<<userName<<" "<<userPassword<<endl;
			}
			else{
				cout<<"File not found";
			}
			return true;
		}
		else{
			cout<<"User Name is already taken please try again";
			userRegistration();
			return true;
		}
		
	}



	// For User Login
	bool userLogin(){
		string inputPassword,inputUsername;
		cout<<"\n\nWelcome Back User\n\n";
		cout<<"\nEnter your username: ";
		cin>>inputUsername;
		cout<<"Enter your password: ";
		cin>>inputPassword;
		if(userData.find(inputUsername) != userData.end()){
			if(userData[inputUsername] == inputPassword){
				cout<<"\nSuccessful Login\n\n";
				loggedIN = true;
				loggedUser = inputUsername;
			}
			else{
				cout<<"\nPlease recheck your password and try again";
			}
		}
		else{
			cout<<"No user found";

		}
	}



	//Choice module
	char choice(){
		string ch;
		cout<<"\n\nPress 'R' to register as a new user\n\n";
		cout<<"Press 'L' to login"<<endl;
		cin>>ch;
		if(ch.length() != 1 && !(ch == "r" || ch == "l" || ch == "R" || ch == "L")){
			cout<<"Invalid Output!! Please try again";
			choice();
		}
		else{
			if(ch == "r" || ch == "R"){
				cout<<"\n\n Register Yourself \n\n";
				return 'r';
			}
			else return 'l';
		}
	}


};


