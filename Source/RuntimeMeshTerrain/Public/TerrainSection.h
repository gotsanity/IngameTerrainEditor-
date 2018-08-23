// Copyright 2016 Andreas Schoch (aka Minaosis). All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TerrainEditorStuff.h"
#include "TerrainSection.generated.h"

class UProceduralMeshComponent;
class ATerrainGenerator;

UCLASS()
class RUNTIMEMESHTERRAIN_API ATerrainSection : public AActor
{
	GENERATED_BODY()
	
public:	
	ATerrainSection();
	void InitializeOnSpawn(int32 SectionIndex, ATerrainGenerator* Terrain);
	void CreateSection();
	void UpdateSection();

	FVector SectionCoordinates;
	FVector CenterLocation;

	UPROPERTY(EditAnywhere, Category = "ProceduralMeshGeneration")
	bool bUseRuntimeMeshComponent = false;

	UFUNCTION(BlueprintCallable, Category = "ProceduralMeshGeneration")
	void RequestSculpting(const FSculptSettings& Settings, const FSculptInputInfo& InputInfo);

	UPROPERTY(VisibleAnywhere, Category = "Components")
		USceneComponent* SceneRoot = nullptr;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Components")
		UProceduralMeshComponent* ProceduralMeshComponent = nullptr;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Components")
		UProceduralMeshComponent* ProceduralMeshComponentLOD1 = nullptr;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Components")
		UProceduralMeshComponent* ProceduralMeshComponentLOD2 = nullptr;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Components")
		UProceduralMeshComponent* ProceduralMeshComponentLOD3 = nullptr;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Components")
		UProceduralMeshComponent* ProceduralMeshComponentLOD4 = nullptr;

private:
	virtual void BeginPlay() override;
	void SetVisibility();


	TArray<UProceduralMeshComponent*> ProceduralMeshLODs;

	APlayerController* PlayerControllerReference = nullptr;

	int32 SectionIndexLocal = 0;

	TArray<int32> IndexBufferLocal;

	FTimerHandle VisibilityTimerHandle;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sculpting")
	ATerrainGenerator* OwningTerrain = nullptr;
};
