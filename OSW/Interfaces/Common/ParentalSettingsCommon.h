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

#ifndef PARENTALSETTINGSCOMMON_H
#define PARENTALSETTINGSCOMMON_H
#ifdef _WIN32
#pragma once
#endif


// versions
#define CLIENTPARENTALSETTINGS_INTERFACE_VERSION "CLIENTPARENTALSETTINGS_INTERFACE_VERSION001"
#define STEAMPARENTALSETTINGS_INTERFACE_VERSION_001 "STEAMPARENTALSETTINGS_INTERFACE_VERSION001"


enum EParentalFeature 
{
	k_EParentalFeatureInvalid,
	k_EParentalFeatureStore,
	k_EParentalFeatureCommunity,
	k_EParentalFeatureProfile,
	k_EParentalFeatureFriends,
	k_EParentalFeatureNews,
	k_EParentalFeatureTrading,
	k_EParentalFeatureSettings,
	k_EParentalFeatureConsole,
	k_EParentalFeatureBrowser,
	k_EParentalFeatureParentalSetup,
	k_EParentalFeatureLibrary,
	k_EParentalFeatureTest,
};


// callbacks
#pragma pack( push, 8 )


#pragma pack( pop )


#endif // PARENTALSETTINGSCOMMON_H
