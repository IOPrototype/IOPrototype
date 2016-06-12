#include "stdafx.h"
#include "Profesor.h"

bool Profesor::HandleAll(){
	int temp;
	while(1){
		std::cout<< "You are logged as: "
			<< name << " " << surname << std::endl
			<<"What do you want to do?\n"
			<<"1. Show Owned Courses\n"
			<<"2. Show All Courses\n"
			<<"3. Add Courses\n"
			<<"4. Edit Courses\n"
			<<"5. Delete Course\n"
			<<"6. Open Notes\n"
			<<"7. Set Advertisements\n"
			<<"8. Set Articles\n"
			<<"9. Set Promotions\n"
			<<"10. Deactivate Account\n"
			<<"11. Log Out\n"
			<<"12. Exit\n";

		std::cin>> temp;
		switch(temp){
			case 1:
				ShowOwnedCourses();
				break;
			case 2:
				ShowAllCourses();
				break;
			case 3:
				AddNewCourse();
				break;
			case 4:
				EditCoures();
				break;
			case 5:
				if(DeleteCourse())
					return 0;
				break;
			case 6:
				OpenNotes();
				break;
			case 7:
				Advertisements();
				break;
			case 8:
				SetArticles();
				break;
			case 9:
				SetPromotions();
				break;
			case 10:
				DeactivateAccount();
				return 0;
				break;
			case 11:
				return 1;
				break;
			case 12:
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

Profesor::Profesor(std::vector<Course>* const _vcourses, const std::vector<const Users const*>* const _vusers,std::string& _login,std::string& _password,std::string& _name,std::string& _surname,int _id,std::vector<int>& icourses):vcourses(_vcourses),vusers(_vusers)
{
	login=_login;
	password=_password;
	name=_name;
	surname=_surname;
	id=_id;
	type=1;
	deleted=0;
	for(int j=0;j<icourses.size();j++)
		for(int i=0;i<(*_vcourses).size();i++)
			if((*_vcourses)[i].getID()==icourses[j]) courses.push_back((*_vcourses)[i].getID());

}


Profesor::~Profesor(void)
{
}



void Profesor::SetPromotions(){return;}
void Profesor::SetArticles(){return;}
void Profesor::Advertisements(){return;}

void Profesor::AddNewCourse(){
	std::string Name;
		int Level;
			float Price;
	int _id=vcourses->begin()->getID();

	bool isFree;


	std::cout<<"Name of Course (use \"_\" instead of spaces: ";
	std::cin >> Name;
	std::cout<<"Level of Course: ";
	std::cin >> Level;
	std::cout<<"Price ( 0 to make it free) : ";
	std::cin >> Price;

	if(Price==0.0f)isFree=1;
	else isFree=0;

	for(auto i=vcourses->begin();i!=vcourses->end();i++){
		if(i->getID()>_id)_id=i->getID();
		}
	
	_id++;

	vcourses->push_back(Course(_id,Name,Level,isFree,Price,this->id));
	vcourses->back().SetaName(this->surname+" "+ this->name);
	courses.push_back(_id);
}
void Profesor::EditCoures(){
	std::string Name;
	int Level;
	float Price;
	ShowOwnedCourses();
	std::cout << "Which one do you want to edit? ";
	bool flag=0;
	int temp,temp2 ;
	std::cin >>temp;
	temp--;

	for(auto i=vcourses->begin();i!=vcourses->end();i++){
		if(i->getAuthor()==id && i->getID()==temp) {
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
bool Profesor::DeleteCourse(){
	ShowOwnedCourses();
	std::cout << "Which one do you want to delete? ";
	bool flag=0;
	int temp ;
	std::cin >>temp;
	temp--;
	for(auto i=vcourses->begin();i!=vcourses->end();i++){
		if(i->getAuthor()==id && i->getID()==temp) {
			i->deleted=1;
			return 1;
		}
	}
	std::cout << "You are not a owner or Course doesnt exist\n";
	return 0;
}


void Profesor::DeactivateAccount(){

	for(auto i=vcourses->begin();i!=vcourses->end();i++){
		if(i->getAuthor()==id) {
			i->deleted=1;
		}
	}
	deleted=1;
}


	void Profesor::ShowAllCourses(){
		for(auto i=0;i<vcourses->size();i++){
			std::cout << vcourses->at(i).getID()+1<< ".\n";
			vcourses->at(i).Print();
	}
	
	}


void Profesor::OpenNotes(){notes.StartNotes();}

void Profesor::ShowOwnedCourses(){

	for(auto i=0;i<vcourses->size();i++){
			for( auto j=courses.begin();j!=courses.end();j++)
		if(vcourses->at(i).getID()==*j){
			std::cout << vcourses->at(i).getID()+1<< ".\n";
			vcourses->at(i).Print();
			}
	}
		
}