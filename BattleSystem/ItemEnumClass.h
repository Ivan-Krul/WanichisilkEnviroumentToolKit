#pragma once

namespace battle_system_lib
{
	enum class ItemType
	{
		common,
		eatable,
		armor,
		shootable_weapon,
		melee_weapon, // TODO: made more types of item, such as "ItemArmor" or "ItemWeapon"
		damagable_potion,
		upgradable_potion,
		heal_potion
	};
}
