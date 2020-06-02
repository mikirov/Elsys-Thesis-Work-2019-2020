// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class APawn;
#ifdef REINFORCEMENTLEARNING_Action_generated_h
#error "Action.generated.h already included, missing '#pragma once' in Action.h"
#endif
#define REINFORCEMENTLEARNING_Action_generated_h

#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetPawn) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(APawn**)Z_Param__Result=P_THIS->GetPawn(); \
		P_NATIVE_END; \
	}


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetPawn) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(APawn**)Z_Param__Result=P_THIS->GetPawn(); \
		P_NATIVE_END; \
	}


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_EVENT_PARMS \
	struct Action_eventExecute_Parms \
	{ \
		bool ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		Action_eventExecute_Parms() \
			: ReturnValue(false) \
		{ \
		} \
	};


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_CALLBACK_WRAPPERS
#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAction(); \
	friend struct Z_Construct_UClass_UAction_Statics; \
public: \
	DECLARE_CLASS(UAction, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ReinforcementLearning"), NO_API) \
	DECLARE_SERIALIZER(UAction)


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUAction(); \
	friend struct Z_Construct_UClass_UAction_Statics; \
public: \
	DECLARE_CLASS(UAction, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ReinforcementLearning"), NO_API) \
	DECLARE_SERIALIZER(UAction)


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAction(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAction) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAction); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAction); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAction(UAction&&); \
	NO_API UAction(const UAction&); \
public:


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAction(UAction&&); \
	NO_API UAction(const UAction&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAction); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAction); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UAction)


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_PRIVATE_PROPERTY_OFFSET
#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_12_PROLOG \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_EVENT_PARMS


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_PRIVATE_PROPERTY_OFFSET \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_RPC_WRAPPERS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_CALLBACK_WRAPPERS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_INCLASS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_PRIVATE_PROPERTY_OFFSET \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_CALLBACK_WRAPPERS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_INCLASS_NO_PURE_DECLS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> REINFORCEMENTLEARNING_API UClass* StaticClass<class UAction>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_Action_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
