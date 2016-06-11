#pragma once
#include "users.h"
class Student :
	public Users
{
public:
	void HandleAll();
	Student(std::string&,std::string&,std::string&,std::string&,int,std::vector<Course>&,std::vector<int>&);
	~Student(void);
};

