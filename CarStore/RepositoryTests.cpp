#include"Tests.h"
void Test::addTests() 
{
	Repository repo;
	Car car1{ "223","Toyota","x345", "family" };
	Car car2{ "245", "Audi", "24", "trip" };

	assert(repo.getSize() == 0);

	repo.addNewElement(car1);
	assert(repo.getSize() == 1);

	repo.addNewElement(car1);
	assert(repo.getSize() == 2);

}

void Test::deleteTests()
{
	Repository repo;
	Car car1{ "223","Toyota","x345", "family" };
	Car car2{ "245", "Audi", "24", "trip" };
	Car car3{ "fe2","Opel", "3446", "family" };
	repo.addNewElement(car1);
	repo.addNewElement(car2);
	repo.addNewElement(car3);
	assert(repo.getSize() == 3);

	repo.deleteElement("245");
	assert(repo.getSize() == 2);

	Car car = repo.getElement(1);
	assert(car.getRegistration() == "fe2");
	assert(car.getModel() == "3446");
	assert(car.getManufacturer() == "Opel");
	assert(car1.getType() == "family");
}


void Test::updateTests()
{
	Repository repo;
	Car car1{ "223","Toyota","x345", "family" };
	Car car2{ "245", "Audi", "24", "trip" };
	Car car3{ "fe2","Opel", "3446", "family" };
	repo.addNewElement(car1);
	repo.addNewElement(car2);
	repo.addNewElement(car3);

	Car car = repo.getElement(1);
	std::string manufacturer = "Mercedes";

	repo.updateElement("Mercedes",&Car::setManufacturer);
	setterFunction fn = &Car::setManufacturer;
	//std::invoke(car, fn, "34");
	car.*fn("#$");
	for (int i = 0; i < repo.getSize(); i++)
		std::cout <<"\n"<< repo.getElement(i);
		
}

