#include"Service.h"

/*
	Add a new element to the list
	Exception are thrown in repository class
*/
void Service::addNewElementService(const Car& element)
{
	m_val.isValidElement(element);
	m_repo.addNewElement(element);
}

/*
	Delete an element by its registration number
	Exception are thrown in repository class

*/
void Service::deleteElementService(const std::string& registrationNr)
{
	m_val.isValidRegistrationNR(registrationNr);
	m_repo.deleteElement(registrationNr);
}

/*
	Update manufacturer field for an element
	Exception are thrown in repository class

*/
void Service::updateManufacturerService(const std::string& registrationNr, const std::string& attribute)
{
	m_val.isValidRegistrationNR(registrationNr);
	m_val.isValidManufacturer(attribute);
	m_repo.updateElement(registrationNr, attribute, &Car::setManufacturer);
}

/*
	Update type field for an element
	Exception are thrown in repository class

*/
void Service::updateTypeService(const std::string& registrationNr, const std::string& attribute)
{

	m_val.isValidRegistrationNR(registrationNr);
	m_val.isValidType(attribute);
	m_repo.updateElement(registrationNr, attribute, &Car::setType);

}

/*
	Update model field for an element
	Exception are thrown in repository classs
*/
void Service::updateModelService(const std::string& registrationNr, const std::string& attribute)
{

	m_val.isValidRegistrationNR(registrationNr);
	m_val.isValidModel(attribute);
	m_repo.updateElement(registrationNr, attribute, &Car::setModel);
}

/*
	Get current size of elements list.
*/
int Service::getSizeRepo() const
{
	return m_repo.getSize();
}

/*
	Get element from a position
*/
Car& Service::getElementService(const int& position) const
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
	for (int i = 0; i < getSizeRepo(); i++)
	{
		Car car = m_repo.getElement(i);
		if (fct(car))
		{
			rez.push_back(car);
		}
	}

	return rez;
}
/*
Return a vector that contains all cars that their manufacturer contains the substring: attribute

*/
std::vector<Car> Service::filterByManufacturer(const std::string& attribute) const
{
	m_val.isValidManufacturer(attribute);
	return filterElements([attribute](const Car& car)
	{return car.getManufacturer() == attribute; });

}

/*
Return a vector that contains all cars that their type contains the substring: attribute

*/
std::vector<Car> Service::filterByType(const std::string& attribute) const
{
	m_val.isValidType(attribute);
	return filterElements([attribute](const Car& car)
	{return car.getType() == attribute; });

}
/*
	General sort function.
	This function can be applied for sorting after register number, type and manufacturer+ model
*/
std::vector<Car> Service::sortElements(SortFunction fct) const
{
	std::vector<Car> rez;
	for (int i = 0; i < getSizeRepo(); i++)
	{
		Car car = getElementService(i);
		rez.push_back(car);
	}

	std::sort(rez.begin(), rez.end(), fct);
	return rez;
}

/*
	Use general sort function defined above.
	Sort ascending after register number
*/
std::vector<Car> Service::sortRegistrationNumber() const
{
	return sortElements([](const Car& c1, const Car& c2)
	{
		int rez = c1.getRegistration().compare(c2.getRegistration());
		return rez == -1 ? 1 : 0;
	});
}

/*
	
	Use general sort function defined above.
	Sort ascending after type.
*/
std::vector<Car> Service::sortType() const
{
	return sortElements([](const Car& c1, const Car &c2)
	{
		int rez = c1.getType().compare(c2.getType());
		return rez == -1 ? 1 : 0;
	});
}

/*
	
	Use general sort function defined above.
	Sort ascending after manufacturer + model.
*/
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
