#include "Functions.h"
#include <iostream>

// the main function
int main(int numArguments, char** arguments)
{
	if(numArguments != 2)
	{
		std::cerr << "Expected filename as first argument!";
		return 1;
	}

	// read file
	std::cout << "Reading file \"" << arguments[1] << "\"." << std::endl;
	std::string fileAsString = readFileToString(arguments[1]);
	if(fileAsString.empty())
	{
		std::cerr << "Error reading file!\n" << std::endl;
		return 1;
	}

	// break down into items
	Table table = itemArrayFromCSV(fileAsString);

	// print table
	std::cout << std::endl;
	printTable(table);

	return 0;
}