// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WaterRendering/RandomFunctions.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRandomFunctions() {}
// Cross Module References
	WATERRENDERING_API UClass* Z_Construct_UClass_ARandomFunctions_NoRegister();
	WATERRENDERING_API UClass* Z_Construct_UClass_ARandomFunctions();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_WaterRendering();
// End Cross Module References
	void ARandomFunctions::StaticRegisterNativesARandomFunctions()
	{
	}
	UClass* Z_Construct_UClass_ARandomFunctions_NoRegister()
	{
		return ARandomFunctions::StaticClass();
	}
	struct Z_Construct_UClass_ARandomFunctions_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARandomFunctions_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_WaterRendering,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARandomFunctions_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "RandomFunctions.h" },
		{ "ModuleRelativePath", "RandomFunctions.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARandomFunctions_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARandomFunctions>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ARandomFunctions_Statics::ClassParams = {
		&ARandomFunctions::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ARandomFunctions_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ARandomFunctions_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ARandomFunctions()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ARandomFunctions_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ARandomFunctions, 2914380971);
	template<> WATERRENDERING_API UClass* StaticClass<ARandomFunctions>()
	{
		return ARandomFunctions::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARandomFunctions(Z_Construct_UClass_ARandomFunctions, &ARandomFunctions::StaticClass, TEXT("/Script/WaterRendering"), TEXT("ARandomFunctions"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARandomFunctions);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
