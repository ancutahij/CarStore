#include"Repository.h"
#include<fstream>
#pragma once

/*
	A file repository that writes to files and override the functions from base Repository
*/
class FileRepository : public Repository
{
	std::string fileName;
	void loadFromFile();
	void writeToFile();
public:
	FileRepository(const std::string& fileName)
		: Repository(), fileName(fileName)
	{
		loadFromFile();
	}
	
	void addNewElement(const Car& element) override;
	void deleteElement(const std::string& registrationNr) override;
	void updateElement(const std::string& registrationNr, const std::string& attribute, setterFunction setAttribute) override;
};