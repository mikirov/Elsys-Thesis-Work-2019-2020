// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ReinforcementLearning/Public/Utilities/AimAction.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAimAction() {}
// Cross Module References
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_UAimAction_NoRegister();
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_UAimAction();
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_UAction();
	UPackage* Z_Construct_UPackage__Script_ReinforcementLearning();
// End Cross Module References
	void UAimAction::StaticRegisterNativesUAimAction()
	{
	}
	UClass* Z_Construct_UClass_UAimAction_NoRegister()
	{
		return UAimAction::StaticClass();
	}
	struct Z_Construct_UClass_UAimAction_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAimAction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAction,
		(UObject* (*)())Z_Construct_UPackage__Script_ReinforcementLearning,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAimAction_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Utilities/AimAction.h" },
		{ "ModuleRelativePath", "Public/Utilities/AimAction.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAimAction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAimAction>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAimAction_Statics::ClassParams = {
		&UAimAction::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UAimAction_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UAimAction_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAimAction()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAimAction_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAimAction, 3220077001);
	template<> REINFORCEMENTLEARNING_API UClass* StaticClass<UAimAction>()
	{
		return UAimAction::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAimAction(Z_Construct_UClass_UAimAction, &UAimAction::StaticClass, TEXT("/Script/ReinforcementLearning"), TEXT("UAimAction"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAimAction);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
