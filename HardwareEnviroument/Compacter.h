// Target: Save variables in different datatypes in one and convert in needly with indexation

#pragma once
#include <string>
#include <list>

namespace hardware_envi_lib
{
	enum class DateType
	{
		str__,
		int__,
		uint_,
		bool_,
		char_,
		flot_,
		dobl_,
		shrt_,
		size_
	};

	struct float_var
	{
		std::string name;
		DateType date_type;
		std::string binary;
	};

	class Compacter
	{
		std::list<float_var> m_Variables;

		float_var& f_GetVar(const std::string str_index) const;
	public:
		void PushVariable(const DateType date_type, const std::string name, const char* p_ref);

		size_t Size() const;
		
		std::list<float_var>::const_iterator Begin() const;
		std::list<float_var>::const_iterator End() const;

		const std::string NameOfVariable(size_t index) const;

		const std::string operator[](const std::string str_index) const;
		const DateType GetDataType(const std::string str_index) const;

		bool ConvertToBool(const std::string str_index) const;
		char ConvertToChar(const std::string str_index) const;
		short ConvertToShort(const std::string str_index) const;
		int ConvertToInt(const std::string str_index) const;
		uint32_t ConvertToUInt(const std::string str_index) const;
		float ConvertToFloat(const std::string str_index) const;
		double ConvertToDouble(const std::string str_index) const;
		size_t ConvertToSize(const std::string str_index) const;

		void PopVariable(const std::string str_index);
	};
}

