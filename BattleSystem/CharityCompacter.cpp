#include "CharityCompacter.h"

namespace battle_system_lib
{
	Charity CharityCompacter::Decrypt(const hardware_envi_lib::Compacter& comp) const
	{
		return Charity("a", 1, 2, Dimension{ 3,4 }, 5);
	}

	const hardware_envi_lib::Compacter CharityCompacter::Encrypt(Charity& charity) const
	{
		using namespace hardware_envi_lib;

		auto inventory = charity.GetInventoryInstance();

		inventory.push(charity.GetWeapon());
		for(size_t i = 0; i < charity.c_ArmorSlotSize; i++)
			inventory.push(charity.GetArmorSlot(i));

		auto invcomp = InventoryCompacter();

		invcomp.copy(inventory);

		auto comp = invcomp.Encrypt();
		auto bufnum = charity.GetMaxProductivity();

		comp.push(DateType::str__, "charity::name", charity.GetName().c_str());
		comp.push(DateType::shrt_, "charity::max_productivity", reinterpret_cast<const char*>(&bufnum));

		bufnum = charity.GetProductivity();

		comp.push(DateType::shrt_, "charity::productivity", reinterpret_cast<const char*>(&bufnum));

		bufnum = charity.GetMaxForce();

		comp.push(DateType::shrt_, "charity::max_force", reinterpret_cast<const char*>(&bufnum));

		bufnum = charity.GetForce();

		comp.push(DateType::shrt_, "charity::force", reinterpret_cast<const char*>(&bufnum));

		bufnum = charity.GetDimension().min_size;

		comp.push(DateType::shrt_, "charity::dimension.min_size", reinterpret_cast<const char*>(&bufnum));

		bufnum = charity.GetDimension().max_size;

		comp.push(DateType::shrt_, "charity::dimension.max_size", reinterpret_cast<const char*>(&bufnum));

		return comp;
	}
}
