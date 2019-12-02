#ifndef SypbBotControl_H
#define SypbBotControl_H

#include "precompiled.h"

class CSypbBotControl : public CSypbBotManager
{
public:
	CSypbBotControl();
	virtual ~CSypbBotControl() {}

	int GetIndex(edict_t* ent);
};

#endif