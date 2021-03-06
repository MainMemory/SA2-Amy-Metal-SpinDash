// SA2-Amy-Metal-SpinDash.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "..\sa2-mod-loader\SA2ModLoader\include\SA2ModLoader.h"

#define Texlist_SonEff 0xA08B94
#define Texlist_ShadEff 0xA08D94
#define Texlist_AmyEff 0xA08F94
#define Texlist_MetEff 0xA0917C

const int loc_757BC8 = 0x757BC8;
__declspec(naked) void loc_757BB2()
{
	__asm
	{
		test ecx, ecx
		jz NotAmy
		movsx ecx, [ecx].CharID2
		cmp	ecx, Characters_Sonic
		jne	short NotSonic
		mov	ecx, Texlist_SonEff
		jmp	loc_757BC8

NotSonic:
		cmp	ecx, Characters_Shadow
		jne	short NotShadow
		mov	ecx, Texlist_ShadEff
		jmp	loc_757BC8

NotShadow:
		cmp	ecx, Characters_Amy
		jne	short NotAmy
		mov	ecx, Texlist_AmyEff
		jmp	loc_757BC8

NotAmy:
		mov	ecx, Texlist_MetEff
		jmp	loc_757BC8
	}
}

const int loc_757D68 = 0x757D68;
__declspec(naked) void loc_757D52()
{
	__asm
	{
		test ecx, ecx
		jz NotAmy
		movsx ecx, [ecx].CharID2
		cmp	ecx, Characters_Sonic
		jne	short NotSonic
		mov	ecx, Texlist_SonEff
		jmp	loc_757D68

NotSonic:
		cmp	ecx, Characters_Shadow
		jne	short NotShadow
		mov	ecx, Texlist_ShadEff
		jmp	loc_757D68

NotShadow:
		cmp	ecx, Characters_Amy
		jne	short NotAmy
		mov	ecx, Texlist_AmyEff
		jmp	loc_757D68

NotAmy:
		mov	ecx, Texlist_MetEff
		jmp	loc_757D68
	}
}

extern "C"
{
	__declspec(dllexport) void Init(const char *path, const HelperFunctions &helperFunctions)
	{
		WriteData<2>((void*)0x723E1F, 0x90u);
		WriteJump((void*)0x757BB2, loc_757BB2);
		WriteJump((void*)0x757D52, loc_757D52);
		WriteData<2>((void*)0x72386C, 2);
	}

	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
}