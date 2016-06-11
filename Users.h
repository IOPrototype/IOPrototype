#pragma once
class Users
{
	std::string login,password,type;
	int id;

public:
	Users(void);
	~Users(void);
	virtual void HandleAll()=0;
};

