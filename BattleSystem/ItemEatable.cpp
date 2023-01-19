#include "ItemEatable.h"

namespace battle_system_lib
{
	const std::string ItemEatable::GetDescription() const
	{
		return "(benefit " + std::to_string(m_Benefit) + ") " + m_Description;
	}
	ItemEatable::ItemEatable(std::string name, std::string description, int16_t benefit) 
		: Item(name, description, ItemType::eatable)
	{
		m_Benefit = benefit;
	}
	const int16_t ItemEatable::GetBenefit() const
	{
		return m_Benefit;
	}
}
