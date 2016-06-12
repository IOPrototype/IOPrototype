#include "stdafx.h"
#include "Admin.h"

bool Admin::HandleAll(){
	return true;
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


	void Admin::EditCourses(){}
	void Admin::DeleteCourses(){}
	void Admin::SetFeaturedAdvertisements(){}

	void Admin::EditAccounts(){}
	void Admin::DeleteUser(){}
	void Admin::ShowUsers(){}
	void Admin::ShowStatisticsOfUsers(){}