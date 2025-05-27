#include <iostream>
#include <cstdint>
#include "Offsets.h"
#include "WindowsOtter.cpp"
#include "UEngine.h"

uintptr_t GWORLD = 0;
uintptr_t GENGINE = 0;
HANDLE hProcess;
uintptr_t moduleBase;


// Addresses
uintptr_t localGravity;
uintptr_t localJump;
uintptr_t localReload;
uintptr_t localTurnRate;
uintptr_t localCrawlSpeed;
uintptr_t localRollInitialSpeed;
uintptr_t localRollFinalSpeed;
uintptr_t localdashInitialSpeed;

//Values
float jumpHeight = 2.0;
float gravAmt = 1;
float reloadRate = 8.0;
float turnRate = 1.0;
float crawlSpeed = 1.75;
float rollInitialSpeed = 2100;
float rollFinalSpeed = 1700;
float dashInitialSpeed = 1200;

void CalculateAddresses()
{

    //Create GWORLD    
   ReadProcessMemory(hProcess, (BYTE*)(moduleBase + Offsets::GWORLD), &GWORLD, sizeof(GWORLD), nullptr);

    //Create GENGINE    
   ReadProcessMemory(hProcess, (BYTE*)(moduleBase + Offsets::GENGINE), &GENGINE, sizeof(GENGINE), nullptr);
   localGravity = FindDMAAddy(hProcess, GENGINE + (unsigned int)UEngine::Engine::GameInstance, Offsets::gravityOffsets);
   localJump = FindDMAAddy(hProcess, GENGINE + (unsigned int)UEngine::Engine::GameInstance, Offsets::jumpOffsets);
   localReload = FindDMAAddy(hProcess, GENGINE + (unsigned int)UEngine::Engine::GameInstance, Offsets::cooldownOffsets);
   localTurnRate = FindDMAAddy(hProcess, GENGINE + (unsigned int)UEngine::Engine::GameInstance, Offsets::runTurnRateOffsets);
   localCrawlSpeed = FindDMAAddy(hProcess, GENGINE + (unsigned int)UEngine::Engine::GameInstance, Offsets::crawlSpeedOffsets);
   localRollInitialSpeed = FindDMAAddy(hProcess, GENGINE + (unsigned int)UEngine::Engine::GameInstance, Offsets::rollInitialSpeedOffsets);
   localRollFinalSpeed = FindDMAAddy(hProcess, GENGINE + (unsigned int)UEngine::Engine::GameInstance, Offsets::rollFinalSpeedOffsets);
   localdashInitialSpeed = FindDMAAddy(hProcess, GENGINE + (unsigned int)UEngine::Engine::GameInstance, Offsets::dashInitialSpeedOffsets);
}

void SetValues()
{
    CalculateAddresses();    
    WriteProcessMemory(hProcess, (BYTE*)localGravity, &gravAmt, sizeof(gravAmt), nullptr);
    WriteProcessMemory(hProcess, (BYTE*)localJump, &jumpHeight, sizeof(jumpHeight), nullptr);
    WriteProcessMemory(hProcess, (BYTE*)localReload, &(reloadRate), sizeof(reloadRate), nullptr);
    WriteProcessMemory(hProcess, (BYTE*)localTurnRate, &(turnRate), sizeof(turnRate), nullptr);
    WriteProcessMemory(hProcess, (BYTE*)localCrawlSpeed, &(crawlSpeed), sizeof(crawlSpeed), nullptr);
    WriteProcessMemory(hProcess, (BYTE*)localRollInitialSpeed, &(rollInitialSpeed), sizeof(rollInitialSpeed), nullptr);
    WriteProcessMemory(hProcess, (BYTE*)localRollFinalSpeed, &(rollFinalSpeed), sizeof(rollFinalSpeed), nullptr);
    WriteProcessMemory(hProcess, (BYTE*)localdashInitialSpeed, &(dashInitialSpeed), sizeof(dashInitialSpeed), nullptr);
}


int main() {
    //Get Process ID
    DWORD procId = GetProcId(L"MHUR.exe");
    
    std::cout << "Process ID is: " << procId << "\n";

    //Get moduleBaseAddress
    moduleBase = GetModuleBaseAddress(procId, L"MHUR.exe");
    
    std::cout << "Module Base is: " << std::hex << moduleBase;

    //Get Handle to Process
    hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, procId);
   
    CalculateAddresses();

    std::cout << "\nGWORLD IS: " << std::hex << GWORLD << "\nGENGINE IS: " << std::hex << GENGINE;   

    SetValues();


}