#pragma once
#include "users.h"
class Profesor :
	public Users
{
	std::vector<Course>* const vcourses;
	const std::vector<const Users const*>* const vusers;

	Notes notes;

	void SetPromotions();
	void SetArticles();
	void Advertisements();
	void OpenNotes();


	void AddNewCourse();
	void EditCoures();
	bool DeleteCourse();
	void ShowAllCourses();
	void ShowOwnedCourses();
	void DeactivateAccount();

public:
	bool HandleAll();
	Profesor(std::vector<Course>* const,const std::vector<const Users const*>* const,std::string&,std::string&,std::string&,std::string&,int,std::vector<int>&);
	~Profesor(void);
};

