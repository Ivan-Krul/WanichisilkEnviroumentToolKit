#pragma once
#include <stdint.h>
#include <string>
namespace battle_system_lib
{
	class Charity
	{
		static uint16_t s_Count;

		std::string m_Name;
		uint16_t m_MaxProductivity;
		uint16_t m_MaxForce;
		int16_t m_Productivity;
		int16_t m_Force;
	public:
		Charity(const std::string name, const uint16_t max_productivity, const uint16_t max_force);
		
		const uint16_t GetCount() const;
		const uint16_t GetMaxProductivity() const;
		const uint16_t GetMaxForce() const;
		const int16_t GetForce() const;
		const int16_t GetProductivity() const;
		const std::string GetName() const;

		void SetProductivity(const int16_t new_productivity);
		void SetForce(const int16_t new_force);
		void ChangeProductivity(const int16_t delta_productivity);
		void ChangeForce(const int16_t delta_force);



		~Charity();
	};
}

