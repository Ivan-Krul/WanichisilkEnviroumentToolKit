#include "CharityCompacter.h"

namespace battle_system_lib
{
	Charity CharityCompacter::Decrypt(const hardware_envi_lib::Compacter& comp) const
	{
		using namespace hardware_envi_lib;

		if(comp["charity"][0] != 1)
			return Charity("a", 1, 2, Dimension{ 3,4 }, 5);

		auto inv_comp = InventoryCompacter();
		inv_comp.Decrypt(comp);
		auto inv = inv_comp.paste();
		
		auto max_capacity = comp.ConvertToShort("charity::inventory.max_capacity");
		auto name = comp["charity::name"];
		auto prod_max = comp.ConvertToShort("charity::max_productivity");
		auto force_max = comp.ConvertToShort("charity::max_force");
		auto dimension = Dimension();
		dimension.min_size = comp.ConvertToShort("charity::dimension.min_size");
		dimension.max_size = comp.ConvertToShort("charity::dimension.max_size");

		auto charity = Charity(name, prod_max, force_max, dimension, max_capacity);
		for(uint16_t i = 0; i < inv.size(); i++)
			charity.GetInventoryInstance().push(inv[i]);
		auto armsize = comp.ConvertToShort("charity::armor_index.size()");
		auto arm = short();
		for (uint16_t i = 0; i < armsize; i++)
		{
			arm = comp.ConvertToShort("charity::armor_index[" + std::to_string(i) + "]");
			charity.ChangeArmorSlot(i, arm);
		}
		charity.SetProductivity(comp.ConvertToShort("charity::productivity"));
		charity.SetForce(comp.ConvertToShort("charity::force"));


		return charity;
	}

	const hardware_envi_lib::Compacter& CharityCompacter::Encrypt(Charity& charity) const
	{
		using namespace hardware_envi_lib;

		auto inventory = charity.GetInventoryInstance();
		auto invcomp = InventoryCompacter();
		invcomp.copy(inventory);
		auto comp = invcomp.Encrypt();
		auto bufnum = size_t();

		bufnum = inventory.max_capacity();
		comp.push(DateType::shrt_, "charity::inventory.max_capacity", reinterpret_cast<const char*>(&bufnum));
		bufnum = charity.GetRawWeaponIndex();
		comp.push(DateType::shrt_, "charity::weapon_index", reinterpret_cast<const char*>(&bufnum));
		bufnum = charity.c_ArmorSlotSize;
		comp.push(DateType::shrt_, "charity::armor_index.size()", reinterpret_cast<const char*>(&bufnum));
		for (uint16_t i = 0; i < charity.c_ArmorSlotSize; i++)
		{
			bufnum = charity.GetRawArmorIndex(i);
			comp.push(DateType::shrt_, "charity::armor_index[" + std::to_string(i) + "]", reinterpret_cast<const char*>(&bufnum));
		}

		bufnum = 1;
		comp.push(DateType::bool_, "charity", reinterpret_cast<const char*>(&bufnum));

		comp.push(DateType::str__, "charity::name", charity.GetName().c_str());
		bufnum = charity.GetMaxProductivity();
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
