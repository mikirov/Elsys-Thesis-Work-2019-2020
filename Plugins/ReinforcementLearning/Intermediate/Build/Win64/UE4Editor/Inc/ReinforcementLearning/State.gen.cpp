// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ReinforcementLearning/Public/Utilities/State.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeState() {}
// Cross Module References
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_UState_NoRegister();
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_UState();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_ReinforcementLearning();
	REINFORCEMENTLEARNING_API UFunction* Z_Construct_UFunction_UState_IsSatisfied();
// End Cross Module References
	static FName NAME_UState_IsSatisfied = FName(TEXT("IsSatisfied"));
	bool UState::IsSatisfied()
	{
		State_eventIsSatisfied_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_UState_IsSatisfied),&Parms);
		return !!Parms.ReturnValue;
	}
	void UState::StaticRegisterNativesUState()
	{
	}
	struct Z_Construct_UFunction_UState_IsSatisfied_Statics
	{
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UState_IsSatisfied_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((State_eventIsSatisfied_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UState_IsSatisfied_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(State_eventIsSatisfied_Parms), &Z_Construct_UFunction_UState_IsSatisfied_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UState_IsSatisfied_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UState_IsSatisfied_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UState_IsSatisfied_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Utilities/State.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UState_IsSatisfied_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UState, nullptr, "IsSatisfied", nullptr, nullptr, sizeof(State_eventIsSatisfied_Parms), Z_Construct_UFunction_UState_IsSatisfied_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UState_IsSatisfied_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UState_IsSatisfied_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UState_IsSatisfied_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UState_IsSatisfied()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UState_IsSatisfied_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UState_NoRegister()
	{
		return UState::StaticClass();
	}
	struct Z_Construct_UClass_UState_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PotentialAmount_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PotentialAmount;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UState_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_ReinforcementLearning,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UState_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UState_IsSatisfied, "IsSatisfied" }, // 4006014798
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UState_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Utilities/State.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Utilities/State.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UState_Statics::NewProp_PotentialAmount_MetaData[] = {
		{ "Category", "Setup" },
		{ "ModuleRelativePath", "Public/Utilities/State.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UState_Statics::NewProp_PotentialAmount = { "PotentialAmount", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UState, PotentialAmount), METADATA_PARAMS(Z_Construct_UClass_UState_Statics::NewProp_PotentialAmount_MetaData, ARRAY_COUNT(Z_Construct_UClass_UState_Statics::NewProp_PotentialAmount_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UState_Statics::NewProp_PotentialAmount,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UState_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UState>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UState_Statics::ClassParams = {
		&UState::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UState_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_UState_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UState_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UState_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UState()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UState_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UState, 3397642127);
	template<> REINFORCEMENTLEARNING_API UClass* StaticClass<UState>()
	{
		return UState::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UState(Z_Construct_UClass_UState, &UState::StaticClass, TEXT("/Script/ReinforcementLearning"), TEXT("UState"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UState);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
