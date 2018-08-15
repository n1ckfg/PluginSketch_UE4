// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "GameFramework/Actor.h"
#include "ConstructorHelpers.h"

// this must always be the last include
#include "TestActor1.generated.h"

UCLASS()
class PLUGINSKETCH1_API ATestActor1 : public AActor 
{
  GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATestActor1();
	
	UClass* findBlueprint(ConstructorHelpers::FObjectFinder<UBlueprint> finder);
	TSubclassOf<class AActor> BP_Blimp;

	UPROPERTY(EditAnywhere)
	FString meshFilePath;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void loadMesh(FString MeshName);

	FString formatBlueprintUrl(FString url);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UStaticMeshComponent *Mesh;

};
