#pragma once
#include <string>

namespace battle_system_lib
{
	enum class ItemType
	{
		common,
		eatable // TODO: made more types of item, such as "ItemArmor" or "ItemWeapon"
	};

	class Item // parent class
	{
		ItemType m_ItemType;
		
	protected:
		std::string m_Name;
		std::string m_Description;

	public:
		Item(std::string name, std::string description, ItemType type = ItemType::common);

		virtual const std::string GetDescription() const;

		const ItemType GetItemType() const;
		const std::string GetName() const;

		virtual ~Item() = default;
	};
}
