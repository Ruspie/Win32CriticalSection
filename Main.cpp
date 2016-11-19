#include "CriticalSection.h"
#include <conio.h>
#include <tchar.h>

int _tmain(int argc, _TCHAR *argv[])
{
	CriticalSection criticalSection;
	int idProcess;
	if (argc == 1) {

		idProcess = 1;
		STARTUPINFO startInfo = { sizeof(startInfo) };
		PROCESS_INFORMATION processInfo;
		TCHAR text[] = TEXT("two params");
		if (!CreateProcess(TEXT("Win32CriticalSection.exe"), text, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &startInfo, &processInfo)) {
			std::wcout << "Can't create process" << std::endl << GetLastError << std::endl;
			system("pause");
			return 0;
		}

		for (int i = 0; i < 100; i++) {
			criticalSection.Write(idProcess, i);
			Sleep(1000);
		}
		system("pause");

	}
	else {
		idProcess = 2;

		for (int i = 0; i < 100; i++) {
			criticalSection.Read(idProcess);
			Sleep(450);
		}

	}
	return 0;
}