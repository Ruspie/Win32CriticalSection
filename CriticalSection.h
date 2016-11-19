#pragma once
#include <Windows.h>
#include <iostream>

class CriticalSection
{
private:
	HANDLE hMap;
	HANDLE hMutex;
	LPCTSTR pBuf;
	const int BUF_SIZE = 5;
public:
	CriticalSection();
	~CriticalSection();
	void Write(int idProcess, int number);
	void Read(int idProcess);
};

