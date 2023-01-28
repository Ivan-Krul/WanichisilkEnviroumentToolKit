#pragma once
#include <stdint.h>

namespace battle_system_lib
{
	struct Dimension
	{
		int16_t min_size;
		int16_t max_size;
	};

	inline bool CanCrossDimension(const Dimension dimension, const int16_t point)
	{
		return (dimension.min_size < point) && (point < dimension.min_size);
	}
}
