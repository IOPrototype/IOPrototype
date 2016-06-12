#pragma once
class Course
{
	friend class System;
	friend class Admin;
	friend class Profesor;
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

	int getAuthor(){return Author;}
	int getAuthor() const {return Author;}

	float getPrice(){return Price;}
	float getPrice() const {return Price;}

	void Execute() const;

	void Print();
	void Print() const;
	void SetaName(std::string);
	Course(int,	std::string&,
	int,
	bool,
	float,int);
	~Course(void);
};

