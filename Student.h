#pragma once
#include "users.h"
class Student :
	public Users
{
	const std::vector<const Course>* const vcourses;
	const std::vector<const Users const*>* const vusers;

	float Money;
	Console console;
	Notes notes;

	void ShowOwnedCourses();
	void ShowAllCourses();
	void ExecuteCourse();
	void BuyCourse();
	void DeactivateAccount();

	void CustomizePage();

	void OpenNotes();
	void OpenConsole();
	void ContactTeacher();
	void PrintStatistics();

public:
	bool HandleAll();
	Student(const std::vector<const Course>* const,const std::vector<const Users const*>* const,std::string&,std::string&,std::string&,std::string&,int,std::vector<int>&);
	Student(const std::vector<const Course>* const,const std::vector<const Users const*>* const,std::string&,std::string&,std::string&,std::string&,int);
	~Student(void);
};

