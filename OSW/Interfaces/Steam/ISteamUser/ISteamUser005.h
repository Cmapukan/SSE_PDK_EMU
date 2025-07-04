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

#ifndef ISTEAMUSER005_H
#define ISTEAMUSER005_H
#ifdef _WIN32
#pragma once
#endif

#include "Types/SteamTypes.h"
#include "Interfaces/Common/UserCommon.h"

abstract_class ISteamUser005
{
public:

	// returns the HSteamUser this interface represents
	// this is only used internally by the API, and by a few select interfaces that support multi-user
	virtual HSteamUser GetHSteamUser() = 0;

	// steam account management functions
	virtual void LogOn( CSteamID steamID ) = 0;
	virtual void LogOff() = 0;

	// returns true if the Steam client current has a live connection to the Steam servers. 
	// If false, it means there is no active connection due to either a networking issue on the local machine, or the Steam server is down/busy.
	// The Steam client will automatically be trying to recreate the connection as often as possible.
	virtual bool BLoggedOn() = 0;

	virtual ELogonState GetLogonState() = 0;
	virtual bool BConnected() = 0;

	// returns the CSteamID of the account currently logged into the Steam client
	// a CSteamID is a unique identifier for an account, and used to differentiate users in all parts of the Steamworks API
	STEAMWORKS_STRUCT_RETURN_0(CSteamID, GetSteamID) /*virtual CSteamID GetSteamID() = 0;*/

	// returns true if this account is VAC banned from the specified ban set
	virtual bool IsVACBanned( EVACBan eVACBan ) = 0;

	// returns true if the user needs to see the newly-banned message from the specified ban set
	virtual bool RequireShowVACBannedMessage( EVACBan eVACBan ) = 0;

	// tells the server that the user has seen the 'you have been banned' dialog
	virtual void AcknowledgeVACBanning( EVACBan eVACBan ) = 0;

	// steam2 stuff
	virtual void SetSteam2Ticket( uint8 *pubTicket, int cubTicket ) = 0;
	virtual OBSOLETE_FUNCTION void AddServerNetAddress( uint32 unIP, uint16 unPort ) = 0;

	// email address setting
	virtual bool SetEmail( const char *pchEmail ) = 0;


	// persist per user data
	virtual bool SetRegistryString( ERegistrySubTree eRegistrySubTree, const char *pchKey, const char *pchValue ) = 0;
	virtual bool GetRegistryString( ERegistrySubTree eRegistrySubTree, const char *pchKey, char *pchValue, int cbValue ) = 0;
	virtual bool SetRegistryInt( ERegistrySubTree eRegistrySubTree, const char *pchKey, int iValue ) = 0;
	virtual bool GetRegistryInt( ERegistrySubTree eRegistrySubTree, const char *pchKey, int *piValue ) = 0;

	// InitiateGameConnection() starts the state machine for authenticating the game client with the game server
	// It is the client portion of a three-way handshake between the client, the game server, and the steam servers
	//
	// Parameters:
	// void *pAuthBlob - a pointer to empty memory that will be filled in with the authentication token.
	// int cbMaxAuthBlob - the number of bytes of allocated memory in pBlob. Should be at least 2048 bytes.
	// CSteamID steamIDGameServer - the steamID of the game server, received from the game server by the client
	// int nGameID - the ID of the current game.
	// uint32 unIPServer, uint16 usPortServer - the IP address of the game server
	// bool bSecure - whether or not the client thinks that the game server is reporting itself as secure (i.e. VAC is running)
	//
	// return value - returns the number of bytes written to pBlob. If the return is 0, then the buffer passed in was too small, and the call has failed
	// The contents of pBlob should then be sent to the game server, for it to use to complete the authentication process.
	virtual int InitiateGameConnection( void *pBlob, int cbMaxBlob, CSteamID steamID, CGameID nGameAppID, uint32 unIPServer, uint16 usPortServer, bool bSecure ) = 0;

	// notify of disconnect
	// needs to occur when the game client leaves the specified game server, needs to match with the InitiateGameConnection() call
	virtual void TerminateGameConnection( uint32 unIPServer, uint16 usPortServer ) = 0;

	// controls where chat messages go to - puts the caller on top of the stack of chat destinations
	virtual void SetSelfAsPrimaryChatDestination() = 0;
    // returns true if the current caller is the one that should open new chat dialogs
	virtual bool IsPrimaryChatDestination() = 0;

	virtual void RequestLegacyCDKey( AppId_t iAppID ) = 0;

	virtual bool SendGuestPassByEmail( const char *pchEmailAccount, GID_t gidGuestPassID, bool bResending ) = 0;
	virtual bool SendGuestPassByAccountID( uint32 uAccountID, GID_t gidGuestPassID, bool bResending ) = 0;

	virtual bool AckGuestPass( const char *pchGuestPassCode ) = 0;
	virtual bool RedeemGuestPass( const char *pchGuestPassCode ) = 0;

	virtual uint32 GetGuestPassToGiveCount() = 0;
	virtual uint32 GetGuestPassToRedeemCount() = 0;
	virtual uint32 GetGuestPassLastUpdateTime() = 0;

	virtual bool GetGuestPassToGiveInfo( uint32 nPassIndex, GID_t *pgidGuestPassID, PackageId_t* pnPackageID, RTime32* pRTime32Created, RTime32* pRTime32Expiration, RTime32* pRTime32Sent, RTime32* pRTime32Redeemed, char * pchRecipientAddress, int cRecipientAddressSize ) = 0;
	virtual bool GetGuestPassToRedeemInfo( uint32 nPassIndex, GID_t *pgidGuestPassID, PackageId_t* pnPackageID, RTime32* pRTime32Created, RTime32* pRTime32Expiration, RTime32* pRTime32Sent, RTime32* pRTime32Redeemed ) = 0;
	virtual bool GetGuestPassToRedeemSenderAddress( uint32 nPassIndex, char* pchSenderAddress, int cSenderAddressSize ) = 0;
	virtual bool GetGuestPassToRedeemSenderName( uint32 nPassIndex, char* pchSenderName, int cSenderNameSize ) = 0;
	virtual void AcknowledgeMessageByGID( const char *pchMessageGID ) = 0;

	virtual bool SetLanguage( const char *pchLanguage ) = 0;

	// used by only a few games to track usage events
	virtual void TrackAppUsageEvent( CGameID gameID, EAppUsageEvent eAppUsageEvent, const char *pchExtraInfo = "" ) = 0;

	virtual void SetAccountName( const char* pchAccountName ) = 0;
	virtual void SetPassword( const char* pchPassword ) = 0;

	virtual void SetAccountCreationTime( RTime32 rtime32Time ) = 0;
};


#endif // ISTEAMUSER005_H
