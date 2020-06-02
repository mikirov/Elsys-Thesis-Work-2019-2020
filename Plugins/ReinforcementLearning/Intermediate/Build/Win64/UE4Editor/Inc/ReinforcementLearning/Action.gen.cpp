// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ReinforcementLearning/Public/Utilities/Action.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAction() {}
// Cross Module References
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_UAction_NoRegister();
	REINFORCEMENTLEARNING_API UClass* Z_Construct_UClass_UAction();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_ReinforcementLearning();
	REINFORCEMENTLEARNING_API UFunction* Z_Construct_UFunction_UAction_Execute();
	REINFORCEMENTLEARNING_API UFunction* Z_Construct_UFunction_UAction_GetPawn();
	ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
// End Cross Module References
	static FName NAME_UAction_Execute = FName(TEXT("Execute"));
	bool UAction::Execute()
	{
		Action_eventExecute_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_UAction_Execute),&Parms);
		return !!Parms.ReturnValue;
	}
	void UAction::StaticRegisterNativesUAction()
	{
		UClass* Class = UAction::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetPawn", &UAction::execGetPawn },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UAction_Execute_Statics
	{
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UAction_Execute_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Action_eventExecute_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UAction_Execute_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Action_eventExecute_Parms), &Z_Construct_UFunction_UAction_Execute_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAction_Execute_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAction_Execute_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_Execute_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//execute method overridden by every action\n" },
		{ "ModuleRelativePath", "Public/Utilities/Action.h" },
		{ "ToolTip", "execute method overridden by every action" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAction_Execute_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAction, nullptr, "Execute", nullptr, nullptr, sizeof(Action_eventExecute_Parms), Z_Construct_UFunction_UAction_Execute_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAction_Execute_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAction_Execute_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAction_Execute_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAction_Execute()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAction_Execute_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UAction_GetPawn_Statics
	{
		struct Action_eventGetPawn_Parms
		{
			APawn* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAction_GetPawn_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Action_eventGetPawn_Parms, ReturnValue), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAction_GetPawn_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAction_GetPawn_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UAction_GetPawn_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Utilities/Action.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UAction_GetPawn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UAction, nullptr, "GetPawn", nullptr, nullptr, sizeof(Action_eventGetPawn_Parms), Z_Construct_UFunction_UAction_GetPawn_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UAction_GetPawn_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UAction_GetPawn_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UAction_GetPawn_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UAction_GetPawn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UAction_GetPawn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UAction_NoRegister()
	{
		return UAction::StaticClass();
	}
	struct Z_Construct_UClass_UAction_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAction_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_ReinforcementLearning,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UAction_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UAction_Execute, "Execute" }, // 348665606
		{ &Z_Construct_UFunction_UAction_GetPawn, "GetPawn" }, // 3762499003
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAction_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Utilities/Action.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Utilities/Action.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAction_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAction>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAction_Statics::ClassParams = {
		&UAction::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UAction_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UAction_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAction()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAction_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAction, 1279798376);
	template<> REINFORCEMENTLEARNING_API UClass* StaticClass<UAction>()
	{
		return UAction::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAction(Z_Construct_UClass_UAction, &UAction::StaticClass, TEXT("/Script/ReinforcementLearning"), TEXT("UAction"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAction);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
