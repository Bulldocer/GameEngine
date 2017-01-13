#include "ManagerOfManagers.h"



int main(int argc, char* args[])
{	
	ManagerOfManagers::CreateSingleton();

	ManagerOfManagers::GetInstance().initialice();

	ManagerOfManagers::GetInstance().update();
	return 0;
}