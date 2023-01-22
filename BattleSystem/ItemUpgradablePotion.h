#pragma once
#include "ItemPotion.h"

namespace battle_system_lib
{
	class ItemUpgradablePotion :
		public ItemPotion
	{
	protected:
		enum UpgradeType
		{
			force,
			duration,
			benefit,
			armor,
			dismention
		};

		UpgradeType m_UpgradeType;
	public:
		ItemUpgradablePotion(const std::string name, const std::string description, const int16_t effect, const uint16_t size, const UpgradeType type);

		const UpgradeType GetUpgradeType() const;
		const std::string ConvertUpgradeTypeToString(UpgradeType type) const;

		virtual const std::string GetDescription() const;
	};
}