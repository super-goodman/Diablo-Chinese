#include "Memory.h"
#include "Windows.h"
#include "Psapi.h"
DWORD Memory::pid = 0;
HWND Memory::windowsHandle = 0;
Memory::Memory()
{
	getGameModuleBase();
}

Memory::Memory(int m_pid)
{
	pid = m_pid;
}

Memory::~Memory()
{
}


//获得游戏主模块的首地址
UINT64 Memory::getGameModuleBase()
{
	__try
	{
		windowsHandle = FindWindowA(nullptr, "Diablo Immortal");
		GetWindowThreadProcessId((HWND)windowsHandle, &pid);
		HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
		if (processHandle)
		{
			UINT64 pro_base = NULL;
			HMODULE hModule[120] = { 0 };
			DWORD dwRet = 0;
			int bRet = EnumProcessModulesEx(processHandle, (HMODULE*)(hModule), sizeof(hModule), &dwRet, NULL);
			CloseHandle(processHandle);
			return (UINT64)hModule[0];
		}
		else
		{
			return -1;
		}

	}
	__except (1)
	{

		return -1;
	}
	return -1;
}

UINT64 Memory::R8(int pid,UINT64 adr)
{
	UINT64 ret = 0;
	__try
	{
		SIZE_T bWrite = 0;
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
		ReadProcessMemory(hProcess,(LPCVOID)adr, &ret, 8, &bWrite);
		CloseHandle(hProcess);
		return ret;
	
	}
	__except (1)
	{
		return -1;
	}
	return -1;
}

UINT64 Memory::R8(UINT64 adr)
{
	if (!pid)//如果有PID
		return false;
	UINT64 ret = 0;
	__try
	{
		SIZE_T bWrite = 0;
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
		ReadProcessMemory(hProcess, (LPCVOID)adr, &ret, 8, &bWrite);
		CloseHandle(hProcess);
		return ret;

	}
	__except (1)
	{
		return -1;
	}
	return -1;
}

UINT32 Memory::R4(int pid,UINT64 adr)
{
	UINT32 ret = 0;
	__try
	{
		SIZE_T bWrite = 0;
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
		ReadProcessMemory(hProcess, (LPCVOID)adr, &ret, 4, &bWrite);
		CloseHandle(hProcess);
		return ret;
	}
	__except (1)
	{
		return -1;
	}
	return -1;
}

UINT32 Memory::R4(UINT64 adr)
{
	if (!pid)//如果有PID
		return false;
	UINT32 ret = 0;
	__try
	{
		SIZE_T bWrite = 0;
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
		ReadProcessMemory(hProcess, (LPCVOID)adr, &ret, 4, &bWrite);
		CloseHandle(hProcess);
		return ret;
	}
	__except (1)
	{
		return -1;
	}
	return -1;
}

float Memory::R4F(int pid, UINT64 adr)
{
	float ret = 0;
	__try
	{
		SIZE_T bWrite = 0;
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
		ReadProcessMemory(hProcess, (LPCVOID)adr, &ret, 4, &bWrite);
		CloseHandle(hProcess);
		return ret;
	}
	__except (1)
	{
		return -1;
	}
	return -1;
}

float Memory::R4F(UINT64 adr)
{
	if (!pid)//如果有PID
		return false;
	float ret = 0;
	__try
	{
		SIZE_T bWrite = 0;
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
		ReadProcessMemory(hProcess, (LPCVOID)adr, &ret, 4, &bWrite);
		CloseHandle(hProcess);
		return ret;
	}
	__except (1)
	{
		return -1;
	}
	return -1;
}

UINT16 Memory::R2(int pid,UINT64 adr)
{
	UINT16 ret = 0;
	__try
	{
		SIZE_T bWrite = 0;
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
		ReadProcessMemory(hProcess, (LPCVOID)adr, &ret, 2, &bWrite);
		CloseHandle(hProcess);
		return ret;
	}
	__except (1)
	{
		return -1;
	}
	return -1;
}

UINT16 Memory::R2(UINT64 adr)
{
	if (!pid)//如果有PID
		return false;
	UINT16 ret = 0;
	__try
	{
		SIZE_T bWrite = 0;
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
		ReadProcessMemory(hProcess, (LPCVOID)adr, &ret, 2, &bWrite);
		CloseHandle(hProcess);
		return ret;
	}
	__except (1)
	{
		return -1;
	}
	return -1;
}

byte Memory::R1(int pid,UINT64 adr)
{
	byte ret = 0;
	__try
	{
		SIZE_T bWrite = 0;
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
		ReadProcessMemory(hProcess, (LPCVOID)adr, &ret, 1, &bWrite);
		CloseHandle(hProcess);
		return ret;
	}
	__except (1)
	{
		return -1;
	}
	return -1;
}

byte Memory::R1(UINT64 adr)
{
	if (!pid)//如果有PID
		return false;
	byte ret = 0;
	__try
	{
		SIZE_T bWrite = 0;
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
		ReadProcessMemory(hProcess, (LPCVOID)adr, &ret, 1, &bWrite);
		CloseHandle(hProcess);
		return ret;
	}
	__except (1)
	{
		return -1;
	}
	return -1;
}

bool Memory::RM(UINT64 adr,UINT64 size, byte* buffer)
{
	if (!pid)//如果有PID
		return false;
	__try
	{
		SIZE_T bWrite = 0;
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
		bool statue = ReadProcessMemory(hProcess, (LPCVOID)adr, buffer, size, &bWrite);
		CloseHandle(hProcess);return statue;
	}
	__except (1)
	{
		return -1;
	}
	return -1;
}






bool Memory::W8(int pid, UINT64 adr, UINT64 data)
{
	SIZE_T bWrite = 0;
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	bool state = WriteProcessMemory(hProcess,(LPVOID)adr, &data,8, &bWrite);
	CloseHandle(hProcess);
	return state;
}

bool Memory::W8( UINT64 adr, UINT64 data)
{
	if (!pid)//如果有PID
		return false;
	SIZE_T bWrite = 0;
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	bool state = WriteProcessMemory(hProcess, (LPVOID)adr, &data, 8, &bWrite);
	CloseHandle(hProcess);
	return state;
}

bool Memory::W4(int pid, UINT64 adr, UINT32 data)
{
	SIZE_T bWrite = 0;
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	bool state = WriteProcessMemory(hProcess, (LPVOID)adr, &data, 4, &bWrite);
	CloseHandle(hProcess);
	return state;
}

bool Memory::W4(UINT64 adr, UINT32 data)
{
	if (!pid)//如果有PID
		return false;
	SIZE_T bWrite = 0;
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	bool state = WriteProcessMemory(hProcess, (LPVOID)adr, &data, 4, &bWrite);
	CloseHandle(hProcess);
	return state;

}

bool Memory::W4F(int pid, UINT64 adr, float data)
{

	SIZE_T bWrite = 0;
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	bool state = WriteProcessMemory(hProcess, (LPVOID)adr, &data, 4, &bWrite);
	CloseHandle(hProcess);
	return state;
}

bool Memory::W4F( UINT64 adr, float data)
{
	if (!pid)//如果有PID
		return false;
	SIZE_T bWrite = 0;
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	bool state = WriteProcessMemory(hProcess, (LPVOID)adr, &data, 4, &bWrite);
	CloseHandle(hProcess);
	return state;
}

bool Memory::W1(int pid, UINT64 adr, byte data)
{
	SIZE_T bWrite = 0;
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	bool state = WriteProcessMemory(hProcess, (LPVOID)adr, &data, 1, &bWrite);
	CloseHandle(hProcess);
	return state;
}

bool Memory::W1(UINT64 adr, byte data)
{
	if (!pid)//如果有PID
		return false;
	SIZE_T bWrite = 0;
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	bool state = WriteProcessMemory(hProcess, (LPVOID)adr, &data, 1, &bWrite);
	CloseHandle(hProcess);
	return state;

}
