#include"Repository.h"
#include<algorithm>
#pragma warning (disable : 4244)
#pragma warning(disable : 4267)

/*
	Add an element to the end of the vector 
*/
void Repository::addNewElement(const Car& element)
{
	m_allElements.push_back(element); 
}
/*
	Delete an element by its registration number using the erase built-in function.
*/
void Repository::deleteElement(const std::string& registrationNr)
{
	const int position = getPosition( registrationNr);
	m_allElements.erase(m_allElements.begin()+position);
}


/*
	An attribute of an element is changed.
*/
void Repository::updateElement(  const std::string& registrationNr,const std::string& attribute, setterFunction setAttribute)
{
	const int poz = getPosition(registrationNr);
	Car &car = getElement(poz);
	std::invoke(setAttribute,car, attribute);
	//	It also works this syntax: (car.*setAttribute)(attribute);
}

/*
Return the element from the given position.
*/
Car& Repository::getElement(const int& position)
{
	return m_allElements.at(position);
}

/*
	Return position for an element from the vector
	Otherwise, return -1
*/
int Repository::getPosition(const std::string & registrationNr) 
{
	auto pred = [registrationNr](const Car & item) {
		return item.getRegistration()== registrationNr;
	};
	auto it = std::find_if(m_allElements.begin(), m_allElements.end(), pred);

	if (it == m_allElements.end())
	{
		return -1;
	}
	
	const auto index = std::distance(m_allElements.begin(), it);
	return index;
	
	
}
int Repository::getSize() noexcept
{
	return m_allElements.size();

}

std::vector<Car> Repository::getAll() const
{
	return m_allElements;
}



