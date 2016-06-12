#pragma once
#include "users.h"
class Profesor :
	public Users
{
	const std::vector<Course>* const vcourses;
	const std::vector<const Users const*>* const vusers;

	Notes notes;

	void SetPromotions();
	void SetArticles();
	void Advertisements();

	void AddNewCourse();
	void EditCoures();
	void DeleteCourse();
	void ShowAllCourses();
	void ShowOwnedCourses();


public:
	bool HandleAll();
	Profesor(const std::vector<Course>* const,const std::vector<const Users const*>* const,std::string&,std::string&,std::string&,std::string&,int,std::vector<int>&);
	~Profesor(void);
};

