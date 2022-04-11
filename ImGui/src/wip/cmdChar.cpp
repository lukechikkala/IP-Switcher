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
	FILE *cmd = popen("networksetup -listallnetworkservices | grep -v \"*\"", "r");
	static char NICs[1024];
	size_t n;
	while ((n == fread(NICs, 1, sizeof(NICs)-1, cmd)) > 0)
	{
		NICs[n] = '\0';
	}
	// std::cout << cmd << std::endl;
	if (pclose(cmd) < 0)
		perror("ERROR");

	std::cout << NICs[5] << std::endl;
	std::string Networks[1024];
	for (int i = 0 ; i < 20 ; i++)
	{
		std::cout << NICs[i] << std::endl;
		// if (NICs[i] == '\n')
		// 	std::cout << "BREAK" << std::endl;
	}
}