#include "ManagerOfManagers.h"
int main(int argc, char* args[])
{	
	ManagerOfManagers::CreateSingleton();

	ManagerOfManagers::GetInstance().initialice();

	ManagerOfManagers::GetInstance().getRender().openWindow();

	return 0;
}