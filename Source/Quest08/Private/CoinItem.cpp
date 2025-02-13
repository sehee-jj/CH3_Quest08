// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinItem.h"
#include "Engine/World.h"
#include "NBCGameStateBase.h"

ACoinItem::ACoinItem()
{
	PointValue = 0;
	ItemType = "DefaultCoin";
}

void ACoinItem::ActivateItem(AActor* Activator)
{
	if (Activator && Activator->ActorHasTag("Player"))
	{
		if (UWorld* World = GetWorld())
		{
			if (ANBCGameStateBase* GameState = World->GetGameState<ANBCGameStateBase>())
			{
				GameState->AddScore(PointValue);
				GameState->OnCoinCollected();
			}
		}

		DestroyItem();
	}
}