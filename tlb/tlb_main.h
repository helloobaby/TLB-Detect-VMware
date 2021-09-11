#pragma once
#include"stdafx.h"
#include"KernelBase.h"

typedef struct _HARDWARE_PTE           // 16 elements, 0x8 bytes (sizeof) 
{
    /*0x000*/     UINT64       Valid : 1;            // 0 BitPosition                   
    /*0x000*/     UINT64       Write : 1;            // 1 BitPosition                   
    /*0x000*/     UINT64       Owner : 1;            // 2 BitPosition                   
    /*0x000*/     UINT64       WriteThrough : 1;     // 3 BitPosition                   
    /*0x000*/     UINT64       CacheDisable : 1;     // 4 BitPosition                   
    /*0x000*/     UINT64       Accessed : 1;         // 5 BitPosition                   
    /*0x000*/     UINT64       Dirty : 1;            // 6 BitPosition                   
    /*0x000*/     UINT64       LargePage : 1;        // 7 BitPosition                   
    /*0x000*/     UINT64       Global : 1;           // 8 BitPosition                   
    /*0x000*/     UINT64       CopyOnWrite : 1;      // 9 BitPosition                   
    /*0x000*/     UINT64       Prototype : 1;        // 10 BitPosition                  
    /*0x000*/     UINT64       reserved0 : 1;        // 11 BitPosition                  
    /*0x000*/     UINT64       PageFrameNumber : 36; // 12 BitPosition                  
    /*0x000*/     UINT64       reserved1 : 4;        // 48 BitPosition                  
    /*0x000*/     UINT64       SoftwareWsIndex : 11; // 52 BitPosition                  
    /*0x000*/     UINT64       NoExecute : 1;        // 63 BitPosition                  
}HARDWARE_PTE, * PHARDWARE_PTE;

inline ULONG_PTR NtBase;
inline ULONG_PTR PteBase;

void Init();

void Test();