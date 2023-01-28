#include <iostream>

#include "Hardware.h"

#include "ItemLib.h"
#include "Charity.h"
#include "Inventory.h"

int main()
{	
	using namespace battle_system_lib;

	auto p = Charity("Pawn", 10, 5, {1,5});
	auto r = Charity("Rook", 21, 9, {2,6});

	std::cout << "Count: " << p.GetCount() << '\n';
	std::cout << p.GetName() << '\n';
	std::cout << p.GetForce() << " / " << p.GetMaxForce() << '\n';
	std::cout << p.GetProductivity() << " / " << p.GetProductivity() << '\n';

	p.GetInventoryInstance().PushItem(std::make_shared<ItemMeleeWeapon>("Sword", "Make swing", 5, 3, 5, 6));
	p.GetInventoryInstance().PushItem(std::make_shared<ItemEatable>("Banana", "From jungle", 5, 3, 7));
	p.GetInventoryInstance().PushItem(std::make_shared<ItemArmor>("Shield", "From metal", 8, 9));
	p.GetInventoryInstance().PushItem(std::make_shared<ItemDamagablePotion>("Potion of death", "do not touch", 0x7fff, 4));
	p.GetInventoryInstance().PushItem(std::make_shared<ItemHealPotion>("Potion of Blue Tree", "distilisation", 64, 3));
	p.GetInventoryInstance().PushItem(std::make_shared<ItemShootableWepon>("Shotgun", "make boom", 15, Dimension{5 , 8}, 4));
	p.GetInventoryInstance().PushItem(std::make_shared<ItemUpgradablePotion>("Upgrader", "Upgrade yourself", 6, 3, ItemUpgradablePotion::force));

	for (const auto i : p.GetInventoryInstance())
	{
		std::cout<<i->GetName() << ": " << i->GetDescription() << '\n';
	}
}
