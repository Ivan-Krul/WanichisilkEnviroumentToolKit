#pragma once
#include "ItemPotion.h"

namespace battle_system_lib
{
	class ItemDamagablePotion :
		public ItemPotion
	{
	public:
		ItemDamagablePotion(const std::string name, const std::string description, const int16_t effect, const uint16_t size);

		virtual const std::string GetDescription() const;
	};

	inline ItemDamagablePotion::ItemDamagablePotion(const std::string name, const std::string description, const int16_t effect, const uint16_t size)
		: ItemPotion(name, description, effect, size, ItemType::damagable_potion)
	{
	}

	inline const std::string ItemDamagablePotion::GetDescription() const
	{
		return "(damage "
			+ std::to_string(m_Effect)
			+ ") "
			+ m_Description
			+ DescriptSize();
	}
}
