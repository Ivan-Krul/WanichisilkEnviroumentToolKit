#include <iostream>

#include "Hardware.h"

int main()
{
	auto c = hardware_envi_lib::Compacter();

	auto a = 6.5f;

	c.PushVariable(hardware_envi_lib::DateType::flot_, "kuger", reinterpret_cast<char*>(&a));

	std::cout << c.GetProperties("kuger") << '\n';
}
