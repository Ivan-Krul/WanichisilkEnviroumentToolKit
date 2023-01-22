#include "ItemMeleeWeapon.h"

namespace battle_system_lib
{
	ItemMeleeWeapon::ItemMeleeWeapon(const std::string name, const std::string description, const int16_t force_coef, const uint16_t length, const uint16_t weight, const uint16_t size)
		: ItemWeapon(name, description, force_coef, ItemType::melee_weapon, size)
	{
		m_Length = length;
		m_Weight = weight;
	}
	const uint16_t ItemMeleeWeapon::GetLength() const
	{
		return m_Length;
	}
	const uint16_t ItemMeleeWeapon::GetWeight() const
	{
		return m_Weight;
	}
	const std::string ItemMeleeWeapon::GetDescription() const
	{
		return "(force coef "
			+ std::to_string(m_ForceCoef)
			+ ", length "
			+ std::to_string(m_Length)
			+ ", weight"
			+ std::to_string(m_Weight)
			+ ") "
			+ m_Description
			+ DescriptSize();
	}
}

