#include "stdafx.h"
#include "Course.h"


Course::Course(int _ID,	std::string& _Name,
	int _Level,
	bool _IsFree,
	float _Price
	)
{
	Name=_Name;
	Level=_Level;
	IsFree=_IsFree;
	Price=_Price;
	ID=_ID;

}


Course::~Course(void)
{
}
