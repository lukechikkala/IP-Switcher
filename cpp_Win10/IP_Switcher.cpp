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
				AvailableNICs = std::regex_replace(line, RegularExpression, "");
			}
		}
		TempNICList.close();
	}

	AvailableNICList.open("AvailableNICList.txt", std::ios::out);
	AvailableNICList << AvailableNICs;
	AvailableNICList.close();
	system("del NICs.txt");

	std::cout << "Choose NIC: " << std::endl;
	std::cout << AvailableNICs << std::endl;
}

/*
	Active Network Interfaces are logged into the file, AvailableNICsList.txt.
	For now, as a demo, the program shows a list of NICs but this needs to be referencable to a NIC
	ID.
	Having this, will allow for the user to choose a number tied to a NIC and perform the proceeding
	operations on that specific NIC.
*/