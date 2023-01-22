#pragma once
#include "ItemWeapon.h"

namespace battle_system_lib
{
	class ItemMeleeWeapon :
		public ItemWeapon
	{
	protected:
		uint16_t m_Length;
		uint16_t m_Weight;

	public:
		ItemMeleeWeapon(const std::string name, const std::string description, const int16_t force_coef, const uint16_t length, const uint16_t weight, const uint16_t size);

		const uint16_t GetLength() const;
		const uint16_t GetWeight() const;

		virtual const std::string GetDescription() const;

	};
}
