#pragma once
#include "users.h"
class Admin :
	public Users
{
	std::vector<Course>* const vcourses;
	std::vector<Users*>* const vusers;
public:
	bool HandleAll();
	Admin(std::vector<Course>* const,std::vector<Users*>*,std::string&,std::string&,std::string&,std::string&,int);
	~Admin(void);
};

