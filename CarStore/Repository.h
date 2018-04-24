#include<vector>
#include<exception>
#include"Domain.h"
#pragma once
#pragma warning(disable : 4244 )
class RepositoryException : public std::exception
{
	std::string m_exception;
public:
	RepositoryException(std::string exception)
		:m_exception(exception)
	{
		for (auto & c : m_exception)
			c = toupper(c);
	}

	const char* what() { return m_exception.c_str(); }
};


typedef void(Car::*setterFunction)(const std::string& attribute);
class Repository
{
	std::vector<Car> m_allElements;
public:
	Repository(std::vector<Car> allElements)
		:m_allElements(allElements) {}
	Repository() noexcept {}

	Repository(const Repository& list)
	{
		for (const auto& element : list.m_allElements)
			m_allElements.push_back(element);
	}

	~Repository() {}

	void addNewElement(const Car& element);
	void deleteElement(const std::string& registrationNr);
	void updateElement(const std::string& registrationNr, const std::string& attribute, setterFunction setAttribute);
	int getPosition(const std::string & registrationNr);
	int getSize() noexcept;

	Car& getElement(const int& position);
	const std::vector<Car>& getAll() const;
};