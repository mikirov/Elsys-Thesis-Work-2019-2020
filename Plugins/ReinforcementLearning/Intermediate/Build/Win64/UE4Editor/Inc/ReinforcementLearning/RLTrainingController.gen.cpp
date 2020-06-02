// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ReinforcementLearning/Public/AI/RLTrainingController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRLTrainingController() {}
// Cross Module References
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_ARLTrainingController_NoRegister();
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_ARLTrainingController();
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_ARLController();
	UPackage* Z_Construct_UPackage__Script_ReinforcementLearning();
// End Cross Module References
	void ARLTrainingController::StaticRegisterNativesARLTrainingController()
	{
	}
	UClass* Z_Construct_UClass_ARLTrainingController_NoRegister()
	{
		return ARLTrainingController::StaticClass();
	}
	struct Z_Construct_UClass_ARLTrainingController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LearningRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_LearningRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DiscountFactor_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DiscountFactor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bRandomAction_MetaData[];
#endif
		static void NewProp_bRandomAction_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRandomAction;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Epsilon_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Epsilon;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TakingDamageReward_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TakingDamageReward;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AliveReward_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AliveReward;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DealingDamageReward_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DealingDamageReward;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CriticalHealthRewardMultiplier_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CriticalHealthRewardMultiplier;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DeathReward_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeathReward;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_KillReward_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_KillReward;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bDealingDamage_MetaData[];
#endif
		static void NewProp_bDealingDamage_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bDealingDamage;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARLTrainingController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ARLController,
		(UObject* (*)())Z_Construct_UPackage__Script_ReinforcementLearning,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLTrainingController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "AI/RLTrainingController.h" },
		{ "ModuleRelativePath", "Public/AI/RLTrainingController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLTrainingController_Statics::NewProp_LearningRate_MetaData[] = {
		{ "Category", "RL Character" },
		{ "Comment", "//rate at which the action values in the QTable get updated\n" },
		{ "ModuleRelativePath", "Public/AI/RLTrainingController.h" },
		{ "ToolTip", "rate at which the action values in the QTable get updated" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARLTrainingController_Statics::NewProp_LearningRate = { "LearningRate", nullptr, (EPropertyFlags)0x0020080000020005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARLTrainingController, LearningRate), METADATA_PARAMS(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_LearningRate_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_LearningRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLTrainingController_Statics::NewProp_DiscountFactor_MetaData[] = {
		{ "Category", "RL Character" },
		{ "Comment", "//discount factor for the future expected rewards\n" },
		{ "ModuleRelativePath", "Public/AI/RLTrainingController.h" },
		{ "ToolTip", "discount factor for the future expected rewards" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARLTrainingController_Statics::NewProp_DiscountFactor = { "DiscountFactor", nullptr, (EPropertyFlags)0x0020080000020005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARLTrainingController, DiscountFactor), METADATA_PARAMS(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_DiscountFactor_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_DiscountFactor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLTrainingController_Statics::NewProp_bRandomAction_MetaData[] = {
		{ "Category", "RL Character" },
		{ "Comment", "//whether or not the character should take a random action\n" },
		{ "ModuleRelativePath", "Public/AI/RLTrainingController.h" },
		{ "ToolTip", "whether or not the character should take a random action" },
	};
#endif
	void Z_Construct_UClass_ARLTrainingController_Statics::NewProp_bRandomAction_SetBit(void* Obj)
	{
		((ARLTrainingController*)Obj)->bRandomAction = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ARLTrainingController_Statics::NewProp_bRandomAction = { "bRandomAction", nullptr, (EPropertyFlags)0x0020080000020005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ARLTrainingController), &Z_Construct_UClass_ARLTrainingController_Statics::NewProp_bRandomAction_SetBit, METADATA_PARAMS(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_bRandomAction_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_bRandomAction_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLTrainingController_Statics::NewProp_Epsilon_MetaData[] = {
		{ "Category", "RLTrainingController" },
		{ "Comment", "//random action chance\n" },
		{ "ModuleRelativePath", "Public/AI/RLTrainingController.h" },
		{ "ToolTip", "random action chance" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARLTrainingController_Statics::NewProp_Epsilon = { "Epsilon", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARLTrainingController, Epsilon), METADATA_PARAMS(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_Epsilon_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_Epsilon_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLTrainingController_Statics::NewProp_TakingDamageReward_MetaData[] = {
		{ "Category", "RL Character" },
		{ "Comment", "//reward for taking damage\n" },
		{ "ModuleRelativePath", "Public/AI/RLTrainingController.h" },
		{ "ToolTip", "reward for taking damage" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARLTrainingController_Statics::NewProp_TakingDamageReward = { "TakingDamageReward", nullptr, (EPropertyFlags)0x0020080000020005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARLTrainingController, TakingDamageReward), METADATA_PARAMS(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_TakingDamageReward_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_TakingDamageReward_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLTrainingController_Statics::NewProp_AliveReward_MetaData[] = {
		{ "Category", "RL Character" },
		{ "Comment", "//reward for dealing damage to the enemy\n" },
		{ "ModuleRelativePath", "Public/AI/RLTrainingController.h" },
		{ "ToolTip", "reward for dealing damage to the enemy" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARLTrainingController_Statics::NewProp_AliveReward = { "AliveReward", nullptr, (EPropertyFlags)0x0020080000020005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARLTrainingController, AliveReward), METADATA_PARAMS(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_AliveReward_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_AliveReward_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLTrainingController_Statics::NewProp_DealingDamageReward_MetaData[] = {
		{ "Category", "RL Character" },
		{ "Comment", "//reward for dealing damage to the enemy\n" },
		{ "ModuleRelativePath", "Public/AI/RLTrainingController.h" },
		{ "ToolTip", "reward for dealing damage to the enemy" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARLTrainingController_Statics::NewProp_DealingDamageReward = { "DealingDamageReward", nullptr, (EPropertyFlags)0x0020080000020005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARLTrainingController, DealingDamageReward), METADATA_PARAMS(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_DealingDamageReward_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_DealingDamageReward_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLTrainingController_Statics::NewProp_CriticalHealthRewardMultiplier_MetaData[] = {
		{ "Category", "RL Character" },
		{ "Comment", "//multiplier\n" },
		{ "ModuleRelativePath", "Public/AI/RLTrainingController.h" },
		{ "ToolTip", "multiplier" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARLTrainingController_Statics::NewProp_CriticalHealthRewardMultiplier = { "CriticalHealthRewardMultiplier", nullptr, (EPropertyFlags)0x0020080000020005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARLTrainingController, CriticalHealthRewardMultiplier), METADATA_PARAMS(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_CriticalHealthRewardMultiplier_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_CriticalHealthRewardMultiplier_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLTrainingController_Statics::NewProp_DeathReward_MetaData[] = {
		{ "Category", "RL Character" },
		{ "Comment", "//reward the character receives for dying\n" },
		{ "ModuleRelativePath", "Public/AI/RLTrainingController.h" },
		{ "ToolTip", "reward the character receives for dying" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARLTrainingController_Statics::NewProp_DeathReward = { "DeathReward", nullptr, (EPropertyFlags)0x0020080000020005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARLTrainingController, DeathReward), METADATA_PARAMS(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_DeathReward_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_DeathReward_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLTrainingController_Statics::NewProp_KillReward_MetaData[] = {
		{ "Category", "RL Character" },
		{ "Comment", "//reward the character receives for killing the enemy\n" },
		{ "ModuleRelativePath", "Public/AI/RLTrainingController.h" },
		{ "ToolTip", "reward the character receives for killing the enemy" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARLTrainingController_Statics::NewProp_KillReward = { "KillReward", nullptr, (EPropertyFlags)0x0020080000020005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARLTrainingController, KillReward), METADATA_PARAMS(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_KillReward_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_KillReward_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLTrainingController_Statics::NewProp_bDealingDamage_MetaData[] = {
		{ "Category", "RL Character" },
		{ "Comment", "// is the RL character hitting the AI character?\n" },
		{ "ModuleRelativePath", "Public/AI/RLTrainingController.h" },
		{ "ToolTip", "is the RL character hitting the AI character?" },
	};
#endif
	void Z_Construct_UClass_ARLTrainingController_Statics::NewProp_bDealingDamage_SetBit(void* Obj)
	{
		((ARLTrainingController*)Obj)->bDealingDamage = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ARLTrainingController_Statics::NewProp_bDealingDamage = { "bDealingDamage", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ARLTrainingController), &Z_Construct_UClass_ARLTrainingController_Statics::NewProp_bDealingDamage_SetBit, METADATA_PARAMS(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_bDealingDamage_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARLTrainingController_Statics::NewProp_bDealingDamage_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ARLTrainingController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLTrainingController_Statics::NewProp_LearningRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLTrainingController_Statics::NewProp_DiscountFactor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLTrainingController_Statics::NewProp_bRandomAction,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLTrainingController_Statics::NewProp_Epsilon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLTrainingController_Statics::NewProp_TakingDamageReward,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLTrainingController_Statics::NewProp_AliveReward,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLTrainingController_Statics::NewProp_DealingDamageReward,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLTrainingController_Statics::NewProp_CriticalHealthRewardMultiplier,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLTrainingController_Statics::NewProp_DeathReward,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLTrainingController_Statics::NewProp_KillReward,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLTrainingController_Statics::NewProp_bDealingDamage,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARLTrainingController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARLTrainingController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ARLTrainingController_Statics::ClassParams = {
		&ARLTrainingController::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ARLTrainingController_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_ARLTrainingController_Statics::PropPointers),
		0,
		0x009002A0u,
		METADATA_PARAMS(Z_Construct_UClass_ARLTrainingController_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ARLTrainingController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ARLTrainingController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ARLTrainingController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ARLTrainingController, 2327120592);
	template<> REINFORCEMENTLEARNING_API UClass* StaticClass<ARLTrainingController>()
	{
		return ARLTrainingController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARLTrainingController(Z_Construct_UClass_ARLTrainingController, &ARLTrainingController::StaticClass, TEXT("/Script/ReinforcementLearning"), TEXT("ARLTrainingController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARLTrainingController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
