// Fill out your copyright notice in the Description page of Project Settings.


#include "RollaBallGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "../Items/RollaBallItemBase.h"
#include "RollaBallWidget.h"

void ARollaBallGameModeBase::BeginPlay()
{
	// Create pointers items tab
	TArray<AActor*> Items;
	// Retrieve all items and set in the tab
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ARollaBallItemBase::StaticClass(), Items);
	// Save items number
	ItemsInLevel = Items.Num();

	if (GameWidgetClass)
	{
		GameWidget = Cast<URollaBallWidget>(CreateWidget(GetWorld(), GameWidgetClass));

		if (GameWidget)
		{
			GameWidget->AddToViewport();
			UpdateItemText();
		}
	}
}

void ARollaBallGameModeBase::UpdateItemText()
{
	GameWidget->SetItemText(ItemsCollected, ItemsInLevel);
}

void ARollaBallGameModeBase::ItemCollected()
{
	ItemsCollected++;
	UpdateItemText();
}
