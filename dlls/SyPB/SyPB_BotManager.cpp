#include "precompiled.h"
#include "SyPB.h"

void CSypbBotManager::ServerCommand(const char* pCmd)
{
	if (!AreBotsAllowed())
		return;

	char buffer[128];
	const char* msg = CMD_ARGV(1);

	if (FStrEq(msg, "version"))
		return;
	else
	{
		CONSOLE_ECHO("sypb version	|	Show SyPB Version");
	}
}
