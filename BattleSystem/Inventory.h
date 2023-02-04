#pragma once
#include <vector>
#include <memory>

#include "Item.h"

namespace battle_system_lib
{
	typedef std::shared_ptr<Item> v_Item_p;

	class Inventory
	{
		uint16_t m_MaxCapacity;
		std::vector<v_Item_p> m_Items_p;
	public:
		Inventory(uint16_t max_capacity);

		void PushItem(v_Item_p item);
		const size_t size() const;
		const uint16_t max_capacity() const;

		std::vector<v_Item_p>::const_iterator begin() const;
		std::vector<v_Item_p>::const_iterator end() const;

		const v_Item_p operator[](size_t index) const;

		void PopItem(size_t index);
		void PopItem(std::vector<v_Item_p>::const_iterator iter);
	};
}
