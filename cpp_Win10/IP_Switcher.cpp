#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <windows.h>

int main()
{
//	-- Variables --------------------------------------------------------------------------------------------------------------------------------------
	std::fstream	TempNICList,				// File-type variable to handle NICs.txt [ stores the output of "netsh interface show interface" ]
					AvailableNICList;			// File-type variable to handle AvailableNICList.txt [ filters NICs.txt to show only enabled NICs ]
	std::string		AvailableNICs,				// 
					NICs[10];					// 
	std::regex		RegularExpression(".*  ");	// 
	int				i		= 0,				// 
					NICID	= 0,				// 
					UserInput_NIC;				// 
//	---------------------------------------------------------------------------------------------------------------------------------------------------



//	-- Get All NIC ------------------------------------------------------------------------------------------------------------------------------------
	system("netsh interface show interface > NICs.txt");
//	---------------------------------------------------------------------------------------------------------------------------------------------------



//	-- Store Active NICs ------------------------------------------------------------------------------------------------------------------------------
	TempNICList.open("NICs.txt", std::ios::in);
	if ( TempNICList.is_open() )
	{
		std::string line;
		while ( getline( TempNICList , line ) )
		{
			if ( line.find ("Enabled" ) != std::string::npos )
			{
				AvailableNICs = std::regex_replace(line, RegularExpression, "");
				NICs[NICID] = AvailableNICs;
				NICID = NICID + 1;
			}
		}
		TempNICList.close();
	}

	AvailableNICList.open("AvailableNICList.txt", std::ios::out);
	AvailableNICList << AvailableNICs;
	AvailableNICList.close();
//	---------------------------------------------------------------------------------------------------------------------------------------------------



//	-- TITLE ------------------------------------------------------------------------------------------------------------------------------------------
	std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓"	<< std::endl;
	std::cout << "┃ ██╗██████╗     ███████╗██╗    ██╗██╗████████╗ ██████╗██╗  ██╗███████╗██████╗  ┃"	<< std::endl;
	std::cout << "┃ ██║██╔══██╗    ██╔════╝██║    ██║██║╚══██╔══╝██╔════╝██║  ██║██╔════╝██╔══██╗ ┃"	<< std::endl;
	std::cout << "┃ ██║██████╔╝    ███████╗██║ █╗ ██║██║   ██║   ██║     ███████║█████╗  ██████╔╝ ┃"	<< std::endl;
	std::cout << "┃ ██║██╔═══╝     ╚════██║██║███╗██║██║   ██║   ██║     ██╔══██║██╔══╝  ██╔══██╗ ┃"	<< std::endl;
	std::cout << "┃ ██║██║         ███████║╚███╔███╔╝██║   ██║   ╚██████╗██║  ██║███████╗██║  ██║ ┃"	<< std::endl;
	std::cout << "┃ ╚═╝╚═╝         ╚══════╝ ╚══╝╚══╝ ╚═╝   ╚═╝    ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ ┃"	<< std::endl;
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"	<< std::endl;
	std::cout << "                            ╭──────────────────────╮ "								<< std::endl;
	std::cout << "                            │ " << NICID << " NICs are available │ "					<< std::endl;
	std::cout << "                            ╰──────────────────────╯ "								<< std::endl;
//	---------------------------------------------------------------------------------------------------------------------------------------------------



//	-- Display NICs -----------------------------------------------------------------------------------------------------------------------------------
	for ( i = 0 ; i < NICID ; i++ )
	{
		std::cout << "\t[" << i << "]\t" << NICs[i] << std::endl;
	}
//	---------------------------------------------------------------------------------------------------------------------------------------------------



//	-- NIC Input --------------------------------------------------------------------------------------------------------------------------------------
	std::cout << "\nChoose NIC: ";
	std::cin >> UserInput_NIC;
	std::cout << "You chose " << NICs[UserInput_NIC] << std::endl;
//	---------------------------------------------------------------------------------------------------------------------------------------------------



//	-- CleanUp ----------------------------------------------------------------------------------------------------------------------------------------
	system("del NICs.txt");
	for ( i = 0 ; i < 5 ; i++ )
	{
		std::cout << 5-i << std::endl;
		Sleep(1000);
	}
//	---------------------------------------------------------------------------------------------------------------------------------------------------



}

/*
	Active Network Interfaces are logged into the file, AvailableNICsList.txt.
	For now, as a demo, the program shows a list of NICs but this needs to be referencable to a NIC
	ID.
	Having this, will allow for the user to choose a number tied to a NIC and perform the proceeding
	operations on that specific NIC.
*/