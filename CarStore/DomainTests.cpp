#include"Tests.h"
#include<iostream>
void Test::gettersTests() 
{
	Car car1{ "223","Toyota","x345", "family" };
	assert(car1.getRegistration() == "223");
	assert(car1.getModel() == "x345");
	assert(car1.getManufacturer() == "Toyota");
	assert(car1.getType() == "family");

	std::cout << car1;
}

void Test::settersTests()
{
	Car car1{ "223","Toyota","x345", "family" };
	Car car2{ "245", "Audi", "24", "trip" };
	car1 = car2;
	assert(car1.getRegistration() == "245");
	assert(car1.getModel() == "24");
	assert(car1.getManufacturer() == "Audi");
	assert(car1.getType() == "trip");
}

