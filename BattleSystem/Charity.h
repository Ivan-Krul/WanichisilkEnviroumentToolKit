#pragma once
#include <stdint.h>

#include <string>

#include "Inventory.h"
#include "Dimension.h"

#include "Count.h"

namespace battle_system_lib
{
	class Charity : public ICount
	{
		static Count s_Count;

		std::string m_Name;
		uint16_t m_MaxProductivity;
		uint16_t m_MaxForce;

	protected:
		int16_t m_Productivity;
		int16_t m_Force;

		Inventory m_Inventory;

		Dimension m_Dimension;

	public:
		Charity(const std::string name, const uint16_t max_productivity, const uint16_t max_force, const Dimension dimension);
		
		const uint16_t GetCount() const override;
		const uint16_t GetMaxProductivity() const;
		const uint16_t GetMaxForce() const;
		const int16_t GetForce() const;
		const int16_t GetProductivity() const;
		const std::string GetName() const;
		const Dimension GetDimension() const;

		void SetProductivity(const int16_t new_productivity);
		void SetForce(const int16_t new_force);
		void ChangeProductivity(const int16_t delta_productivity);
		void ChangeForce(const int16_t delta_force);

		Inventory& GetInventoryInstance();

		virtual ~Charity();
	};
}

