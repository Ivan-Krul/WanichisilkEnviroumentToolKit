#include "Charity.h"

#include "Hardware.h"

namespace battle_system_lib
{
	Charity::Charity(const std::string name, const uint16_t max_productivity, const uint16_t max_force, const Dimension dimension, const uint16_t max_inv_capacity)
		: m_Inventory(max_inv_capacity)
	{
		s_Count.Increment();
		m_Name = name;
		m_Productivity = m_MaxProductivity = max_productivity;
		m_Force = m_MaxForce = max_force;
		m_Dimension = dimension;
		m_WeaponIndex = -1;
		m_ArmorIndex.fill(-1);
	}

	Charity::Charity(Charity&& temp)
		: m_Inventory(temp.GetInventoryInstance().max_capacity())
	{
		s_Count.Increment();
		m_Name = temp.m_Name;
		m_ArmorIndex = temp.m_ArmorIndex;
		m_WeaponIndex = temp.m_WeaponIndex;
		m_MaxForce = temp.m_MaxForce;
		m_MaxProductivity = temp.m_MaxProductivity;
		m_Force = temp.m_Force;
		m_Productivity = temp.m_Productivity;
		m_Dimension = temp.m_Dimension;
		m_Inventory = temp.m_Inventory;
	}

	const uint16_t Charity::GetCount() const
	{
		return s_Count.GetCount();
	}

	const uint16_t Charity::GetMaxProductivity() const
	{
		return m_MaxProductivity;
	}

	const uint16_t Charity::GetMaxForce() const
	{
		return m_MaxForce;
	}

	const int16_t Charity::GetForce() const
	{
		return m_Force;
	}

	const int16_t Charity::GetProductivity() const
	{
		return m_Productivity;
	}

	const std::string Charity::GetName() const
	{
		return m_Name;
	}

	const Dimension Charity::GetDimension() const
	{
		return m_Dimension;
	}

	const std::shared_ptr<ItemWeapon> Charity::GetWeapon() const
	{
		if (m_WeaponIndex < 0)
			return s_CommonWeapon;
		else
			return std::static_pointer_cast<ItemWeapon>(m_Inventory[m_WeaponIndex]);
	}

	const std::shared_ptr<ItemArmor> Charity::GetArmorSlot(uint16_t index) const
	{
		if (index < 0 || index >= m_ArmorIndex.size())
			return s_CommonArmor;
		else if(m_ArmorIndex[index] < 0)
			return s_CommonArmor;
		else
			return std::static_pointer_cast<ItemArmor>(m_Inventory[m_ArmorIndex[index]]);
	}

	const int16_t Charity::GetRawWeaponIndex() const
	{
		return m_WeaponIndex;
	}

	const int16_t Charity::GetRawArmorIndex(uint16_t armor_index) const
	{
		if (armor_index < m_ArmorIndex.size())
			return m_ArmorIndex[armor_index];
		else
			return -1;
	}

	void Charity::SetProductivity(const int16_t new_productivity)
	{
		m_Productivity = new_productivity;
	}

	void Charity::SetForce(const int16_t new_force)
	{
		m_Force = new_force;
	}

	void Charity::ChangeProductivity(const int16_t delta_productivity)
	{
		if(m_Productivity + delta_productivity < m_MaxProductivity)
			m_Productivity += delta_productivity;
	}

	void Charity::ChangeForce(const int16_t delta_force)
	{
		if (m_Force + delta_force < m_MaxForce)
			m_Force += delta_force;
	}

	void Charity::ChangeWeaponSlot(const int16_t inv_index)
	{
		if (inv_index < 0 || inv_index >= m_Inventory.size())
		{
			m_WeaponIndex = -1;
			return;
		}
		if (m_Inventory[inv_index]->GetItemType() == ItemType::melee_weapon || m_Inventory[inv_index]->GetItemType() == ItemType::shootable_weapon)
			m_WeaponIndex = inv_index;
		else
			m_WeaponIndex = -1;
	}

	void Charity::ChangeArmorSlot(const int16_t armor_index, const int16_t inv_index)
	{
		if (armor_index < 0 || armor_index >= m_ArmorIndex.size() || inv_index < 0 || inv_index >= m_Inventory.size())
			return;
		if (inv_index < 0)
		{
			m_ArmorIndex[armor_index] = -1;
			return;
		}
		if (m_Inventory[inv_index]->GetItemType() == ItemType::armor)
			m_ArmorIndex[armor_index] = inv_index;
		else
			m_ArmorIndex[armor_index] = -1;
	}

	Inventory& Charity::GetInventoryInstance()
	{
		return m_Inventory;
	}

	Charity::~Charity()
	{
		s_Count.Decrement();
	}

	const std::shared_ptr<ItemMeleeWeapon> Charity::s_CommonWeapon = std::make_shared<ItemMeleeWeapon>("Hand", "Just hand", 1, 1, 1, 1);
	const std::shared_ptr<ItemArmor> Charity::s_CommonArmor = std::make_shared<ItemArmor>("None", "none", 1, 1);

	Count Charity::s_Count;
}
