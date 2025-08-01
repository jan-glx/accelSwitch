#include "stdafx.h"
#include "windows.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestToggle)
		{
			int pvParam[3]; 
			if (!SystemParametersInfoW(SPI_GETMOUSE, 0, pvParam, 0))
				ExitProcess(GetLastError());
			int before = pvParam[2];

			STARTUPINFO info = { sizeof(info) };
			PROCESS_INFORMATION processInfo;
			wchar_t command[] = L"accelSwitch.exe toggle";
			if (!CreateProcessW(NULL, command, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo))
				ExitProcess(GetLastError());
			WaitForSingleObject(processInfo.hProcess, INFINITE);
			CloseHandle(processInfo.hProcess);
			CloseHandle(processInfo.hThread);
			
			if (!SystemParametersInfoW(SPI_GETMOUSE, 0, pvParam, 0))
				ExitProcess(GetLastError());
			Assert::AreEqual(!!before, !pvParam[2]);
		}

                TEST_METHOD(TestOffOn)
		{
			int pvParam[3];

			STARTUPINFO info = { sizeof(info) };
			PROCESS_INFORMATION processInfo;

			wchar_t command[] = L"accelSwitch.exe off";
			if (!CreateProcessW(NULL, command, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo))
				ExitProcess(GetLastError());
			WaitForSingleObject(processInfo.hProcess, INFINITE);
			CloseHandle(processInfo.hProcess);
			CloseHandle(processInfo.hThread);

			if (!SystemParametersInfoW(SPI_GETMOUSE, 0, pvParam, 0))
				ExitProcess(GetLastError());
			Assert::AreEqual(pvParam[2], 0);

			wchar_t command2[] = L"accelSwitch.exe on";
			if (!CreateProcessW(NULL, command2, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo))
				ExitProcess(GetLastError());
			WaitForSingleObject(processInfo.hProcess, INFINITE);
			CloseHandle(processInfo.hProcess);
			CloseHandle(processInfo.hThread);

			if (!SystemParametersInfoW(SPI_GETMOUSE, 0, pvParam, 0))
				ExitProcess(GetLastError());
			Assert::AreEqual(pvParam[2], 1);
		}

	};
}