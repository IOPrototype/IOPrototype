#include "stdafx.h"
#include "Users.h"


Users::Users(void)
{
}
bool Users::HandleAll(){
	return true;
}

void Users::Print(){
		std::cout 
			<< "ID: "
			<< id
			<< " Login: "
			<< login
			<< " Password: "
			<< password
			<< " Name: "
			<< name
			<< " Surname: "
			<< surname
			<< " Type: "
			<< type
			<< "\n\n";

}


Users::~Users(void)
{
}
