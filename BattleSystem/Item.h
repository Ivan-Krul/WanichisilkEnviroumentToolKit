#pragma once
#include <string>

#include "ItemEnumClass.h"

#define USING_ITEM

namespace battle_system_lib
{
	class Item // parent class
	{
		ItemType m_ItemType;
		
	protected:
		std::string m_Name;
		std::string m_Description;

		uint16_t m_Size = 0;

		const std::string DescriptSize() const;
	public:
		Item(std::string name, std::string description, uint16_t size, ItemType type = ItemType::common);

		virtual const std::string GetDescription() const;

		const ItemType GetItemType() const;
		const std::string GetName() const;
		const uint16_t GetSize() const;

		virtual ~Item() = default;
	};
}
