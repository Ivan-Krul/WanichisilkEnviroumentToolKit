#pragma once
#include <memory>
#include <list>

#include "ItemLib.h"
#include "Inventory.h"

#include "Compacter.h"

namespace battle_system_lib
{
	class InventoryCompacter
	{
		std::list<v_Item_p> m_Items_p;

		void f_WriteShort(hardware_envi_lib::Compacter& compacter, const size_t index, const short var, const std::string field) const;

		void f_WriteItemBase(hardware_envi_lib::Compacter& compacter, const size_t index, const v_Item_p item_p) const;
		void f_WriteItemEatable(hardware_envi_lib::Compacter& compacter, const size_t index, const v_Item_p item_p) const;
		void f_WriteItemArmor(hardware_envi_lib::Compacter& compacter, const size_t index, const v_Item_p item_p) const;
		void f_WriteItemPoisonHeal(hardware_envi_lib::Compacter& compacter, const size_t index, const v_Item_p item_p) const;
		void f_WriteItemPoisonUpgradable(hardware_envi_lib::Compacter& compacter, const size_t index, const v_Item_p item_p) const;
		void f_WriteItemPoisonDamagable(hardware_envi_lib::Compacter& compacter, const size_t index, const v_Item_p item_p) const;
		void f_WriteItemWeaponShootable(hardware_envi_lib::Compacter& compacter, const size_t index, const v_Item_p item_p) const;
		void f_WriteItemWeaponMelee(hardware_envi_lib::Compacter& compacter, const size_t index, const v_Item_p item_p) const;
	public:
		void Decrypt(const hardware_envi_lib::Compacter& c);
		const hardware_envi_lib::Compacter Encrypt() const;

		void copy(const Inventory& inv);
		Inventory paste() const;

		size_t size() const;

		void push(const v_Item_p && item_p);
		void pop(const std::list<v_Item_p>::iterator iter);

		std::list<v_Item_p>::const_iterator begin() const;
		std::list<v_Item_p>::const_iterator end() const;

		void clear();
	};
}
