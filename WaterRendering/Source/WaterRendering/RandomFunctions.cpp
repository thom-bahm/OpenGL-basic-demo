// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomFunctions.h"
#include "DrawDebugHelpers.h"
#include "Components/BoxComponent.h"

// Sets default values
ARandomFunctions::ARandomFunctions()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Mesh"));
	RootComponent = MyMesh;

	MyBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Comp"));
	MyBoxComponent->InitBoxExtent(FVector(100,100,100));
	MyBoxComponent->SetCollisionProfileName("Trigger");
	MyBoxComponent->SetupAttachment(RootComponent);

	onMaterial = CreateDefaultSubobject<UMaterial>(TEXT("On Mat"));
	offMaterial = CreateDefaultSubobject<UMaterial>(TEXT("off Mat"));

	MyBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ARandomFunctions::OnOverlapBegin);

}

// Called when the game starts or when spawned
void ARandomFunctions::BeginPlay()
{
	Super::BeginPlay();
	
	DrawDebugBox(GetWorld(), GetActorLocation(), FVector(100,100,100), FColor::White, true, -1, 0, 10);

	MyMesh->SetMaterial(0, offMaterial);
}

// Called every frame
void ARandomFunctions::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

