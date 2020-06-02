// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef REINFORCEMENTLEARNING_State_generated_h
#error "State.generated.h already included, missing '#pragma once' in State.h"
#endif
#define REINFORCEMENTLEARNING_State_generated_h

#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_RPC_WRAPPERS
#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_EVENT_PARMS \
	struct State_eventIsSatisfied_Parms \
	{ \
		bool ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		State_eventIsSatisfied_Parms() \
			: ReturnValue(false) \
		{ \
		} \
	};


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_CALLBACK_WRAPPERS
#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUState(); \
	friend struct Z_Construct_UClass_UState_Statics; \
public: \
	DECLARE_CLASS(UState, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ReinforcementLearning"), NO_API) \
	DECLARE_SERIALIZER(UState)


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_INCLASS \
private: \
	static void StaticRegisterNativesUState(); \
	friend struct Z_Construct_UClass_UState_Statics; \
public: \
	DECLARE_CLASS(UState, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ReinforcementLearning"), NO_API) \
	DECLARE_SERIALIZER(UState)


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UState(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UState) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UState); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UState); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UState(UState&&); \
	NO_API UState(const UState&); \
public:


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UState(UState&&); \
	NO_API UState(const UState&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UState); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UState); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UState)


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__PotentialAmount() { return STRUCT_OFFSET(UState, PotentialAmount); }


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_9_PROLOG \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_EVENT_PARMS


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_PRIVATE_PROPERTY_OFFSET \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_RPC_WRAPPERS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_CALLBACK_WRAPPERS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_INCLASS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_PRIVATE_PROPERTY_OFFSET \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_CALLBACK_WRAPPERS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_INCLASS_NO_PURE_DECLS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> REINFORCEMENTLEARNING_API UClass* StaticClass<class UState>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Utilities_State_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
