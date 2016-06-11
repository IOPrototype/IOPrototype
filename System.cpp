#include "stdafx.h"
#include "System.h"


int System::Service(){

	int temp;
		std::cout
			<< "What do you desire?"
			<< std::endl
			<< "1. Log on user"
			<< std::endl
			<< "2. View Courses"
			<< std::endl
			<< "3. Exit"
			<< std::endl;

		std::cin >> temp;

		switch(temp){
			case 1:
				return 1;
				break;
			case 2:
				return 1;
				break;
			case 3:
				return 0;
				break;
			default:
				std::cout 
					<<"Wrong option"
					<< std::endl
					<<"Press Enter to continue"
					<< std::endl;
				std::cin.clear();
				std::cin.ignore(256,'\n');
				std::cin.get();
				return 1;
				break;
		}	
}


bool System::start(){
	if(this->LoadUsers() && this->LoadCourses()){
		while(this->Service()){		
			system("cls");
		}
		return true;
	}
	return false;
}


bool System::LoadCourses(){

	return true;
}

bool System::LoadUsers(){

	return true;
}



System::System(void)
{
}


System::~System(void)
{
}
