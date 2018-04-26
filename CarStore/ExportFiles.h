#include<vector>
#include<string>
#include<fstream>
#include"Domain.h"
#pragma once

class Export
{
public:
	static void exportHTML(const std::string& fileName, const std::vector<Car>& carsBasket);
};