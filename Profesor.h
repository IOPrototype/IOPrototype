#pragma once
#include "users.h"
class Profesor :
	public Users
{
	const std::vector<Course>* const vcourses;
	const std::vector<const Users const*>* const vusers;

public:
	bool HandleAll();
	Profesor(const std::vector<Course>* const,const std::vector<const Users const*>* const,std::string&,std::string&,std::string&,std::string&,int,std::vector<int>&);
	~Profesor(void);
};

