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
}

