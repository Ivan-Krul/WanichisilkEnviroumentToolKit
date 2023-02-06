#include <iostream>

#include "Hardware.h"

#include "ItemLib.h"
#include "Charity.h"
#include "Inventory.h"
#include "CharityCompacter.h"

int main()
{
	using namespace battle_system_lib;

	//auto p = Charity("Pawn", 10, 5, { 1,5 }, 10);
	//p.GetInventoryInstance().push(std::make_shared<ItemEatable>("Apple", "from a tree", 6, 4, 5));
	//p.GetInventoryInstance().push(std::make_shared<ItemArmor>("Shield", "from forger", 4, 5));
	//p.GetInventoryInstance().push(std::make_shared<ItemShootableWeapon>("Slingshot", "shots well", 6, Dimension{3,4}, 5));
	//p.GetInventoryInstance().push(std::make_shared<ItemMeleeWeapon>("Sword", "cuts well", 6, 4, 7, 5));
	//p.GetInventoryInstance().push(std::make_shared<ItemDamagablePotion>("Potion of death", "don't touch", 6, 4, 5));
	//p.GetInventoryInstance().push(std::make_shared<ItemUpgradablePotion>("Potion of upgrade", "it could help u", 6,  4, ItemUpgradablePotion::UpgradeType(2), 5));
	//p.GetInventoryInstance().push(std::make_shared<ItemHealPotion>("Potion of heal", "it must be necessary", 6, 4, 5));
	//p.ChangeProductivity(-4);
	//p.ChangeForce(-2);
	//p.ChangeArmorSlot(0, 1);
	//auto c = InventoryCompacter();
	//c.copy(p.GetInventoryInstance());
	//auto h = hardware_envi_lib::Hardware::GetInstance();
	//h.GetCompacter() = hardware_envi_lib::Compacter(c.Encrypt());
	//auto cc = CharityCompacter();
	//h.GetCompacter() = cc.Encrypt(p);
	//h.Write("Charity.dat");

	auto h = hardware_envi_lib::Hardware::GetInstance();
	h.Read("Charity.dat");
	auto cc = CharityCompacter();
	auto p = cc.Decrypt(h.GetCompacter());
	
	std::cout << "cunt: " << p.GetCount() << '\n';

	std::cout << "name: " << p.GetName() << '\n';
	std::cout << "prod: " << p.GetProductivity() << '/' << p.GetMaxProductivity() << '\n';
	std::cout << "forc: " << p.GetForce() << '/' << p.GetMaxForce() << '\n';
	std::cout << "dimn: " << p.GetDimension().min_size << '-' << p.GetDimension().max_size << '\n';
	std::cout << "invt: " << p.GetInventoryInstance().size() << '/' << p.GetInventoryInstance().max_capacity() << '\n';
	std::cout << "weap: " << p.GetWeapon()->GetName() << '\n';
	std::cout << "armr: " << p.GetArmorSlot(0)->GetName() << '\n';
	std::cout << "armr: " << p.GetArmorSlot(1)->GetName() << '\n';
}
