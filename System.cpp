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
void System::ViewCourses(int id){


	for(auto i=courses.begin();i!=courses.end();i++){
		if(id==-1 || id==i->ID)
		{
		for(auto j=users.begin();j!=users.end();j++){
			if((*j)->id==i->Autor)
			std::cout
				<<"Autor: "
				<<  (*j)->name
				<<std::endl;
		}

		std::cout
			<<"Nazwa kursu: "
			<<  i->Name
			<<std::endl
			<<"Poziom: "
			<<  i->Level
			<<std::endl;
		if(i->IsFree)
			std::cout
			<<"Cena: Darmowy"
			<<std::endl;
		else
			std::cout
			<<"Cena: "
			<<  i->Price
			<<std::endl;

		std::cout << "\n\n";
		}
	}


}

bool System::start(){
	if(this->LoadCourses() && this->LoadUsers()){
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
		file << i->ID <<'\t'<<  i->Name <<'\t'<<  i->Level <<'\t'<<  i->IsFree <<'\t'<<  i->Price<<'\t'<<  i->Autor;
		if((i+1)!=courses.end() )file <<'\n';
		}
	//file <<"h";

	file.close();
	file.open("Users.txt");
	for(auto i=users.begin();i!=users.end();i++){
		file << (*i)->id <<'\t'<<  (*i)->login <<'\t'<<  (*i)->password <<'\t'<<  (*i)->name <<'\t'<<  (*i)->surname<<'\t'<<  (*i)->type;
		if(!(*i)->type ||(*i)->courses.empty())
			file <<'\t' << "-1";
		else
		for(auto j=(*i)->courses.begin();j!=(*i)->courses.end();j++)
			file <<'\t' << *j;
		if((i+1)!=users.end() )file <<'\n';
		}
	//file <<"h";
	file.close();

	return;
}

bool System::LoadCourses(){
	std::fstream file;
	file.open("Courses.txt");
		if(!file.is_open()) return false;
	std::string Name;
	int Level,Autor;
	bool IsFree;
	float Price;
	int ID;

	while(!file.eof()){
		file >> ID >> Name >> Level >> IsFree >> Price>> Autor;
		courses.push_back(Course(ID, Name, Level, IsFree, Price,Autor));
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

	users.push_back(new Student(login,pass,name,surname,id));

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
			users.push_back(new	Admin(login,pass,name,surname,id,courses));
		else if(type==1)
			users.push_back(new Profesor(login,pass,name,surname,id,courses,temp));
		else if(type==2)
			users.push_back(new Student(login,pass,name,surname,id,courses,temp));


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
