#include<exception>
#include<algorithm>
#include"Domain.h"
#pragma once
#pragma warning (disable: 4244)
/*
Exception class for elements with car type
*/
class ElementException : public std::exception
{
private:
	std::string m_exception;
public:
	ElementException(std::string exception)
		:m_exception(exception)
	{
		for (auto & c : m_exception) c = toupper(c);
	}
	const char*  what() { return m_exception.c_str(); }  //  return the std::string as a const C-style string
};

class Validator
{
public:
	Validator() {}
	void isValidRegistrationNR(const std::string&) const;
	void isValidManufacturer(const std::string&) const;
	void isValidModel(const std::string&) const;
	void isValidType(const std::string&) const;
	void isValidElement(const  Car&) const;
	void isNumber(const std::string&) const;
};
