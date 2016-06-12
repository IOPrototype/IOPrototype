#include "stdafx.h"
#include "Student.h"

bool Student::HandleAll(){

	return true;
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
}

Student::~Student(void)
{
}
