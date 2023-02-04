#include "Inventory.h"

namespace battle_system_lib
{
	Inventory::Inventory(uint16_t max_capacity)
	{
		m_MaxCapacity = max_capacity;
	}

	void Inventory::PushItem(v_Item_p item)
	{
		if(m_MaxCapacity != m_Items_p.size())
			m_Items_p.push_back(item);
	}
	const size_t Inventory::size() const
	{
		return m_Items_p.size();
	}
	const uint16_t Inventory::max_capacity() const
	{
		return m_MaxCapacity;
	}
	std::vector<v_Item_p>::const_iterator Inventory::begin() const
	{
		return m_Items_p.begin();
	}
	std::vector<v_Item_p>::const_iterator Inventory::end() const
	{
		return m_Items_p.end();
	}
	const v_Item_p Inventory::operator[](size_t index) const
	{
		return (index < m_Items_p.size())
			? m_Items_p[index]
			: v_Item_p();
	}
	void Inventory::PopItem(size_t index)
	{
		m_Items_p.erase(m_Items_p.begin() + index);
	}
	void Inventory::PopItem(std::vector<v_Item_p>::const_iterator iter)
	{
		m_Items_p.erase(iter);
	}
}
