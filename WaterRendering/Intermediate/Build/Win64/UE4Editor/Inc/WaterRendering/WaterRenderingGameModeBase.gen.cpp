// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WaterRendering/WaterRenderingGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWaterRenderingGameModeBase() {}
// Cross Module References
	WATERRENDERING_API UClass* Z_Construct_UClass_AWaterRenderingGameModeBase_NoRegister();
	WATERRENDERING_API UClass* Z_Construct_UClass_AWaterRenderingGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_WaterRendering();
// End Cross Module References
	void AWaterRenderingGameModeBase::StaticRegisterNativesAWaterRenderingGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AWaterRenderingGameModeBase_NoRegister()
	{
		return AWaterRenderingGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AWaterRenderingGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWaterRenderingGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_WaterRendering,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWaterRenderingGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "WaterRenderingGameModeBase.h" },
		{ "ModuleRelativePath", "WaterRenderingGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWaterRenderingGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWaterRenderingGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AWaterRenderingGameModeBase_Statics::ClassParams = {
		&AWaterRenderingGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AWaterRenderingGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AWaterRenderingGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AWaterRenderingGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AWaterRenderingGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AWaterRenderingGameModeBase, 1152820855);
	template<> WATERRENDERING_API UClass* StaticClass<AWaterRenderingGameModeBase>()
	{
		return AWaterRenderingGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AWaterRenderingGameModeBase(Z_Construct_UClass_AWaterRenderingGameModeBase, &AWaterRenderingGameModeBase::StaticClass, TEXT("/Script/WaterRendering"), TEXT("AWaterRenderingGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWaterRenderingGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
