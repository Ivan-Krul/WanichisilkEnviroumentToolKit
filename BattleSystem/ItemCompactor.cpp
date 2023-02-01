#include "ItemCompactor.h"

namespace battle_system_lib
{
	void ItemCompactor::f_WriteShort(hardware_envi_lib::Compacter& compacter, const size_t index, const short var, const std::string field) const
	{
		compacter.PushVariable(hardware_envi_lib::DateType::shrt_, "item::index[" + std::to_string(index) + "]." + field, reinterpret_cast<const char*>(&var));
	}
	void ItemCompactor::f_WriteItemBase(hardware_envi_lib::Compacter& compacter, const size_t index, const std::shared_ptr<Item> item_p) const
	{
		auto bufnum = item_p->GetItemType();

		compacter.PushVariable(hardware_envi_lib::DateType::char_, "item::index[" + std::to_string(index) + "].item_type", reinterpret_cast<const char*>(&bufnum));
		compacter.PushVariable(hardware_envi_lib::DateType::str__, "item::index[" + std::to_string(index) + "].name", item_p->GetName().c_str());
		compacter.PushVariable(hardware_envi_lib::DateType::str__, "item::index[" + std::to_string(index) + "].description", item_p->GetRawDescription().c_str());
		f_WriteShort(compacter, index, item_p->GetSize(), "size");
	}
	void ItemCompactor::f_WriteItemEatable(hardware_envi_lib::Compacter& compacter, const size_t index, const std::shared_ptr<Item> item_p) const
	{
		f_WriteItemBase(compacter, index, item_p);
		f_WriteShort(compacter, index, static_cast<ItemEatable*>(&(*item_p))->GetBenefit(), "benefit");
		f_WriteShort(compacter, index, static_cast<ItemEatable*>(&(*item_p))->GetDurationOfDigestion(), "duration_of_digestion");
	}
	void ItemCompactor::f_WriteItemArmor(hardware_envi_lib::Compacter& compacter, const size_t index, const std::shared_ptr<Item> item_p) const
	{
		f_WriteItemBase(compacter, index, item_p);
		f_WriteShort(compacter, index, static_cast<ItemArmor*>(&(*item_p))->GetArmorCoef(), "armor");
	}
	void ItemCompactor::f_WriteItemPoisonHeal(hardware_envi_lib::Compacter& compacter, const size_t index, const std::shared_ptr<Item> item_p) const
	{
		f_WriteItemBase(compacter, index, item_p);
		f_WriteShort(compacter, index, static_cast<ItemUpgradablePotion*>(&(*item_p))->GetEffect(), "effect");
		f_WriteShort(compacter, index, static_cast<ItemUpgradablePotion*>(&(*item_p))->GetDuration(), "duration");
	}
	void ItemCompactor::f_WriteItemPoisonUpgradable(hardware_envi_lib::Compacter& compacter, const size_t index, const std::shared_ptr<Item> item_p) const
	{
		f_WriteItemBase(compacter, index, item_p);
		f_WriteShort(compacter, index, static_cast<ItemUpgradablePotion*>(&(*item_p))->GetEffect(), "effect");
		f_WriteShort(compacter, index, static_cast<ItemUpgradablePotion*>(&(*item_p))->GetDuration(), "duration");
		f_WriteShort(compacter, index, static_cast<ItemUpgradablePotion*>(&(*item_p))->GetUpgradeType(), "upgrade_type");
	}
	void ItemCompactor::f_WriteItemPoisonDamagable(hardware_envi_lib::Compacter& compacter, const size_t index, const std::shared_ptr<Item> item_p) const
	{
		f_WriteItemBase(compacter, index, item_p);
		f_WriteShort(compacter, index, static_cast<ItemDamagablePotion*>(&(*item_p))->GetEffect(), "effect");
		f_WriteShort(compacter, index, static_cast<ItemDamagablePotion*>(&(*item_p))->GetDuration(), "duration");
	}
	void ItemCompactor::f_WriteItemWeaponShootable(hardware_envi_lib::Compacter& compacter, const size_t index, const std::shared_ptr<Item> item_p) const
	{
		f_WriteItemBase(compacter, index, item_p);
		f_WriteShort(compacter, index, static_cast<ItemShootableWeapon*>(&(*item_p))->GetForceCoef(), "force_coef");
		f_WriteShort(compacter, index, static_cast<ItemShootableWeapon*>(&(*item_p))->GetDimensions().min_size, "dimension::min_size");
		f_WriteShort(compacter, index, static_cast<ItemShootableWeapon*>(&(*item_p))->GetDimensions().max_size, "dimension::max_size");
	}
	void ItemCompactor::f_WriteItemWeaponMelee(hardware_envi_lib::Compacter& compacter, const size_t index, const std::shared_ptr<Item> item_p) const
	{
		f_WriteItemBase(compacter, index, item_p);
		f_WriteShort(compacter, index, static_cast<ItemMeleeWeapon*>(&(*item_p))->GetForceCoef(), "force_coef");
		f_WriteShort(compacter, index, static_cast<ItemMeleeWeapon*>(&(*item_p))->GetLength(), "length");
		f_WriteShort(compacter, index, static_cast<ItemMeleeWeapon*>(&(*item_p))->GetWeight(), "weight");
	}
	void ItemCompactor::Decrypt(const hardware_envi_lib::Compacter c)
	{
		auto item_type = ItemType();
		auto item_name = std::string();
		auto item_description = std::string();
		short size = c.ConvertToShort("size"), item_size, buf1, buf2, buf3;

		for (size_t i = 0; i < size; i++)
		{
			// ItemBase
			item_type = static_cast<ItemType>(c.ConvertToChar("item::index[" + std::to_string(i) + "].item_type"));
			item_name = c["item::index[" + std::to_string(i) + "].name"];
			item_description = c["item::index[" + std::to_string(i) + "].description"];
			item_size = c.ConvertToShort("item::index[" + std::to_string(i) + "].description");

			switch (item_type)
			{
				case battle_system_lib::ItemType::eatable:
					buf1 = c.ConvertToShort("item::index[" + std::to_string(i) + "].benefit");
					buf2 = c.ConvertToShort("item::index[" + std::to_string(i) + "].duration_of_digestion");
					m_Items_p.push_back(std::make_shared<ItemEatable>(item_name, item_description, buf1, buf2,  item_size));
					break;
				case battle_system_lib::ItemType::armor:
					buf1 = c.ConvertToShort("item::index[" + std::to_string(i) + "].armor");
					m_Items_p.push_back(std::make_shared<ItemArmor>(item_name, item_description, buf1, item_size));
					break;
				case battle_system_lib::ItemType::shootable_weapon:
					buf1 = c.ConvertToShort("item::index["+std::to_string(i)+"].force_coef");
					buf2 = c.ConvertToShort("item::index["+std::to_string(i)+"].dimension::min_size");
					buf3 = c.ConvertToShort("item::index["+std::to_string(i)+"].dimension::max_size");
					m_Items_p.push_back(std::make_shared<ItemShootableWeapon>(item_name, item_description, buf1, Dimension{buf2, buf3}, item_size));
					break;
				case battle_system_lib::ItemType::melee_weapon:
					buf1 = c.ConvertToShort("item::index[" + std::to_string(i) + "].force_coef");
					buf2 = c.ConvertToShort("item::index[" + std::to_string(i) + "].length");
					buf3 = c.ConvertToShort("item::index[" + std::to_string(i) + "].weight");
					m_Items_p.push_back(std::make_shared<ItemMeleeWeapon>(item_name, item_description, buf1, buf2, buf3, item_size));
					break;
				case battle_system_lib::ItemType::damagable_potion:
					buf1 = c.ConvertToShort("item::index[" + std::to_string(i) + "].effect");
					buf2 = c.ConvertToShort("item::index[" + std::to_string(i) + "].duration");
					m_Items_p.push_back(std::make_shared<ItemDamagablePotion>(item_name, item_description, buf1, buf2, item_size));
					break;
				case battle_system_lib::ItemType::upgradable_potion:
					buf1 = c.ConvertToShort("item::index[" + std::to_string(i) + "].effect");
					buf2 = c.ConvertToShort("item::index[" + std::to_string(i) + "].duration");
					buf3 = c.ConvertToShort("item::index[" + std::to_string(i) + "].upgrade_type");
					m_Items_p.push_back(std::make_shared<ItemUpgradablePotion>(item_name, item_description, buf1, buf2, ItemUpgradablePotion::UpgradeType(buf3), item_size));
					break;
				case battle_system_lib::ItemType::heal_potion:
					buf1 = c.ConvertToShort("item::index[" + std::to_string(i) + "].effect");
					buf2 = c.ConvertToShort("item::index[" + std::to_string(i) + "].duration");
					m_Items_p.push_back(std::make_shared<ItemHealPotion>(item_name, item_description, buf1, buf2, item_size));
					break;
				default:
					break;
			}
		}
	}

	const hardware_envi_lib::Compacter ItemCompactor::Encrypt() const
	{
		auto compacter = hardware_envi_lib::Compacter();
		auto bufnum = m_Items_p.size();
		auto index = size_t();

		compacter.PushVariable(hardware_envi_lib::DateType::shrt_, "size", reinterpret_cast<const char*>(&bufnum));

		for (const auto& item_p : m_Items_p)
		{
			switch (item_p->GetItemType())
			{
				case battle_system_lib::ItemType::eatable:
					f_WriteItemEatable(compacter, index, item_p);
					break;
				case battle_system_lib::ItemType::armor:
					f_WriteItemArmor(compacter, index, item_p);
					break;
				case battle_system_lib::ItemType::shootable_weapon:
					f_WriteItemWeaponShootable(compacter, index, item_p);
					break;
				case battle_system_lib::ItemType::melee_weapon:
					f_WriteItemWeaponMelee(compacter, index, item_p);
					break;
				case battle_system_lib::ItemType::damagable_potion:
					f_WriteItemPoisonDamagable(compacter, index, item_p);
					break;
				case battle_system_lib::ItemType::upgradable_potion:
					f_WriteItemPoisonUpgradable(compacter, index, item_p);
					break;
				case battle_system_lib::ItemType::heal_potion:
					f_WriteItemPoisonHeal(compacter, index, item_p);
					break;
				default:
					f_WriteItemBase(compacter, index, item_p);
					break;
			}
			index++;
		}

		return compacter;
	}

	void ItemCompactor::Copy(const Inventory& inv)
	{
		if (!m_Items_p.empty())
			m_Items_p.clear();
		for (const auto& items : inv)
			m_Items_p.push_back(items);
	}

	Inventory ItemCompactor::Paste() const
	{
		Inventory i;
		for (auto& it : m_Items_p)
			i.PushItem(it);
		return i;
	}

	// TODO: do the realization of the class

	size_t ItemCompactor::size() const
	{
		return m_Items_p.size();
	}

	void ItemCompactor::push(const std::shared_ptr<Item>&& item_p)
	{
		m_Items_p.push_back(item_p);
	}

	void ItemCompactor::pop(const std::list<std::shared_ptr<Item>>::iterator iter)
	{
		m_Items_p.erase(iter);
	}

	std::list<std::shared_ptr<Item>>::const_iterator ItemCompactor::begin() const
	{
		return m_Items_p.begin();
	}

	std::list<std::shared_ptr<Item>>::const_iterator ItemCompactor::end() const
	{
		return m_Items_p.end();
	}

	void ItemCompactor::clear()
	{
		m_Items_p.clear();
	}
}
