#pragma once
#include <list>

#include "ILogMachine.h"

namespace hardware_envi_lib
{
	class LogMachineFile : public ILogMachine
	{
	public:
		LogMachineFile() = default;
		inline LogMachineFile(const std::string& path, const bool need_binary) noexcept { Init(path, need_binary); }

		virtual void Init(const std::string& path, const bool need_binary) noexcept;
		virtual void Log(const char* pFunction_name, const std::string& message) noexcept;
		virtual void LogNumberx64i(const char* pFunction_name, const std::string& message, const int64_t argument) noexcept;
		virtual void LogNumberx64f(const char* pFunction_name, const std::string& message, const double argument) noexcept;
		virtual void LogNumberx32i(const char* pFunction_name, const std::string& message, const int32_t argument) noexcept;
		virtual void LogNumberx32f(const char* pFunction_name, const std::string& message, const float argument) noexcept;
		virtual void Save() noexcept;
		virtual ~LogMachineFile() = default;

	private:
		template<typename T>
		void f_WriteAnyLogWithArgument(const char* pFunction_name, const std::string& message, T argument);

		std::list<std::string> m_Logs;
		std::string m_Path;
		bool m_NeedBinary = false;

		const std::string c_LogFormat = ":\t";
	};
}
