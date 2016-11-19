#pragma once
#include <Windows.h>


class CriticalSection
{
private:
	HANDLE hMap;
	HANDLE hMutex;
	const int BUF_SIZE = 5;
public:
	CriticalSection();
	~CriticalSection();
	void Write(int);
	void Read();
};

