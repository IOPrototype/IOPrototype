#pragma once
class Users
{
	std::string login,password,type;
	int id;
	std::vector<int> courses;

public:
	Users(void);
	~Users(void);
	virtual void HandleAll()=0;
};

