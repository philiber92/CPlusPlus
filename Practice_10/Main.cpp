#include "SpaceShipFactory.h"
#include "SpaceShips.h"
#include "Fleet.h"
#include <sstream>

int main()
{
	// Register SpaceShips by using the SpaceShipFactory::getInstance().registerSpaceShip with lambda functions.

	SpaceShipFactory::getInstance().registerSpaceShip("TieFighter", 
		[](const std::string pilotName){return std::shared_ptr<TieFighter>(new TieFighter(pilotName));});

	SpaceShipFactory::getInstance().registerSpaceShip("DeathStar", 
		[](const std::string buildProgress){return std::shared_ptr<DeathStar>(new DeathStar(stof(buildProgress)));});

	SpaceShipFactory::getInstance().registerSpaceShip("Destroyer", 
		[](const std::string numLasers){std::stringstream str; str << numLasers; int i; str >> i;
										return std::shared_ptr<Destroyer>(new Destroyer(0, i));});

	SpaceShipFactory::getInstance().registerSpaceShip("LargeDestroyer",
		[](const std::string numLasers){std::stringstream str; str << numLasers; int i; str >> i;
										return std::shared_ptr<Destroyer>(new Destroyer(1, i));});

	// Loads fleet from file
	Fleet imperialFleet("imperialships.txt");

	return 0;
}