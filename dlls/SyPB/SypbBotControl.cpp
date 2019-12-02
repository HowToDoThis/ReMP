#include "precompiled.h"
#include "SyPB.h"

CSypbBotControl::CSypbBotControl()
{

}

int CSypbBotControl::GetIndex(edict_t* ent)
{
	if (FNullEnt(ent))
		return -1;

	int index = ENTINDEX(ent) - 1;

	if (index < 0 | index >= 32)
		return -1;



	return 0;
}

