#include"Tests.h"

void Test::addTestService()
{
	Repository<List> repo;
	Validator val;
	Service srv{ repo, val };
	Car car1{ "223","Toyota","x345", "family" };
	Car car2{ "245", "Audi", "24", "trip" };
	Car car3{ "245", "Audi", " ", "trip" };
	assert( srv.getSizeRepo() == 0);

	srv.addNewElementService(car1);
	assert(srv.getSizeRepo() == 1);
	
	srv.addNewElementService(car2);
	assert(srv.getSizeRepo() == 2);

	bool ExceptionThrown = false;
	try {
		srv.addNewElementService(car3);
	}
	catch(std::exception& )
	{
		ExceptionThrown = true;
	}
	assert(ExceptionThrown);
}
void Test::deleteTestService()
{
	Repository<List> repo;
	Validator val;
	Service srv{ repo, val };
	Car car1{ "223","Toyota","x345", "family" };
	Car car2{ "245", "Audi", "24", "trip" };
	Car car3{ "fe2","Opel", "3446", "family" };
	srv.addNewElementService(car1);
	srv.addNewElementService(car2);
	srv.addNewElementService(car3);
	assert(srv.getSizeRepo() == 3);

	srv.deleteElementService("245");
	assert(srv.getSizeRepo() == 2);

	Car car = srv.getElementService(1);
	assert(car.getRegistration() == "fe2");
	assert(car.getModel() == "3446");
	assert(car.getManufacturer() == "Opel");
	assert(car1.getType() == "family");

	bool ExceptionThrown = false;
	try {
		srv.deleteElementService(" ");
	}
	catch (std::exception&)
	{
		ExceptionThrown = true;
	}
	assert(ExceptionThrown);
}
void Test::updateTestService()
{
	Repository<List> repo;
	Validator val;
	Service srv{ repo, val };
	Car car1{ "223","Toyota","x345", "family" };
	Car car2{ "245", "Audi", "24", "trip" };
	Car car3{ "fe2","Opel", "3446", "family" };
	srv.addNewElementService(car1);
	srv.addNewElementService(car2);
	srv.addNewElementService(car3);
	assert(srv.getSizeRepo() == 3);


	srv.updateManufacturerService("245", "Mercedes");
	srv.updateModelService("245", "1234");
	srv.updateTypeService("245", "Family");

	Car car = srv.getElementService(1);
	assert(car.getModel() == "1234");
	assert(car.getManufacturer() == "Mercedes");
	assert(car.getType() == "Family");

	
}

void Test::searchElement()
{
	Repository<List> repo;
	Validator val;
	Service srv{ repo, val };
	Car car1{ "223","Toyota","x345", "family" };
	Car car2{ "245", "Audi", "24", "trip" };
	Car car3{ "fe2","Opel", "3446", "family" };
	srv.addNewElementService(car1);
	srv.addNewElementService(car2);
	srv.addNewElementService(car3);
	assert(srv.getSizeRepo() == 3);

	int pos = srv.searchElement("223");
	assert(pos == 0);

	bool exceptionThrown = 0;
	try
	{
		srv.searchElement("34536ff");

	}
	catch (const std::exception&)
	{
		exceptionThrown = 1;
	}
	assert(exceptionThrown);

}

void Test::filterTests()
{
	Repository<List> repo;
	Validator val;
	Service srv{ repo, val };
	Car car1{ "223","Toyota","x345", "family" };
	Car car2{ "245", "Audi", "24", "trip" };
	Car car3{ "fe2","Audi", "3446", "family" };
	srv.addNewElementService(car1);
	srv.addNewElementService(car2);
	srv.addNewElementService(car3);

	assert(srv.filterByManufacturer("Audi").size() == 2);
	assert(srv.filterByType("family").size() == 2);
	assert(srv.filterByType("i").size() == 0);
	assert(srv.filterByType("sport").size() == 0);

}

void Test::sortTests()
{
	Repository<List> repo;
	Validator val;
	Service srv{ repo, val };
	Car car1{ "223","Toyota","x345", "family" };
	Car car2{ "245", "Audi", "24", "trip" };
	Car car3{ "fe2","Audi", "3446", "family" };
	srv.addNewElementService(car1);
	srv.addNewElementService(car2);
	srv.addNewElementService(car3);

	std::vector<Car> sortedVector;
	sortedVector = srv.sortRegistrationNumber();
	Car car = srv.getElementService(1);
	assert(car.getModel() == "24");
	assert(car.getManufacturer() == "Audi");
	assert(car.getType() == "trip");


	sortedVector = srv.sortType();
	car = sortedVector.at(1);

	assert(car.getModel() == "3446");
	assert(car.getManufacturer() == "Audi");
	assert(car.getType() == "family");
	

	sortedVector = srv.sortManufacturerModel();
	car = sortedVector.at(1);
	
	assert(car.getModel() == "3446");
	assert(car.getManufacturer() == "Audi");
	assert(car.getType() == "family");
}




