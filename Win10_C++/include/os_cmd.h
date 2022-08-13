#include <iostream>

void LC_OS_CMD(std::string cmd)
{
    system(cmd.c_str());
}