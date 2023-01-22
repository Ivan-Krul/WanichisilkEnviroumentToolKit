#include "ItemShootableWepon.h"

namespace battle_system_lib
{
	ItemShootableWepon::ItemShootableWepon(const std::string name, const std::string description, const int16_t force, const uint16_t min_dimensions, const uint16_t max_dimensions, const uint16_t size)
		: ItemWeapon(name, description, force, ItemType::shootable_weapon, size)
	{
		m_MinDimensions = min_dimensions;
		m_MaxDimensions = max_dimensions;
	}

	const uint16_t ItemShootableWepon::GetMinDimensions() const
	{
		return m_MinDimensions;
	}

	const uint16_t ItemShootableWepon::GetMaxDimensions() const
	{
		return m_MaxDimensions;
	}

	const std::string ItemShootableWepon::GetDescription() const
	{
		return "(force coef "
			+ std::to_string(m_ForceCoef)
			+ ", dismentions "
			+ std::to_string(m_MinDimensions)
			+ " - "
			+ std::to_string(m_MinDimensions)
			+ ") "
			+ m_Description
			+ DescriptSize();
	}
}
