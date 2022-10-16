#include <iostream>
#include <windows.h>

//--------------------
// COLOR MACROS
//--------------------
#define color_black  0
#define color_amber  6
#define color_grey   8
#define color_cyan  11
#define color_red   12

void Divider()
{
	int i;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_grey);
	std::cout << " __________________________________________________________\n" << std::endl;
}

void LC_Title()
{
	//	-- TITLE ------------------------------------------------------------------------------------------------------------------------------------------
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_grey);
	std::cout << "  ________________________________________________________ " << std::endl;
	std::cout << " |  ___ ____    ____          _ _       _                 |" << std::endl;
	std::cout << " | |_ _|  _ \\  / ___|_      _(_) |_ ___| |__   ___ _ __   |" << std::endl;
	std::cout << " |  | || |_) | \\___ \\ \\ /\\ / / | __/ __| '_ \\ / _ \\ '__|  |" << std::endl;
	std::cout << " |  | ||  __/   ___) \\ V  V /| | || (__| | | |  __/ |     |" << std::endl;
	std::cout << " | |___|_|     |____/ \\_/\\_/ |_|\\__\\___|_| |_|\\___|_|     |" << std::endl;
	std::cout << " |                                                        |" << std::endl;
	std::cout << " |                                        by lukechikkala |" << std::endl;
	//	---------------------------------------------------------------------------------------------------------------------------------------------------
}

void LC_TotalNICs(int NICID, std::string NICs[10])
{
	int i;

	std::cout << " |________________________________________________________|" << std::endl;
	std::cout << " |                                                        |" << std::endl;
	std::cout << " |                  ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_cyan);
	std::cout << NICID;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_grey);
	std::cout << " NICs are available                  |" << std::endl;

	//	-- Display::NICs -----------------------------------------------------------------------------------------------------------------------------------
	std::cout << " |________________________________________________________|" << std::endl;
	std::cout << " |                                                        |" << std::endl;
	for (i = 0; i < NICID; i++)
	{
		std::cout << " | [";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_cyan);
		std::cout << i + 1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_grey);
		std::cout << "] ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_red);
		std::cout << NICs[i] + std::string(51 - NICs[i].length(), ' ');
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_grey);
		std::cout << "|" << std::endl;
	}
	//	---------------------------------------------------------------------------------------------------------------------------------------------------
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_grey); 
	std::cout << " |________________________________________________________|" << std::endl;
}

void LC_IPModes()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_grey);
	std::cout << "  ________________________________________________________" << std::endl;
	std::cout << " |                                                        | " << std::endl;
	std::cout << " | [";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_cyan);
	std::cout << "1";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_grey);
	std::cout << "] ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_red);
	std::cout << "Static";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_grey);
	std::cout << "                                             | " << std::endl;

	std::cout << " | [";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_cyan);
	std::cout << "2";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_grey);
	std::cout << "] ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_red);
	std::cout << "DHCP";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_grey);
	std::cout << "                                               | " << std::endl;
	std::cout << " |________________________________________________________| " << std::endl;
}
