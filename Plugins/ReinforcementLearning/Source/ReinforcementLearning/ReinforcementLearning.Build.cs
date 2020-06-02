// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ReinforcementLearning : ModuleRules
{
	public ReinforcementLearning(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        
			
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{

                "Core",
                "AIModule",
                "UMG",
                "CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);

		
		
	}
}
