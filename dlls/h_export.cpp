#include "precompiled.h"

// Holds engine functionality callbacks
enginefuncs_t g_engfuncs;
globalvars_t *gpGlobals;

// Receive engine function table from engine.
// This appears to be the _first_ DLL routine called by the engine, so we
// do some setup operations here.
C_DLLEXPORT void WINAPI GiveFnptrsToDll(enginefuncs_t *pEnginefuncsTable, globalvars_t *pGlobals)
{
	Q_memcpy(&g_engfuncs, pEnginefuncsTable, sizeof(enginefuncs_t));
	Q_memcpy(&gEngfuncReMP, &g_engfuncs, sizeof(enginefuncs_t));
	gpGlobals = pGlobals;

	// now let us hook some function
	g_engfuncs.pfnPrecacheModel = ReMP_PrecacheModel;
	g_engfuncs.pfnPrecacheSound = ReMP_PrecacheSound;
	g_engfuncs.pfnPrecacheEvent = ReMP_PrecacheEvent;

	FileSystem_Init();
	Regamedll_Game_Init();
}

// DLL entry point
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
	}
	else if (fdwReason == DLL_PROCESS_DETACH)
	{
	}

	return TRUE;
}