#pragma once
#include "Item.h"

namespace battle_system_lib
{
	class ItemArmor
		: public Item
	{
	protected:
		int16_t m_ArmorCoef = 0;
	
	public:
		ItemArmor(const std::string name, const std::string description, const int16_t armor_coef, const uint16_t size);

		const int16_t GetArmorCoef() const;

		virtual const std::string GetDescription() const;
	};

	inline ItemArmor::ItemArmor(const std::string name, const std::string description, const int16_t armor_coef, const uint16_t size)
		: Item(name, description, size, ItemType::armor)
	{
		m_ArmorCoef = armor_coef;
	}
	inline const int16_t ItemArmor::GetArmorCoef() const
	{
		return m_ArmorCoef;
	}
	inline const std::string ItemArmor::GetDescription() const
	{
		return "(armor coef " + std::to_string(m_ArmorCoef) + ") " + m_Description + DescriptSize();
	}
}
