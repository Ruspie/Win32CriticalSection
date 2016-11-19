#include "CriticalSection.h"

CriticalSection::CriticalSection()
{
	hMap = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 100, "FileMapping");
	hMutex = CreateMutex(NULL, FALSE, "Mutex");
}


CriticalSection::~CriticalSection()
{
	CloseHandle(hMap);
	CloseHandle(hMutex);
}

void CriticalSection::Write(int idProcess, int number)
{
	WaitForSingleObject(hMutex, INFINITE);
	pBuf = (LPCTSTR)MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, BUF_SIZE);
	TCHAR chMessage[5];
	wsprintf(chMessage, "%d", number);
	CopyMemory((PVOID)pBuf, chMessage, (5 * sizeof(TCHAR)));
	std::wcout << idProcess << L" process write : " << number << std::endl;
	ReleaseMutex(hMutex);
}

void CriticalSection::Read(int idProcess)
{
	WaitForSingleObject(hMutex, INFINITE);
	pBuf = (LPCUTSTR)MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, BUF_SIZE);
	std::wcout << L" process read : " << pBuf << std::endl;
	ReleaseMutex(hMutex);
}
