#pragma once
#include "ILogMachine.h"

namespace hardware_envi_lib
{
	class LogMachineFile : public ILogMachine
	{
	public:
		virtual void Init(const std::string& path) noexcept;
		virtual void Log(const std::string& message) noexcept;
		virtual void LogNumber(const std::string& message, const uint64_t argument) noexcept;
		virtual void LogNumber(const std::string& message, const int64_t argument) noexcept;
		virtual void LogNumber(const std::string& message, const double argument) noexcept;
		virtual void LogNumberx32(const std::string& message, const uint32_t argument) noexcept;
		virtual void LogNumberx32(const std::string& message, const int32_t argument) noexcept;
		virtual void LogNumberx32(const std::string& message, const float argument) noexcept;
		virtual void Save() noexcept;
		virtual ~LogMachineFile() = default;
	};
}
