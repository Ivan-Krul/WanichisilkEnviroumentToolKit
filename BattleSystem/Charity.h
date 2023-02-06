#pragma once
#include <stdint.h>

#include <string>
#include <array>

#include "Inventory.h"
#include "Dimension.h"

#include "ItemLib.h"
#include "Count.h"

#define MAX_ARMOR_SLOT 2

namespace battle_system_lib
{
	class Charity : public ICount
	{
		static Count s_Count;
		const static std::shared_ptr<ItemMeleeWeapon> s_CommonWeapon;
		const static std::shared_ptr<ItemArmor> s_CommonArmor;

		std::string m_Name;
		uint16_t m_MaxProductivity;
		uint16_t m_MaxForce;
	public:
		const static uint16_t c_ArmorSlotSize = 2;
	protected:
		int16_t m_Productivity;
		int16_t m_Force;

		Inventory m_Inventory;

		int16_t m_WeaponIndex = -1;
		std::array<int16_t, MAX_ARMOR_SLOT> m_ArmorIndex;

		Dimension m_Dimension;

	public:
		Charity(const std::string name, const uint16_t max_productivity, const uint16_t max_force, const Dimension dimension, const uint16_t max_inv_capacity);
		Charity(Charity&& temp);

		const uint16_t GetCount() const override;
		const uint16_t GetMaxProductivity() const;
		const uint16_t GetMaxForce() const;
		const int16_t GetForce() const;
		const int16_t GetProductivity() const;
		const std::string GetName() const;
		const Dimension GetDimension() const;
		const std::shared_ptr<ItemWeapon> GetWeapon() const;
		const std::shared_ptr<ItemArmor> GetArmorSlot(uint16_t index) const;
		const int16_t GetRawWeaponIndex() const;
		const int16_t GetRawArmorIndex(uint16_t armor_index) const;

		void SetProductivity(const int16_t new_productivity);
		void SetForce(const int16_t new_force);
		void ChangeProductivity(const int16_t delta_productivity);
		void ChangeForce(const int16_t delta_force);
		void ChangeWeaponSlot(const int16_t inv_index);
		void ChangeArmorSlot(const int16_t armor_index, const int16_t inv_index);

		Inventory& GetInventoryInstance();

		virtual ~Charity();
	};
}

