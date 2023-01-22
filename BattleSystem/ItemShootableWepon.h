#pragma once
#include "ItemWeapon.h"

namespace battle_system_lib
{
	class ItemShootableWepon :
		public ItemWeapon
	{
	protected:
		uint16_t m_MinDimensions;
		uint16_t m_MaxDimensions;
	public:
		ItemShootableWepon(const std::string name, const std::string description, const int16_t force, const uint16_t min_dimensions, const uint16_t max_dimensions, const uint16_t size);

		const uint16_t GetMinDimensions() const;
		const uint16_t GetMaxDimensions() const;

		virtual const std::string GetDescription() const;
	};

	inline ItemShootableWepon::ItemShootableWepon(const std::string name, const std::string description, const int16_t force, const uint16_t min_dimensions, const uint16_t max_dimensions, const uint16_t size)
		: ItemWeapon(name, description, force, ItemType::shootable_weapon, size)
	{
		m_MinDimensions = min_dimensions;
		m_MaxDimensions = max_dimensions;
	}

	inline const uint16_t ItemShootableWepon::GetMinDimensions() const
	{
		return m_MinDimensions;
	}

	inline const uint16_t ItemShootableWepon::GetMaxDimensions() const
	{
		return m_MaxDimensions;
	}

	inline const std::string ItemShootableWepon::GetDescription() const
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
