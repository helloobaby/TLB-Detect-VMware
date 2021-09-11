#include "tlb_main.h"
#include "PDBSDK.h"
#include<intrin.h>

#pragma section("mysec",read,write)
#pragma section("mysec2",read,write)

//
//test a var
//
__declspec(allocate("mysec"))
ULONG64 t_a;

//
//test b var
//
__declspec(allocate("mysec2"))
ULONG64 t_b;

//
//4K page size
//
#define GetPteAddress(x) ((HARDWARE_PTE*)( (((ULONG_PTR)x&0xffffffffffff) >> 12)*8 + PteBase))


void Init()
{
	NtBase = GetKernelBase();
	PteBase = *(ULONG_PTR*)(NtBase + OffsetMmPteBase);

	Log("[INFO]NtBase = %p\n", NtBase);
	Log("[INFO]PteBase = %p\n", PteBase);
}

void Test()
{
	t_a = 0x1111111111111111;
	t_b = 0x2222222222222222;
	
	HARDWARE_PTE* a_pte = GetPteAddress(&t_a);
	HARDWARE_PTE* b_pte = GetPteAddress(&t_b);
	auto old_a_pte = *a_pte;

#if 0
	DbgBreakPoint();
	Log("[INFO]t_a = %p\n", &t_a);
	Log("[INFO]a_pte = %p\n", a_pte);
#endif
	//
	//修改PTE
	//
	*a_pte = *b_pte;

	//强制vm-exit
	int tmp[4];
	__cpuid(tmp, 1);

	//测试刷新TLB
#if 0
	//__invlpg(&t_a);
#endif 
	//
	//tlb无效输出一串2
	//tlb有效输出一串1
	//
	Log("new t_a %p\n", t_a);

	//
	//recover
	//
	*a_pte = old_a_pte;
	


}