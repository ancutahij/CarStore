#include"Repository.h"
#include<functional>
#include<vector>
#include<algorithm>
#pragma once
#pragma warning (disable: 4267)
typedef int(*SortFunction)(const Car&, const Car&);
class Service
{
	Repository m_repo;
public:
	Service(const Repository& repo)
	{
		m_repo = repo;
	}

	/*Service()
	{
		m_repo = Repository
	}
	*/
	~Service() {}

	//Service(const Service& srv) = delete;

	void addNewElementService(const Car& element);
	void deleteElementService(const std::string& registrationNr);
	void updateManufacturerService(const std::string& registrationNr, const std::string& attribute);
	void updateTypeService(const std::string& registrationNr, const std::string& attribute);
	void updateModelService(const std::string& registrationNr, const std::string& attribute);
	int getSizeRepo() ;
	Car& getElementService(const int& position);
	int searchElement(const std::string& registrationNumber);
	std::vector<Car> filterElements(std::function<int(const Car&)> fct) const; 
	std::vector<Car> filterByManufacturer(const std::string& attribute) const;
	std::vector<Car> filterByType(const std::string& attribute) const;
	std::vector<Car> sortElements(SortFunction fct) const;
	std::vector<Car> sortRegistrationNumber() const;
	std::vector<Car> sortType() const;
	std::vector <Car> sortManufacturerModel() const;
};

