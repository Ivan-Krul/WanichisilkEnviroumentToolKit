#include "Charity.h"

#include "Hardware.h"

namespace battle_system_lib
{
	Charity::Charity(const std::string name, const uint16_t max_productivity, const uint16_t max_force, const Dimension dimension)
	{
		s_Count.Increment();
		m_Name = name;
		m_Productivity = m_MaxProductivity = max_productivity;
		m_Force = m_MaxForce = max_force;
		m_Dimension = dimension;
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

	Inventory& Charity::GetInventoryInstance()
	{
		return m_Inventory;
	}

	Charity::~Charity()
	{
		s_Count.Decrement();
	}

	Count Charity::s_Count;
}
