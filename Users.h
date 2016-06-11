#pragma once
#include "Course.h"
class Users
{
protected:
	std::string login,password,name,surname;
	int id;
	std::vector<int> courses;

public:
	Users(void);
	~Users(void);
	virtual void HandleAll()=0;
};

