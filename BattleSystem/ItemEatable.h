#pragma once
#include <stdint.h>

#include "Item.h"


namespace battle_system_lib
{
	class ItemEatable
		: public Item
	{
		int16_t m_Benefit = 0;

	public:
		ItemEatable(std::string name, std::string description, int16_t benefit);

		const int16_t GetBenefit() const;

		virtual const std::string GetDescription() const;
	};
}

