#include "stdafx.h"
#include "Course.h"


Course::Course(int _ID,	std::string& _Name,
	int _Level,
	bool _IsFree,
	float _Price,int _Author
	)
{
	Name=_Name;
	Level=_Level;
	IsFree=_IsFree;
	Price=_Price;
	ID=_ID;
	Author=_Author;
	deleted=0;

}

void Course::SetaName(std::string value){

	aName=value;
}


void Course::Execute() const
{

}

void Course::Print(){
		std::cout
			<<"Autor: "
			<<  aName
			<<std::endl
			<<"Nazwa kursu: "
			<<  Name
			<<std::endl
			<<"Poziom: "
			<<  Level
			<<std::endl;
		if(IsFree)
			std::cout
			<<"Cena: Darmowy"
			<<std::endl;
		else
			std::cout
			<<"Cena: "
			<<  Price
			<<std::endl;

		std::cout << "\n\n";

}

void Course::Print()const{
		std::cout
			<<"Autor: "
			<<  aName
			<<std::endl
			<<"Nazwa kursu: "
			<<  Name
			<<std::endl
			<<"Poziom: "
			<<  Level
			<<std::endl;
		if(IsFree)
			std::cout
			<<"Cena: Darmowy"
			<<std::endl;
		else
			std::cout
			<<"Cena: "
			<<  Price
			<<std::endl;

		std::cout << "\n\n";

}

Course::~Course(void)
{
}
