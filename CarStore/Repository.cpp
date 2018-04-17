#include"Repository.h"
#include<algorithm>
#pragma warning (disable : 4244)
#pragma warning(disable : 4267)

/*
	Add an element to the end of the vector 
	Firstly verify is the element doesn't already exist in vector. In this case an exception is raised.
*/
template <class T>
void Repository<T>::addNewElement(const Car& element)
{
	try
	{
		getPosition(element.getRegistration());

	}
	catch (const std::exception&)
	{
		m_allElements.push_back(element);
		return;}
	throw RepositoryException("\n\t The car already exists!");

}
/*
	Return the current size of vector
*/
template <class T>
int Repository<T>::getSize() const noexcept 
{
	return m_allElements.size();

}



/*
Return position for an element from vector
Otherwise, raise an exception
*/
template <class T>
int Repository<T>::getPosition(const std::string & registrationNr)
{

	int poz = -1;
	for (int i = 0; i < getSize(); i++)
		if (m_allElements[i].getRegistration() == registrationNr)
		{
			poz = i;
			break;
		}
	return poz>-1 ? poz : throw RepositoryException("\n\t The car couldn't be found!");
}
/*
Delete an element by its registration number using the erase function which is implemented in List class.
Otherwise, raise an exception if an element with given register number can not be found
*/
template <class T>
void Repository<T>::deleteElement(const std::string& registrationNr)
{
	const int position = getPosition(registrationNr);
	m_allElements.erase( position);
}


/*
Return the element from  given position.
*/
template <class T>
Car& Repository<T>::getElement(const int& position) const 
{
	return m_allElements[position];
}


/*
	An attribute of an element is changed.
	The attrbute can be:
	- manufacuter
	- type
	- model
	Otherwise, raise an exception if an element with given register number can not be found.

*/
template <class T>
void Repository<T>::updateElement(const std::string& registrationNr, const std::string& attribute, setterFunction setAttribute)
{
	const int poz = getPosition(registrationNr);
	Car &car = getElement(poz);
	std::invoke(setAttribute, car, attribute); //	It also works this syntax: (car.*setAttribute)(attribute);
}
