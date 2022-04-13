#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *GetNICListRaw = popen("networksetup -listallnetworkservices | grep -v \"*\"", "r");
	static char NICs[1024];
	size_t SomeNomadicVarN;
	while ((SomeNomadicVarN == fread(NICs, 1, sizeof(NICs)-1, GetNICListRaw)) > 0)
	{
		NICs[SomeNomadicVarN] = '\0';
	}
	if (pclose(GetNICListRaw) < 0)
		perror("ERROR");

	std::string Nx;
	Nx += NICs;

	int NetworkListSize = sizeof(NICs);
	std::string Network_List[100];
	int NetworkListCount = 0;
	for (int i = 0 ; i < NetworkListSize ; i++)
		if(NICs[i] == '\n')
			NetworkListCount = NetworkListCount + 1;

	std::cout << "No. of Interfaces: " << NetworkListCount << std::endl;
	size_t FoundNewLine;
	FoundNewLine = Nx.find_first_of('\n');

	for (int i = 0 ; i < NetworkListCount ; i++)
	{
		Network_List[i] = Nx.substr(0, Nx.find('\n'));
		Nx = Nx.replace(0,Nx.find('\n'), 4, 0);
		Nx = Nx.substr(FoundNewLine);
	}

	std::cout << Network_List[2] << std::endl;

	// for (int i = 0 ; i < NetworkListCount ; i++)
	// {
	// 	const char* items[i] = i;
	// }
	// const char* items[] = 	{
	// 							"Wi-Fi",
	// 							"Network Port",
	// 							"Bluetooth"
	// 						};
	// std::cout << items[1] << std::endl;
}