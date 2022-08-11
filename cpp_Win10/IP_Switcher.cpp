#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <windows.h>

int main()
{
//	-- Variables --------------------------------------------------------------------------------------------------------------------------------------
	std::fstream	TempNICList,						// To handle NICs.txt				[ stores the output of "netsh interface show interface" ]
					AvailableNICList;					// To handle AvailableNICList.txt	[ filters NICs.txt to show only enabled NICs ]
	std::string		AvailableNICs,						// A string to store filtered text from NICs.txt.
					NICs[10],							// An array to map the enabled NICs to allow for selection.
					IPMode[2] = { "Static", "DHCP" };	// 0: Static | 1: DHCP
	std::regex		RegularExpression(".*  ");			// Regex used for filtering NICs.txt.
	int				i		= 0,						// Counter.
					NICID	= 0,						// An array for mappaing enabled NICs.
					UserInput_NIC,						// Used to take input from user to select the NIC.
					UserInput_Mode;						// Used to take input from user to select the IP Mode.
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



//	-- Display::NICs -----------------------------------------------------------------------------------------------------------------------------------
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"	<< std::endl;
	for ( i = 0 ; i < NICID ; i++ )
		std::cout << "\t[" << i << "]\t" << NICs[i] << std::endl;
//	---------------------------------------------------------------------------------------------------------------------------------------------------



//	-- Input::NIC -------------------------------------------------------------------------------------------------------------------------------------
	std::cout << "\nChoose NIC: ";
	std::cin >> UserInput_NIC;
	std::cout << "You chose \"" << NICs[UserInput_NIC] << "\"" << std::endl;
//	---------------------------------------------------------------------------------------------------------------------------------------------------



//	-- Display::IPMode --------------------------------------------------------------------------------------------------------------------------------
	std::cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"	<< std::endl;
	std::cout << "\t[0]\t Static" << std::endl;
	std::cout << "\t[1]\t DHCP" << std::endl;
//	---------------------------------------------------------------------------------------------------------------------------------------------------



//	-- Input::IPMode ----------------------------------------------------------------------------------------------------------------------------------
	std::cout << "\nChoose IP Mode: ";
	std::cin >> UserInput_Mode;
	if ( UserInput_Mode == 0 )
	{
		std::cout << "You chose " << IPMode[UserInput_Mode] << std::endl;
	}
	else if ( UserInput_Mode == 1 )
	{
		std::cout << "You chose \"" << IPMode[UserInput_Mode] << "\" Mode" << std::endl;
	}
	else
	{
		return 1;
	}
//	---------------------------------------------------------------------------------------------------------------------------------------------------



//	-- Set::IPMode ------------------------------------------------------------------------------------------------------------------------------------
	std::cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"	<< std::endl;
	std::cout << "Result: " << std::endl;
	if ( UserInput_Mode == 0 )
	{
		std::string StaticIP_cmd = "netsh int ipv4 set address name=\"" + NICs[NICID] + "\" static 192.168.1.77 255.255.255.0";
		std::cout << "\t";
		system(StaticIP_cmd.c_str());
	}
	else if ( UserInput_Mode == 1 )
	{
		std::string DHCP_cmd = "netsh int ipv4 set address \"" + NICs[NICID] + "\" dhcp";
		std::cout << "\t";
		system(DHCP_cmd.c_str());
	}
//	---------------------------------------------------------------------------------------------------------------------------------------------------



//	-- CleanUp ----------------------------------------------------------------------------------------------------------------------------------------
	system("del NICs.txt");
	system("del AvailableNICList.txt");
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"	<< std::endl;
	for ( i = 0 ; i < 5 ; i++ )
	{
		std::cout << 5-i << std::endl;
		Sleep(1000);
	}
//	---------------------------------------------------------------------------------------------------------------------------------------------------
}

/*
	Need testing with active adaptor.
	Need to build safety precautions around "Set" options.
	https://docs.microsoft.com/en-us/windows/win32/cimwin32prov/win32-networkadapter
*/