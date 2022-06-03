#pragma once
#include <string>

class Opcode
{
public:
	Opcode(int pid);
	~Opcode();
	DWORD findBaseAddressOffset(std::string markCode, UINT64 retAddrs[], int deviation, int numOffset);
	DWORD findAddressOffset(std::string markCode, UINT64 retAddrs[]);
	DWORD findAddress(std::string markCode, UINT64 retAddrs[]);
	DWORD findBunchOfBaseAddress(std::string markCode, UINT64 offset, UINT64 retAddrs[], int deviation, int numOffset);
	DWORD findMatchingCode(const HANDLE hProcess, std::string markCode, UINT64 retAddr[], const int deviation, const bool isCall, const bool isAll);
	HANDLE processHandle_;

private:
};


