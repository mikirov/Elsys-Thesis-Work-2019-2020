// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ReinforcementLearning/Private/Utilities/TrainingSaveGame.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTrainingSaveGame() {}
// Cross Module References
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_UTrainingSaveGame_NoRegister();
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_UTrainingSaveGame();
	ENGINE_API UClass* Z_Construct_UClass_USaveGame();
	UPackage* Z_Construct_UPackage__Script_ReinforcementLearning();
// End Cross Module References
	void UTrainingSaveGame::StaticRegisterNativesUTrainingSaveGame()
	{
	}
	UClass* Z_Construct_UClass_UTrainingSaveGame_NoRegister()
	{
		return UTrainingSaveGame::StaticClass();
	}
	struct Z_Construct_UClass_UTrainingSaveGame_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_UserIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp_UserIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SaveSlotName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_SaveSlotName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActionFailReward_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ActionFailReward;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DelayFrames_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_DelayFrames;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LearningRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_LearningRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DiscountFactor_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DiscountFactor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Epsilon_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Epsilon;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTrainingSaveGame_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USaveGame,
		(UObject* (*)())Z_Construct_UPackage__Script_ReinforcementLearning,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTrainingSaveGame_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Utilities/TrainingSaveGame.h" },
		{ "ModuleRelativePath", "Private/Utilities/TrainingSaveGame.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_UserIndex_MetaData[] = {
		{ "Category", "Setup" },
		{ "ModuleRelativePath", "Private/Utilities/TrainingSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_UserIndex = { "UserIndex", nullptr, (EPropertyFlags)0x0020080000020001, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTrainingSaveGame, UserIndex), METADATA_PARAMS(Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_UserIndex_MetaData, ARRAY_COUNT(Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_UserIndex_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_SaveSlotName_MetaData[] = {
		{ "Category", "Setup" },
		{ "ModuleRelativePath", "Private/Utilities/TrainingSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_SaveSlotName = { "SaveSlotName", nullptr, (EPropertyFlags)0x0020080000020015, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTrainingSaveGame, SaveSlotName), METADATA_PARAMS(Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_SaveSlotName_MetaData, ARRAY_COUNT(Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_SaveSlotName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_ActionFailReward_MetaData[] = {
		{ "Category", "RL Character" },
		{ "ModuleRelativePath", "Private/Utilities/TrainingSaveGame.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_ActionFailReward = { "ActionFailReward", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTrainingSaveGame, ActionFailReward), METADATA_PARAMS(Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_ActionFailReward_MetaData, ARRAY_COUNT(Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_ActionFailReward_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_DelayFrames_MetaData[] = {
		{ "Category", "RL Character" },
		{ "Comment", "//perform an action after every DelayFrames frames\n" },
		{ "ModuleRelativePath", "Private/Utilities/TrainingSaveGame.h" },
		{ "ToolTip", "perform an action after every DelayFrames frames" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_DelayFrames = { "DelayFrames", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTrainingSaveGame, DelayFrames), METADATA_PARAMS(Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_DelayFrames_MetaData, ARRAY_COUNT(Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_DelayFrames_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_LearningRate_MetaData[] = {
		{ "Category", "RL Character" },
		{ "Comment", "//rate at which the action values in the QTable get updated\n" },
		{ "ModuleRelativePath", "Private/Utilities/TrainingSaveGame.h" },
		{ "ToolTip", "rate at which the action values in the QTable get updated" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_LearningRate = { "LearningRate", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTrainingSaveGame, LearningRate), METADATA_PARAMS(Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_LearningRate_MetaData, ARRAY_COUNT(Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_LearningRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_DiscountFactor_MetaData[] = {
		{ "Category", "RL Character" },
		{ "Comment", "//discount factor for the future expected rewards\n" },
		{ "ModuleRelativePath", "Private/Utilities/TrainingSaveGame.h" },
		{ "ToolTip", "discount factor for the future expected rewards" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_DiscountFactor = { "DiscountFactor", nullptr, (EPropertyFlags)0x0010000000020005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTrainingSaveGame, DiscountFactor), METADATA_PARAMS(Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_DiscountFactor_MetaData, ARRAY_COUNT(Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_DiscountFactor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_Epsilon_MetaData[] = {
		{ "Category", "TrainingSaveGame" },
		{ "Comment", "//random action chance\n" },
		{ "ModuleRelativePath", "Private/Utilities/TrainingSaveGame.h" },
		{ "ToolTip", "random action chance" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_Epsilon = { "Epsilon", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTrainingSaveGame, Epsilon), METADATA_PARAMS(Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_Epsilon_MetaData, ARRAY_COUNT(Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_Epsilon_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTrainingSaveGame_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_UserIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_SaveSlotName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_ActionFailReward,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_DelayFrames,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_LearningRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_DiscountFactor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTrainingSaveGame_Statics::NewProp_Epsilon,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTrainingSaveGame_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTrainingSaveGame>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UTrainingSaveGame_Statics::ClassParams = {
		&UTrainingSaveGame::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UTrainingSaveGame_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_UTrainingSaveGame_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UTrainingSaveGame_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UTrainingSaveGame_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UTrainingSaveGame()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UTrainingSaveGame_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UTrainingSaveGame, 2256906590);
	template<> REINFORCEMENTLEARNING_API UClass* StaticClass<UTrainingSaveGame>()
	{
		return UTrainingSaveGame::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UTrainingSaveGame(Z_Construct_UClass_UTrainingSaveGame, &UTrainingSaveGame::StaticClass, TEXT("/Script/ReinforcementLearning"), TEXT("UTrainingSaveGame"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTrainingSaveGame);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
