#pragma once
class Course
{
	friend class System;
	std::string Name;
	int Level,Autor;
	bool IsFree;
	float Price;
	int ID;

public:
	int getID(){return ID;}
	void Execute();
	Course(int,	std::string&,
	int,
	bool,
	float,int);
	~Course(void);
};

