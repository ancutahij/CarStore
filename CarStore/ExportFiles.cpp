#include"ExportFiles.h"
#include<iostream>
#include"Validator.h"
/*
	Export the entire basket of cars to a HTML file where data are stocked in a table.
*/
void Export::exportHTML(const std::string& fileName, const std::vector<Car>& carsBasket)
{
	std::ofstream out(fileName, std::ios::trunc);
	
	if (!out.is_open()) {
		throw ElementException("Unable to open file:" + fileName);
	}
	out << "<html><head>" << std::endl;
	
	out << "<style> ";
	out << "tr:hover {background-color:#f5f5f5;}";
	out << "table { border-collapse: collapse; width: 100% ; }";
	out << " th, td { padding: 8px; text-align: left; border-bottom: 1px solid #ddd};";
	out<<"</style></head><body>";
	//out << "<table border=\"1\" style=\"width:100 % \">" << std::endl;
	out << "<table><tr>" << std::endl;
	out << "<th>" << "REGISTRATION NUMBER" << "</th>" << std::endl;
	out << "<th>" << "MANUFACTURER" << "</th>" << std::endl;
	out << "<th>" << "MODEL" << "</th>" << std::endl;
	out << "<th>" << "TYPE" << "</th>" << std::endl;
	out << "</tr>" << std::endl;
	for (const auto& c : carsBasket) {
		out << "<tr>" << std::endl;
		out << "<td>" << c.getRegistration() << "</td>" << std::endl;
		out << "<td>" << c.getManufacturer()<< "</td>" << std::endl;
		out << "<td>" << c.getModel() << "</td>" << std::endl;
		out << "<td>" << c.getType() << "</td>" << std::endl;
		out << "</tr>" << std::endl;
	}
	out << "</table>" << std::endl;
	out << "</body></html>" << std::endl;
	out.close();
	
}