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
			<< "3. Register new user"
			<< std::endl
			<< "4. Exit"
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
				return 1;
				break;
			case 4:
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
		this->Exit();
		return true;
	}
	return false;
}

void System::Exit(){



}

bool System::LoadCourses(){

	return true;
}

bool System::LoadUsers(){
	std::fstream file;
	file.open("Users.txt");
		if(!file.is_open()) return false;
	int id,type,tmp;
	std::string login,pass,name,surname;
	std::vector<int> temp;
	while(!file.eof()){
		file >> id >> login >> pass >> name >> surname >> type ;
		while((char)file.peek()!='\n' && file.peek()!=-1 )
			if((char)file.peek()=='\t'){
				file >>tmp;
				temp.push_back(tmp);
			}
		std::cout << id << login << pass << name << surname << type ;
	
		for(auto i=temp.begin();i!=temp.end();i++)
			std::cout << *i;
		//new user;
		std::cout << std::endl;
		temp.clear();
		if(file.peek()==-1) break;
	}

	return true;
}



System::System(void)
{
}


System::~System(void)
{
	for(auto i=users.begin();i!=users.end();i++)
		delete (*i);
}
