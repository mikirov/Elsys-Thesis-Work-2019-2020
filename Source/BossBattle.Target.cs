// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class BossBattleTarget : TargetRules
{
	public BossBattleTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

        bUsesSteam = true;
        ExtraModuleNames.Add("BossBattle");

        //bLegacyPublicIncludePaths = true;

        //DefaultBuildSettings = BuildSettingsVersion.V2;

    }
}
