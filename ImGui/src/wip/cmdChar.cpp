#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// // const char* items[] = {
	// // 	"Wi-Fi",
	// // 	"Network Port",
	// // 	"Bluetooth"
	// // 	};
	// const char cmd = system("networksetup -listallnetworkservices | grep -v \"*\"");
	FILE *cmd = popen("networksetup -listallnetworkservices | grep -v \"*\"", "r");			// Stores list of NIC in "cmd"
	static char NICs[1024];
	size_t n;
	while ((n == fread(NICs, 1, sizeof(NICs)-1, cmd)) > 0)
	{
		NICs[n] = '\0';																		// Stores "cmd" in "NICs"
	}
	// std::cout << cmd << std::endl;
	if (pclose(cmd) < 0)
		perror("ERROR");

	std::cout << NICs[5] << std::endl;														// NIC's sample Output
	std::string Networks[1024];																// "Networks" of string data type
	// for (int i = 0 ; i < 20 ; i++)
	// {
	// 	std::cout << Networks[i] << std::endl;													// NIC's sample Output
	// 	// if (NICs[i] == '\n')
	// 	// 	std::cout << "BREAK" << std::endl;
	// }
	Networks[1] = NICs[1];
	std::cout << Networks[1] << std::endl;
}