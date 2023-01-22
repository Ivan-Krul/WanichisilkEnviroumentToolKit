#pragma once
#include "ItemWeapon.h"

namespace battle_system_lib
{
	class ItemShootableWepon :
		public ItemWeapon
	{
	protected:
		uint16_t m_MinDimensions;
		uint16_t m_MaxDimensions;
	public:
		ItemShootableWepon(const std::string name, const std::string description, const int16_t force, const uint16_t min_dimensions, const uint16_t max_dimensions, const uint16_t size);

		const uint16_t GetMinDimensions() const;
		const uint16_t GetMaxDimensions() const;

		virtual const std::string GetDescription() const;
	};
}
