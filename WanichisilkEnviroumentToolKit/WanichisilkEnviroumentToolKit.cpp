#include <iostream>

#include "Hardware.h"

#include "ItemLib.h"
#include "Charity.h"
#include "Inventory.h"

int main()
{
	using namespace battle_system_lib;

	auto p = Charity("Pawn", 10, 5, { 1,5 });

	//p.GetInventoryInstance().PushItem(std::make_shared<ItemEatable>("Apple", "from a tree", 6, 4, 5));
	//p.GetInventoryInstance().PushItem(std::make_shared<ItemArmor>("Apple", "from a tree", 4, 5));
	//p.GetInventoryInstance().PushItem(std::make_shared<ItemShootableWeapon>("Apple", "from a tree", 6, Dimension{3,4}, 5));
	//p.GetInventoryInstance().PushItem(std::make_shared<ItemMeleeWeapon>("Apple", "from a tree", 6, 4, 7, 5));
	//p.GetInventoryInstance().PushItem(std::make_shared<ItemDamagablePotion>("Apple", "from a tree", 6, 4, 5));
	//p.GetInventoryInstance().PushItem(std::make_shared<ItemUpgradablePotion>("Apple", "from a tree", 6,  4, ItemUpgradablePotion::UpgradeType(2), 5));
	//p.GetInventoryInstance().PushItem(std::make_shared<ItemHealPotion>("Apple", "from a tree", 6, 4, 5));

	//auto c = ItemCompactor();

	//c.Copy(p.GetInventoryInstance());

	//auto h = hardware_envi_lib::Hardware::GetInstance();
	//h.GetCompacter() = hardware_envi_lib::Compacter(c.Encrypt());
	//h.Write("inventory.dat");

	auto h = hardware_envi_lib::Hardware::GetInstance();
	h.Read("inventory.dat");
	
	auto ic = ItemCompactor();
	ic.Decrypt(h.GetCompacter());

	p.GetInventoryInstance() = ic.Paste();
	for (auto& i : p.GetInventoryInstance())
		std::cout << static_cast<int>(i->GetItemType()) << '\n';
}
