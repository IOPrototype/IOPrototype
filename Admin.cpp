#include "stdafx.h"
#include "Admin.h"

bool Admin::HandleAll(){



int temp;
	while(1){
		std::cout<< "You are logged as: "
			<< name << " " << surname << std::endl
			<<"What do you want to do?\n"
			<<"1. Show All Courses\n"
			<<"2. Edit Courses\n"
			<<"3. Delete Course\n"
			<<"4. Open Console\n"
			<<"5. Open Notes\n"
			<<"6. Set Featured Advertisements\n"
			<<"7. Show users\n"
			<<"8. Edit Accounts\n"
			<<"9. Delete User\n"
			<<"10. ShowStatistics\n"
			<<"11. Deactivate Account\n"
			<<"12. Log Out\n"
			<<"13. Exit\n";

		std::cin>> temp;
		switch(temp){
			case 1:
				ShowAllCourses();
				break;
			case 2:
				EditCourses();
				break;
			case 3:
				if(DeleteCourses())
					return 0;
				break;
			case 4:
				StartConsole();
				break;
			case 5:
				OpenNotes();
				break;
			case 6:
				SetFeaturedAdvertisements();
				break;
			case 7:
				ShowUsers();
				break;
			case 8:
				EditAccounts();
				break;
			case 9:
				if(DeleteUser());
					return 0;
				break;
			case 10:
				ShowStatisticsOfUsers();
				break;
			case 11:
				DeactivateAccount();
				return 0;
				break;
			case 12:
				return 1;
				break;
			case 13:
				return 0;
				break;
			default:
				std::cout 
					<<"Wrong option"
					<< std::endl
					<<"Press Enter to continue"
					<< std::endl;

				break;
		}	
				std::cin.clear();
				std::cin.ignore(256,'\n');
				std::cin.get();

	}
}

Admin::Admin(std::vector<Course>* const _vcourses,std::vector<Users*>* _vusers,std::string& _login,std::string& _password,std::string& _name,std::string& _surname,int _id) : vcourses(_vcourses),vusers(_vusers)
{
	login=_login;
	password=_password;
	name=_name;
	surname=_surname;
	id=_id;
	type=0;
	deleted=0;
	for(auto i=(*_vcourses).begin();i!=(*_vcourses).end();i++)
		courses.push_back(i->getID());
}


Admin::~Admin(void)
{
}


	void Admin::EditCourses(){
	std::string Name;
	int Level;
	float Price;
	ShowAllCourses();
	std::cout << "Which one do you want to edit? ";
	bool flag=0;
	int temp,temp2 ;
	std::cin >>temp;
	temp--;

	for(auto i=vcourses->begin();i!=vcourses->end();i++){
		if(i->getID()==temp) {
			std::cout << "What do you want to change? ";
			std::cout<<"1. Name of Course\n ";
			std::cout<<"2. Level of Course\n";
			std::cout<<"3. Price\n";
			std::cout<<"4. Go back\n";
			std::cin >>temp2;
			switch(temp2){
			case 1:
					std::cout<<"Name of Course (use \"_\" instead of spaces: ";
					std::cin >> Name;
					i->Name=Name;

				break;
			case 2:
					std::cout<<"Level of Course: ";
					std::cin >> Level;
					i->Level=Level;
					break;
			case 3:
					std::cout<<"Price ( 0 to make it free) : ";
			std::cin >> Price;
			i->Price=Price;
			break;
			default:
				return;
				break;
				
				
			};




			return;
		}
	}

	std::cout << "Course Either doesnt exist or you are not an owner\n";
	return;
	
	
	}
	bool Admin::DeleteCourses(){

	ShowAllCourses();
	std::cout << "Which one do you want to delete? ";
	bool flag=0;
	int temp ;
	std::cin >>temp;
	temp--;
	for(auto i=vcourses->begin();i!=vcourses->end();i++){
		if(i->getID()==temp) {
			i->deleted=1;
			return 1;
		}
	}
	std::cout << "Course doesnt exist\n";
	return 0;	
	}

	void Admin::SetFeaturedAdvertisements(){return;}

	void Admin::EditAccounts(){}
	bool Admin::DeleteUser(){
	
	ShowUsers();
	std::cout << "Which one do you want to delete? ";
	bool flag=0;
	int temp ;
	std::cin >>temp;
	temp--;
	for(auto i=vusers->begin();i!=vusers->end();i++){
		if((*i)->id==temp) {
			(*i)->deleted=1;
			return 1;
		}
	}
	std::cout << "User doesnt exist\n";
	return 0;	
	
	}


	void Admin::ShowUsers(){

	for(auto i=0;i<vusers->size();i++){	
			vusers->at(i)->Print();
		}
	
	}

	void Admin::ShowAllCourses(){
		for(auto i=0;i<vcourses->size();i++){
			std::cout << vcourses->at(i).getID()+1<< ".\n";
			vcourses->at(i).Print();
		}
	}



	void Admin::ShowStatisticsOfUsers(){return;}
	void Admin::StartConsole(){MainConsole.StartConsole();}
	void Admin::OpenNotes(){notes.StartNotes();}
	void Admin::DeactivateAccount(){deleted=1;}
