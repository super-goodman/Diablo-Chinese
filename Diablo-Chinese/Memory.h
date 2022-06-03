#pragma once
#include <windows.h>

class Memory
{
public:
	Memory();
	Memory(int m_pid);
	~Memory();

	static DWORD pid;
	static HWND windowsHandle;

	static UINT64 getGameModuleBase(DWORD pid);
	static UINT64 getGameModuleBase();
	static UINT64 R8(int pid,UINT64 adr);
	static UINT64 R8(UINT64 adr);
	static UINT32 R4(int pid,UINT64 adr);
	static UINT32 R4(UINT64 adr);
	static float R4F(int pid, UINT64 adr);
	static float R4F(UINT64 adr);
	static UINT16 R2(int pid, UINT64 adr);
	static UINT16 R2(UINT64 adr);
	static byte R1(int pid, UINT64 adr);
	static byte R1(UINT64 adr);

	static bool RM(UINT64 adr, UINT64 size, byte* buffer);


	static bool W8(int pid, UINT64 adr,UINT64 data);
	static bool W8(UINT64 adr, UINT64 data);
	static bool W4(int pid, UINT64 adr, UINT32 data);
	static bool W4(UINT64 adr, UINT32 data);
	static bool W4F(int pid, UINT64 adr, float data);
	static bool W4F(UINT64 adr, float data);
	static bool W1(int pid, UINT64 adr, byte data);
	static bool W1(UINT64 adr, byte data);





};

