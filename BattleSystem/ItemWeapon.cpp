#include "ItemWeapon.h"

namespace battle_system_lib
{
	ItemWeapon::ItemWeapon(const std::string name, const std::string description, const int16_t force_coef, const ItemType item_type, const uint16_t size)
		: Item(name, description, size, item_type)
	{
		m_ForceCoef = force_coef;
	}

	const int16_t ItemWeapon::GetForceCoef() const
	{
		return m_ForceCoef;
	}

	const std::string ItemWeapon::GetDescription() const
	{
		return "(force coef " + std::to_string(m_ForceCoef) + ") " + m_Description + DescriptSize();
	}
}
