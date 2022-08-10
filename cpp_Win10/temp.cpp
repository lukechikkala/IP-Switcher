#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main()
{
	std::fstream	TempNICList,
					AvailableNICList;

	std::string		AvailableNICs;

	std::regex		RegularExpression(".* ");

	system("netsh interface show interface > NICs.txt");
	TempNICList.open("NICs.txt", std::ios::in);
	if ( TempNICList.is_open() )
	{
		std::string line;
		while ( getline( TempNICList , line ) )
		{
			if ( line.find ("Enabled" ) != std::string::npos )
			{
				std::cout << std::regex_replace(line, RegularExpression, "") << std::endl;
				AvailableNICs = std::regex_replace(line, RegularExpression, "");
			}
		}
		TempNICList.close();
	}

	AvailableNICList.open("AvailableNICList.txt", std::ios::out);
	AvailableNICList << AvailableNICs;
	AvailableNICList.close();

	system("del NICs.txt");
}