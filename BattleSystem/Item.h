#pragma once
#include <string>

#include "ItemEnumClass.h"

namespace battle_system_lib
{
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
