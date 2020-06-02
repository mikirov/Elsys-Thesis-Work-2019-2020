// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ReinforcementLearning/Public/UI/TrainingHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTrainingHUD() {}
// Cross Module References
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_ATrainingHUD_NoRegister();
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_ATrainingHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_ReinforcementLearning();
	REINFORCEMENTLEARNING_API UFunction* Z_Construct_UFunction_ATrainingHUD_GetTrainingStatsWidget();
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_UTrainingStatsWidget_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
// End Cross Module References
	void ATrainingHUD::StaticRegisterNativesATrainingHUD()
	{
		UClass* Class = ATrainingHUD::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetTrainingStatsWidget", &ATrainingHUD::execGetTrainingStatsWidget },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATrainingHUD_GetTrainingStatsWidget_Statics
	{
		struct TrainingHUD_eventGetTrainingStatsWidget_Parms
		{
			UTrainingStatsWidget* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATrainingHUD_GetTrainingStatsWidget_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ATrainingHUD_GetTrainingStatsWidget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(TrainingHUD_eventGetTrainingStatsWidget_Parms, ReturnValue), Z_Construct_UClass_UTrainingStatsWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ATrainingHUD_GetTrainingStatsWidget_Statics::NewProp_ReturnValue_MetaData, ARRAY_COUNT(Z_Construct_UFunction_ATrainingHUD_GetTrainingStatsWidget_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATrainingHUD_GetTrainingStatsWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATrainingHUD_GetTrainingStatsWidget_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATrainingHUD_GetTrainingStatsWidget_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UI/TrainingHUD.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATrainingHUD_GetTrainingStatsWidget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATrainingHUD, nullptr, "GetTrainingStatsWidget", nullptr, nullptr, sizeof(TrainingHUD_eventGetTrainingStatsWidget_Parms), Z_Construct_UFunction_ATrainingHUD_GetTrainingStatsWidget_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ATrainingHUD_GetTrainingStatsWidget_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATrainingHUD_GetTrainingStatsWidget_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATrainingHUD_GetTrainingStatsWidget_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATrainingHUD_GetTrainingStatsWidget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATrainingHUD_GetTrainingStatsWidget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ATrainingHUD_NoRegister()
	{
		return ATrainingHUD::StaticClass();
	}
	struct Z_Construct_UClass_ATrainingHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TrainingStatsWidgetTemplate_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_TrainingStatsWidgetTemplate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATrainingHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_ReinforcementLearning,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ATrainingHUD_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATrainingHUD_GetTrainingStatsWidget, "GetTrainingStatsWidget" }, // 3538012659
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrainingHUD_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "UI/TrainingHUD.h" },
		{ "ModuleRelativePath", "Public/UI/TrainingHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATrainingHUD_Statics::NewProp_TrainingStatsWidgetTemplate_MetaData[] = {
		{ "Category", "UI" },
		{ "Comment", "//training stats widget\n" },
		{ "ModuleRelativePath", "Public/UI/TrainingHUD.h" },
		{ "ToolTip", "training stats widget" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ATrainingHUD_Statics::NewProp_TrainingStatsWidgetTemplate = { "TrainingStatsWidgetTemplate", nullptr, (EPropertyFlags)0x0044000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ATrainingHUD, TrainingStatsWidgetTemplate), Z_Construct_UClass_UTrainingStatsWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ATrainingHUD_Statics::NewProp_TrainingStatsWidgetTemplate_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATrainingHUD_Statics::NewProp_TrainingStatsWidgetTemplate_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATrainingHUD_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATrainingHUD_Statics::NewProp_TrainingStatsWidgetTemplate,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATrainingHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATrainingHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATrainingHUD_Statics::ClassParams = {
		&ATrainingHUD::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ATrainingHUD_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_ATrainingHUD_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ATrainingHUD_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ATrainingHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATrainingHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATrainingHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATrainingHUD, 1652982233);
	template<> REINFORCEMENTLEARNING_API UClass* StaticClass<ATrainingHUD>()
	{
		return ATrainingHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATrainingHUD(Z_Construct_UClass_ATrainingHUD, &ATrainingHUD::StaticClass, TEXT("/Script/ReinforcementLearning"), TEXT("ATrainingHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATrainingHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
