#pragma once

#include <memory>
#include <string>
#include <functional>
#include <unordered_map>

// predeclaration saves us from including the SpaceShips.h
class SpaceShip;

/// \brief Factory for creating SpaceShip by using a runtime dictionary
class SpaceShipFactory
{
public:
	typedef std::function<std::shared_ptr<SpaceShip>(const std::string& parameter)> CreateSpaceShipFunc;

	/// \brief returns singleton instance
	static SpaceShipFactory& getInstance()
	{
		// compiler will secure that the constructor is only called once
		// most likely by using a flag that will be checked every call
		// see also here: http://stackoverflow.com/questions/246564/what-is-the-lifetime-of-a-static-variable-in-a-c-function
		static SpaceShipFactory instance;
		return instance;
	}

	/// Creates a SpaceShip from typename and string-parameter.
	/// \param spaceShipTypeName	Registered SpaceShip type identifier.
	/// \param parameter			String parameter for the creation of the SpaceShip.
	/// \return shared_ptr to a new buildt spaceship or nullptr if the spaceShipTypeName was not registred.
	std::shared_ptr<SpaceShip> buildSpaceShip(const std::string& spaceShipTypeName, const std::string& parameter);

	/// Makes a SpaceShip known to the factory.
	/// \param spaceShipTypeName	SpaceShip type identifier to register.
	/// \param createSpaceShipFunc	Function for creating the given SpaceShip.
	/// \throw std::exception if the spaceShipTypeName already exists.
	void registerSpaceShip(const std::string& spaceShipTypeName, const CreateSpaceShipFunc& createSpaceShipFunc);

private:
	/// \brief private constructor
	SpaceShipFactory() {}
	/// \brief private copyconstructor
	SpaceShipFactory(SpaceShipFactory const&) {}
	/// \brief private = operator
	void operator=(SpaceShipFactory const&) {}


	/// Dictionary of all known SpaceShips
	std::unordered_map<std::string, CreateSpaceShipFunc> m_createSpaceShipFuncRegister;
};

