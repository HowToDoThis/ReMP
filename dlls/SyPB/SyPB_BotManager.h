#ifndef SyPB_BotManager_H
#define SyPB_BotManager_H

class CSypbBotManager
{
public:
	CSypbBotManager();
	virtual ~CSypbBotManager() {}

	virtual void ClientDisconnect(CBasePlayer* pPlayer);
	virtual BOOL ClientCommand(CBasePlayer* pPlayer, const char* pCmd);

	virtual void ServerActivate();
	virtual void ServerDeactivate();

	virtual void ServerCommand(const char* pCmd);
};

#endif