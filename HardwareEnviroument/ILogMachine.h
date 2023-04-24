#pragma once
#include <string>

namespace hardware_envi_lib
{
	struct ILogMachine
	{
		virtual void Init(const std::string& path) noexcept = 0;
		virtual void Log(const std::string& message) noexcept = 0;
		virtual void LogNumber(const std::string& message, const uint64_t argument) noexcept = 0;
		virtual void LogNumber(const std::string& message, const int64_t argument) noexcept = 0;
		virtual void LogNumber(const std::string& message, const double argument) noexcept = 0;
		virtual void LogNumberx32(const std::string& message, const uint32_t argument) noexcept = 0;
		virtual void LogNumberx32(const std::string& message, const int32_t argument) noexcept = 0;
		virtual void LogNumberx32(const std::string& message, const float argument) noexcept = 0;
		virtual void Save() noexcept = 0;
		virtual ~ILogMachine() = default;
	};
}
