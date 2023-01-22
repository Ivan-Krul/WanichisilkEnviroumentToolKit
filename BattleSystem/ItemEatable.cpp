#include "ItemEatable.h"

namespace battle_system_lib
{
	const std::string ItemEatable::GetDescription() const
	{
		return "(benefit " + std::to_string(m_Benefit) + ", duration of digestion "+ std::to_string(m_DurationOfDigestion) + ") " + m_Description + DescriptSize();
	}
	ItemEatable::ItemEatable(const std::string name, const std::string description, const int16_t benefit, const uint16_t duration_of_digestion, const uint16_t size)
		: Item(name, description,size, ItemType::eatable)
	{
		m_DurationOfDigestion = duration_of_digestion;
		m_Benefit = benefit;
	}
	const int16_t ItemEatable::GetBenefit() const
	{
		return m_Benefit;
	}
	const uint16_t ItemEatable::GetDurationOfDigestion() const
	{
		return m_DurationOfDigestion;
	}
}
