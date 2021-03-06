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
	Test::copyConstructer();
	Test::addTestService();
	Test::deleteTestService();
	Test::updateTestService();
	Test::searchElement();
	Test::filterTests();
	Test::sortTests();
	Test::validatorTests();
	Test::addBasketTest();
	Test::deleteBasketTest();
	Test::updateBasketTest();
	Test::populateBasketTest();
	Test::basketServiceTest();
	
	cls();
}


int main()
{
	tests();

	{
		try
		{

			FileRepository repo{ "cars.txt" };
			//	Repository repo;
			Validator val;
			Basket basket;
			Service srv{ repo, val , basket };
			Console cons{ srv };
			cons.ui();
		
		}
		catch (RepositoryException &error)
		{
			std::cout << error.what();
		}
	}
	_CrtDumpMemoryLeaks();
	return 0;

}

