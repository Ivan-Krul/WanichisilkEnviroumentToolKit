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
}
