// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef REINFORCEMENTLEARNING_RLController_generated_h
#error "RLController.generated.h already included, missing '#pragma once' in RLController.h"
#endif
#define REINFORCEMENTLEARNING_RLController_generated_h

#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLController_h_15_RPC_WRAPPERS
#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLController_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLController_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARLController(); \
	friend struct Z_Construct_UClass_ARLController_Statics; \
public: \
	DECLARE_CLASS(ARLController, AAIController, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ReinforcementLearning"), NO_API) \
	DECLARE_SERIALIZER(ARLController)


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLController_h_15_INCLASS \
private: \
	static void StaticRegisterNativesARLController(); \
	friend struct Z_Construct_UClass_ARLController_Statics; \
public: \
	DECLARE_CLASS(ARLController, AAIController, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ReinforcementLearning"), NO_API) \
	DECLARE_SERIALIZER(ARLController)


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLController_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARLController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARLController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARLController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARLController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARLController(ARLController&&); \
	NO_API ARLController(const ARLController&); \
public:


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLController_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARLController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARLController(ARLController&&); \
	NO_API ARLController(const ARLController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARLController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARLController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARLController)


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLController_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Actions() { return STRUCT_OFFSET(ARLController, Actions); } \
	FORCEINLINE static uint32 __PPO__States() { return STRUCT_OFFSET(ARLController, States); } \
	FORCEINLINE static uint32 __PPO__CurrentStateIndex() { return STRUCT_OFFSET(ARLController, CurrentStateIndex); } \
	FORCEINLINE static uint32 __PPO__PreviousStateIndex() { return STRUCT_OFFSET(ARLController, PreviousStateIndex); } \
	FORCEINLINE static uint32 __PPO__CurrentActionIndex() { return STRUCT_OFFSET(ARLController, CurrentActionIndex); } \
	FORCEINLINE static uint32 __PPO__CurrentActionValue() { return STRUCT_OFFSET(ARLController, CurrentActionValue); } \
	FORCEINLINE static uint32 __PPO__DelayFrames() { return STRUCT_OFFSET(ARLController, DelayFrames); } \
	FORCEINLINE static uint32 __PPO__ActionFailReward() { return STRUCT_OFFSET(ARLController, ActionFailReward); }


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLController_h_12_PROLOG
#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLController_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLController_h_15_PRIVATE_PROPERTY_OFFSET \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLController_h_15_RPC_WRAPPERS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLController_h_15_INCLASS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLController_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLController_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLController_h_15_PRIVATE_PROPERTY_OFFSET \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLController_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLController_h_15_INCLASS_NO_PURE_DECLS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLController_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> REINFORCEMENTLEARNING_API UClass* StaticClass<class ARLController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
