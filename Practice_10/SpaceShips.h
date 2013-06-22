#pragma once

#include <string>
#include <iostream>

// A Simple hierachy of "SpaceShips"

class SpaceShip
{
public:
	SpaceShip() {}
	virtual ~SpaceShip() {}
};

class DeathStar : public SpaceShip
{
public:
	DeathStar(float buildProgress) :
		buildProgress(buildProgress)
	{
		std::cout << "DeathStar created, completed by " << buildProgress  << " %" << std::endl;
	}

private:
	float buildProgress;
};

class Destroyer : public SpaceShip
{
public:
	/// \param large		true if this is a large Destroyer
	/// \param numLasers	number of lasers carried by this Destroyer
	Destroyer(bool large, int numLasers) : 
		large(large), numLasers(numLasers)
	{
		if(large)
			std::cout << "large ";
		std::cout << "Destroyer created, carrying " << numLasers << " lasers" << std::endl;
	}

private:
	bool large;
	int numLasers;
};

class TieFighter : public SpaceShip
{
public:
	TieFighter(const std::string pilotName) : 
		pilotName(pilotName)
	{
		std::cout << "TieFighter created, piloted by " << pilotName << std::endl;
	}

private:
	std::string pilotName;
};
