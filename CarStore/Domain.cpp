#include"Domain.h"

std::string Car::getRegistration() const
{
	return this->m_registrationNumber;
}
std::string Car::getManufacturer() const
{
	return this->m_manufacturer;
}
std::string Car::getModel() const
{
	return this->m_model;
}
std::string Car::getType() const
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

