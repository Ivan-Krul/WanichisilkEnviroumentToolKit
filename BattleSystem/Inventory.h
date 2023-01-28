#pragma once
#include <vector>
#include <memory>

#include "Item.h"

namespace battle_system_lib
{
	class Inventory
	{
		std::vector<std::shared_ptr<Item>> m_Items_p;
	public:
		void PushItem(std::shared_ptr<Item> item);
		const size_t size() const;

		std::vector<std::shared_ptr<Item>>::const_iterator begin() const;
		std::vector<std::shared_ptr<Item>>::const_iterator end() const;

		const std::shared_ptr<Item> operator[](size_t index) const;

		void PopItem(size_t index);
		void PopItem(std::vector<std::shared_ptr<Item>>::const_iterator iter);
	};
}
