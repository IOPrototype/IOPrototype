#include "stdafx.h"
#include "Student.h"

void Student::HandleAll(){
	return;
}

Student::Student(std::string& _login,std::string& _password,std::string& _name,std::string& _surname,int _id, std::vector<Course>& _courses,std::vector<int>& icourses)
{
	login=_login;
	password=_password;
	name=_name;
	surname=_surname;
	id=_id;
	type=2;
	for(int j=0;j<icourses.size();j++)
		for(int i=0;i<_courses.size();i++)
			if(_courses[i].getID()==icourses[j]) courses.push_back(_courses[i].getID());

}
Student::Student(std::string& _login,std::string& _password,std::string& _name,std::string& _surname,int _id)
{
	login=_login;
	password=_password;
	name=_name;
	surname=_surname;
	id=_id;
	type=2;
}

Student::~Student(void)
{
}
