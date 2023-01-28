#include "Inventory.h"

namespace battle_system_lib
{
	void Inventory::PushItem(std::shared_ptr<Item> item)
	{
		m_Items_p.push_back(item);
	}
	const size_t Inventory::size() const
	{
		return m_Items_p.size();
	}
	std::vector<std::shared_ptr<Item>>::const_iterator Inventory::begin() const
	{
		return m_Items_p.begin();
	}
	std::vector<std::shared_ptr<Item>>::const_iterator Inventory::end() const
	{
		return m_Items_p.end();
	}
	const std::shared_ptr<Item> Inventory::operator[](size_t index) const
	{
		return (index < m_Items_p.size())
			? m_Items_p[index]
			: std::shared_ptr<Item>();
	}
	void Inventory::PopItem(size_t index)
	{
		m_Items_p.erase(m_Items_p.begin() + index);
	}
	void Inventory::PopItem(std::vector<std::shared_ptr<Item>>::const_iterator iter)
	{
		m_Items_p.erase(iter);
	}
}
