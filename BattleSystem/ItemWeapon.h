#pragma once
#include "Item.h"

namespace battle_system_lib
{
	class ItemWeapon :
		public Item
	{
	protected:
		int16_t m_ForceCoef = 0;

	public:
		ItemWeapon(const std::string name, const std::string description, const int16_t force_coef, const ItemType item_type, const uint16_t size);

		const int16_t GetForceCoef() const;

		virtual const std::string GetDescription() const;
	};
}
