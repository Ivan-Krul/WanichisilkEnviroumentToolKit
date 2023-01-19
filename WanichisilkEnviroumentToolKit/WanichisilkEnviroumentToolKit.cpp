#include <iostream>

#include "Hardware.h"

#include "Charity.h"

int main()
{	
	auto p = battle_system_lib::Charity("Pawn", 10, 5);
	auto r = battle_system_lib::Charity("Rook", 21, 9);

	std::cout << "Count: " << p.GetCount() << '\n';
	std::cout << p.GetName() << '\n';
	std::cout << p.GetForce() << " / " << p.GetMaxForce() << '\n';
	std::cout << p.GetProductivity() << " / " << p.GetProductivity() << '\n';
}
