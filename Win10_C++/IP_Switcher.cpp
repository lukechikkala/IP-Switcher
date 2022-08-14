#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <windows.h>
#include "include/os_cmd.h"								// LC_OS_CMD(std::string cmd);
#include "include/prints.h"								// Title

int main()
{
	LC_OS_CMD("title IP Switcher");
//	-- Variables --------------------------------------------------------------------------------------------------------------------------------------
	std::fstream	TempNICList,						// To handle NICs.txt				[ stores the output of "netsh interface show interface" ]
					AvailableNICList;					// To handle AvailableNICList.txt	[ filters NICs.txt to show only enabled NICs ]
	std::string		AvailableNICs,						// A string to store filtered text from NICs.txt.
					NICs[10],							// An array to map the enabled NICs to allow for selection.
					IPMode[2] = { "Static", "DHCP" },	// 0: Static | 1: DHCP
					line,								// Used to get single line from NICs.txt and store regex-ed version in AvailableNICs as string. 
					StaticIP_cmd,						// Used to execute OS commands for setting static IP Addresses.
					DHCP_cmd,							// Used to execute OS commands for setting DHCP IP Address.
					GetAssignedIPAddresses;				// Used to receive assigned IP Address.
	std::regex		RegularExpression(".*  ");			// Regex used for filtering NICs.txt.
	int				i		= 0,						// Counter.
					NICID	= 0,						// An array for mappaing enabled NICs.
					UserInput_NIC,						// Used to take input from user to select the NIC.
					UserInput_Mode;						// Used to take input from user to select the IP Mode.
//	---------------------------------------------------------------------------------------------------------------------------------------------------



//	-- Get All NIC ------------------------------------------------------------------------------------------------------------------------------------
	LC_OS_CMD("netsh interface show interface > NICs.txt");
//	---------------------------------------------------------------------------------------------------------------------------------------------------



//	-- Store Active NICs ------------------------------------------------------------------------------------------------------------------------------
	TempNICList.open("NICs.txt", std::ios::in);
	if ( TempNICList.is_open() )
	{
		while ( getline( TempNICList , line ) )
		{
			if ( line.find( "Enabled" ) != std::string::npos )
			{
				AvailableNICs = std::regex_replace( line, RegularExpression, "" );
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



//	---------------------------------------------------------------------------------------------------------------------------------------------------
	LC_Title();
	LC_TotalNICs(NICID, NICs);
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
		std::cout << "You chose \"" << IPMode[UserInput_Mode] << "\" Mode" << std::endl;
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
	//  -- IP::1 --------------------------------------------------------------------------------------------------------------------------------------
		StaticIP_cmd = "netsh int ipv4 set address name=\"" + NICs[UserInput_NIC] + "\" static 192.168.1.77 255.255.255.0";
		LC_OS_CMD(StaticIP_cmd.c_str());
	//  -- IP::2 --------------------------------------------------------------------------------------------------------------------------------------
		StaticIP_cmd = "netsh int ipv4 add address name=\"" + NICs[UserInput_NIC] + "\" 2.168.1.77 255.0.0.0";
		LC_OS_CMD(StaticIP_cmd.c_str());
	//  -- IP::3 --------------------------------------------------------------------------------------------------------------------------------------
		StaticIP_cmd = "netsh int ipv4 add address name=\"" + NICs[UserInput_NIC] + "\" 10.168.1.77 255.0.0.0";
		LC_OS_CMD(StaticIP_cmd.c_str());
	//  -- IP::4 --------------------------------------------------------------------------------------------------------------------------------------
		StaticIP_cmd = "netsh int ipv4 add address name=\"" + NICs[UserInput_NIC] + "\" 192.168.0.77 255.255.255.0";
		LC_OS_CMD(StaticIP_cmd.c_str());
	//  -- IP::5 --------------------------------------------------------------------------------------------------------------------------------------
		StaticIP_cmd = "netsh int ipv4 add address name=\"" + NICs[UserInput_NIC] + "\" 192.168.3.77 255.255.255.0";
		LC_OS_CMD(StaticIP_cmd.c_str());
	//  -- IP::6 --------------------------------------------------------------------------------------------------------------------------------------
		StaticIP_cmd = "netsh int ipv4 add address name=\"" + NICs[UserInput_NIC] + "\" 192.168.100.77 255.255.255.0";
		LC_OS_CMD(StaticIP_cmd.c_str());
	//  -----------------------------------------------------------------------------------------------------------------------------------------------
		GetAssignedIPAddresses = "netsh interface ip show config name=\"" + NICs[UserInput_NIC] + "\" | findstr \"IP Address\"";
		for ( i = 0 ; i < 10 ; i++ )
		{
			std::cout << ".";
			Sleep(1000);
		}
		std::cout << "\n";
		LC_OS_CMD(GetAssignedIPAddresses.c_str());
	}
	else if ( UserInput_Mode == 1 )
	{
		DHCP_cmd = "netsh int ipv4 set address name=\"" + NICs[UserInput_NIC] + "\" dhcp";
			 LC_OS_CMD(DHCP_cmd.c_str());
		GetAssignedIPAddresses = "netsh interface ip show config name=\"" + NICs[UserInput_NIC] + "\" | findstr \"IP Address\"";
		for ( i = 0 ; i < 10 ; i++ )
		{
			std::cout << ".";
			Sleep(1000);
		}
		std::cout << "\n";
		LC_OS_CMD(GetAssignedIPAddresses.c_str());
	}
//	---------------------------------------------------------------------------------------------------------------------------------------------------



//	-- CleanUp ----------------------------------------------------------------------------------------------------------------------------------------
	LC_OS_CMD("del NICs.txt");
	LC_OS_CMD("del AvailableNICList.txt");
	std::cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"	<< std::endl;
	Sleep(10000);
	return 0;
//	---------------------------------------------------------------------------------------------------------------------------------------------------
}

/*
	Need testing with active adaptor.
	Need to build safety precautions around "Set" options.
	Check if the network cable is connected in the first place.
	Need better progress bars.
	https://docs.microsoft.com/en-us/windows/win32/cimwin32prov/win32-networkadapter
*/