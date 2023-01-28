#pragma once
#include <stdint.h>

#include "Hardware.h"

namespace battle_system_lib
{
	struct ICount
	{
		virtual const uint16_t GetCount() const = 0;
	};

	class Count
	{
		uint16_t count = 0;

		void f_Abort() const;
	public:
		void Increment();
		const uint16_t GetCount() const;
		void Decrement();
	};

	inline void Count::f_Abort() const
	{
		auto h = hardware_envi_lib::Hardware::GetInstance();

		h.WriteAbortLine(__FUNCTION__, "variable s_Count is overflow, too much objects for uint16_t");

		abort();
	}

	inline void Count::Increment()
	{
		if(count != 0xffff)
			count++;
		else
			f_Abort();
	}

	inline const uint16_t Count::GetCount() const
	{
		return count;
	}

	inline void Count::Decrement()
	{
		if (count != 0x0000)
			count--;
		else
			f_Abort();
	}

	
}
