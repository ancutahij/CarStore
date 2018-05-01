#include"FileRepository.h"


/*
	We ensure that our file didn't end 

void isEndOfFile(const std::ifstream& in)
{
	if (in.eof())


}
*/

/*
	Load from file the list of all cars and write it to a vector of cars.
*/
void FileRepository::loadFromFile()
{
	std::ifstream in(fileName);
	if (!in.is_open())
	{
		throw RepositoryException("Unable to open file: " + fileName);
	}
	while (!in.eof())
	{
		std::string model, type, manufacturer, registrationNR;
		in >> registrationNR >> manufacturer >> model;
		if (in.eof())
			break;
		in>>type;
		Car car{ registrationNR, manufacturer, model, type };
		Repository::addNewElement(car);
	}
	in.close();
}

/*
	Make the opposite action of loadFromFile function defined above.
	Data are loaded from a vector and are writed to a file.
	An exception is raised if the file couldn't be open properly.

*/
void FileRepository::writeToFile()
{
	std::ofstream out(fileName);
	if (!out.is_open())
	{
		throw RepositoryException("Unable to open file: " + fileName);
	}
	for(const auto&car: getAll())
	{
		out << car.getRegistration()<<"\n";
		out << car.getManufacturer() << "\n";
		out << car.getModel() << "\n";
		out << car.getType() << "\n";
	}
	out.close();

}
void FileRepository::addNewElement(const Car& element) 
{
	Repository::addNewElement(element);
	writeToFile();
}
void FileRepository::deleteElement(const std::string& registrationNr) 
{
	Repository::deleteElement(registrationNr);
	writeToFile();
}
void FileRepository::updateElement(const std::string& registrationNr, const std::string& attribute, setterFunction setAttribute) 
{
	Repository::updateElement(registrationNr, attribute, setAttribute);
	writeToFile();
}

