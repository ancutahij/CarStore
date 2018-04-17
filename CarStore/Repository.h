//#include<vector>
#include<exception>
#include"Domain.h"
#include"LinkedList.h"
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

template <class T>
class Repository
{
	T m_allElements;
public:
	
	Repository() noexcept {} 
	
	/*Repository(const Repository<T>& list)
	{
		Node *temp = new Node;
		temp = list.getAll().begin();
		while (temp != nullptr)
		{
			//m_allElements.push_back(temp->value);
			temp = temp->next;
		}

		delete temp;
	}
	*/
	~Repository() {}

	void addNewElement(const Car& element);
	int getSize() const noexcept  ;
	int getPosition(const std::string & registrationNr);
	void deleteElement(const std::string& registrationNr);
	Car& getElement(const int& position) const ;
	void updateElement(const std::string& registrationNr, const std::string& attribute, setterFunction setAttribute);
	
	
};