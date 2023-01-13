#include <iostream>

#include "Hardware.h"

int main()
{
	auto h = hardware_envi_lib::Hardware::GetInstance();

	std::cout << "Hello World!\n";
}
