#pragma once
#include "Course.h"
class Users
{
	friend class System;
protected:
	std::string login,password,name,surname;
	int id,type;
	std::vector<int> courses;
	bool deleted;
public:
	Users(void);
	~Users(void);
	virtual bool HandleAll()=0;


/*
	std::string	getname(){
		return name;
	}

	std::string	getsurname(){
		return surname;
	}
	int getid(){
		return id;
	}
	*/
};

