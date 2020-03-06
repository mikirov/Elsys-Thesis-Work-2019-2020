// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ANIMATEDTEXTURE_AnimatedTexture2D_generated_h
#error "AnimatedTexture2D.generated.h already included, missing '#pragma once' in AnimatedTexture2D.h"
#endif
#define ANIMATEDTEXTURE_AnimatedTexture2D_generated_h

#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AnimatedTexture_Source_AnimatedTexture_Public_AnimatedTexture2D_h_27_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetAnimationLength) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetAnimationLength(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPlayRate) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetPlayRate(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetPlayRate) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NewRate); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetPlayRate(Z_Param_NewRate); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsLooping) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsLooping(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLooping) \
	{ \
		P_GET_UBOOL(Z_Param_bNewLooping); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetLooping(Z_Param_bNewLooping); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsPlaying) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsPlaying(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStop) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Stop(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlayFromStart) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->PlayFromStart(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlay) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Play(); \
		P_NATIVE_END; \
	}


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AnimatedTexture_Source_AnimatedTexture_Public_AnimatedTexture2D_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetAnimationLength) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetAnimationLength(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPlayRate) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetPlayRate(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetPlayRate) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_NewRate); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetPlayRate(Z_Param_NewRate); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsLooping) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsLooping(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetLooping) \
	{ \
		P_GET_UBOOL(Z_Param_bNewLooping); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetLooping(Z_Param_bNewLooping); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsPlaying) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsPlaying(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStop) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Stop(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlayFromStart) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->PlayFromStart(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPlay) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Play(); \
		P_NATIVE_END; \
	}


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AnimatedTexture_Source_AnimatedTexture_Public_AnimatedTexture2D_h_27_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAnimatedTexture2D(); \
	friend struct Z_Construct_UClass_UAnimatedTexture2D_Statics; \
public: \
	DECLARE_CLASS(UAnimatedTexture2D, UTexture, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AnimatedTexture"), NO_API) \
	DECLARE_SERIALIZER(UAnimatedTexture2D)


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AnimatedTexture_Source_AnimatedTexture_Public_AnimatedTexture2D_h_27_INCLASS \
private: \
	static void StaticRegisterNativesUAnimatedTexture2D(); \
	friend struct Z_Construct_UClass_UAnimatedTexture2D_Statics; \
public: \
	DECLARE_CLASS(UAnimatedTexture2D, UTexture, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AnimatedTexture"), NO_API) \
	DECLARE_SERIALIZER(UAnimatedTexture2D)


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AnimatedTexture_Source_AnimatedTexture_Public_AnimatedTexture2D_h_27_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAnimatedTexture2D(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAnimatedTexture2D) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAnimatedTexture2D); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAnimatedTexture2D); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAnimatedTexture2D(UAnimatedTexture2D&&); \
	NO_API UAnimatedTexture2D(const UAnimatedTexture2D&); \
public:


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AnimatedTexture_Source_AnimatedTexture_Public_AnimatedTexture2D_h_27_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UAnimatedTexture2D(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UAnimatedTexture2D(UAnimatedTexture2D&&); \
	NO_API UAnimatedTexture2D(const UAnimatedTexture2D&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UAnimatedTexture2D); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAnimatedTexture2D); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAnimatedTexture2D)


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AnimatedTexture_Source_AnimatedTexture_Public_AnimatedTexture2D_h_27_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__AnimSource() { return STRUCT_OFFSET(UAnimatedTexture2D, AnimSource); } \
	FORCEINLINE static uint32 __PPO__bPlaying() { return STRUCT_OFFSET(UAnimatedTexture2D, bPlaying); }


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AnimatedTexture_Source_AnimatedTexture_Public_AnimatedTexture2D_h_24_PROLOG
#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AnimatedTexture_Source_AnimatedTexture_Public_AnimatedTexture2D_h_27_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AnimatedTexture_Source_AnimatedTexture_Public_AnimatedTexture2D_h_27_PRIVATE_PROPERTY_OFFSET \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AnimatedTexture_Source_AnimatedTexture_Public_AnimatedTexture2D_h_27_RPC_WRAPPERS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AnimatedTexture_Source_AnimatedTexture_Public_AnimatedTexture2D_h_27_INCLASS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AnimatedTexture_Source_AnimatedTexture_Public_AnimatedTexture2D_h_27_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AnimatedTexture_Source_AnimatedTexture_Public_AnimatedTexture2D_h_27_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AnimatedTexture_Source_AnimatedTexture_Public_AnimatedTexture2D_h_27_PRIVATE_PROPERTY_OFFSET \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AnimatedTexture_Source_AnimatedTexture_Public_AnimatedTexture2D_h_27_RPC_WRAPPERS_NO_PURE_DECLS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AnimatedTexture_Source_AnimatedTexture_Public_AnimatedTexture2D_h_27_INCLASS_NO_PURE_DECLS \
	Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AnimatedTexture_Source_AnimatedTexture_Public_AnimatedTexture2D_h_27_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ANIMATEDTEXTURE_API UClass* StaticClass<class UAnimatedTexture2D>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Build___Portal_Dev_Marketplace_Full_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_AnimatedTexture_Source_AnimatedTexture_Public_AnimatedTexture2D_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
