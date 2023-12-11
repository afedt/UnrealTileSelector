// Fill out your copyright notice in the Description page of Project Settings.


#include "MDVProject4/UI/Widgets/Settings.h"

#include "MDVProject4/UI/HUD/MyHUD.h"


void USettings::NativeOnInitialized() {
	Super::NativeOnInitialized();
	MyHUD = Cast<AMyHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
}

void USettings::ChangeScreenshotDirPressed() {
	MyHUD->ChangeScreenshotDir();
}

void USettings::ChangeResourcesDirPressed() {
	MyHUD->ChangeResourcesDir();
}

void USettings::OpenScreenshotDirPressed() {
	MyHUD->OpenScreenshotDir();
}

void USettings::OpenResourcesDirPressed() {
	MyHUD->OpenResourcesDir();
}

void USettings::CloseButtonPressed() {
	RemoveFromParent();
	MyHUD->EnableTileSelect();
}

void USettings::SaveButtonPressed() {
	
}
