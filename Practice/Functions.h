#include <vector>
#include <string>

/// \brief List of List of strings, representing a table
typedef std::vector<std::vector<std::string>> Table;

/// \brief		Reads an entire file into a std::string.
/// \details	Uses std::fstream to read the file.
/// \param	filename	Filename of the file to read. Can be a relative path.
/// \return				String containing the whole file.
std::string readFileToString(const std::string& filename);

/// \brief		Splits an incoming CSV file up into its single items
/// \details	Uses regular expressions to split up the incoming string. Assumes that there are NO emtpy entries!
/// \param	csv		A CSV as string.
/// \return				A vector of vectors containing all (csv-)table items.
Table itemArrayFromCSV(const std::string& csv);

/// \brief Prints a csv table to the console.
/// \param table	table consisting out of list of list of strings (=items)
void printTable(const Table& tableItems);

void escapeStrings(std::string& string);