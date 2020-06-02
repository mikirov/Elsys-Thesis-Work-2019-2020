// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UTrainingStatsWidget;
#ifdef REINFORCEMENTLEARNING_TrainingHUD_generated_h
#error "TrainingHUD.generated.h already included, missing '#pragma once' in TrainingHUD.h"
#endif
#define REINFORCEMENTLEARNING_TrainingHUD_generated_h

#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingHUD_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetTrainingStatsWidget) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UTrainingStatsWidget**)Z_Param__Result=P_THIS->GetTrainingStatsWidget(); \
		P_NATIVE_END; \
	}


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingHUD_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetTrainingStatsWidget) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UTrainingStatsWidget**)Z_Param__Result=P_THIS->GetTrainingStatsWidget(); \
		P_NATIVE_END; \
	}


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingHUD_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATrainingHUD(); \
	friend struct Z_Construct_UClass_ATrainingHUD_Statics; \
public: \
	DECLARE_CLASS(ATrainingHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/ReinforcementLearning"), NO_API) \
	DECLARE_SERIALIZER(ATrainingHUD)


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingHUD_h_15_INCLASS \
private: \
	static void StaticRegisterNativesATrainingHUD(); \
	friend struct Z_Construct_UClass_ATrainingHUD_Statics; \
public: \
	DECLARE_CLASS(ATrainingHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/ReinforcementLearning"), NO_API) \
	DECLARE_SERIALIZER(ATrainingHUD)


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingHUD_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATrainingHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATrainingHUD) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATrainingHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATrainingHUD); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATrainingHUD(ATrainingHUD&&); \
	NO_API ATrainingHUD(const ATrainingHUD&); \
public:


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingHUD_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATrainingHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATrainingHUD(ATrainingHUD&&); \
	NO_API ATrainingHUD(const ATrainingHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATrainingHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATrainingHUD); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATrainingHUD)


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingHUD_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__TrainingStatsWidgetTemplate() { return STRUCT_OFFSET(ATrainingHUD, TrainingStatsWidgetTemplate); }


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingHUD_h_12_PROLOG
#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingHUD_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingHUD_h_15_PRIVATE_PROPERTY_OFFSET \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingHUD_h_15_RPC_WRAPPERS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingHUD_h_15_INCLASS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingHUD_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingHUD_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingHUD_h_15_PRIVATE_PROPERTY_OFFSET \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingHUD_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingHUD_h_15_INCLASS_NO_PURE_DECLS \
	elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingHUD_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> REINFORCEMENTLEARNING_API UClass* StaticClass<class ATrainingHUD>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID elsys_thesis_work_Plugins_ReinforcementLearning_Source_ReinforcementLearning_Public_UI_TrainingHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
