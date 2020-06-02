// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ReinforcementLearning/Public/UI/TrainingStatsWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTrainingStatsWidget() {}
// Cross Module References
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_UTrainingStatsWidget_NoRegister();
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_UTrainingStatsWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_ReinforcementLearning();
	REINFORCEMENTLEARNING_API UFunction* Z_Construct_UFunction_UTrainingStatsWidget_Back();
	REINFORCEMENTLEARNING_API UFunction* Z_Construct_UFunction_UTrainingStatsWidget_Reset();
	UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
// End Cross Module References
	void UTrainingStatsWidget::StaticRegisterNativesUTrainingStatsWidget()
	{
		UClass* Class = UTrainingStatsWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Back", &UTrainingStatsWidget::execBack },
			{ "Reset", &UTrainingStatsWidget::execReset },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UTrainingStatsWidget_Back_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTrainingStatsWidget_Back_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//goes back to main menu\n" },
		{ "ModuleRelativePath", "Public/UI/TrainingStatsWidget.h" },
		{ "ToolTip", "goes back to main menu" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UTrainingStatsWidget_Back_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTrainingStatsWidget, nullptr, "Back", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UTrainingStatsWidget_Back_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UTrainingStatsWidget_Back_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UTrainingStatsWidget_Back()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UTrainingStatsWidget_Back_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UTrainingStatsWidget_Reset_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UTrainingStatsWidget_Reset_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//resets the training\n" },
		{ "ModuleRelativePath", "Public/UI/TrainingStatsWidget.h" },
		{ "ToolTip", "resets the training" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UTrainingStatsWidget_Reset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UTrainingStatsWidget, nullptr, "Reset", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UTrainingStatsWidget_Reset_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UTrainingStatsWidget_Reset_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UTrainingStatsWidget_Reset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UTrainingStatsWidget_Reset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UTrainingStatsWidget_NoRegister()
	{
		return UTrainingStatsWidget::StaticClass();
	}
	struct Z_Construct_UClass_UTrainingStatsWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ResetButton_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ResetButton;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BackButton_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BackButton;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UTrainingStatsWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_ReinforcementLearning,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UTrainingStatsWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UTrainingStatsWidget_Back, "Back" }, // 1008220542
		{ &Z_Construct_UFunction_UTrainingStatsWidget_Reset, "Reset" }, // 1594024265
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTrainingStatsWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "UI/TrainingStatsWidget.h" },
		{ "ModuleRelativePath", "Public/UI/TrainingStatsWidget.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTrainingStatsWidget_Statics::NewProp_ResetButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "Comment", "//reset the q-table button\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/TrainingStatsWidget.h" },
		{ "ToolTip", "reset the q-table button" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTrainingStatsWidget_Statics::NewProp_ResetButton = { "ResetButton", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTrainingStatsWidget, ResetButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UTrainingStatsWidget_Statics::NewProp_ResetButton_MetaData, ARRAY_COUNT(Z_Construct_UClass_UTrainingStatsWidget_Statics::NewProp_ResetButton_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UTrainingStatsWidget_Statics::NewProp_BackButton_MetaData[] = {
		{ "BindWidget", "" },
		{ "Comment", "//back to main menu button\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/UI/TrainingStatsWidget.h" },
		{ "ToolTip", "back to main menu button" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UTrainingStatsWidget_Statics::NewProp_BackButton = { "BackButton", nullptr, (EPropertyFlags)0x0020080000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UTrainingStatsWidget, BackButton), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UTrainingStatsWidget_Statics::NewProp_BackButton_MetaData, ARRAY_COUNT(Z_Construct_UClass_UTrainingStatsWidget_Statics::NewProp_BackButton_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UTrainingStatsWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTrainingStatsWidget_Statics::NewProp_ResetButton,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UTrainingStatsWidget_Statics::NewProp_BackButton,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UTrainingStatsWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UTrainingStatsWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UTrainingStatsWidget_Statics::ClassParams = {
		&UTrainingStatsWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UTrainingStatsWidget_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_UTrainingStatsWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UTrainingStatsWidget_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UTrainingStatsWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UTrainingStatsWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UTrainingStatsWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UTrainingStatsWidget, 1131239960);
	template<> REINFORCEMENTLEARNING_API UClass* StaticClass<UTrainingStatsWidget>()
	{
		return UTrainingStatsWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UTrainingStatsWidget(Z_Construct_UClass_UTrainingStatsWidget, &UTrainingStatsWidget::StaticClass, TEXT("/Script/ReinforcementLearning"), TEXT("UTrainingStatsWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTrainingStatsWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
