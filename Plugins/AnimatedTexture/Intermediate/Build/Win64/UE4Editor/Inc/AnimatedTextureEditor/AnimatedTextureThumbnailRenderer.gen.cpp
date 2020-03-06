// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AnimatedTextureEditor/Public/AnimatedTextureThumbnailRenderer.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimatedTextureThumbnailRenderer() {}
// Cross Module References
	ANIMATEDTEXTUREEDITOR_API UClass* Z_Construct_UClass_UAnimatedTextureThumbnailRenderer_NoRegister();
	ANIMATEDTEXTUREEDITOR_API UClass* Z_Construct_UClass_UAnimatedTextureThumbnailRenderer();
	UNREALED_API UClass* Z_Construct_UClass_UThumbnailRenderer();
	UPackage* Z_Construct_UPackage__Script_AnimatedTextureEditor();
// End Cross Module References
	void UAnimatedTextureThumbnailRenderer::StaticRegisterNativesUAnimatedTextureThumbnailRenderer()
	{
	}
	UClass* Z_Construct_UClass_UAnimatedTextureThumbnailRenderer_NoRegister()
	{
		return UAnimatedTextureThumbnailRenderer::StaticClass();
	}
	struct Z_Construct_UClass_UAnimatedTextureThumbnailRenderer_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAnimatedTextureThumbnailRenderer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UThumbnailRenderer,
		(UObject* (*)())Z_Construct_UPackage__Script_AnimatedTextureEditor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimatedTextureThumbnailRenderer_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "AnimatedTextureThumbnailRenderer.h" },
		{ "ModuleRelativePath", "Public/AnimatedTextureThumbnailRenderer.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAnimatedTextureThumbnailRenderer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAnimatedTextureThumbnailRenderer>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAnimatedTextureThumbnailRenderer_Statics::ClassParams = {
		&UAnimatedTextureThumbnailRenderer::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UAnimatedTextureThumbnailRenderer_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UAnimatedTextureThumbnailRenderer_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAnimatedTextureThumbnailRenderer()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAnimatedTextureThumbnailRenderer_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAnimatedTextureThumbnailRenderer, 2400955240);
	template<> ANIMATEDTEXTUREEDITOR_API UClass* StaticClass<UAnimatedTextureThumbnailRenderer>()
	{
		return UAnimatedTextureThumbnailRenderer::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAnimatedTextureThumbnailRenderer(Z_Construct_UClass_UAnimatedTextureThumbnailRenderer, &UAnimatedTextureThumbnailRenderer::StaticClass, TEXT("/Script/AnimatedTextureEditor"), TEXT("UAnimatedTextureThumbnailRenderer"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAnimatedTextureThumbnailRenderer);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
