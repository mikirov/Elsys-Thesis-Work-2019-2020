// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef REINFORCEMENTLEARNING_TrainingStatsWidget_generated_h
#error "TrainingStatsWidget.generated.h already included, missing '#pragma once' in TrainingStatsWidget.h"
#endif
#define REINFORCEMENTLEARNING_TrainingStatsWidget_generated_h

#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingStatsWidget_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execReset) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Reset(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBack) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Back(); \
		P_NATIVE_END; \
	}


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingStatsWidget_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execReset) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Reset(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBack) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Back(); \
		P_NATIVE_END; \
	}


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingStatsWidget_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUTrainingStatsWidget(); \
	friend struct Z_Construct_UClass_UTrainingStatsWidget_Statics; \
public: \
	DECLARE_CLASS(UTrainingStatsWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ReinforcementLearning"), NO_API) \
	DECLARE_SERIALIZER(UTrainingStatsWidget)


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingStatsWidget_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUTrainingStatsWidget(); \
	friend struct Z_Construct_UClass_UTrainingStatsWidget_Statics; \
public: \
	DECLARE_CLASS(UTrainingStatsWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ReinforcementLearning"), NO_API) \
	DECLARE_SERIALIZER(UTrainingStatsWidget)


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingStatsWidget_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTrainingStatsWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTrainingStatsWidget) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTrainingStatsWidget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTrainingStatsWidget); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UTrainingStatsWidget(UTrainingStatsWidget&&); \
	NO_API UTrainingStatsWidget(const UTrainingStatsWidget&); \
public:


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingStatsWidget_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UTrainingStatsWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UTrainingStatsWidget(UTrainingStatsWidget&&); \
	NO_API UTrainingStatsWidget(const UTrainingStatsWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UTrainingStatsWidget); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UTrainingStatsWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UTrainingStatsWidget)


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingStatsWidget_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__BackButton() { return STRUCT_OFFSET(UTrainingStatsWidget, BackButton); } \
	FORCEINLINE static uint32 __PPO__ResetButton() { return STRUCT_OFFSET(UTrainingStatsWidget, ResetButton); }


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingStatsWidget_h_12_PROLOG
#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingStatsWidget_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingStatsWidget_h_15_PRIVATE_PROPERTY_OFFSET \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingStatsWidget_h_15_RPC_WRAPPERS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingStatsWidget_h_15_INCLASS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingStatsWidget_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingStatsWidget_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingStatsWidget_h_15_PRIVATE_PROPERTY_OFFSET \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingStatsWidget_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingStatsWidget_h_15_INCLASS_NO_PURE_DECLS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingStatsWidget_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> REINFORCEMENTLEARNING_API UClass* StaticClass<class UTrainingStatsWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingStatsWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
