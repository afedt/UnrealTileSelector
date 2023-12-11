// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IDirectoryWatcher.h"
#include "MDVProject4/Utils/DataStructures.h"
#include "AMyController.generated.h"

class AMyActor;
class AMyReferenceManager;
class AMyHUD;


UCLASS()
/**
 * 
 */
class MDVPROJECT4_API AMyController : public AActor {

DECLARE_DELEGATE_RetVal(AMyController, Delegate);

	GENERATED_BODY()
	
public:
	explicit AMyController();
	
	void SetWallMaterial(UMaterialInstanceDynamic* DynamicMaterial) const;

	void SetDefaultMaterial() const;

	void UpdateSelectedWall(AMyActor* MyWallActor);

	void SaveGame();
	void LoadGame();
	void DeleteSaveFile();
	
	void CreateScreenshot(const FText& ScreenshotName) const;
	
	FText RetrieveDataTableMessage(EDataTableContentIndex DataTableContentIndex);

static bool IsTileSelectEnabled();

	static void ScreenshotCaptured(int32 Width, int32 Height, const TArray<FColor>& Bitmap);
	
	void ScreenClicked();

	TArray<FMyDynamicMat> DynamicMaterialArray;

	bool WallHovered;
	
	FString ResourcesDirPath;

protected:
	void CreateDirectoryWatcherDelegate();
	
	virtual void BeginPlay() override;

	UStaticMeshComponent* GetSelectedWallStaticMeshComponent() const;
	
	void InitialiseDynamicMaterialArray();
	
	void InsertItemToDynamicMaterialArray(const FString& FilePath);
	
	void UpdateDynamicMaterialArray(const FString& FileName, FFileChangeData::EFileChangeAction Action);
	
	void OnProjectDirectoryChanged(const TArray<FFileChangeData>& Data);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wall tagging")
	FName WallsTag;
	
	UPROPERTY()
	UDataTable* MessageDataTable;
	
	TArray<FName> MessageDataTableRowNames;
	
private:
	static inline AMyReferenceManager* MyReferenceManager;

	UPROPERTY()
	UMaterialInterface* BaseMaterial;

	UPROPERTY()
	AMyActor* SelectedWall;

	UPROPERTY()
	TArray<AActor*> MyWalls;

	UPROPERTY()
	TMap<AMyActor*, FString> SaveMap;
	
	bool RenderSaveMap();

	FDelegateHandle ScreenshotDelegateHandle;

	static inline FString ScreenshotFilename;
};
