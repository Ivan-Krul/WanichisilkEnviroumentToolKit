#include "Item.h"

namespace battle_system_lib
{
	const std::string Item::GetName() const
	{
		return m_Name;
	}

	Item::Item(std::string name, std::string description, uint16_t size, ItemType type)
	{
		m_Name = name;
		m_ItemType = type;
		m_Description = description;
		m_Size = size;
	}

	const std::string Item::DescriptSize() const
	{
		return " (size "+std::to_string(m_Size) + ")";
	}

	const std::string Item::GetDescription() const
	{
		return m_Description + DescriptSize();
	}

	const uint16_t Item::GetSize() const
	{
		return m_Size;
	}

	const ItemType Item::GetItemType() const
	{
		return m_ItemType;
	}
}


