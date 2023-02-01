#pragma once
#include "Item.h"
namespace battle_system_lib
{
	class ItemPotion :
		public Item
	{
	protected:
		int16_t m_Effect;

		uint16_t m_Duration;
	public:
		ItemPotion(const std::string name, const std::string description, const int16_t effect, const uint16_t duration, const ItemType type, const uint16_t size);

		const int16_t GetEffect() const;
		const uint16_t GetDuration() const;
	};

	inline ItemPotion::ItemPotion(const std::string name, const std::string description, const int16_t effect, const uint16_t duration, const ItemType type, const uint16_t size)
		: Item(name, description, size, type)
	{
		m_Effect = effect;
		m_Duration = duration;
	}
	inline const int16_t ItemPotion::GetEffect() const
	{
		return m_Effect;
	}
	inline const uint16_t ItemPotion::GetDuration() const
	{
		return m_Duration;
	}
}
