#include"Tests.h"
#include"UserInterface.h"
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

/*
	Clear the screen
*/
void cls() noexcept
{
	system("cls");
}

void tests()
{
	Test::gettersTests();
	Test::settersTests();
	Test::addTests();
	Test::deleteTests();
	Test::updateTests();
	Test::addTestService();
	Test::deleteTestService();
	Test::updateTestService();
	Test::searchElement();
	Test::filterTests();
	Test::sortTests();
	Test::validatorTests();
	
	cls();
}
int main()
{
	tests();
	
	{Repository<List> repo;
	Validator val;
	Service srv{ repo, val };
	Console cons{ srv };
	cons.ui();

	}
	_CrtDumpMemoryLeaks();
	return 0;

}

