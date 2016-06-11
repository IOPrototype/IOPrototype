#pragma once
class Course
{
	std::string Name;
	int Level,Autor;
	bool IsFree;
	float Price;
	int ID;
public:

	std::string getName(){return Name;}
	int getLevel(){return Level;}
	bool getIsFree(){return IsFree;}
	float getPrice(){return Price;}
	int getID(){return ID;}
	int getAutor(){return Autor;}

	void Execute();
	Course(int,	std::string&,
	int,
	bool,
	float,int);
	~Course(void);
};

