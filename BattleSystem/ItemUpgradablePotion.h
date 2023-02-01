#pragma once
#include "ItemPotion.h"

namespace battle_system_lib
{
	class ItemUpgradablePotion :
		public ItemPotion
	{
	public:
		enum UpgradeType
		{
			force,
			duration,
			benefit,
			armor,
			dismention
		};
	protected:
		UpgradeType m_UpgradeType;
	public:
		ItemUpgradablePotion(const std::string name, const std::string description, const int16_t effect, const uint16_t duration, const UpgradeType type, const uint16_t size);

		const UpgradeType GetUpgradeType() const;
		const std::string ConvertUpgradeTypeToString(UpgradeType type) const;

		virtual const std::string GetDescription() const;
	};
}
