#include "ItemUpgradablePotion.h"

namespace battle_system_lib
{
	ItemUpgradablePotion::ItemUpgradablePotion(const std::string name, const std::string description, const int16_t effect, const uint16_t duration, const UpgradeType type, const uint16_t size)
		: ItemPotion(name, description, effect, duration, ItemType::upgradable_potion, size)
	{
		m_UpgradeType = type;
	}

	const ItemUpgradablePotion::UpgradeType ItemUpgradablePotion::GetUpgradeType() const
	{
		return m_UpgradeType;
	}

	const std::string ItemUpgradablePotion::ConvertUpgradeTypeToString(UpgradeType type) const
	{
		switch (type)
		{
			case force:
				return "force";
			case duration:
				return "duration";
			case benefit:
				return "benefit";
			case armor:
				return "armor";
			case dismention:
				return "dismention";
			default:
				return std::string();
		}
	}

	const std::string ItemUpgradablePotion::GetDescription() const
	{
		return "(upgrade "
			+ ConvertUpgradeTypeToString(m_UpgradeType)
			+ " by "
			+ std::to_string(m_Effect)
			+ ") "
			+ m_Description
			+ DescriptSize();

	}
}
