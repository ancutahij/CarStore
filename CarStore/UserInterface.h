#include"Service.h"

#pragma once

class Console
{
	Service m_srv;
public:
	Console(const Service& srv)
		: m_srv(srv) {}

	/*
	It's not allowed to copy objects from Console class.
	*/
	//Console(const Console& srv) = delete;

	enum  OptionMenu
	{
		PRINT = 1,
		ADD = 2,
		DELETE = 3,
		UPDATE = 4,
		SEARCH = 5,
		FILTER = 6,
		SORT = 7,
		ADD_TO_BASKET = 8,
		DELETE_ALL = 9,
		POPULATE_RANDOM = 10,
		PRINT_BASKET=11,
		EXIT = -1,
	};

	enum  OptionUpdate
	{
		byMANUFACTURER = 1,
		byMODEL = 2,
		byTYPE = 3,
		IESIRE = -1,
	};

	enum OptionFilter
	{
		MANUFACTURER = 1,
		TYPE = 2,

	};

	enum  OptionSort
	{
		sortREGISTRATION = 1,
		sortTYPE = 2,
		sortMANUFACTURER_MODEL = 3,
	};


	void ui();
	std::string getUserInput();
	void addElement();
	void printElements();
	void deleteElement();
	void updateElement();
	void searchElement();
	void filterElements();
	void sortElements();
	void addToBasketElement();
	void delete_all();
	void populate_randomBasket();

};