#include "stdafx.h"
#include "Student.h"

bool Student::HandleAll(){

	int temp;
	while(1){
		std::cout<< "You are logged as: "
			<< name << " " << surname << std::endl
			<<"What do you want to do?\n"
			<<"1. Show Owned Courses\n"
			<<"2. Show All Courses\n"
			<<"3. Buy Courses\n"
			<<"4. Do Courses\n"
			<<"5. Customize Page\n"
			<<"6. Open Notes\n"
			<<"7. Open Console\n"
			<<"8. Contact Teacher\n"
			<<"9. Print Statistics\n"
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
				BuyCourse();
				break;
			case 4:
				ExecuteCourse();
				break;
			case 5:
				CustomizePage();
				break;
			case 6:
				OpenNotes();
				break;
			case 7:
				OpenConsole();
				break;
			case 8:
				ContactTeacher();
				break;
			case 9:
				PrintStatistics();
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

Student::Student(const std::vector<const Course>* const _vcourses,const std::vector<const Users const*>* const _vusers,std::string& _login,std::string& _password,std::string& _name,std::string& _surname,int _id,std::vector<int>& icourses):vcourses(_vcourses), vusers(_vusers)
{
	login=_login;
	password=_password;
	name=_name;
	surname=_surname;
	id=_id;
	type=2;
	deleted=0;
	Money=9999.0;
	for(int j=0;j<icourses.size();j++)
		for(int i=0;i<(*_vcourses).size();i++)
			if((*_vcourses)[i].getID()==icourses[j]) courses.push_back((*_vcourses)[i].getID());

}
Student::Student(const std::vector<const Course>* const _vcourses,const std::vector<const Users const*>* const _vusers,std::string& _login,std::string& _password,std::string& _name,std::string& _surname,int _id):vcourses(_vcourses), vusers(_vusers)
{
	login=_login;
	password=_password;
	name=_name;
	surname=_surname;
	id=_id;
	type=2;
	deleted=0;
	Money=9999.0;
}

Student::~Student(void)
{
}


	void Student::ShowOwnedCourses(){

	for(auto i=0;i<vcourses->size();i++){
			for( auto j=courses.begin();j!=courses.end();j++)
		if(vcourses->at(i).getID()==*j){
			std::cout << vcourses->at(i).getID()+1<< ".\n";
			vcourses->at(i).Print();
			}
	}
		
	}

	void Student::ExecuteCourse(){
	ShowOwnedCourses();
	int temp;
	std::cout <<"Which one do you want to start?: ";
	std::cin >>temp;
	temp--;
		for(auto i=0;i<vcourses->size();i++){
			if(temp== vcourses->at(i).getID())
				vcourses->at(i).Execute();
		}	
	}

	void Student::BuyCourse(){
	ShowAllCourses();
	std::cout << "Which one do you want to buy? ";
	bool flag=0;
	int temp ;
	std::cin >>temp;
	temp--;
	for( auto i=courses.begin();i!=courses.end();i++){
		if(temp==*i) {
			std::cout <<"You already have this course\n";
			return;
		}
	}


	for(auto i=0;i<vcourses->size();i++){
		if(temp== vcourses->at(i).getID()){
			flag=1;
			if(Money-vcourses->at(i).getPrice()>0){
				Money-=vcourses->at(i).getPrice();
				courses.push_back(temp);
				std::cout<< "Bought\n";
				return;
			}
			else {std::cout<< "Not Enough money\n"; return;}

		}

	}
	if(!flag){
		std::cout<< "Course doesnt exist\n";
		return;
	}
	}

	void Student::ShowAllCourses(){
		for(auto i=0;i<vcourses->size();i++){
			std::cout << vcourses->at(i).getID()+1<< ".\n";
			vcourses->at(i).Print();
	}
	
	}


	void Student::DeactivateAccount(){deleted=1;}
	void Student::CustomizePage(){return;}
	void Student::OpenNotes(){notes.StartNotes();}
	void Student::OpenConsole(){console.StartConsole();}
	void Student::ContactTeacher(){return;}
	void Student::PrintStatistics(){return;}
