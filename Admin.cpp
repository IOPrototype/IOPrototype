#include "stdafx.h"
#include "Admin.h"

void Admin::HandleAll(){
	return;
}


Admin::Admin(std::string& _login,std::string& _password,std::string& _name,std::string& _surname,int _id, std::vector<Course>& _courses)
{
	login=_login;
	password=_password;
	name=_name;
	surname=_surname;
	id=_id;
	for(auto i=_courses.begin();i!=_courses.end();i++)
		courses.push_back(i->getID());
}


Admin::~Admin(void)
{
}
