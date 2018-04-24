#include"Validator.h"
#include<regex>
/*
Checks out if the registration number is valid (that means registration number is not empty)
*/
void Validator::isValidRegistrationNR(const std::string& regNr) const
{
	if (regNr == " ")
		throw ElementException("\n\t Invalid input!");
}

/*
Checks out if the manufacturer field is valid.
Uses a regular expression to verify if the manufacturer field contains only letters.
If other characters(like digits ore special characters) are included in manufacuterer field, an exception is thrown
*/
void Validator::isValidManufacturer(const std::string& manufacturer) const
{


	if (std::regex_search(manufacturer, std::regex("[^a-zA-Z]")) || manufacturer == " ")
		throw ElementException("\n\t invalid input!");

}

/*
Checks out if the model is valid (that means model is not empty)
*/
void Validator::isValidModel(const std::string& model) const
{
	if (model == " ")
		throw ElementException("\n\t Invalid input!");

}

/*

Like manufacturer verification function, it is checked out if the type ( string type ) contains only letters.
*/
void Validator::isValidType(const std::string& type) const
{
	if (std::regex_search(type, std::regex("[^a-zA-Z]")) || type == " ")
		throw ElementException("\n\t invalid input!");

}
/*
Gets a car object and maked a verification for every car's field.
A car contains:
- a registration number
- a manufacturer
- a model
- a type
*/
void Validator::isValidElement(const  Car& car) const
{
	isValidRegistrationNR(car.getRegistration());
	isValidManufacturer(car.getManufacturer());
	isValidType(car.getType());
	isValidModel(car.getModel());
}

/*
	Check out if a string is a positive number using an regex expression.
*/

void Validator::isNumber(const std::string& nr) const
{
	if (std::regex_search(nr, std::regex("[^0-9]")))
		throw ElementException("\n\t invalid input!");

}