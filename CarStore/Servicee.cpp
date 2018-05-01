#include"Service.h"

const std::vector<Car> Service::getAllService() const
{
	return m_repo.getAll();
}
/*
Add a new element to the list
*/
void Service::addNewElementService(const Car& element)
{
	m_val.isValidElement(element);
	m_repo.addNewElement(element);
	UndoActions.push_back(new UndoAddAction{ m_repo, element });
	
}

/*
Delete an element by its registration number
*/
void Service::deleteElementService(const std::string& registrationNr)
{

	m_val.isValidRegistrationNR(registrationNr);
	Car c = getElementService(searchElement(registrationNr));
	m_repo.deleteElement(registrationNr);
	m_basket.deleteCarBascket(c);
	UndoActions.push_back(new UndoDeleteAction{ m_repo, c });

}

/*
Update manufacturer field for an element
*/
void Service::updateManufacturerService(const std::string& registrationNr, const std::string& attribute)
{
	m_val.isValidRegistrationNR(registrationNr);
	m_val.isValidManufacturer(attribute);
	Car c = getElementService(searchElement(registrationNr));
	m_repo.updateElement(registrationNr, attribute, &Car::setManufacturer);
	Car cNew = getElementService(searchElement(registrationNr));
	
	m_basket.updateCarBasket(c, cNew);
	UndoActions.push_back(new UndoUpdateAction{ m_repo, c });

}

/*
Update type field for an element

*/
void Service::updateTypeService(const std::string& registrationNr, const std::string& attribute)
{

	m_val.isValidRegistrationNR(registrationNr);
	m_val.isValidType(attribute);
	Car c = getElementService(searchElement(registrationNr));
	m_repo.updateElement(registrationNr, attribute, &Car::setType);
	Car cNew = getElementService(searchElement(registrationNr));
	m_basket.updateCarBasket(c, cNew);
	UndoActions.push_back(new UndoUpdateAction{ m_repo, c });

}


/*
Update model field for an element
*/
void Service::updateModelService(const std::string& registrationNr, const std::string& attribute)
{

	m_val.isValidRegistrationNR(registrationNr);
	m_val.isValidModel(attribute);
	Car c = getElementService(searchElement(registrationNr));
	m_repo.updateElement(registrationNr, attribute, &Car::setModel);
	Car cNew = getElementService(searchElement(registrationNr));
	m_basket.updateCarBasket(c, cNew);
	UndoActions.push_back(new UndoUpdateAction{ m_repo, c });

}

/*
Get current size of elements list.
*/
int Service::getSizeRepo()
{
	return m_repo.getSize();
}

/*
Get element from a position
*/
Car& Service::getElementService(const int& position)
{
	return m_repo.getElement(position);
}

/*
Search a car in the list of cars by its unique identifier (registration number)
Return car's position if it's found
Otherwise, return -1
*/
int Service::searchElement(const std::string& registrationNumber)
{
	return m_repo.getPosition(registrationNumber);
}

/*
Return a vector that contains all cars that grant the condition
If a car has the needed requirements, it is added in vector

*/
std::vector<Car> Service::filterElements(std::function<int(const Car&)> fct) const
{
	std::vector<Car> rez;
	std::vector<Car> cars = m_repo.getAll();
	std::copy_if(cars.begin(), cars.end(), std::back_inserter(rez), fct);
	// For some reason rez.begin() doesn't work. I used std::back_inserter that makes the same thing

	return rez;
}
/*
Return a vector that contains all cars that their manufacturer contains the substring: attribute

*/
std::vector<Car> Service::filterByManufacturer(const std::string& attribute) const
{
	m_val.isValidManufacturer(attribute);
	return filterElements([attribute](const Car& car) {return car.getManufacturer() == attribute; });

}

/*
Return a vector that contains all cars that their type contains the substring: attribute
*/

std::vector<Car> Service::filterByType(const std::string& attribute) const
{
	m_val.isValidType(attribute);
	return filterElements([attribute](const Car& car) {return car.getType() == attribute; });

}

std::vector<Car> Service::sortElements(SortFunction fct) const
{
	std::vector<Car> rez{ m_repo.getAll() };
	std::sort(rez.begin(), rez.end(), fct);
	return rez;
}

std::vector<Car> Service::sortRegistrationNumber() const
{
	return sortElements([](const Car& c1, const Car& c2)
	{
		int rez = c1.getRegistration().compare(c2.getRegistration());
		return rez == -1 ? 1 : 0;
	});
}

std::vector<Car> Service::sortType() const
{
	return sortElements([](const Car& c1, const Car &c2)
	{
		int rez = c1.getType().compare(c2.getType());
		return rez == -1 ? 1 : 0;
	});
}
std::vector <Car> Service::sortManufacturerModel() const
{
	return sortElements([](const Car& c1, const Car& c2)
	{
		int rez = c1.getManufacturer().compare(c2.getManufacturer());
		if (rez < 0)
			return 1;	else
		{
			if (!rez)
			{
				rez = c1.getModel().compare(c2.getModel());
				return rez == -1 ? 1 : 0;
			}
			else return 0;
		}
	});
}

/*
Add a new car by registration number to the basket.
*/
void Service::addToBasketService(const std::string& registrationNumber)
{
	m_val.isValidRegistrationNR(registrationNumber);
	Car c = getElementService(searchElement(registrationNumber));
	m_basket.addCarToBasket(c);
}
/*
Add nrTimes elements to the basket
Throw exception if nrTimes is less than number of elements in repository or nrTimes isn't a number or is negative
*/
void Service::addRandomToBasket(const std::string& nrTimes)
{
	m_val.isNumber(nrTimes);
	if (getSizeRepo() < std::stoi(nrTimes))
		throw RepositoryException("\n\tTo few elements in repository!");
	std::vector<Car> copy = getAllService();
	m_basket.populateRandom(std::stoi(nrTimes), copy);
}

/*
Delete all elements from basket.
*/
void Service::deleteAllService()
{
	m_basket.deleteAll();
}

/*
Get all elements from basket.
*/
const std::vector<Car>& Service::getAllBasketService() const
{
	return m_basket.getAllBasket();
}

/*
Export all basket elements to a html file.
*/
void Service::exportHtmlFile(const std::string& fileName) const
{
	Export::exportHTML(fileName, m_basket.getAllBasket());
}


/*
Remake the last operation.
*/
void Service::undo()
{
	if (UndoActions.empty())
		throw ElementException("Impossible Undo!");
	UndoAction* act = UndoActions.back();
	act->doUndo();
	UndoActions.pop_back();
	delete act;
}
