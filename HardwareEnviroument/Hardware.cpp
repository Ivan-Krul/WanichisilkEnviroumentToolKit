#include "Hardware.h"

namespace hardware_envi_lib
{
	void hardware_envi_lib::Hardware::Write(const std::string directory)
	{
		auto writer = std::ofstream(directory, std::ios::binary | std::ios::out);
	}

	void hardware_envi_lib::Hardware::Read(const std::string directory)
	{
		if (!CanBeFileOpen(directory))
			return;
		auto reader = std::ifstream(directory, std::ios::binary | std::ios::in);
	}

	bool Hardware::CanBeFileOpen(const std::string directory)
	{
		auto reader = std::ifstream(directory);
		auto open = reader.is_open();

		reader.close();

		return open;
	}
}
