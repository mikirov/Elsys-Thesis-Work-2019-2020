// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ReinforcementLearning/Public/Gamemodes/TrainingGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTrainingGameMode() {}
// Cross Module References
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_ATrainingGameMode_NoRegister();
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_ATrainingGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_ReinforcementLearning();
	REINFORCEMENTLEARNING_API UFunction* Z_Construct_UFunction_ATrainingGameMode_DecrementEnemyCounter();
	REINFORCEMENTLEARNING_API UFunction* Z_Construct_UFunction_ATrainingGameMode_ResetCharacters();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
// End Cross Module References
	void ATrainingGameMode::StaticRegisterNativesATrainingGameMode()
	{
		UClass* Class = ATrainingGameMode::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DecrementEnemyCounter", &ATrainingGameMode::execDecrementEnemyCounter },
			{ "ResetCharacters", &ATrainingGameMode::execResetCharacters },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATrainingGameMode_DecrementEnemyCounter_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATrainingGameMode_DecrementEnemyCounter_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gamemodes/TrainingGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATrainingGameMode_DecrementEnemyCounter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATrainingGameMode, nullptr, "DecrementEnemyCounter", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATrainingGameMode_DecrementEnemyCounter_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATrainingGameMode_DecrementEnemyCounter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATrainingGameMode_DecrementEnemyCounter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATrainingGameMode_DecrementEnemyCounter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATrainingGameMode_ResetCharacters_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATrainingGameMode_ResetCharacters_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Gamemodes/TrainingGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATrainingGameMode_ResetCharacters_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATrainingGameMode, nullptr, "ResetCharacters", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATrainingGameMode_ResetCharacters_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATrainingGameMode_ResetCharacters_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATrainingGameMode_ResetCharacters()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATrainingGameMode_ResetCharacters_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ATrainingGameMode_NoRegister()
	{
		return ATrainingGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ATrainingGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InitialRLTransform_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_InitialRLTransform;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InitialAITransforms_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_InitialAITransforms;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_InitialAITransforms_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AIEnemyTemplate_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_AIEnemyTemplate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RLEnemyTemplate_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_RLEnemyTemplate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATrainingGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ReinforcementLearning,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ATrainingGameMode_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATrainingGameMode_DecrementEnemyCounter, "DecrementEnemyCounter" }, // 2161309356
		{ &Z_Construct_UFunction_ATrainingGameMode_ResetCharacters, "ResetCharacters" }, // 1494987114
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrainingGameMode_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Gamemodes/TrainingGameMode.h" },
		{ "ModuleRelativePath", "Public/Gamemodes/TrainingGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_InitialRLTransform_MetaData[] = {
		{ "Category", "TrainingGameMode" },
		{ "ModuleRelativePath", "Public/Gamemodes/TrainingGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_InitialRLTransform = { "InitialRLTransform", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATrainingGameMode, InitialRLTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_InitialRLTransform_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_InitialRLTransform_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_InitialAITransforms_MetaData[] = {
		{ "Category", "TrainingGameMode" },
		{ "ModuleRelativePath", "Public/Gamemodes/TrainingGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_InitialAITransforms = { "InitialAITransforms", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATrainingGameMode, InitialAITransforms), METADATA_PARAMS(Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_InitialAITransforms_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_InitialAITransforms_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_InitialAITransforms_Inner = { "InitialAITransforms", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_AIEnemyTemplate_MetaData[] = {
		{ "Category", "TrainingGameMode" },
		{ "ModuleRelativePath", "Public/Gamemodes/TrainingGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_AIEnemyTemplate = { "AIEnemyTemplate", nullptr, (EPropertyFlags)0x0024080000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATrainingGameMode, AIEnemyTemplate), Z_Construct_UClass_APawn_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_AIEnemyTemplate_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_AIEnemyTemplate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_RLEnemyTemplate_MetaData[] = {
		{ "Category", "TrainingGameMode" },
		{ "ModuleRelativePath", "Public/Gamemodes/TrainingGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_RLEnemyTemplate = { "RLEnemyTemplate", nullptr, (EPropertyFlags)0x0024080000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATrainingGameMode, RLEnemyTemplate), Z_Construct_UClass_APawn_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_RLEnemyTemplate_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_RLEnemyTemplate_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATrainingGameMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_InitialRLTransform,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_InitialAITransforms,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_InitialAITransforms_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_AIEnemyTemplate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATrainingGameMode_Statics::NewProp_RLEnemyTemplate,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATrainingGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATrainingGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATrainingGameMode_Statics::ClassParams = {
		&ATrainingGameMode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ATrainingGameMode_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_ATrainingGameMode_Statics::PropPointers),
		0,
		0x009002A8u,
		METADATA_PARAMS(Z_Construct_UClass_ATrainingGameMode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ATrainingGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATrainingGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATrainingGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATrainingGameMode, 1062046304);
	template<> REINFORCEMENTLEARNING_API UClass* StaticClass<ATrainingGameMode>()
	{
		return ATrainingGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATrainingGameMode(Z_Construct_UClass_ATrainingGameMode, &ATrainingGameMode::StaticClass, TEXT("/Script/ReinforcementLearning"), TEXT("ATrainingGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATrainingGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
