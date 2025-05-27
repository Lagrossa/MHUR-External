#include <windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <vector>

inline int GetProcId(const wchar_t* processName) {
    int procId = 0;

    // Get All Processes on System
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

    if (snapshot != INVALID_HANDLE_VALUE)
    {
        PROCESSENTRY32 proc;
        proc.dwSize = sizeof(proc);

        if (Process32First(snapshot, &proc))
        {
            do
            {
                if (!_wcsicmp(proc.szExeFile, processName))
                {
                    procId = proc.th32ProcessID;
                    break;
                }
            } while (Process32Next(snapshot, &proc));
        }
        CloseHandle(snapshot);
        return procId;
    }
}

inline uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName) {
    uintptr_t modBaseAddr = 0;
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);

    if (snapshot != INVALID_HANDLE_VALUE)
    {
        MODULEENTRY32 modEntry;
        modEntry.dwSize = sizeof(modEntry);
        if (Module32First(snapshot, &modEntry))
        {
            do
            {
                if (!_wcsicmp(modEntry.szModule, modName))
                {
                    modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
                    break;
                }               
            } while (Module32NextW(snapshot, &modEntry));
        }
    }
    CloseHandle(snapshot);
    return modBaseAddr;
}

inline uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets) {
    uintptr_t addr = ptr;
    for (unsigned int i = 0; i < offsets.size(); i++)
    {
        std::cout << "\n Current Addr: " << std::hex << addr;
        ReadProcessMemory(hProc, (BYTE*)addr, &addr, sizeof(addr), 0);
        addr += offsets[i];
    }
    std::cout << "\n Return Addr: " << std::hex << addr;
    return addr;
}