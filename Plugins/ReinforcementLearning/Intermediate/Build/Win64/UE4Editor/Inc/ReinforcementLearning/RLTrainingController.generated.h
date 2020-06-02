// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef REINFORCEMENTLEARNING_RLTrainingController_generated_h
#error "RLTrainingController.generated.h already included, missing '#pragma once' in RLTrainingController.h"
#endif
#define REINFORCEMENTLEARNING_RLTrainingController_generated_h

#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLTrainingController_h_16_RPC_WRAPPERS
#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLTrainingController_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLTrainingController_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARLTrainingController(); \
	friend struct Z_Construct_UClass_ARLTrainingController_Statics; \
public: \
	DECLARE_CLASS(ARLTrainingController, ARLController, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ReinforcementLearning"), NO_API) \
	DECLARE_SERIALIZER(ARLTrainingController)


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLTrainingController_h_16_INCLASS \
private: \
	static void StaticRegisterNativesARLTrainingController(); \
	friend struct Z_Construct_UClass_ARLTrainingController_Statics; \
public: \
	DECLARE_CLASS(ARLTrainingController, ARLController, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ReinforcementLearning"), NO_API) \
	DECLARE_SERIALIZER(ARLTrainingController)


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLTrainingController_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARLTrainingController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARLTrainingController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARLTrainingController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARLTrainingController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARLTrainingController(ARLTrainingController&&); \
	NO_API ARLTrainingController(const ARLTrainingController&); \
public:


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLTrainingController_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARLTrainingController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARLTrainingController(ARLTrainingController&&); \
	NO_API ARLTrainingController(const ARLTrainingController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARLTrainingController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARLTrainingController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARLTrainingController)


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLTrainingController_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__bDealingDamage() { return STRUCT_OFFSET(ARLTrainingController, bDealingDamage); } \
	FORCEINLINE static uint32 __PPO__KillReward() { return STRUCT_OFFSET(ARLTrainingController, KillReward); } \
	FORCEINLINE static uint32 __PPO__DeathReward() { return STRUCT_OFFSET(ARLTrainingController, DeathReward); } \
	FORCEINLINE static uint32 __PPO__CriticalHealthRewardMultiplier() { return STRUCT_OFFSET(ARLTrainingController, CriticalHealthRewardMultiplier); } \
	FORCEINLINE static uint32 __PPO__DealingDamageReward() { return STRUCT_OFFSET(ARLTrainingController, DealingDamageReward); } \
	FORCEINLINE static uint32 __PPO__AliveReward() { return STRUCT_OFFSET(ARLTrainingController, AliveReward); } \
	FORCEINLINE static uint32 __PPO__TakingDamageReward() { return STRUCT_OFFSET(ARLTrainingController, TakingDamageReward); } \
	FORCEINLINE static uint32 __PPO__Epsilon() { return STRUCT_OFFSET(ARLTrainingController, Epsilon); } \
	FORCEINLINE static uint32 __PPO__bRandomAction() { return STRUCT_OFFSET(ARLTrainingController, bRandomAction); } \
	FORCEINLINE static uint32 __PPO__DiscountFactor() { return STRUCT_OFFSET(ARLTrainingController, DiscountFactor); } \
	FORCEINLINE static uint32 __PPO__LearningRate() { return STRUCT_OFFSET(ARLTrainingController, LearningRate); }


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLTrainingController_h_13_PROLOG
#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLTrainingController_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLTrainingController_h_16_PRIVATE_PROPERTY_OFFSET \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLTrainingController_h_16_RPC_WRAPPERS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLTrainingController_h_16_INCLASS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLTrainingController_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLTrainingController_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLTrainingController_h_16_PRIVATE_PROPERTY_OFFSET \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLTrainingController_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLTrainingController_h_16_INCLASS_NO_PURE_DECLS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLTrainingController_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> REINFORCEMENTLEARNING_API UClass* StaticClass<class ARLTrainingController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_AI_RLTrainingController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
