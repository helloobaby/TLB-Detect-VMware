#include "stdafx.h"
#include "driver_unload.h"
#include"tlb_main.h"

EXTERN_C NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegPath)
{
	DriverObject->DriverUnload = DriverUnload;

	Init();
	Test();

	return STATUS_SUCCESS;
}



















