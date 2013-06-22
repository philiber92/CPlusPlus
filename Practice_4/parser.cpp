#include "Functions.h"
#include <fstream>
#include <string>
#include <regex>
#include <iostream>
#include <vector>

std::string readFileToString(const std::string& filename)
{
	std::ifstream file;
	std::string out = "";
	std::string c;

	file.open(filename, std::ios::in);

	while(!file.eof())
	{
		std::getline(file, c);
		out+= c;
	}

	file.close();

	return out;
}


Table itemArrayFromCSV(const std::string& csv)
{

	std::regex e("((\")[A-Za-z0-9 ]{1,}(;)[A-Za-z0-9]{1,}(\")(;))|[a-zA-Z0-9 -]*(;){0,1}");

	std::sregex_iterator rit (csv.begin(), csv.end(), e);
	std::sregex_iterator rend;

	Table out;
	std::vector<std::string> vector;
	std::string string;

	const int COLUMN_SIZE = 6;
	int i = 0;

	while(rit!=rend)
	{
		//if empty
		if(rit->str().length()==0) {
			++rit;
			continue;
		}

		++i;
		string = rit->str();
		escapeStrings(string);

		// for each column create a new array
		if(i==COLUMN_SIZE) {

			//split digit out of string and put it in the next column
			if(isdigit(string[string.length()-1])) {

				std::string c = &string[string.length()-1];
				string.pop_back();
				vector.push_back(string);
				out.push_back(vector);
				vector.clear();
				vector.push_back(c);

				//if no more digit exists
			} else {

				vector.push_back(string);
				out.push_back(vector);
				vector.clear();

			}

			i = 1;

		} else
			vector.push_back(string);

		++rit;
	}

	return out;

}

void printTable(const Table& table)
{
	for(unsigned int i = 0; i < table.size(); ++i) {
		for(unsigned int j = 0; j < table[i].size(); ++j)
			std::cout << table[i][j] << " ";
		std:: cout << std::endl;
	}
}

void escapeStrings(std::string& string)
{
	if(string[string.length()-1]==';')
		string.pop_back();

	if(string[0]=='"') {
		string.pop_back();
		string.erase(0, 1);
	}
}