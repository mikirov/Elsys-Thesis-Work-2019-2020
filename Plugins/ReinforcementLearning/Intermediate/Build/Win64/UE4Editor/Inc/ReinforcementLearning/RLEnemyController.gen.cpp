// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ReinforcementLearning/Public/AI/RLEnemyController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRLEnemyController() {}
// Cross Module References
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_ARLEnemyController_NoRegister();
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_ARLEnemyController();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_ReinforcementLearning();
	AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
// End Cross Module References
	void ARLEnemyController::StaticRegisterNativesARLEnemyController()
	{
	}
	UClass* Z_Construct_UClass_ARLEnemyController_NoRegister()
	{
		return ARLEnemyController::StaticClass();
	}
	struct Z_Construct_UClass_ARLEnemyController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BehaviorTreeTemplate_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BehaviorTreeTemplate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARLEnemyController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_ReinforcementLearning,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLEnemyController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "AI/RLEnemyController.h" },
		{ "ModuleRelativePath", "Public/AI/RLEnemyController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLEnemyController_Statics::NewProp_BehaviorTreeTemplate_MetaData[] = {
		{ "Category", "RLEnemyController" },
		{ "Comment", "//The behavior tree template to be loaded at BeginPlay by the controller\n" },
		{ "ModuleRelativePath", "Public/AI/RLEnemyController.h" },
		{ "ToolTip", "The behavior tree template to be loaded at BeginPlay by the controller" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARLEnemyController_Statics::NewProp_BehaviorTreeTemplate = { "BehaviorTreeTemplate", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARLEnemyController, BehaviorTreeTemplate), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ARLEnemyController_Statics::NewProp_BehaviorTreeTemplate_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARLEnemyController_Statics::NewProp_BehaviorTreeTemplate_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ARLEnemyController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLEnemyController_Statics::NewProp_BehaviorTreeTemplate,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARLEnemyController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARLEnemyController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ARLEnemyController_Statics::ClassParams = {
		&ARLEnemyController::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ARLEnemyController_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_ARLEnemyController_Statics::PropPointers),
		0,
		0x008002A0u,
		METADATA_PARAMS(Z_Construct_UClass_ARLEnemyController_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ARLEnemyController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ARLEnemyController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ARLEnemyController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ARLEnemyController, 2032929310);
	template<> REINFORCEMENTLEARNING_API UClass* StaticClass<ARLEnemyController>()
	{
		return ARLEnemyController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARLEnemyController(Z_Construct_UClass_ARLEnemyController, &ARLEnemyController::StaticClass, TEXT("/Script/ReinforcementLearning"), TEXT("ARLEnemyController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARLEnemyController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
