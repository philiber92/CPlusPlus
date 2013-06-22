#include "SpaceShipFactory.h"

// If SpaceShips.h would be not included, the SpaceShip's destructor would be unknown.
// This leads normally to a warning
#include "SpaceShips.h"

void SpaceShipFactory::registerSpaceShip(const std::string& spaceShipTypeName, const CreateSpaceShipFunc& createSpaceShipFunc)
{
	//check if class type is already defined
	std::unordered_map<std::string, CreateSpaceShipFunc>::const_iterator got = this->m_createSpaceShipFuncRegister.find (spaceShipTypeName);
	if(got != this->m_createSpaceShipFuncRegister.end())
		throw new std::exception;

	//register space ship
	std::pair<std::string, CreateSpaceShipFunc> temp (spaceShipTypeName,createSpaceShipFunc);
	this->m_createSpaceShipFuncRegister.insert(temp);
}

std::shared_ptr<SpaceShip> SpaceShipFactory::buildSpaceShip(const std::string& spaceShipTypeName, const std::string& parameter)
{
	//check if class type is already defined
	std::unordered_map<std::string, CreateSpaceShipFunc>::const_iterator got = this->m_createSpaceShipFuncRegister.find (spaceShipTypeName);
	if(got == this->m_createSpaceShipFuncRegister.end())
		return nullptr;

	//calling registered class
	return this->m_createSpaceShipFuncRegister.at(spaceShipTypeName)(parameter);
}