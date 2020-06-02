// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ReinforcementLearning/Public/AI/RLController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRLController() {}
// Cross Module References
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_ARLController_NoRegister();
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_ARLController();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_ReinforcementLearning();
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_UState_NoRegister();
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_UAction_NoRegister();
// End Cross Module References
	void ARLController::StaticRegisterNativesARLController()
	{
	}
	UClass* Z_Construct_UClass_ARLController_NoRegister()
	{
		return ARLController::StaticClass();
	}
	struct Z_Construct_UClass_ARLController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActionFailReward_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ActionFailReward;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DelayFrames_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_DelayFrames;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentActionValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CurrentActionValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentActionIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_CurrentActionIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PreviousStateIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_PreviousStateIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentStateIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_CurrentStateIndex;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_States_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_States;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_States_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Actions_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Actions;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Actions_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARLController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_ReinforcementLearning,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "AI/RLController.h" },
		{ "ModuleRelativePath", "Public/AI/RLController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLController_Statics::NewProp_ActionFailReward_MetaData[] = {
		{ "Category", "RLController" },
		{ "ModuleRelativePath", "Public/AI/RLController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARLController_Statics::NewProp_ActionFailReward = { "ActionFailReward", nullptr, (EPropertyFlags)0x0020080000000014, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARLController, ActionFailReward), METADATA_PARAMS(Z_Construct_UClass_ARLController_Statics::NewProp_ActionFailReward_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARLController_Statics::NewProp_ActionFailReward_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLController_Statics::NewProp_DelayFrames_MetaData[] = {
		{ "Category", "RLController" },
		{ "Comment", "//frames to wait before performing an action\n" },
		{ "ModuleRelativePath", "Public/AI/RLController.h" },
		{ "ToolTip", "frames to wait before performing an action" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ARLController_Statics::NewProp_DelayFrames = { "DelayFrames", nullptr, (EPropertyFlags)0x0020080000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARLController, DelayFrames), METADATA_PARAMS(Z_Construct_UClass_ARLController_Statics::NewProp_DelayFrames_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARLController_Statics::NewProp_DelayFrames_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLController_Statics::NewProp_CurrentActionValue_MetaData[] = {
		{ "Category", "RLController" },
		{ "Comment", "//expected reward from the current action\n" },
		{ "ModuleRelativePath", "Public/AI/RLController.h" },
		{ "ToolTip", "expected reward from the current action" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARLController_Statics::NewProp_CurrentActionValue = { "CurrentActionValue", nullptr, (EPropertyFlags)0x0020080000000014, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARLController, CurrentActionValue), METADATA_PARAMS(Z_Construct_UClass_ARLController_Statics::NewProp_CurrentActionValue_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARLController_Statics::NewProp_CurrentActionValue_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLController_Statics::NewProp_CurrentActionIndex_MetaData[] = {
		{ "Category", "RLController" },
		{ "Comment", "//index of the current action\n" },
		{ "ModuleRelativePath", "Public/AI/RLController.h" },
		{ "ToolTip", "index of the current action" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ARLController_Statics::NewProp_CurrentActionIndex = { "CurrentActionIndex", nullptr, (EPropertyFlags)0x0020080000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARLController, CurrentActionIndex), METADATA_PARAMS(Z_Construct_UClass_ARLController_Statics::NewProp_CurrentActionIndex_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARLController_Statics::NewProp_CurrentActionIndex_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLController_Statics::NewProp_PreviousStateIndex_MetaData[] = {
		{ "Category", "RLController" },
		{ "Comment", "//index of the previous state\n" },
		{ "ModuleRelativePath", "Public/AI/RLController.h" },
		{ "ToolTip", "index of the previous state" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ARLController_Statics::NewProp_PreviousStateIndex = { "PreviousStateIndex", nullptr, (EPropertyFlags)0x0020080000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARLController, PreviousStateIndex), METADATA_PARAMS(Z_Construct_UClass_ARLController_Statics::NewProp_PreviousStateIndex_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARLController_Statics::NewProp_PreviousStateIndex_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLController_Statics::NewProp_CurrentStateIndex_MetaData[] = {
		{ "Category", "RLController" },
		{ "Comment", "//index of the current state\n" },
		{ "ModuleRelativePath", "Public/AI/RLController.h" },
		{ "ToolTip", "index of the current state" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ARLController_Statics::NewProp_CurrentStateIndex = { "CurrentStateIndex", nullptr, (EPropertyFlags)0x0020080000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARLController, CurrentStateIndex), METADATA_PARAMS(Z_Construct_UClass_ARLController_Statics::NewProp_CurrentStateIndex_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARLController_Statics::NewProp_CurrentStateIndex_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLController_Statics::NewProp_States_MetaData[] = {
		{ "Category", "RLController" },
		{ "Comment", "//array of states that the environment can give to the agent\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/AI/RLController.h" },
		{ "ToolTip", "array of states that the environment can give to the agent" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ARLController_Statics::NewProp_States = { "States", nullptr, (EPropertyFlags)0x002008800000000c, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARLController, States), METADATA_PARAMS(Z_Construct_UClass_ARLController_Statics::NewProp_States_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARLController_Statics::NewProp_States_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARLController_Statics::NewProp_States_Inner = { "States", nullptr, (EPropertyFlags)0x0000000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UState_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARLController_Statics::NewProp_Actions_MetaData[] = {
		{ "Category", "RLController" },
		{ "Comment", "//array of actions that can be taken by the agent\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/AI/RLController.h" },
		{ "ToolTip", "array of actions that can be taken by the agent" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ARLController_Statics::NewProp_Actions = { "Actions", nullptr, (EPropertyFlags)0x002008800000000c, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARLController, Actions), METADATA_PARAMS(Z_Construct_UClass_ARLController_Statics::NewProp_Actions_MetaData, ARRAY_COUNT(Z_Construct_UClass_ARLController_Statics::NewProp_Actions_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ARLController_Statics::NewProp_Actions_Inner = { "Actions", nullptr, (EPropertyFlags)0x0000000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UAction_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ARLController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLController_Statics::NewProp_ActionFailReward,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLController_Statics::NewProp_DelayFrames,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLController_Statics::NewProp_CurrentActionValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLController_Statics::NewProp_CurrentActionIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLController_Statics::NewProp_PreviousStateIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLController_Statics::NewProp_CurrentStateIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLController_Statics::NewProp_States,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLController_Statics::NewProp_States_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLController_Statics::NewProp_Actions,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARLController_Statics::NewProp_Actions_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARLController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARLController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ARLController_Statics::ClassParams = {
		&ARLController::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ARLController_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_ARLController_Statics::PropPointers),
		0,
		0x009002A0u,
		METADATA_PARAMS(Z_Construct_UClass_ARLController_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ARLController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ARLController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ARLController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ARLController, 4131091079);
	template<> REINFORCEMENTLEARNING_API UClass* StaticClass<ARLController>()
	{
		return ARLController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARLController(Z_Construct_UClass_ARLController, &ARLController::StaticClass, TEXT("/Script/ReinforcementLearning"), TEXT("ARLController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARLController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
