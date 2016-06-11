#pragma once
#include "users.h"
class Admin :
	public Users
{

public:
	void HandleAll();
	Admin(std::string&,std::string&,std::string&,std::string&,int,std::vector<Course>&);
	~Admin(void);
};

