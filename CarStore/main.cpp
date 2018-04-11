#include"Tests.h"
#include"Domain.h"

void tests()
{
	Test::gettersTests();
	Test::settersTests();
	Test::addTests();
	Test::deleteTests();
	Test::updateTests();
}
int main()
{
	tests();
}
