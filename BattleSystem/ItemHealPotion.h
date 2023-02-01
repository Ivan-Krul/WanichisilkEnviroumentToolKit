#pragma once
#include "ItemPotion.h"

namespace battle_system_lib
{
	class ItemHealPotion :
		public ItemPotion
	{
	public:
		ItemHealPotion(const std::string name, const std::string description, const int16_t effect, const uint16_t duration, const uint16_t size);

		virtual const std::string GetDescription() const;
	};

	inline ItemHealPotion::ItemHealPotion(const std::string name, const std::string description, const int16_t effect, const uint16_t duration, const uint16_t size)
		: ItemPotion(name, description, effect, duration, ItemType::heal_potion, size)
	{
	}
	inline const std::string ItemHealPotion::GetDescription() const
	{
		return "(heal "
			+ std::to_string(m_Effect)
			+ ") "
			+ m_Description
			+ DescriptSize();
	}
}
