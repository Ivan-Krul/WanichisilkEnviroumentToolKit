#include <iostream>

#include "Hardware.h"
#include "LogMachineFile.h"

#include <Windows.h>

int main()
{
	hardware_envi_lib::LogMachineFile lmf;
	lmf.Init("Logs/Tomorrow", false);
	lmf.Log(__FUNCTION__, "Hello...");
	lmf.Log(__FUNCTION__, "world!");
	lmf.LogNumberx32i(__FUNCTION__, "argument int", 15);
	lmf.LogNumberx32f(__FUNCTION__, "argument float", 15.4f);
	lmf.LogNumberx64i(__FUNCTION__, "argument int64_t", 10);
	lmf.LogNumberx64f(__FUNCTION__, "argument double", 16.9);
	
	lmf.Save();
}
