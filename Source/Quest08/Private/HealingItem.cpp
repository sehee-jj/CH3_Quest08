// Fill out your copyright notice in the Description page of Project Settings.


#include "HealingItem.h"
#include "NBCCharacter.h"

AHealingItem::AHealingItem()
{
	HealAmount = 20.0f;
	ItemType = "Healing";
}

void AHealingItem::ActivateItem(AActor* Activator)
{
	if (Activator && Activator->ActorHasTag("Player"))
	{
		if (ANBCCharacter* PlayerCharacter = Cast<ANBCCharacter>(Activator))
		{
			PlayerCharacter->AddHealth(HealAmount);
		}
		DestroyItem();
	}
}
