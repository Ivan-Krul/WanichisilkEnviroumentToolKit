#pragma once
#include "ItemWeapon.h"

namespace battle_system_lib
{
	class ItemMeleeWeapon :
		public ItemWeapon
	{
	protected:
		uint16_t m_Length;
		uint16_t m_Weight;

	public:
		ItemMeleeWeapon(const std::string name, const std::string description, const int16_t force_coef, const uint16_t length, const uint16_t weight, const uint16_t size);

		const uint16_t GetLength() const;
		const uint16_t GetWeight() const;

		virtual const std::string GetDescription() const;
	};

	inline ItemMeleeWeapon::ItemMeleeWeapon(const std::string name, const std::string description, const int16_t force_coef, const uint16_t length, const uint16_t weight, const uint16_t size)
		: ItemWeapon(name, description, force_coef, ItemType::melee_weapon, size)
	{
		m_Length = length;
		m_Weight = weight;
	}
	inline const uint16_t ItemMeleeWeapon::GetLength() const
	{
		return m_Length;
	}
	inline const uint16_t ItemMeleeWeapon::GetWeight() const
	{
		return m_Weight;
	}
	inline const std::string ItemMeleeWeapon::GetDescription() const
	{
		return "(force coef "
			+ std::to_string(m_ForceCoef)
			+ ", length "
			+ std::to_string(m_Length)
			+ ", weight "
			+ std::to_string(m_Weight)
			+ ") "
			+ m_Description
			+ DescriptSize();
	}
}
