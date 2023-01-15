#include <iostream>

#include "Hardware.h"

int main()
{
	auto h = hardware_envi_lib::Hardware::GetInstance();
	
	h.Read("compacter_test.dat");

	std::cout << h.GetCompacter().GetProperties("kuger") << '\n';
	std::cout << h.GetCompacter().GetProperties("string") << '\n';

	//auto a = 0x10101010;
	//auto b = "Hello";

	//h.GetCompacter().PushVariable(hardware_envi_lib::DateType::uint_, "kuger", reinterpret_cast<char*>(&a));
	//h.GetCompacter().PushVariable(hardware_envi_lib::DateType::str__, "string", b);
	//h.Write("compacter_test.dat");
}
