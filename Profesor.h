#pragma once
#include "users.h"
class Profesor :
	public Users
{
public:
	void HandleAll();
	Profesor(std::string&,std::string&,std::string&,std::string&,int,std::vector<Course>&,std::vector<int>&);
	~Profesor(void);
};

