#pragma once
#include "Course.h"
#include "Console.h"
#include "Notes.h"
class Users
{
	friend class System;
	friend class Admin;
protected:
	std::string login,password,name,surname;
	int id,type;
	std::vector<int> courses;
	bool deleted;
	void Print();

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

