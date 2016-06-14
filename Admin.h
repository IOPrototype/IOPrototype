#pragma once
#include "users.h"
class Admin :
	public Users
{
	std::vector<Course>* const vcourses;
	std::vector<Users*>* const vusers;

	Console MainConsole;
	Notes notes;

	void EditCourses();
	bool DeleteCourses();
	void SetFeaturedAdvertisements();

	void EditAccounts();
	bool DeleteUser();
	void ShowUsers();
	void ShowAllCourses();
	void ShowStatisticsOfUsers();
	void StartConsole();
	void OpenNotes();
	void DeactivateAccount();


public:
	bool HandleAll();
	
	Admin(std::vector<Course>* const,std::vector<Users*>*,std::string&,std::string&,std::string&,std::string&,int);
	~Admin(void);
};

