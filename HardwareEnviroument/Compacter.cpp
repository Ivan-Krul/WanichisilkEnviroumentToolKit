#include "Compacter.h"

namespace hardware_envi_lib
{
	float_var& Compacter::f_GetVar(const std::string str_index) const
	{
		auto comp = [=](const float_var& fv) {return fv.name == str_index; };
		auto iter = static_cast<float_var>(*std::find_if(m_Variables.begin(), m_Variables.end(), comp));
		return iter;
	}
	void hardware_envi_lib::Compacter::PushVariable(const DateType date_type, const std::string name, const char* p_ref)
	{
		auto fl_var = float_var();
		fl_var.date_type = date_type;
		fl_var.binary = p_ref;
		fl_var.name = name;
		m_Variables.push_back(fl_var);
	}

	size_t Compacter::Size() const
	{
		return m_Variables.size();
	}

	std::list<float_var>::const_iterator Compacter::Begin() const
	{
		return m_Variables.begin();
	}

	std::list<float_var>::const_iterator Compacter::End() const
	{
		return m_Variables.end();
	}

	const std::string Compacter::NameOfVariable(size_t index) const
	{
		for (const auto& v : m_Variables)
		{
			if (index == 0)
				return v.name;
			index--;
		}
		return std::string();
	}

	const std::string Compacter::operator[](const std::string str_index) const
	{
		return f_GetVar(str_index).binary;
	}

	const DateType Compacter::GetDataType(const std::string str_index) const
	{
		return f_GetVar(str_index).date_type;
	}

	bool Compacter::ConvertToBool(const std::string str_index) const
	{
		auto elem = f_GetVar(str_index);
		if (elem.date_type != DateType::bool_)
			return bool();
		return elem.binary.c_str();
	}
	char Compacter::ConvertToChar(const std::string str_index) const
	{
		auto elem = f_GetVar(str_index);
		if (elem.date_type != DateType::char_)
			return char();
		return elem.binary.c_str()[0];
	}

	short Compacter::ConvertToShort(const std::string str_index) const
	{
		auto elem = f_GetVar(str_index);
		if (elem.date_type != DateType::shrt_ && elem.binary.size() != sizeof(short))
			return short();
		return *reinterpret_cast<short*>(const_cast<char*>(elem.binary.c_str()));
	}

	int Compacter::ConvertToInt(const std::string str_index) const
	{
		auto elem = f_GetVar(str_index);
		if (elem.date_type != DateType::int__ && elem.binary.size() != sizeof(int))
			return int();
		return *reinterpret_cast<int*>(const_cast<char*>(elem.binary.c_str()));
	}

	uint32_t Compacter::ConvertToUInt(const std::string str_index) const
	{
		auto elem = f_GetVar(str_index);
		if (elem.date_type != DateType::uint_ && elem.binary.size() != sizeof(uint32_t))
			return uint32_t();
		return *reinterpret_cast<uint32_t*>(const_cast<char*>(elem.binary.c_str()));
	}

	float Compacter::ConvertToFloat(const std::string str_index) const
	{
		auto elem = f_GetVar(str_index);
		if (elem.date_type != DateType::flot_ && elem.binary.size() != sizeof(float))
			return float();
		return *reinterpret_cast<float*>(const_cast<char*>(elem.binary.c_str()));
	}

	double Compacter::ConvertToDouble(const std::string str_index) const
	{
		auto elem = f_GetVar(str_index);
		if (elem.date_type != DateType::dobl_ && elem.binary.size() != sizeof(double))
			return double();
		return *reinterpret_cast<double*>(const_cast<char*>(elem.binary.c_str()));
	}

	size_t Compacter::ConvertToSize(const std::string str_index) const
	{
		auto elem = f_GetVar(str_index);
		if (elem.date_type != DateType::size_ && elem.binary.size() != sizeof(size_t))
			return size_t();
		return *reinterpret_cast<size_t*>(const_cast<char*>(elem.binary.c_str()));
	}

	void Compacter::PopVariable(const std::string str_index)
	{
		auto comp = [=](const float_var& fv) {return fv.name == str_index; };
		auto iter = std::find_if(m_Variables.begin(), m_Variables.end(), comp);
		m_Variables.erase(iter);
	}
}
