// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef REINFORCEMENTLEARNING_TrainingGameMode_generated_h
#error "TrainingGameMode.generated.h already included, missing '#pragma once' in TrainingGameMode.h"
#endif
#define REINFORCEMENTLEARNING_TrainingGameMode_generated_h

#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Gamemodes_TrainingGameMode_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execDecrementEnemyCounter) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DecrementEnemyCounter(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetCharacters) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ResetCharacters(); \
		P_NATIVE_END; \
	}


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Gamemodes_TrainingGameMode_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDecrementEnemyCounter) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DecrementEnemyCounter(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetCharacters) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ResetCharacters(); \
		P_NATIVE_END; \
	}


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Gamemodes_TrainingGameMode_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATrainingGameMode(); \
	friend struct Z_Construct_UClass_ATrainingGameMode_Statics; \
public: \
	DECLARE_CLASS(ATrainingGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/ReinforcementLearning"), NO_API) \
	DECLARE_SERIALIZER(ATrainingGameMode)


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Gamemodes_TrainingGameMode_h_15_INCLASS \
private: \
	static void StaticRegisterNativesATrainingGameMode(); \
	friend struct Z_Construct_UClass_ATrainingGameMode_Statics; \
public: \
	DECLARE_CLASS(ATrainingGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/ReinforcementLearning"), NO_API) \
	DECLARE_SERIALIZER(ATrainingGameMode)


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Gamemodes_TrainingGameMode_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATrainingGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATrainingGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATrainingGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATrainingGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATrainingGameMode(ATrainingGameMode&&); \
	NO_API ATrainingGameMode(const ATrainingGameMode&); \
public:


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Gamemodes_TrainingGameMode_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATrainingGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATrainingGameMode(ATrainingGameMode&&); \
	NO_API ATrainingGameMode(const ATrainingGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATrainingGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATrainingGameMode); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATrainingGameMode)


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Gamemodes_TrainingGameMode_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__RLEnemyTemplate() { return STRUCT_OFFSET(ATrainingGameMode, RLEnemyTemplate); } \
	FORCEINLINE static uint32 __PPO__AIEnemyTemplate() { return STRUCT_OFFSET(ATrainingGameMode, AIEnemyTemplate); } \
	FORCEINLINE static uint32 __PPO__InitialAITransforms() { return STRUCT_OFFSET(ATrainingGameMode, InitialAITransforms); } \
	FORCEINLINE static uint32 __PPO__InitialRLTransform() { return STRUCT_OFFSET(ATrainingGameMode, InitialRLTransform); }


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Gamemodes_TrainingGameMode_h_12_PROLOG
#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Gamemodes_TrainingGameMode_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Gamemodes_TrainingGameMode_h_15_PRIVATE_PROPERTY_OFFSET \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Gamemodes_TrainingGameMode_h_15_RPC_WRAPPERS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Gamemodes_TrainingGameMode_h_15_INCLASS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Gamemodes_TrainingGameMode_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Gamemodes_TrainingGameMode_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Gamemodes_TrainingGameMode_h_15_PRIVATE_PROPERTY_OFFSET \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Gamemodes_TrainingGameMode_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Gamemodes_TrainingGameMode_h_15_INCLASS_NO_PURE_DECLS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Gamemodes_TrainingGameMode_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> REINFORCEMENTLEARNING_API UClass* StaticClass<class ATrainingGameMode>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_Gamemodes_TrainingGameMode_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
