// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BossBattle : ModuleRules
{
	public BossBattle(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PrivateDependencyModuleNames.AddRange(new string[] { "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "AIModule",
            "UMG",
            "HeadMountedDisplay",
            "NavigationSystem",
            "ReinforcementLearning",
            "Slate",
            "SlateCore",
            "OnlineSubsystem",
            "OnlineSubsystemUtils"
          });

        
        //PublicDependencyModuleNames.AddRange(new string[] {
        //    "OnlineSubsystem",
        //    "OnlineSubsystemUtils"
        // });

    }
}
