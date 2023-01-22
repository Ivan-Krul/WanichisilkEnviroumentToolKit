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
		ItemEatable(std::string name, std::string description, int16_t benefit, uint16_t duration_of_digestion);

		const int16_t GetBenefit() const;
		const uint16_t GetDurationOfDigestion() const;

		virtual const std::string GetDescription() const;
	};
}

