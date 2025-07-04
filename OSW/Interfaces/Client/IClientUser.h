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

#ifndef ICLIENTUSER_H
#define ICLIENTUSER_H
#ifdef _WIN32
#pragma once
#endif

#include "Types/SteamTypes.h"
#include "Interfaces/Common/UserCommon.h"
#include "Interfaces/Common/ContentServerCommon.h"
#include "Interfaces/Common/ParentalSettingsCommon.h"

// Protobuf'ed class
class ClientAppInfo
#ifdef _S4N_
{
	int m_iPadding;
}
#endif
;

// Protobuf, see steammessages_offline.steamclient.proto
class COffline_OfflineLogonTicket
#ifdef _S4N_
{
	int m_iPadding;
}
#endif
;

abstract_class UNSAFE_INTERFACE IClientUser
{
public:
	virtual HSteamUser GetHSteamUser() = 0;
	virtual void LogOn( CSteamID steamID ) = 0;
	virtual void LogOnWithPassword( const char * pchLogin, const char * pchPassword ) = 0;
	virtual void LogOnAndCreateNewSteamAccountIfNeeded() = 0;
	virtual unknown_ret VerifyOfflineLogon() = 0;
	virtual void LogOff() = 0;
	virtual bool BLoggedOn() = 0;
	virtual ELogonState GetLogonState() = 0;
	virtual bool BConnected() = 0;
	virtual bool BTryingToLogin() = 0;
	STEAMWORKS_STRUCT_RETURN_0(CSteamID, GetSteamID) /*virtual CSteamID GetSteamID() = 0;*/
	STEAMWORKS_STRUCT_RETURN_0(CSteamID, GetConsoleSteamID) /*virtual CSteamID GetConsoleSteamID() = 0;*/
	virtual uint32 GetClientInstanceID() = 0;
	virtual bool IsVACBanned( AppId_t nGameID ) = 0;
	virtual bool SetEmail( const char *pchEmail ) = 0;
	virtual bool SetConfigString( ERegistrySubTree eRegistrySubTree, const char *pchKey, const char *pchValue ) = 0;
	virtual bool GetConfigString( ERegistrySubTree eRegistrySubTree, const char *pchKey, char *pchValue, int32 cbValue ) = 0;
	virtual bool SetConfigInt( ERegistrySubTree eRegistrySubTree, const char *pchKey, int32 iValue ) = 0;
	virtual bool GetConfigInt( ERegistrySubTree eRegistrySubTree, const char *pchKey, int32 *pValue ) = 0;
	virtual bool DeleteConfigKey( ERegistrySubTree eRegistrySubTree, const char *pchKey ) = 0;
	virtual bool GetConfigStoreKeyName( ERegistrySubTree eRegistrySubTree, const char *pchKey, char *pchStoreName, int32 cbStoreName ) = 0;
	virtual int32 InitiateGameConnection( void *pOutputBlob, int32 cbBlobMax, CSteamID steamIDGS, CGameID gameID, uint32 unIPServer, uint16 usPortServer, bool bSecure ) = 0;
	virtual int32 InitiateGameConnectionOld( void *pOutputBlob, int32 cbBlobMax, CSteamID steamIDGS, CGameID gameID, uint32 unIPServer, uint16 usPortServer, bool bSecure, void *pvSteam2GetEncryptionKey, int32 cbSteam2GetEncryptionKey ) = 0;
	virtual void TerminateGameConnection( uint32 unIPServer, uint16 usPortServer ) = 0;
	virtual bool TerminateAppMultiStep( uint32, uint32 ) = 0;
	virtual void SetSelfAsPrimaryChatDestination() = 0;
	virtual bool IsPrimaryChatDestination() = 0;
	virtual void RequestLegacyCDKey( AppId_t iAppID ) = 0;
	virtual bool AckGuestPass( const char *pchGuestPassCode ) = 0;
	virtual bool RedeemGuestPass( const char *pchGuestPassCode ) = 0;
	virtual uint32 GetGuestPassToGiveCount() = 0;
	virtual uint32 GetGuestPassToRedeemCount() = 0;
	virtual bool GetGuestPassToGiveInfo( uint32 nPassIndex, GID_t *pgidGuestPassID, PackageId_t* pnPackageID, RTime32* pRTime32Created, RTime32* pRTime32Expiration, RTime32* pRTime32Sent, RTime32* pRTime32Redeemed, char* pchRecipientAddress, int32 cRecipientAddressSize ) = 0;
	virtual unknown_ret GetGuestPassToGiveOut(uint32) = 0;
	virtual unknown_ret GetGuestPassToRedeem(uint32) = 0;
	virtual bool GetGuestPassToRedeemInfo( uint32 nPassIndex, GID_t *pgidGuestPassID, PackageId_t* pnPackageID, RTime32* pRTime32Created, RTime32* pRTime32Expiration, RTime32* pRTime32Sent, RTime32* pRTime32Redeemed ) = 0;
	virtual bool GetGuestPassToRedeemSenderName( uint32 nPassIndex, char* pchSenderName, int32 cSenderNameSize ) = 0;
	virtual int32 GetNumAppsInGuestPassesToRedeem() = 0;
	virtual unknown_ret GetAppsInGuestPassesToRedeem(uint32*, uint32) = 0;
	virtual SteamAPICall_t RequestStoreAuthURL(const char *) = 0;
	virtual bool SetLanguage( const char *pchLanguage ) = 0;
	virtual void TrackAppUsageEvent( CGameID gameID, int32 eAppUsageEvent, const char *pchExtraInfo = "" ) = 0;
	virtual int32 RaiseConnectionPriority( EConnectionPriority eConnectionPriority ) = 0;
	virtual void ResetConnectionPriority( int32 hRaiseConnectionPriorityPrev ) = 0;
	virtual bool BHasCachedCredentials( const char * pchUnk ) = 0;
	virtual bool SetAccountNameForCachedCredentialLogin( const char *pchAccountName, bool bUnk ) = 0;
	virtual bool GetCurrentWebAuthToken( char *pchBuffer, int32 cubBuffer, char *pchBuffer2, int32 cubBuffer2 ) = 0;
	virtual SteamAPICall_t RequestWebAuthToken() = 0;
	virtual void SetLoginInformation( const char *pchAccountName, const char *pchPassword, bool bRememberPassword ) = 0;
	virtual void SetTwoFactorCode(const char *) = 0;
	virtual void ClearAllLoginInformation() = 0;
	virtual bool GetLanguage( char* pchLanguage, int32 cbLanguage ) = 0;
	virtual bool BIsCyberCafe() = 0;
	virtual bool BIsAcademicAccount() = 0;
	virtual bool BIsPortal2EducationAccount() = 0;
	virtual bool BIsAlienwareDemoAccount() = 0;
	virtual void CreateAccount( const char *pchAccountName, const char *pchNewPassword, const char *pchNewEmail, int32 iQuestion, const char *pchNewQuestion, const char *pchNewAnswer ) = 0;
	virtual SteamAPICall_t ResetPassword( const char *pchAccountName, const char *pchOldPassword, const char *pchNewPassword, const char *pchValidationCode, const char *pchAnswer, const char* pchUnk ) = 0;
	virtual EResult ValidatePasswordResetCodeAndSendSms(const char *, const char *) = 0;
	virtual void TrackNatTraversalStat( const CNatTraversalStat *pNatStat ) = 0;
	virtual void TrackSteamUsageEvent( ESteamUsageEvent eSteamUsageEvent, const uint8 *pubKV, uint32 cubKV ) = 0;
	virtual void TrackSteamGUIUsage( const char * ) = 0;
	virtual void SetComputerInUse() = 0;
	virtual bool BIsGameRunning( CGameID gameID ) = 0;
	virtual bool BIsGameWindowReady( CGameID gameID ) = 0;
	virtual bool BUpdateAppOwnershipTicket( AppId_t nAppID, bool bOnlyUpdateIfStale, bool bIsDepot ) = 0;
	virtual bool RequestCustomBinary( const char *pszAbsolutePath, AppId_t nAppID, bool bForceUpdate, bool bAppLaunchRequest ) = 0;
	virtual EResult GetCustomBinariesState( AppId_t unAppID, int64* iUnk1, int64* iUnk2 ) = 0;
	virtual EResult RequestCustomBinaries( AppId_t unAppID, bool, bool, uint32 * ) = 0;
	virtual void SetCellID( CellID_t cellID ) = 0;
	virtual const char *GetUserBaseFolder() = 0;
	virtual bool GetUserDataFolder( CGameID gameID, char* pchBuffer, int32 cubBuffer ) = 0;
	virtual bool GetUserConfigFolder( char *pchBuffer, int32 cubBuffer ) = 0;
	virtual bool GetAccountName( char* pchAccountName, uint32 cb ) = 0;
	virtual bool GetAccountName( CSteamID userID, char * pchAccountName, uint32 cb ) = 0;
	virtual bool IsPasswordRemembered() = 0;
	virtual void CheckoutSiteLicenseSeat( uint32 uUnk ) = 0;
	virtual void GetAvailableSeats( uint32 uUnk ) = 0;
	virtual const char* GetAssociatedSiteName() = 0;
	virtual bool BIsRunningInCafe() = 0;
	virtual bool RequiresLegacyCDKey( AppId_t nAppID, bool * pbUnk ) = 0;
	virtual bool GetLegacyCDKey( AppId_t nAppID, char* pchKeyData, int32 cbKeyData ) = 0;
	virtual bool SetLegacyCDKey( AppId_t nAppID, const char* pchKeyData ) = 0;
	virtual bool WriteLegacyCDKey( AppId_t nAppID ) = 0;
	virtual void RemoveLegacyCDKey( AppId_t nAppID ) = 0;
	virtual void RequestLegacyCDKeyFromApp( AppId_t nMainAppID, AppId_t nDLCAppID, uint32 uUnk ) = 0;
	virtual bool BIsAnyGameRunning() = 0;
	virtual void TestAvailablePassword( const uint8 *pubDigestPassword, int32 cubDigestPassword ) = 0;
	virtual void GetSteamGuardDetails() = 0;
	virtual void GetTwoFactorDetails() = 0;
	virtual bool BHasTwoFactor() = 0;
	virtual void RecoverAuthenticator( const char *, const char *, const char *, const char *, const char *) = 0;
	virtual void ChangePassword( const char *pchOldPassword, const char *pchNewPassword ) = 0;
	virtual bool GetEmail( char* pchEmail, int32 cchEmail, bool* pbValidated ) = 0;
	virtual void RequestForgottenPasswordEmail( const char *pchAccountName, const char *pchTriedPassword ) = 0;
	virtual void RequestAccountResetDetails( const char *, const char * ) = 0;
	virtual void FindAccountsByEmailAddress( const char *pchEmailAddress ) = 0;
	virtual void FindAccountsByCdKey( const char *pchCdKey ) = 0;
	virtual void GetNumAccountsWithEmailAddress( const char * pchEmailAddress ) = 0;
	virtual void IsAccountNameInUse( const char * pchAccountName ) = 0;
	virtual void Test_FakeConnectionTimeout() = 0;
	virtual bool RunInstallScript( AppId_t pAppIDs, const char *pchUnk, bool bUninstall ) = 0;
	virtual AppId_t IsInstallScriptRunning() = 0;
	virtual bool GetInstallScriptState( char* pchDescription, uint32 cchDescription, uint32* punNumSteps, uint32* punCurrStep ) = 0;
	virtual bool SpawnProcess( const char *lpApplicationName, const char *lpCommandLine, uint32 dwCreationFlags, const char *lpCurrentDirectory, CGameID gameID, const char *pchGameName, uint32 uUnk, uint32 uUnk2 ) = 0;
	virtual uint32 GetAppOwnershipTicketLength( uint32 nAppID ) = 0;
	virtual uint32 GetAppOwnershipTicketData( uint32 nAppID, void *pvBuffer, uint32 cbBufferLength ) = 0;
	virtual uint32 GetAppOwnershipTicketExtendedData( uint32 nAppID, void *pvBuffer, uint32 cbBufferLength, uint32* piAppId, uint32* piSteamId, uint32* piSignature, uint32* pcbSignature ) = 0;
	virtual int32 GetMarketingMessageCount() = 0;
	virtual bool GetMarketingMessage( int32 cMarketingMessage, GID_t* gidMarketingMessageID, char* pubMsgUrl, int32 cubMessageUrl, EMarketingMessageFlags *eMarketingMssageFlags ) = 0;
	virtual HAuthTicket GetAuthSessionTicket( void *pMyAuthTicket, int32 cbMaxMyAuthTicket, uint32* pcbAuthTicket ) = 0;
	virtual EBeginAuthSessionResult BeginAuthSession( void const* pTheirAuthTicket, int32 cbTicket, CSteamID steamID ) = 0;
	virtual void EndAuthSession( CSteamID steamID ) = 0;
	virtual void CancelAuthTicket( HAuthTicket hAuthTicket ) = 0;
	virtual EUserHasLicenseForAppResult IsUserSubscribedAppInTicket( CSteamID steamID, AppId_t appID ) = 0;
	virtual void AdvertiseGame( CGameID gameID, CSteamID steamIDGameServer, uint32 unIPServer , uint16 usPortServer ) = 0;
	virtual SteamAPICall_t RequestEncryptedAppTicket( const void *pUserData, int32 cbUserData ) = 0;
	virtual bool GetEncryptedAppTicket( void *pTicket, int32 cbMaxTicket, uint32 *pcbTicket ) = 0;
	virtual int32 GetGameBadgeLevel( int32 nSeries, bool bFoil ) = 0;
	virtual int32 GetPlayerSteamLevel() = 0;
	virtual void SetAccountLimited( bool bAccountLimited ) = 0;
	virtual bool BIsAccountLimited() = 0;
	virtual void SetAccountCommunityBanned( bool bBanned ) = 0;
	virtual bool BIsAccountCommunityBanned() = 0;
	virtual void SetLimitedAccountCanInviteFriends( bool bCanInviteFriends ) = 0;
	virtual bool BLimitedAccountCanInviteFriends() = 0;
	virtual void SendValidationEmail() = 0;
	virtual bool BGameConnectTokensAvailable() = 0;
	virtual int32 NumGamesRunning() = 0;
	STEAMWORKS_STRUCT_RETURN_1(CGameID, GetRunningGameID, int32, iGame) /*virtual CGameID GetRunningGameID( int32 iGame ) = 0;*/
	virtual int32 GetRunningGamePID(int32) = 0;
	virtual uint32 GetAccountSecurityPolicyFlags() = 0;
	virtual void RequestPasswordChangeEmail(const char *, int32) = 0;
	virtual void ChangePasswordWithCode( const char *pchOldPassword, const char *pchCode, const char *pchNewPassword ) = 0;
	virtual void RequestEmailChange( const char *, const char * ) = 0;
	virtual void ChangeEmailWithCode( const char *, const char *, const char *, const char *, const char * ) = 0;
	virtual void SetClientStat( EClientStat eStat, int64 llValue, AppId_t nAppID, DepotId_t nDepotID, CellID_t nCellID ) = 0;
	virtual void VerifyPassword( const char *pchPassword ) = 0;
	virtual bool BSupportUser() = 0;
	virtual bool BNeedsSSANextSteamLogon() = 0;
	virtual void ClearNeedsSSANextSteamLogon() = 0;
	virtual bool BIsAppOverlayEnabled( CGameID gameID ) = 0;
	virtual bool BOverlayIgnoreChildProcesses(CGameID) = 0;
	virtual bool BIsBehindNAT() = 0;
	virtual AppId_t GetMicroTxnAppID( GID_t gidTransID ) = 0;
	virtual uint64 GetMicroTxnOrderID( GID_t gidTransID ) = 0;
	virtual bool BGetMicroTxnPrice( GID_t gidTransID, CAmount *pamtTotal, CAmount *pamtTax, bool *pbVat, CAmount * pUnk ) = 0;
	virtual int32 GetMicroTxnLineItemCount( GID_t gidTransID ) = 0;
	virtual bool BGetMicroTxnLineItem( GID_t gidTransID, uint32 unLineItem, CAmount *pamt, uint32 *punQuantity, char *pchDescription, uint32 cubDescriptionLength, int32 *pRecurringTimeUnit, uint8 *pRecurringFrequency, CAmount *pRecurringAmount, bool * pbUnk ) = 0;
	virtual bool BIsSandboxMicroTxn( GID_t gidTransID, bool* pbSandbox ) = 0;
	virtual bool BMicroTxnRequiresCachedPmtMethod( GID_t gidTransID, bool *pbRequired ) = 0;
	virtual SteamAPICall_t AuthorizeMicroTxn( GID_t gidTransID, EMicroTxnAuthResponse eMicroTxnAuthResponse ) = 0;
	virtual bool BGetWalletBalance( bool *pbHasWallet, CAmount *pamtBalance, CAmount *pamtPending ) = 0;
	virtual SteamAPICall_t RequestMicroTxnInfo( GID_t gidTransID ) = 0;
	virtual bool BMicroTxnRefundable( GID_t gidTransID ) = 0;
	virtual bool BGetAppMinutesPlayed( AppId_t nAppId, int32 *pnForever, int32 *pnLastTwoWeeks ) = 0;
	virtual uint32 GetAppLastPlayedTime( AppId_t nAppId ) = 0;
	virtual uint32 GetAppUpdateDisabledSecondsRemaining(uint32) = 0;
	virtual bool BGetGuideURL( AppId_t uAppID, char *pchURL, uint32 cchURL ) = 0;
	virtual bool BPromptToVerifyEmail() = 0;
	virtual bool BPromptToChangePassword() = 0;
	virtual bool BAccountExtraSecurity() = 0;
	virtual bool BAccountShouldShowLockUI() = 0;
	virtual int32 GetCountAuthedComputers() = 0;
	virtual bool BSteamGuardNewMachineNotification() = 0;
	virtual RTime32 GetSteamGuardEnabledTime() = 0;
	virtual bool GetSteamGuardHistoryEntry( int32 iEntryIndex, RTime32 *puTimestamp, uint32 *puIP, bool *pbIsRemembered, char *pchGeolocInfo, int32 cchGeolocInfo, char * pchUnk, int32 cbUnk ) = 0;
	virtual void SetSteamGuardNewMachineDialogResponse( bool bIsApproved, bool bIsWizardComplete ) = 0;
	virtual void SetPhoneIsVerified(bool) = 0;
	virtual bool BIsPhoneVerified() = 0;
	virtual void SetPhoneIsIdentifying(bool) = 0;
	virtual bool BIsPhoneIdentifying() = 0;
	virtual void SetPhoneIsRequiringVerification(bool) = 0;
	virtual bool BIsPhoneRequiringVerification() = 0;
	virtual void ChangeTwoFactorAuthOptions( int32 eOption ) = 0;
	virtual void Set2ndFactorAuthCode( const char* pchAuthCode, bool bDontRememberComputer ) = 0;
	virtual void SetUserMachineName( const char * pchMachineName ) = 0;
	virtual bool GetUserMachineName( char * pchMachineName, int32 cbMachineName ) = 0;
	virtual bool GetEmailDomainFromLogonFailure( char * pchEmailDomain, int32 cbEmailDomain ) = 0;
	virtual bool BIsSubscribedApp( AppId_t nAppId ) = 0;
	virtual uint32 GetSubscribedApps(AppId_t *, uint32, bool) = 0;
	virtual SteamAPICall_t RegisterActivationCode( const char * pchActivationCode ) = 0;
	virtual void AckSystemIM( uint64 ) = 0;
	virtual SteamAPICall_t RequestSpecialSurvey( uint32 uSurveyId ) = 0;
	virtual SteamAPICall_t SendSpecialSurveyResponse( uint32 uSurveyId, const uint8 * pubData, uint32 cubData ) = 0;
	virtual void RequestNotifications() = 0;
	virtual bool GetAppOwnershipInfo( AppId_t unAppId, RTime32* pRTime32Created, uint32* unk, char* pchCountry ) = 0; // Use a 3 bytes buffer for the country
	virtual void SendGameWebCallback( AppId_t unAppId, const char *szData ) = 0;
	virtual void StopStreaming(bool, int32) = 0;
	virtual bool BIsStreamingUIToRemoteDevice() = 0;
	virtual bool BIsCurrentlyNVStreaming() = 0;
	virtual void RequestStopNVStreaming() = 0;
	virtual void OnBigPictureStreamingResult( bool, void * ) = 0;
	virtual void OnBigPictureStreamingDone() = 0;
	virtual void OnBigPictureStreamRestarting() = 0;
	virtual void LockParentalLock() = 0;
	virtual bool UnlockParentalLock( const char * pchUnk ) = 0;
	virtual bool BIsParentalLockEnabled() = 0;
	virtual bool BIsParentalLockLocked() = 0;
	virtual void BlockApp( AppId_t unAppID ) = 0;
	virtual void UnblockApp( AppId_t unAppID ) = 0;
	virtual bool BIsAppBlocked( AppId_t unAppID ) = 0;
	virtual bool BIsAppInBlockList( AppId_t unAppID ) = 0;
	virtual void BlockFeature( EParentalFeature eParentalFeature ) = 0;
	virtual void UnblockFeature( EParentalFeature eParentalFeature ) = 0;
	virtual bool BIsFeatureBlocked( EParentalFeature eParentalFeature ) = 0;
	virtual bool BIsFeatureInBlockList( EParentalFeature eParentalFeature ) = 0;
	virtual uint32 GetParentalUnlockTime() = 0;
	virtual bool BGetRecoveryEmail(char*, int) = 0;
	virtual void RequestParentalRecoveryEmail() = 0;
	virtual bool BGetSerializedParentalSettings( CUtlBuffer * pBuffer ) = 0;
	virtual bool BSetParentalSettings( CUtlBuffer * pBuffer ) = 0;
	virtual bool BDisableParentalSettings() = 0;
	virtual bool BGetParentalWebToken( CUtlBuffer *, CUtlBuffer * ) = 0;
	virtual bool BCanLogonOfflineMode() = 0;
	virtual EResult LogOnOfflineMode() = 0;
	virtual EResult ValidateOfflineLogonTicket( const char * pchUnk ) = 0;
	virtual bool BGetOfflineLogonTicket( const char * pchUnk, COffline_OfflineLogonTicket * pTicket) = 0;
	virtual void UploadLocalClientLogs() = 0;
	virtual void SetAsyncNotificationEnabled( uint32, bool ) = 0;
	virtual bool BIsOtherSessionPlaying( uint32 * ) = 0;
	virtual bool BKickOtherPlayingSession() = 0;
	virtual void PerformAccountRecoveryUpload() = 0;
	virtual bool BIsAccountLockedDown() = 0;
	virtual void RemoveAppTag(CGameID, const char*) = 0;
	virtual void AddAppTag(CGameID, const char*) = 0;
	virtual void SetAppHidden(CGameID, bool) = 0;
	virtual SteamAPICall_t RequestAccountLinkInfo() = 0;
};

#endif // ICLIENTUSER_H
