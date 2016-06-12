#include "stdafx.h"
#include "System.h"


int System::Service(){

	int temp;
	Users* tmp;
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
				tmp=this->LoginUser();
				if(tmp) return tmp->HandleAll();
				else{
					std::cout 
					<<"Login Failed\nPress Enter to continue"
					<< std::endl;
				std::cin.clear();
				std::cin.ignore(256,'\n');
				std::cin.get();
				return 1;
				}

				break;
			case 2:
				this->ViewCourses();
				std::cout 
					<<"Press Enter to continue"
					<< std::endl;
				std::cin.clear();
				std::cin.ignore(256,'\n');
				std::cin.get();
				return 1;
				break;
			case 3:
				this->RegisterUser();
				std::cout 
					<<"Press Enter to continue"
					<< std::endl;
				std::cin.clear();
				std::cin.ignore(256,'\n');
				std::cin.get();
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

bool System::SetAuthors(){
	bool flag;
	for(auto i=courses.begin();i!=courses.end();i++){
		flag=1;
		for(auto j=users.begin();j!=users.end();j++){
			if((*j)->id==i->Author){
				i->aName=(*j)->surname+" "+(*j)->name;
				flag=0;
			}
			
		}
		if(flag) return false;
	}
	return true;
}



void System::ViewCourses(){


	for(auto i=courses.begin();i!=courses.end();i++){
			i->Print();
	}


}

bool System::start(){
	if(this->LoadCourses() && this->LoadUsers() && this->SetAuthors()){
		while(this->Service()){		
			system("cls");
		}
		this->Exit();
		return true;
	}
	return false;
}

void System::Exit(){
	std::ofstream file;
	file.open("Courses.txt");
	for(auto i=courses.begin();i!=courses.end();i++){
		if(i->deleted) continue;
		file << i->ID <<'\t'<<  i->Name <<'\t'<<  i->Level <<'\t'<<  i->IsFree <<'\t'<<  i->Price<<'\t'<<  i->Author;
		if((i+1)!=courses.end() ){
			for(auto j=i+1;j!=courses.end();j++)
				if(j->deleted) continue;
				else {file <<'\n'; break;}
		}
		}
	file.close();
	file.open("Users.txt");
	for(auto i=users.begin();i!=users.end();i++){
		if((*i)->deleted) continue;
		file << (*i)->id <<'\t'<<  (*i)->login <<'\t'<<  (*i)->password <<'\t'<<  (*i)->name <<'\t'<<  (*i)->surname<<'\t'<<  (*i)->type;
		if(!(*i)->type ||(*i)->courses.empty())
			file <<'\t' << "-1";
		else
		for(auto j=(*i)->courses.begin();j!=(*i)->courses.end();j++)
			file <<'\t' << *j;
		if((i+1)!=users.end() ){
			for(auto j=i+1;j!=users.end();j++)
				if((*j)->deleted) continue;
				else {file <<'\n'; break;}
		}
		}
	//file <<"h";
	file.close();

	return;
}


Users* System::LoginUser(){
	std::string login,pass;
	std::cout <<"Podaj login: ";
	std::cin >>login;
	std::cout <<"Podaj haslo: ";
	std::cin >>pass;

	for(auto i=users.begin();i!=users.end();i++){
		if(!login.compare((*i)->login) && !pass.compare((*i)->password)) return (*i);
	}
	return nullptr;
}



bool System::LoadCourses(){
	std::fstream file;
	file.open("Courses.txt");
		if(!file.is_open()) return false;
	std::string Name;
	int Level,Author;
	bool IsFree;
	float Price;
	int ID;

	while(!file.eof()){
		file >> ID >> Name >> Level >> IsFree >> Price>> Author;
		courses.push_back(Course(ID, Name, Level, IsFree, Price,Author));
		if(file.peek()==-1) break;
	}


	return true;
}

void System::RegisterUser(){
	std::string login,pass,name,surname;
	int id=(*users.begin())->id;
	std::cout<<"Podaj imie: ";
	std::cin >> name;
	std::cout<<"Podaj Nazwisko: ";
	std::cin >> surname;
	std::cout<<"Podaj login: ";
	std::cin >> login;
	for(auto i=users.begin();i!=users.end();i++){
		if((*i)->id>id)id=(*i)->id;
		if(!login.compare((*i)->login)){
			std::cout<<"Login zajenty";
			return;
		}
	}
	id++;
	std::cout<<"Podaj haslo: ";
	std::cin >> pass;

	users.push_back(new Student((const std::vector<const Course>* const) &courses ,(const std::vector<const Users const*>* const) &users, login,pass,name,surname,id));

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
		/*
		std::cout << id << login << pass << name << surname << type ;
	
		for(auto i=temp.begin();i!=temp.end();i++)
			std::cout << *i;
		*/
		if(type==0)
			users.push_back(new	Admin(&courses,&users,login,pass,name,surname,id));
		else if(type==1)
			users.push_back(new Profesor((const std::vector<Course>* const)&courses,(const std::vector<const Users const*>* const)&users,login,pass,name,surname,id,temp));
		else if(type==2)
			users.push_back(new Student((const std::vector<const Course>* const) &courses ,(const std::vector<const Users const*>* const) &users,login,pass,name,surname,id,temp));


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
