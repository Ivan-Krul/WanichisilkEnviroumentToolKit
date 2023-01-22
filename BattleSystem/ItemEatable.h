#pragma once
#include <stdint.h>

#include "Item.h"


namespace battle_system_lib
{
	class ItemEatable
		: public Item
	{
	protected:
		uint16_t m_DurationOfDigestion = 0;
		
		int16_t m_Benefit = 0;

	public:
		ItemEatable(const std::string name, const std::string description, const int16_t benefit, const uint16_t duration_of_digestion, const uint16_t size);

		const int16_t GetBenefit() const;
		const uint16_t GetDurationOfDigestion() const;

		virtual const std::string GetDescription() const;
	};

	inline const std::string ItemEatable::GetDescription() const
	{
		return "(benefit " + std::to_string(m_Benefit) + ", duration of digestion " + std::to_string(m_DurationOfDigestion) + ") " + m_Description + DescriptSize();
	}
	inline ItemEatable::ItemEatable(const std::string name, const std::string description, const int16_t benefit, const uint16_t duration_of_digestion, const uint16_t size)
		: Item(name, description, size, ItemType::eatable)
	{
		m_DurationOfDigestion = duration_of_digestion;
		m_Benefit = benefit;
	}
	inline const int16_t ItemEatable::GetBenefit() const
	{
		return m_Benefit;
	}
	inline const uint16_t ItemEatable::GetDurationOfDigestion() const
	{
		return m_DurationOfDigestion;
	}
}

