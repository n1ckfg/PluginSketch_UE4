// Fill out your copyright notice in the Description page of Project Settings.

#include "TestActor1.h"

// Sets default values
ATestActor1::ATestActor1() 
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootComponent"));
	RootComponent = Mesh;

	static ConstructorHelpers::FObjectFinder<UBlueprint> finder_BP_Blimp(TEXT("Blueprint'/Game/Blueprints/BP_Blimp.BP_Blimp'"));
	BP_Blimp = findBlueprint(finder_BP_Blimp);
}

// Called when the game starts or when spawned
void ATestActor1::BeginPlay() 
{ 
	Super::BeginPlay(); 

	loadMesh(meshFilePath);

	for (int i = 0; i < numActors; i++)
	{
		AActor* blimp = GetWorld()->SpawnActor(BP_Blimp);
	}
}

// Called every frame
void ATestActor1::Tick(float DeltaTime) 
{ 
	Super::Tick(DeltaTime); 
}

void ATestActor1::loadMesh(FString MeshName) 
{	
	UStaticMesh *MeshAsset = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, *MeshName));
	Mesh->SetStaticMesh(MeshAsset);
}

UClass* ATestActor1::findBlueprint(ConstructorHelpers::FObjectFinder<UBlueprint> finder)
{
	FString url = finder.Object->GetPathName();
	UE_LOG(LogTemp, Warning, TEXT("Found Blueprint at url: %s"), *url);
	return (UClass*)finder.Object->GeneratedClass;
}
