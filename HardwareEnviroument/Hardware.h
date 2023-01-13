// Target: Save and load from/to file and put all in Compactor, single object

#pragma once
#include <string>
#include <vector>
#include <fstream>

#include "Compacter.h"

namespace hardware_envi_lib
{
	struct datatype
	{
		char value[5];
		char binary_value;
		DateType date_type;
	};

	class Hardware
	{
		const std::vector<datatype> scm_DataTypes =
		{
			{"str_", 's', DateType::str__},
			{"int_", 'i', DateType::int__},
			{"uint", 'u', DateType::uint_},
			{"char", 'c', DateType::char_},
			{"bool", 'b', DateType::bool_},
			{"flot", 'f', DateType::flot_},
			{"dobl", 'd', DateType::dobl_},
			{"shrt", 'r', DateType::shrt_},
			{"size", 'z', DateType::size_}
		};

		// Singleton pattern
		static Hardware s_Instance;
		Hardware() = default;
	public:
		void Write(const std::string directory);
		void Read(const std::string directory);
		bool CanBeFileOpen(const std::string directory);

		// Singleton pattern
		static Hardware& GetInstance()
		{
			return s_Instance;
		}
	};

	Hardware Hardware::s_Instance;
}
