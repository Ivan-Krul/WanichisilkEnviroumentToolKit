#pragma once
#include <list>

#include "Charity.h"
#include "InventoryCompacter.h"

#include "Hardware.h"

namespace battle_system_lib
{
	class CharityCompacter
	{
	public:
		Charity Decrypt(const hardware_envi_lib::Compacter& comp) const;
		const hardware_envi_lib::Compacter Encrypt(Charity& charity) const;
	};
}
