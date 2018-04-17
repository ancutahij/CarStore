#include<string>
#include<iostream>
#pragma once
class Car 
{
	std::string m_registrationNumber;
	std::string m_manufacturer;
	std::string m_model;
	std::string m_type;

public:

	Car(std::string registrationNumber, std::string manufacturer, std::string model, std::string type)
		: m_registrationNumber(registrationNumber), m_manufacturer(manufacturer), m_model(model), m_type(type){}

	// using dalegating constructor to minimize redundant code
	Car() : Car(" ", " ", " ", " ")  {} 

	~Car() {} 

	Car(const Car& original)
		: m_registrationNumber(original.m_registrationNumber), m_manufacturer(original.m_manufacturer), m_model(original.m_model), m_type(original.m_type)
	{
	}

	// Overloading needed operators
	friend std::ostream& operator<<(std::ostream& out, const Car& car) ;
	Car& operator=(const Car& newCar);

	std::string getRegistration() const;
	std::string getManufacturer() const;
	std::string getModel() const;
	std::string getType() const;

	void setRegistration(const std::string& registrationNr);
	void setManufacturer(const std::string& manufacturer);
	void setModel(const std::string& model);
	void setType(const std::string& type);

};