#include "Item.h"

namespace battle_system_lib
{
	const std::string Item::GetName() const
	{
		return m_Name;
	}

	Item::Item(std::string name, std::string description, ItemType type)
	{
		m_Name = name;
		m_ItemType = type;
		m_Description = description;
	}

	const std::string Item::GetDescription() const
	{
		return m_Description;
	}

	const ItemType Item::GetItemType() const
	{
		return m_ItemType;
	}
}


