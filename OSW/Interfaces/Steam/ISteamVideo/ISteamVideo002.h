//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code, comments, and all related files, projects, resources,
// redistributables included with this project are Copyright Valve Corporation.
// Additionally, Valve, the Valve logo, Half-Life, the Half-Life logo, the
// Lambda logo, Steam, the Steam logo, Team Fortress, the Team Fortress logo,
// Opposing Force, Day of Defeat, the Day of Defeat logo, Counter-Strike, the
// Counter-Strike logo, Source, the Source logo, and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================

#ifndef ISTEAMVIDEO002_H
#define ISTEAMVIDEO002_H
#ifdef _WIN32
#pragma once
#endif

#include "Types/SteamTypes.h"
#include "Interfaces/Common/VideoCommon.h"

abstract_class ISteamVideo002
{
public:
	virtual void GetVideoURL(AppId_t appId) = 0;
	virtual bool IsBroadcasting(int32* pnNumViewers) = 0;
	virtual void GetOPFSettings(AppId_t unVideoAppID) = 0;
	virtual bool GetOPFStringForApp(AppId_t unVideoAppID, char *pchBuffer, int32 *pnBufferSize) = 0;
};


#endif // ISTEAMVIDEO002_H