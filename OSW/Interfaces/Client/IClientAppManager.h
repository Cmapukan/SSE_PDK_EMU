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

#ifndef ICLIENTAPPMANAGER_H
#define ICLIENTAPPMANAGER_H
#ifdef _WIN32
#pragma once
#endif

#include "Types/SteamTypes.h"
#include "Interfaces/Common/AppsCommon.h"



abstract_class UNSAFE_INTERFACE IClientAppManager
{
public:
	virtual EAppUpdateError InstallApp( AppId_t unAppID, int32 iBaseFolder, bool bLegacy ) = 0;
	virtual EAppUpdateError UninstallApp( AppId_t unAppID, bool bComplete ) = 0;
	virtual EAppUpdateError LaunchApp( CGameID gameID, uint32 uLaunchOption, const char *pszUserArgs ) = 0;
	virtual bool ShutdownApp( AppId_t unAppID, bool bForce ) = 0;
	virtual EAppState GetAppInstallState( AppId_t unAppID ) = 0;
	virtual uint32 GetAppBuildID( AppId_t unAppID ) = 0;
	virtual int32 GetCurrentAppSizeOnDisk( AppId_t unAppID ) = 0;
	virtual uint64 GetRequiredAppsSizeOnDisk( AppId_t unAppIDs[], int32 iUnk ) = 0;
	virtual uint64 GetAppInstallDir( AppId_t unAppID, char *pchPath, uint32 cchPath ) = 0;
	virtual bool IsAppDlcInstalled( AppId_t unAppID, AppId_t unDLCAppID ) = 0;
	virtual bool GetDlcDownloadProgress( AppId_t unAppID, AppId_t unDLCAppID, uint64* lluUnk1, uint64* lluUnk2 ) = 0;
	virtual uint32 GetNumInstalledApps() = 0;
	virtual uint32 GetInstalledApps( uint32 *punAppIDs, uint32 cAppIDsMax ) = 0;
	virtual uint32 GetAppDependency( AppId_t unAppID ) = 0;
	virtual uint32 GetDependentApps( AppId_t unAppID, AppId_t *punAppIDs, int32 cAppIDsMax ) = 0;
	virtual uint32 GetUpdateInfo( AppId_t unAppID, AppUpdateInfo_s *pUpdateInfo ) = 0;
	virtual int32 GetAppConfigValue( AppId_t unAppID, const char *pchKey, char *pchValue, int32 cchValueMax ) = 0;
	virtual bool SetAppConfigValue( AppId_t unAppID, const char *pchKey, const char *pchValue ) = 0;
	virtual bool BIsAppUpToDate( AppId_t unAppID ) = 0;
	virtual uint32 GetAvailableLaunchOptions( AppId_t unAppID, uint32 puOptions[], uint32 cuOptionsMax ) = 0;
	virtual uint32 GetAvailableLanguages( AppId_t unAppID, bool, char *pchLanguages, uint32 cchLanguagesMax ) = 0;
	virtual bool BIsDlcEnabled( AppId_t unAppID, uint32, bool* ) = 0;
	virtual void SetDlcEnabled( AppId_t unAppID, uint32, bool ) = 0;
	virtual bool StartValidatingApp( AppId_t unAppID ) = 0;
	virtual bool CancelValidation( AppId_t unAppID ) = 0;
	virtual bool MarkContentCorrupt( AppId_t unAppID, bool bCorrupt ) = 0;
	virtual uint32 GetInstalledDepots( AppId_t unAppID, AppId_t puDepots[], uint32 cuDepotsMax ) = 0;
	virtual unknown_ret GetFileDetails(AppId_t unAppID, const char *pchUnk) = 0;
	virtual unknown_ret VerifySignedFiles(AppId_t unAppID) = 0;
	virtual int32 GetAvailableBetas(AppId_t unAppID, int32* iunk1, char*, int32 iunk2) = 0;
	virtual bool CheckBetaPassword( AppId_t unAppID, char const*) = 0;
	virtual bool BHasCachedBetaPassword( AppId_t unAppID, const char *cszBetaKey ) = 0;
	virtual bool SetDownloadingEnabled( bool ) = 0;
	virtual bool BIsDownloadingEnabled() = 0;
	virtual bool GetDownloadStats( DownloadStats_s *pDownloadStats ) = 0;
	virtual AppId_t GetDownloadingAppID() = 0;
	virtual bool GetAutoUpdateTimeRestrictionEnabled() = 0;
	virtual void SetAutoUpdateTimeRestrictionEnabled(bool) = 0;
	virtual bool GetAutoUpdateTimeRestrictionHours(int32 * piUnk1, int32 * piUnk2) = 0;
	virtual bool SetAutoUpdateTimeRestrictionStartHour(int32 iUnk) = 0;
	virtual bool SetAutoUpdateTimeRestrictionEndHour(int32 iUnk) = 0;
	virtual EAppAutoUpdateBehavior GetAppAutoUpdateBehavior( AppId_t unAppID ) = 0;
	virtual bool SetAppAutoUpdateBehavior( AppId_t unAppID, EAppAutoUpdateBehavior eAppAutoUpdateBehavior ) = 0;
	virtual bool SetAppAllowDownloadsWhileRunningBehavior( AppId_t unAppID, EAppAllowDownloadsWhileRunningBehavior eAppAllowDownloadsWhileRunningBehavior ) =0;
	virtual EAppAllowDownloadsWhileRunningBehavior GetAppAllowDownloadsWhileRunningBehavior( AppId_t unAppID ) = 0;
	virtual void SetAllowDownloadsWhileAnyAppRunning( bool bAllowDownloadsWhileAnyAppRunning ) = 0;
	virtual bool BAllowDownloadsWhileAnyAppRunning() = 0;
	virtual bool ChangeAppDownloadQueuePlacement( AppId_t unAppID, EAppDownloadQueuePlacement eAppDownloadQueuePlacement ) = 0;
	virtual int32 GetAppDownloadQueueIndex( AppId_t unAppID ) = 0;
	virtual int32 GetAppAutoUpdateDelayedUntilTime( AppId_t unAppID ) = 0;
	virtual bool BHasLocalContentServer() = 0;
	virtual bool BuildBackup( AppId_t unAppID, uint64 ullMaxFileSize, const char *cszBackupPath ) = 0;
	virtual bool BuildInstaller( const char *cszProjectFile, const char *cszBackupPath, const char *, const char * ) = 0;
	virtual bool CancelBackup() = 0;
	virtual EAppUpdateError RestoreApp( AppId_t unAppID, int32 iBaseFolder, char const *cszBackupPath ) = 0;
	virtual bool CanMoveApp( AppId_t unAppID ) = 0;
	virtual unknown_ret MoveApp( AppId_t unAppID, int32 unk ) = 0;
	virtual bool GetMoveAppProgress( AppId_t unAppID, uint64* unk_1, uint64* unk_2, uint32* unk_3) = 0;
	virtual bool CancelMoveApp( AppId_t unAppID ) = 0;
	virtual bool BNeedsFile( AppId_t unAppID, char const *cszFilePath, uint64 ullFileSize, uint32 uUnk ) = 0;
	virtual bool BAddFileOnDisk( AppId_t unAppID, char const *cszFilePath, uint64 ullFileSize, uint32 uUnk, SHADigestWrapper_t ubSha1 ) = 0;
	virtual uint32 FinishAddingFiles( AppId_t unAppID ) = 0;
	virtual bool GetAppStateInfo( AppId_t unAppID, EAppReleaseState * peReleaseState, EAppOwnershipFlags * peOwnershipFlags, EAppState * peAppState, CSteamID * pSteamID, uint32* uUnk1, uint32* uUnk2 ) = 0;
	virtual bool BIsAvailableOnPlatform( uint32 uUnk, const char * pUnk ) = 0;
	virtual int32 GetNumInstallBaseFolders() = 0;
	virtual int32 GetInstallBaseFolder( int32 iBaseFolder, char *pchPath, int32 cbPath ) = 0;
	virtual int32 AddInstallBaseFolder( const char *szPath ) = 0;
	virtual bool RemoveInstallBaseFolder( int32 iBaseFolder ) = 0;
	virtual uint64 GetFreeDiskSpace( int32 iBaseFolder ) = 0;
	virtual bool BGetDiskSpaceStats( int32 iBaseFolder, uint64*, uint64*) = 0;
	virtual int32 GetAppInstallBaseFolder( int32 iBaseFolder ) = 0;
	virtual void ForceInstallDirOverride( const char *cszPath ) = 0;
	virtual bool SetDownloadThrottleRateKbps( int32 iRate, bool ) = 0;
	virtual int32 GetDownloadThrottleRateKbps( bool ) = 0;
	virtual void SuspendDownloadThrottling( bool bSuspend ) = 0;
	virtual void SetThrottleDownloadsWhileStreaming( bool ) = 0;
	virtual bool BThrottleDownloadsWhileStreaming() = 0;
	virtual const char * GetLaunchQueryParam( AppId_t unAppID, const char * pchKey ) = 0;
	virtual void BeginLaunchQueryParams( AppId_t unAppId ) = 0;
	virtual void SetLaunchQueryParam( AppId_t unAppId, const char * pchKey, const char * pchValue ) = 0;
	virtual bool CommitLaunchQueryParams( AppId_t unAppId ) = 0;
	virtual void AddContentLogLine( const char* ) = 0;
	virtual bool GetSystemIconFile( AppId_t unAppId, char*, int32 ) = 0;
};

#endif // ICLIENTAPPMANAGER_H
