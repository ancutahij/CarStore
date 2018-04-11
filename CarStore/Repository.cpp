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
	int position = getPosition( registrationNr);
	m_allElements.erase(m_allElements.begin()+position);
}
/*
	Return the element from the given position.
*/
Car& Repository::getElement(const int& position)
{
	return m_allElements.at(position);
}


/*
	An attribute of an element if changed.
*/
void Repository::updateElement( const std::string& attribute, setterFunction setAttribute)
{
	//setAttribute(attribute);
	Car car = getElement(2);
	//std::invoke(car, setAttribute, attribute);
	//car.*setAttribute(attribute);
}

/*
	Return position for an element from the vector
*/
int Repository::getPosition(const std::string & registrationNr) 
{
	auto pred = [registrationNr](const Car & item) {
		return item.getRegistration()== registrationNr;
	};
	auto it = std::find_if(m_allElements.begin(), m_allElements.end(), pred);

	if (it == m_allElements.end())
	{
		// car not in vector
	}
	
	auto index = std::distance(m_allElements.begin(), it);
	return index;
	
	
}
int Repository::getSize()
{
	return m_allElements.size();

}


