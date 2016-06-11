#pragma once

#include "Admin.h"
#include "Profesor.h"
#include "Student.h"
#include "Course.h"

class System
{
	std::vector<Users*> users;
	std::vector<Course> courses;
	bool LoadUsers();
	bool LoadCourses();
	int Service();
	bool LoginUser();
	void Exit();
public:
	bool start();
	System(void);
	~System(void);
};

