#include"Tests.h"
void Test::addTests()
{
	Repository repo;
	Car car1{ "223","Toyota","x345", "family" };
	Car car2{ "245", "Audi", "24", "trip" };

	assert(repo.getSize() == 0);

	repo.addNewElement(car1);
	assert(repo.getSize() == 1);

	repo.addNewElement(car2);
	assert(repo.getSize() == 2);

	bool exceptionThrown = false;
	try
	{
		repo.addNewElement(car1);
	
	}
	catch (RepositoryException &exception)
	{
		exceptionThrown = true;
		std::cout << exception.what();
	}
	assert(exceptionThrown);

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

	repo.updateElement("245", "Mercedes", &Car::setManufacturer);
}


void Test::copyConstructer()
{
	Repository repo;
	Car car1{ "223","Toyota","x345", "family" };
	Car car2{ "245", "Audi", "24", "trip" };
	Car car3{ "fe2","Opel", "3446", "family" };
	repo.addNewElement(car1);
	repo.addNewElement(car2);
	repo.addNewElement(car3);

	Repository newRepo{ repo };
	assert(newRepo.getSize() == 3);
	}