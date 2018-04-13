#include"UserInterface.h"
#include <typeinfo>

std::string Console::getUserInput()
{
	std::string option;
	std::cin >> option;
	return option;
}
void Console::ui()
{
	while (true)
	{
		std::cout << "\n\n ==MENU==\n 1.Print\n 2.Add\n 3.Delete\n 4.Update\n 5.Search\n 6.Filter\n 7.Sort\n -1.Exit\n ";
		std::cout << "\n Option: ";
		std::string option = getUserInput();

		if (std::stoi(option) == OptionMenu::EXIT)// convert string to int type
			break;
		switch (std::stoi(option))
		{
		case OptionMenu::ADD:
			addElement();
			break;
		case OptionMenu::PRINT:
			printElements();
			break;
		case OptionMenu::DELETE:
			if (m_srv.getSizeRepo())
				deleteElement();
			else
				std::cout << "\n\t There are no cars.\n";
			break;
		case OptionMenu::UPDATE:
			if (m_srv.getSizeRepo())
				updateElement();
			else
				std::cout << "\n\t There are no cars.\n";
			break;
		case OptionMenu::SEARCH:
			if (m_srv.getSizeRepo())
				searchElement();
			else
				std::cout << "\n\t There are no cars.\n";

			break;
		case OptionMenu::FILTER:
			if (m_srv.getSizeRepo())
				filterElements();
			else
				std::cout << "\n\t There are no cars.\n";
			break;
		case OptionMenu::SORT:
			if (m_srv.getSizeRepo())
				sortElements();
			else
				std::cout << "\n\t There are no cars.\n";
			break;

		default:
			std::cout << "\n\t INVALID OPTION \n";
		}
	}
}

/*
	Get user inputs and add a new car to the vector
*/
void Console::addElement()
{
	std::string regNr, manufacturer, model, type;
	std::cout << "Give registration number:";
	regNr = getUserInput();
	std::cout << "Give manufacturer:";
	manufacturer = getUserInput();
	std::cout << "Give model:";
	model= getUserInput();
	std::cout << "Give type:";
	type= getUserInput();

	Car car{ regNr,manufacturer, model, type };
	m_srv.addNewElementService(car);

}

/*
	Display on the screen all cars
*/
void Console::printElements()
{
	const int size = m_srv.getSizeRepo();
	if (!size)
		std::cout << "\t THERE ARE NO CARS FOR PRINTING \n";
	else
		for (int i = 0; i < size; i++)
			std::cout << m_srv.getElementService(i);
}

/*
	Delete element by its register number
*/
void Console::deleteElement()
{
	std::string regNr;
	std::cout << "Give registration number:";
	regNr = getUserInput();
	
	m_srv.deleteElementService(regNr);
}
/*
	Update an element's field. 
	The field can be manufacturer, type or model
*/
void Console::updateElement()
{
	while (true)
	{
		std::cout << "\n\n ==MENU UPDATE==\n 1.Update by Manufacturer\n 2.Update by Type\n 3.Update by Model\n -1.Exit\n ";
		std::cout << "\n Option: ";
		std::string option = getUserInput();
		
		if (std::stoi(option) == OptionMenu::EXIT)// convert string to int type
			break;

		std::cout << "\n Attribute: ";
		std::string attribute = getUserInput();
		std::string regNr;
		std::cout << " Registration number:";
		regNr = getUserInput();


		switch (std::stoi(option))
		{
		case OptionUpdate::byMANUFACTURER:
			m_srv.updateManufacturerService(regNr, attribute);
			break;
		case OptionUpdate::byMODEL:
			m_srv.updateModelService(regNr, attribute);
			break;
		case OptionUpdate::byTYPE:
			m_srv.updateTypeService(regNr, attribute);
			break;
		default:
			std::cout << "\n\t INVALID OPTION \n";
		}
	}
	
}

/*
	Print out on the screen the car that has the given register number.
*/
void Console::searchElement()
{
	std::string regNr;
	std::cout << " Registration number:";
	regNr = getUserInput();

	const int pos = m_srv.searchElement(regNr);

	if (pos < 0)
		std::cout << "\n\t Car couldn't be found.\n";
	else
		std::cout << m_srv.getElementService(pos);

}

/*
	Filter elements by a key
*/
void Console::filterElements()
{
	while (true)
	{
		std::cout << "\n\n ==MENU Filter==\n 1.Filter by Manufacturer\n 2.Filter by Type\n -1.Exit\n ";
		std::cout << "\n Option: ";
		std::string option = getUserInput();

		if (std::stoi(option) == OptionMenu::EXIT)// convert string to int type
			break;

		std::cout << "\n Attribute: ";
		std::string attribute = getUserInput();
		std::vector<Car> rez;

		switch (std::stoi(option))
		{
		case OptionFilter::MANUFACTURER:
			rez= m_srv.filterByManufacturer(attribute);
			for (int i = 0; i < rez.size(); i++)
				std::cout << rez.at(i)<<"\n";
			break;
		case OptionFilter::TYPE:
			rez=m_srv.filterByType(attribute);
			for (int i = 0; i < rez.size(); i++)
				std::cout << rez.at(i)<<"\n";
			break;
		default:
			std::cout << "\n\t INVALID OPTION \n";
		}
	}
}

/*
	Sort elements by a key
*/
void Console::sortElements()
{
	while (true)
	{
		std::cout << "\n\n ==MENU Sort==\n 1.Sort by Register Number\n 2.Sort by Type\n 3.Sort by Manufacturer+Model\n -1.Exit\n ";
		std::cout << "\n Option: ";
		std::string option = getUserInput();

		if (std::stoi(option) == OptionMenu::EXIT)// convert string to int type
			break;

		std::cout << "\n Attribute: ";
		std::string attribute = getUserInput();
		std::vector<Car> rez;

		switch (std::stoi(option))
		{
		case OptionSort::sortREGISTRATION:
			rez = m_srv.sortRegistrationNumber();
			for (int i = 0; i < rez.size(); i++)
				std::cout << rez.at(i) << "\n";
			break;
		case OptionSort::sortTYPE:
			rez = m_srv.sortType();
			for (int i = 0; i < rez.size(); i++)
				std::cout << rez.at(i) << "\n";
			break;
		case OptionSort::sortMANUFACTURER_MODEL:
			rez = m_srv.sortManufacturerModel();
			for (int i = 0; i < rez.size(); i++)
				std::cout << rez.at(i) << "\n";
			break;
		default:
			std::cout << "\n\t INVALID OPTION \n";
		}
	}
}