// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AnimatedTexture/Public/AnimatedGIFDecoder.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimatedGIFDecoder() {}
// Cross Module References
	ANIMATEDTEXTURE_API UClass* Z_Construct_UClass_UAnimatedGIFDecoder_NoRegister();
	ANIMATEDTEXTURE_API UClass* Z_Construct_UClass_UAnimatedGIFDecoder();
	ANIMATEDTEXTURE_API UClass* Z_Construct_UClass_UAnimatedTextureSource();
	UPackage* Z_Construct_UPackage__Script_AnimatedTexture();
// End Cross Module References
	void UAnimatedGIFDecoder::StaticRegisterNativesUAnimatedGIFDecoder()
	{
	}
	UClass* Z_Construct_UClass_UAnimatedGIFDecoder_NoRegister()
	{
		return UAnimatedGIFDecoder::StaticClass();
	}
	struct Z_Construct_UClass_UAnimatedGIFDecoder_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Duration_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Duration;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Background_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Background;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GlobalHeight_MetaData[];
#endif
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp_GlobalHeight;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GlobalWidth_MetaData[];
#endif
		static const UE4CodeGen_Private::FUInt32PropertyParams NewProp_GlobalWidth;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UAnimatedGIFDecoder_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UAnimatedTextureSource,
		(UObject* (*)())Z_Construct_UPackage__Script_AnimatedTexture,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimatedGIFDecoder_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Animated GIF Data Storage & Runtime Decoder\n */" },
		{ "IncludePath", "AnimatedGIFDecoder.h" },
		{ "ModuleRelativePath", "Public/AnimatedGIFDecoder.h" },
		{ "SerializeToFArchive", "" },
		{ "ToolTip", "Animated GIF Data Storage & Runtime Decoder" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimatedGIFDecoder_Statics::NewProp_Duration_MetaData[] = {
		{ "Comment", "// 0-based background color index for the current palette\n" },
		{ "ModuleRelativePath", "Public/AnimatedGIFDecoder.h" },
		{ "ToolTip", "0-based background color index for the current palette" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UAnimatedGIFDecoder_Statics::NewProp_Duration = { "Duration", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UAnimatedGIFDecoder, Duration), METADATA_PARAMS(Z_Construct_UClass_UAnimatedGIFDecoder_Statics::NewProp_Duration_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAnimatedGIFDecoder_Statics::NewProp_Duration_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimatedGIFDecoder_Statics::NewProp_Background_MetaData[] = {
		{ "ModuleRelativePath", "Public/AnimatedGIFDecoder.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_UAnimatedGIFDecoder_Statics::NewProp_Background = { "Background", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UAnimatedGIFDecoder, Background), nullptr, METADATA_PARAMS(Z_Construct_UClass_UAnimatedGIFDecoder_Statics::NewProp_Background_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAnimatedGIFDecoder_Statics::NewProp_Background_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimatedGIFDecoder_Statics::NewProp_GlobalHeight_MetaData[] = {
		{ "ModuleRelativePath", "Public/AnimatedGIFDecoder.h" },
	};
#endif
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_UAnimatedGIFDecoder_Statics::NewProp_GlobalHeight = { "GlobalHeight", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UAnimatedGIFDecoder, GlobalHeight), METADATA_PARAMS(Z_Construct_UClass_UAnimatedGIFDecoder_Statics::NewProp_GlobalHeight_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAnimatedGIFDecoder_Statics::NewProp_GlobalHeight_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UAnimatedGIFDecoder_Statics::NewProp_GlobalWidth_MetaData[] = {
		{ "ModuleRelativePath", "Public/AnimatedGIFDecoder.h" },
	};
#endif
	const UE4CodeGen_Private::FUInt32PropertyParams Z_Construct_UClass_UAnimatedGIFDecoder_Statics::NewProp_GlobalWidth = { "GlobalWidth", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::UInt32, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UAnimatedGIFDecoder, GlobalWidth), METADATA_PARAMS(Z_Construct_UClass_UAnimatedGIFDecoder_Statics::NewProp_GlobalWidth_MetaData, ARRAY_COUNT(Z_Construct_UClass_UAnimatedGIFDecoder_Statics::NewProp_GlobalWidth_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAnimatedGIFDecoder_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimatedGIFDecoder_Statics::NewProp_Duration,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimatedGIFDecoder_Statics::NewProp_Background,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimatedGIFDecoder_Statics::NewProp_GlobalHeight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimatedGIFDecoder_Statics::NewProp_GlobalWidth,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UAnimatedGIFDecoder_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAnimatedGIFDecoder>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UAnimatedGIFDecoder_Statics::ClassParams = {
		&UAnimatedGIFDecoder::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UAnimatedGIFDecoder_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_UAnimatedGIFDecoder_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UAnimatedGIFDecoder_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UAnimatedGIFDecoder_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UAnimatedGIFDecoder()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UAnimatedGIFDecoder_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UAnimatedGIFDecoder, 891405375);
	template<> ANIMATEDTEXTURE_API UClass* StaticClass<UAnimatedGIFDecoder>()
	{
		return UAnimatedGIFDecoder::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UAnimatedGIFDecoder(Z_Construct_UClass_UAnimatedGIFDecoder, &UAnimatedGIFDecoder::StaticClass, TEXT("/Script/AnimatedTexture"), TEXT("UAnimatedGIFDecoder"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UAnimatedGIFDecoder);
	IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(UAnimatedGIFDecoder)
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
