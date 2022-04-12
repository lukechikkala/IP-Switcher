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
	Networks += NICs;
/*
############################################################
WORKING EXAMPLE
############################################################
*/
	// int Network_Size = sizeof(NICs);	// 218 at the moment
	// std::string Network_List[10];
	// for (int i = 0 ; i < Network_Size ; i++)
	// {
	// 	if(NICs[i] == '\n')
	// 	{
	// 		Networks = Networks.substr(0, Networks.find('p'));
	// 		// Network_List[i] = Networks;
	// 	}
	// }
/*
############################################################
END OF WORKING EXAMPLE
############################################################
*/


/*
############################################################
TRYING TO CATCH THE LAST NEW LINE; BUT THIS IS BEING A PAIN IN THE ASS
############################################################
*/

	std::cout << Networks << std::endl;
	std::cout << "==========================" << std::endl;
	std::size_t found = Networks.find_last_of('\n');
	std::string NewNetwork = Networks.substr(found-10);
	std::cout << NewNetwork << std::endl;
	// std::cout << Network_List[1] << std::endl;
}