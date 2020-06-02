// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ReinforcementLearning/Public/AI/RLGameController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRLGameController() {}
// Cross Module References
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_ARLGameController_NoRegister();
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_ARLGameController();
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_ARLController();
	UPackage* Z_Construct_UPackage__Script_ReinforcementLearning();
// End Cross Module References
	void ARLGameController::StaticRegisterNativesARLGameController()
	{
	}
	UClass* Z_Construct_UClass_ARLGameController_NoRegister()
	{
		return ARLGameController::StaticClass();
	}
	struct Z_Construct_UClass_ARLGameController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARLGameController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ARLController,
		(UObject* (*)())Z_Construct_UPackage__Script_ReinforcementLearning,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLGameController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "AI/RLGameController.h" },
		{ "ModuleRelativePath", "Public/AI/RLGameController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARLGameController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARLGameController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ARLGameController_Statics::ClassParams = {
		&ARLGameController::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A0u,
		METADATA_PARAMS(Z_Construct_UClass_ARLGameController_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ARLGameController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ARLGameController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ARLGameController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ARLGameController, 1309021660);
	template<> REINFORCEMENTLEARNING_API UClass* StaticClass<ARLGameController>()
	{
		return ARLGameController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARLGameController(Z_Construct_UClass_ARLGameController, &ARLGameController::StaticClass, TEXT("/Script/ReinforcementLearning"), TEXT("ARLGameController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARLGameController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
