#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *cmd = popen("networksetup -listallnetworkservices | grep -v \"*\"", "r");			// Stores list of NIC in "cmd"
	static char NICs[1024];
	size_t n;
	while ((n == fread(NICs, 1, sizeof(NICs)-1, cmd)) > 0)
	{
		NICs[n] = '\0';																		// Stores "cmd" in "NICs"
	}
	if (pclose(cmd) < 0)
		perror("ERROR");

	std::string Networks;																// "Networks" of string data type
	// for (int i = 0 ; i < 20 ; i++)
	// {
	// 	std::cout << Networks[i] << std::endl;													// NIC's sample Output
	// 	// if (NICs[i] == '\n')
	// 	// 	std::cout << "BREAK" << std::endl;
	// }
	Networks += NICs;
	int Network_Size = sizeof(NICs);	// 218 at the moment
	// std::cout << Networks << std::endl;
	char val1 = 'A';
	char val2 = 'b';

	for (int i = 0 ; i < Network_Size ; i++)
	{
		if(NICs[i] == '\n')
			std::cout << "GOTCHA" << std::endl;
	}
}