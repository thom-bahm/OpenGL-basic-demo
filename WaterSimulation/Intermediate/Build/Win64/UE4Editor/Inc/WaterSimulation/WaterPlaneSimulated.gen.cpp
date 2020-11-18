// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WaterSimulation/Public/WaterPlaneSimulated.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWaterPlaneSimulated() {}
// Cross Module References
	WATERSIMULATION_API UClass* Z_Construct_UClass_AWaterPlaneSimulated_NoRegister();
	WATERSIMULATION_API UClass* Z_Construct_UClass_AWaterPlaneSimulated();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_WaterSimulation();
// End Cross Module References
	void AWaterPlaneSimulated::StaticRegisterNativesAWaterPlaneSimulated()
	{
	}
	UClass* Z_Construct_UClass_AWaterPlaneSimulated_NoRegister()
	{
		return AWaterPlaneSimulated::StaticClass();
	}
	struct Z_Construct_UClass_AWaterPlaneSimulated_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWaterPlaneSimulated_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_WaterSimulation,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWaterPlaneSimulated_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "WaterPlaneSimulated.h" },
		{ "ModuleRelativePath", "Public/WaterPlaneSimulated.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWaterPlaneSimulated_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWaterPlaneSimulated>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AWaterPlaneSimulated_Statics::ClassParams = {
		&AWaterPlaneSimulated::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AWaterPlaneSimulated_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AWaterPlaneSimulated_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AWaterPlaneSimulated()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AWaterPlaneSimulated_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AWaterPlaneSimulated, 1272583435);
	template<> WATERSIMULATION_API UClass* StaticClass<AWaterPlaneSimulated>()
	{
		return AWaterPlaneSimulated::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AWaterPlaneSimulated(Z_Construct_UClass_AWaterPlaneSimulated, &AWaterPlaneSimulated::StaticClass, TEXT("/Script/WaterSimulation"), TEXT("AWaterPlaneSimulated"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWaterPlaneSimulated);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
