// Fill out your copyright notice in the Description page of Project Settings.

#include "TestActor1.h"

// Sets default values
ATestActor1::ATestActor1() {
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootComponent"));
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void ATestActor1::BeginPlay() { 
	Super::BeginPlay(); 

	SetMesh(meshFilePath);
}

// Called every frame
void ATestActor1::Tick(float DeltaTime) { 
	Super::Tick(DeltaTime); 
}

void ATestActor1::SetMesh(FString MeshName) {
	UStaticMesh *MeshAsset = Cast<UStaticMesh>(
		StaticLoadObject(UStaticMesh::StaticClass(), NULL, *MeshName));
	Mesh->SetStaticMesh(MeshAsset);
}
