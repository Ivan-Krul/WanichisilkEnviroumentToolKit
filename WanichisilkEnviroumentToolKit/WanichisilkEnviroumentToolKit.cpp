#include <iostream>

#include "Hardware.h"

int main()
{
	auto c = hardware_envi_lib::Compacter();

	auto a = 0.5f;

	c.PushVariable(hardware_envi_lib::DateType::flot_, "var", reinterpret_cast<char*>(& a));
	std::cout << "Hello World!\n";
	std::cout << "Var: " << c.ConvertToFloat("var") << '\n';
}
