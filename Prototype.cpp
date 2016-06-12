// Prototype.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "System.h"

int _tmain(int argc, _TCHAR* argv[])
{
	System sys;
	if(sys.start())	return 0;
	else {
		std::cerr << "Loading Failed";
		std::cin.get();
		return -1;
	}
}

