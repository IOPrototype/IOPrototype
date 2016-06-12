#include "stdafx.h"
#include "Profesor.h"

bool Profesor::HandleAll(){
	return true;
}

Profesor::Profesor(const std::vector<Course>* const _vcourses, const std::vector<const Users const*>* const _vusers,std::string& _login,std::string& _password,std::string& _name,std::string& _surname,int _id,std::vector<int>& icourses):vcourses(_vcourses),vusers(_vusers)
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



void Profesor::SetPromotions(){}
void Profesor::SetArticles(){}
void Profesor::Advertisements(){}

void Profesor::AddNewCourse(){}
void Profesor::EditCoures(){}
void Profesor::DeleteCourse(){}
void Profesor::ShowAllCourses(){}

void Profesor::ShowOwnedCourses(){}