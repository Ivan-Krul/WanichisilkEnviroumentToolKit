#include "ItemArmor.h"

namespace battle_system_lib
{
	ItemArmor::ItemArmor(const std::string name, const std::string description, const int16_t armor_coef)
		: Item(name, description, ItemType::armor)
	{
		m_ArmorCoef = armor_coef;
	}
	const int16_t ItemArmor::GetArmorCoef() const
	{
		return m_ArmorCoef;
	}
	const std::string ItemArmor::GetDescription() const
	{
		return "(armor coef " + std::to_string(m_ArmorCoef) + ") " + m_Description;
	}
}