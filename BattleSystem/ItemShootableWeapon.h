#pragma once
#include "ItemWeapon.h"
#include "Dimension.h"

namespace battle_system_lib
{
	class ItemShootableWeapon :
		public ItemWeapon
	{
	protected:
		Dimension m_Dimension;
	public:
		ItemShootableWeapon(const std::string name, const std::string description, const int16_t force, const Dimension dimensions, const uint16_t size);

		const Dimension GetDimensions() const;

		virtual const std::string GetDescription() const;
	};

	inline ItemShootableWeapon::ItemShootableWeapon(const std::string name, const std::string description, const int16_t force, const Dimension dimension, const uint16_t size)
		: ItemWeapon(name, description, force, ItemType::shootable_weapon, size)
	{
		m_Dimension = dimension;
	}

	inline const Dimension ItemShootableWeapon::GetDimensions() const
	{
		return m_Dimension;
	}

	inline const std::string ItemShootableWeapon::GetDescription() const
	{
		return "(force coef "
			+ std::to_string(m_ForceCoef)
			+ ", dismentions "
			+ std::to_string(m_Dimension.min_size)
			+ " - "
			+ std::to_string(m_Dimension.max_size)
			+ ") "
			+ m_Description
			+ DescriptSize();
	}
}
