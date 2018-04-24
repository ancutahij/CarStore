#include"Domain.h"

const std::string& Car::getRegistration() const
{
	return this->m_registrationNumber;
}
const std::string& Car::getManufacturer() const
{
	return this->m_manufacturer;
}
const std::string& Car::getModel() const
{
	return this->m_model;
}
const std::string& Car::getType() const
{
	return this->m_type;
}

void Car::setRegistration(const std::string& registrationNr)
{
	this->m_registrationNumber = registrationNr;
}
void Car::setManufacturer(const std::string& manufacturer)
{
	this->m_manufacturer = manufacturer;

}
void Car::setModel(const std::string& model)
{
	this->m_model = model;
}
void Car::setType(const std::string& type)
{
	this->m_type = type;
}
/*
Overloading "<<" operator
*/
std::ostream& operator<<(std::ostream& out, const Car& car)
{
	out << "ID: " << car.m_registrationNumber << " MANUFACTURER: " << car.m_manufacturer << " MODEL: " << car.m_model << " TYPE:" << car.m_type << "\n";
	return out;
}
/*
Overloading assign operator
*/
Car& Car::operator=(const Car& newCar)
{
	setRegistration(newCar.m_registrationNumber);
	setManufacturer(newCar.m_manufacturer);
	setModel(newCar.m_model);
	setType(newCar.m_type);

	return *this;
}

/*
	Overload the "==" operator
*/
bool operator== (const Car& c1, const Car&c2)
{
	return c1.getRegistration() == c2.getRegistration() && c1.getModel() == c2.getModel() && c1.getManufacturer() == c2.getManufacturer() && c1.getType() == c2.getType();
}


