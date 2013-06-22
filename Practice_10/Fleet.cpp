#include "Fleet.h"
#include "SpaceShipFactory.h"

#include <fstream>
#include <assert.h>
#include <iostream>

Fleet::Fleet(const std::string& fleetFilename)
{

	// TODO:
	// * Open textfile in "fleetFilename"
	// * Parse line by line:
	// ** Seperate in shipname and parameter at the first ' '
	// ** call SpaceShipFactory::getInstance().buildSpaceShip
	// ** push into m_spaceShips if a new ship was successfully created

	std::vector<std::string> out = this->loadContent(fleetFilename);

	for(int i = 0; i < out.size(); i += 2)
		SpaceShipFactory::getInstance().buildSpaceShip(out.at(i), out.at(i + 1));

}


std::vector<std::string> Fleet::loadContent(const std::string& fileName)
{

	std::ifstream file;
	std::vector<std::string> out;
	std::string c;

	//open file
	file.open("../../"+fileName, std::ios::in);

	//read it out (line by line)
	while(!file.eof())
	{
		std::getline(file, c);
		this->parseLine(c, out);
	}

	//close it
	file.close();

	return out; 
}

void Fleet::parseLine(std::string string, std::vector<std::string>& vector)
{
	//search for first space
	unsigned int spaceFound = string.find_first_of(" ");
	std::string part = "";

	//get substring until space
	for(int i = 0; i < spaceFound; ++i)
		part += string[i];

	vector.push_back(part);
	part.clear();

	//get substring after space
	for(int i = spaceFound+1; i < string.length(); ++i)
		part += string[i];

	vector.push_back(part);
}