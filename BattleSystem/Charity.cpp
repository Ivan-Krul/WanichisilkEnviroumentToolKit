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
		m_Weapon_p = s_CommonWeapon;
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
		return m_Weapon_p;
	}

	const std::shared_ptr<ItemArmor> Charity::GetArmorSlot(uint16_t index) const
	{
		return m_Armors_p[index];
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
		if (inv_index < 0)
		{
			m_Weapon_p = std::static_pointer_cast<ItemWeapon>(s_CommonWeapon);
			return;
		}
		if (static_cast<ItemMeleeWeapon*>(m_Inventory[inv_index].get())->GetItemType() == ItemType::melee_weapon)
			m_Weapon_p = std::static_pointer_cast<ItemWeapon>(m_Inventory[inv_index]);
		else if(static_cast<ItemMeleeWeapon*>(m_Inventory[inv_index].get())->GetItemType() == ItemType::shootable_weapon)
			m_Weapon_p = std::static_pointer_cast<ItemWeapon>(m_Inventory[inv_index]);
		else
			m_Weapon_p = std::static_pointer_cast<ItemWeapon>(s_CommonWeapon);
	}

	void Charity::ChangeArmorSlot(const int16_t armor_index, const int16_t inv_index)
	{
		if (armor_index < 0 || armor_index >= m_Armors_p.size())
			return;
		if (inv_index < 0)
		{
			m_Armors_p[armor_index] = s_CommonArmor;
			return;
		}
		if (static_cast<ItemMeleeWeapon*>(m_Inventory[inv_index].get())->GetItemType() == ItemType::melee_weapon)
			m_Armors_p[armor_index] = std::static_pointer_cast<ItemArmor>(m_Inventory[inv_index]);
		else
			m_Armors_p[armor_index] = s_CommonArmor;
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
