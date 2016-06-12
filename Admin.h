#pragma once
#include "users.h"
class Admin :
	public Users
{
	std::vector<Course>* const vcourses;
	std::vector<Users*>* const vusers;

	Console MainConsole;

	void EditCourses();
	void DeleteCourses();
	void SetFeaturedAdvertisements();

	void EditAccounts();
	void DeleteUser();
	void ShowUsers();
	void ShowStatisticsOfUsers();

public:
	bool HandleAll();
	Admin(std::vector<Course>* const,std::vector<Users*>*,std::string&,std::string&,std::string&,std::string&,int);
	~Admin(void);
};

