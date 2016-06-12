#pragma once
class Course
{
	friend class System;
	std::string Name;
	int Level;
	int Author;
	std::string aName;
	bool IsFree;
	float Price;
	int ID;
	bool deleted;

public:
	int getID(){return ID;}
	int getID() const {return ID;}

	void Execute() const;

	void Print();
	void Print() const;

	Course(int,	std::string&,
	int,
	bool,
	float,int);
	~Course(void);
};

