#include"Tests.h"
#include"UserInterface.h"
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

	cls();
}
int main()
{
	tests();
	Repository repo;
	Service srv{ repo };
	Console cons{ srv };
	cons.ui();
	//cons.addElement();
	
}
