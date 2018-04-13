#include<vector>
#include"Domain.h"
#pragma once

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
		//std::cout << " COPY \n";
	}

	~Repository() {}

	void addNewElement(const Car& element);
	void deleteElement(const std::string& registrationNr);
	void updateElement(const std::string& registrationNr,const std::string& attribute, setterFunction setAttribute);
	int getPosition(const std::string & registrationNr);
	int getSize() noexcept;

	Car& getElement(const int& position);
	std::vector<Car> getAll() const ;
};