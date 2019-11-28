// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
struct FSessionPropertyKeyPair;
class UUpdateSessionCallbackProxyAdvanced;
#ifdef ADVANCEDSESSIONS_UpdateSessionCallbackProxyAdvanced_generated_h
#error "UpdateSessionCallbackProxyAdvanced.generated.h already included, missing '#pragma once' in UpdateSessionCallbackProxyAdvanced.h"
#endif
#define ADVANCEDSESSIONS_UpdateSessionCallbackProxyAdvanced_generated_h

#define D__Documents_Unreal_Projects_VRExpPluginExp_COMPPLUGIN_PluginStaging_ALL_UE4_423_AS_HostProject_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_UpdateSessionCallbackProxyAdvanced_h_11_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execUpdateSession) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_TARRAY_REF(FSessionPropertyKeyPair,Z_Param_Out_ExtraSettings); \
		P_GET_PROPERTY(UIntProperty,Z_Param_PublicConnections); \
		P_GET_PROPERTY(UIntProperty,Z_Param_PrivateConnections); \
		P_GET_UBOOL(Z_Param_bUseLAN); \
		P_GET_UBOOL(Z_Param_bAllowInvites); \
		P_GET_UBOOL(Z_Param_bAllowJoinInProgress); \
		P_GET_UBOOL(Z_Param_bRefreshOnlineData); \
		P_GET_UBOOL(Z_Param_bIsDedicatedServer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UUpdateSessionCallbackProxyAdvanced**)Z_Param__Result=UUpdateSessionCallbackProxyAdvanced::UpdateSession(Z_Param_WorldContextObject,Z_Param_Out_ExtraSettings,Z_Param_PublicConnections,Z_Param_PrivateConnections,Z_Param_bUseLAN,Z_Param_bAllowInvites,Z_Param_bAllowJoinInProgress,Z_Param_bRefreshOnlineData,Z_Param_bIsDedicatedServer); \
		P_NATIVE_END; \
	}


#define D__Documents_Unreal_Projects_VRExpPluginExp_COMPPLUGIN_PluginStaging_ALL_UE4_423_AS_HostProject_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_UpdateSessionCallbackProxyAdvanced_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execUpdateSession) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_TARRAY_REF(FSessionPropertyKeyPair,Z_Param_Out_ExtraSettings); \
		P_GET_PROPERTY(UIntProperty,Z_Param_PublicConnections); \
		P_GET_PROPERTY(UIntProperty,Z_Param_PrivateConnections); \
		P_GET_UBOOL(Z_Param_bUseLAN); \
		P_GET_UBOOL(Z_Param_bAllowInvites); \
		P_GET_UBOOL(Z_Param_bAllowJoinInProgress); \
		P_GET_UBOOL(Z_Param_bRefreshOnlineData); \
		P_GET_UBOOL(Z_Param_bIsDedicatedServer); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UUpdateSessionCallbackProxyAdvanced**)Z_Param__Result=UUpdateSessionCallbackProxyAdvanced::UpdateSession(Z_Param_WorldContextObject,Z_Param_Out_ExtraSettings,Z_Param_PublicConnections,Z_Param_PrivateConnections,Z_Param_bUseLAN,Z_Param_bAllowInvites,Z_Param_bAllowJoinInProgress,Z_Param_bRefreshOnlineData,Z_Param_bIsDedicatedServer); \
		P_NATIVE_END; \
	}


#define D__Documents_Unreal_Projects_VRExpPluginExp_COMPPLUGIN_PluginStaging_ALL_UE4_423_AS_HostProject_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_UpdateSessionCallbackProxyAdvanced_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUUpdateSessionCallbackProxyAdvanced(); \
	friend struct Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics; \
public: \
	DECLARE_CLASS(UUpdateSessionCallbackProxyAdvanced, UOnlineBlueprintCallProxyBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AdvancedSessions"), ADVANCEDSESSIONS_API) \
	DECLARE_SERIALIZER(UUpdateSessionCallbackProxyAdvanced)


#define D__Documents_Unreal_Projects_VRExpPluginExp_COMPPLUGIN_PluginStaging_ALL_UE4_423_AS_HostProject_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_UpdateSessionCallbackProxyAdvanced_h_11_INCLASS \
private: \
	static void StaticRegisterNativesUUpdateSessionCallbackProxyAdvanced(); \
	friend struct Z_Construct_UClass_UUpdateSessionCallbackProxyAdvanced_Statics; \
public: \
	DECLARE_CLASS(UUpdateSessionCallbackProxyAdvanced, UOnlineBlueprintCallProxyBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/AdvancedSessions"), ADVANCEDSESSIONS_API) \
	DECLARE_SERIALIZER(UUpdateSessionCallbackProxyAdvanced)


#define D__Documents_Unreal_Projects_VRExpPluginExp_COMPPLUGIN_PluginStaging_ALL_UE4_423_AS_HostProject_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_UpdateSessionCallbackProxyAdvanced_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ADVANCEDSESSIONS_API UUpdateSessionCallbackProxyAdvanced(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUpdateSessionCallbackProxyAdvanced) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ADVANCEDSESSIONS_API, UUpdateSessionCallbackProxyAdvanced); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUpdateSessionCallbackProxyAdvanced); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADVANCEDSESSIONS_API UUpdateSessionCallbackProxyAdvanced(UUpdateSessionCallbackProxyAdvanced&&); \
	ADVANCEDSESSIONS_API UUpdateSessionCallbackProxyAdvanced(const UUpdateSessionCallbackProxyAdvanced&); \
public:


#define D__Documents_Unreal_Projects_VRExpPluginExp_COMPPLUGIN_PluginStaging_ALL_UE4_423_AS_HostProject_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_UpdateSessionCallbackProxyAdvanced_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ADVANCEDSESSIONS_API UUpdateSessionCallbackProxyAdvanced(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADVANCEDSESSIONS_API UUpdateSessionCallbackProxyAdvanced(UUpdateSessionCallbackProxyAdvanced&&); \
	ADVANCEDSESSIONS_API UUpdateSessionCallbackProxyAdvanced(const UUpdateSessionCallbackProxyAdvanced&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ADVANCEDSESSIONS_API, UUpdateSessionCallbackProxyAdvanced); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UUpdateSessionCallbackProxyAdvanced); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UUpdateSessionCallbackProxyAdvanced)


#define D__Documents_Unreal_Projects_VRExpPluginExp_COMPPLUGIN_PluginStaging_ALL_UE4_423_AS_HostProject_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_UpdateSessionCallbackProxyAdvanced_h_11_PRIVATE_PROPERTY_OFFSET
#define D__Documents_Unreal_Projects_VRExpPluginExp_COMPPLUGIN_PluginStaging_ALL_UE4_423_AS_HostProject_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_UpdateSessionCallbackProxyAdvanced_h_8_PROLOG
#define D__Documents_Unreal_Projects_VRExpPluginExp_COMPPLUGIN_PluginStaging_ALL_UE4_423_AS_HostProject_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_UpdateSessionCallbackProxyAdvanced_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	D__Documents_Unreal_Projects_VRExpPluginExp_COMPPLUGIN_PluginStaging_ALL_UE4_423_AS_HostProject_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_UpdateSessionCallbackProxyAdvanced_h_11_PRIVATE_PROPERTY_OFFSET \
	D__Documents_Unreal_Projects_VRExpPluginExp_COMPPLUGIN_PluginStaging_ALL_UE4_423_AS_HostProject_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_UpdateSessionCallbackProxyAdvanced_h_11_RPC_WRAPPERS \
	D__Documents_Unreal_Projects_VRExpPluginExp_COMPPLUGIN_PluginStaging_ALL_UE4_423_AS_HostProject_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_UpdateSessionCallbackProxyAdvanced_h_11_INCLASS \
	D__Documents_Unreal_Projects_VRExpPluginExp_COMPPLUGIN_PluginStaging_ALL_UE4_423_AS_HostProject_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_UpdateSessionCallbackProxyAdvanced_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define D__Documents_Unreal_Projects_VRExpPluginExp_COMPPLUGIN_PluginStaging_ALL_UE4_423_AS_HostProject_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_UpdateSessionCallbackProxyAdvanced_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	D__Documents_Unreal_Projects_VRExpPluginExp_COMPPLUGIN_PluginStaging_ALL_UE4_423_AS_HostProject_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_UpdateSessionCallbackProxyAdvanced_h_11_PRIVATE_PROPERTY_OFFSET \
	D__Documents_Unreal_Projects_VRExpPluginExp_COMPPLUGIN_PluginStaging_ALL_UE4_423_AS_HostProject_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_UpdateSessionCallbackProxyAdvanced_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	D__Documents_Unreal_Projects_VRExpPluginExp_COMPPLUGIN_PluginStaging_ALL_UE4_423_AS_HostProject_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_UpdateSessionCallbackProxyAdvanced_h_11_INCLASS_NO_PURE_DECLS \
	D__Documents_Unreal_Projects_VRExpPluginExp_COMPPLUGIN_PluginStaging_ALL_UE4_423_AS_HostProject_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_UpdateSessionCallbackProxyAdvanced_h_11_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class UpdateSessionCallbackProxyAdvanced."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ADVANCEDSESSIONS_API UClass* StaticClass<class UUpdateSessionCallbackProxyAdvanced>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID D__Documents_Unreal_Projects_VRExpPluginExp_COMPPLUGIN_PluginStaging_ALL_UE4_423_AS_HostProject_Plugins_AdvancedSessions_Source_AdvancedSessions_Classes_UpdateSessionCallbackProxyAdvanced_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
