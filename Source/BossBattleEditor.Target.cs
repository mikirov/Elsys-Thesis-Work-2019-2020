// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class BossBattleEditorTarget : TargetRules
{
	public BossBattleEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("BossBattle");


        //bLegacyPublicIncludePaths = true;

        //DefaultBuildSettings = BuildSettingsVersion.V2;
    }
}
