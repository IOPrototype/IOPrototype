#pragma once

#include "Admin.h"
#include "Profesor.h"
#include "Student.h"
#include "Course.h"
#include "Users.h"

class System
{
	std::vector<Users*> users;
	std::vector<Course> courses;
	bool LoadUsers();
	bool LoadCourses();
	int Service();
	void LoginUser();
	void RegisterUser();
	void Exit();
	void ViewCourses(int=-1);

public:
	bool start();
	System(void);
	~System(void);
};

