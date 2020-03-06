// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AnimatedTextureEditor/Public/AnimatedTextureFactory.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimatedTextureFactory() {}
// Cross Module References
	ANIMATEDTEXTUREEDITOR_API UClass* Z_Construct_UClass_UAnimatedTextureFactory_NoRegister();
	ANIMATEDTEXTUREEDITOR_API UClass* Z_Construct_UClass_UAnimatedTextureFactory();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_AnimatedTextureEditor();
// End Cross Module References
	void UAnimatedTextureFactory::StaticRegisterNativesUAnimatedTextureFactory()
	{
	}
	UClass* Z_Construct_UClass_UAnimatedTextureFactory_NoRegister()
	{
		return UAnimatedTextureFactory::StaticClass();
	}
	struct Z_Construct_UClass_UAnimatedTextureFactory_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAnimatedTextureFactory_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_AnimatedTextureEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimatedTextureFactory_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Import & Reimport Animated Texture Source, such as .gif file\n */" },
		{ "IncludePath", "AnimatedTextureFactory.h" },
		{ "ModuleRelativePath", "Public/AnimatedTextureFactory.h" },
		{ "ToolTip", "Import & Reimport Animated Texture Source, such as .gif file" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAnimatedTextureFactory_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAnimatedTextureFactory>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAnimatedTextureFactory_Statics::ClassParams = {
		&UAnimatedTextureFactory::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UAnimatedTextureFactory_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UAnimatedTextureFactory_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAnimatedTextureFactory()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAnimatedTextureFactory_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAnimatedTextureFactory, 2557278659);
	template<> ANIMATEDTEXTUREEDITOR_API UClass* StaticClass<UAnimatedTextureFactory>()
	{
		return UAnimatedTextureFactory::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAnimatedTextureFactory(Z_Construct_UClass_UAnimatedTextureFactory, &UAnimatedTextureFactory::StaticClass, TEXT("/Script/AnimatedTextureEditor"), TEXT("UAnimatedTextureFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAnimatedTextureFactory);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
