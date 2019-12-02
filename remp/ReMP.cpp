#include "precompiled.h"

enginefuncs_t gEngfuncReMP;

int ReMP_PrecacheModel(const char* model)
{
	if (strstr(model, "shield"))
	{
		if (_DEBUG)
			CONSOLE_ECHO("PrecacheModel | Found: %s, Using return 4\n", model);
		return 4;
	}
	else
		if (_DEBUG)
			CONSOLE_ECHO("PrecacheModel | Found: %s\n", model);

	return gEngfuncReMP.pfnPrecacheModel(model);
}

int ReMP_PrecacheSound(const char* sound)
{
	if (strstr(sound, "shield"))
	{
		if (_DEBUG)
			CONSOLE_ECHO("PrecacheSound | Found: %s, Using return 4\n", sound);
		return 4;
	}
	else
		if (_DEBUG)
			CONSOLE_ECHO("PrecacheSound | Found: %s\n", sound);

	return gEngfuncReMP.pfnPrecacheSound(sound);
}

unsigned short ReMP_PrecacheEvent(int type, const char* psz)
{
	// try to know each event function?
	if (_DEBUG)
		CONSOLE_ECHO("PrecacheEvent | type: %d, psz: %s\n", type, psz);

	return gEngfuncReMP.pfnPrecacheEvent(type, psz);
}