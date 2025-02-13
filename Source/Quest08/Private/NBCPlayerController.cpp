// Fill out your copyright notice in the Description page of Project Settings.


#include "NBCPlayerController.h"
#include "NBCGameStateBase.h"
#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"

ANBCPlayerController::ANBCPlayerController()
	: InputMappingContext(nullptr),
	MoveAction(nullptr),
	JumpAction(nullptr),
	LookAction(nullptr),
	SprintAction(nullptr),
	HUDWidgetClass(nullptr),
	HUDWidgetInstance(nullptr)
{
}

UUserWidget* ANBCPlayerController::GetHUDWidget() const
{
	return HUDWidgetInstance;
}

void ANBCPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (InputMappingContext)
			{
				Subsystem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}

	if (HUDWidgetClass)
	{
		HUDWidgetInstance = CreateWidget<UUserWidget>(this, HUDWidgetClass);
		if (HUDWidgetInstance)
		{
			HUDWidgetInstance->AddToViewport();
		}
	}

	ANBCGameStateBase* NBCGameState = GetWorld() ? GetWorld()->GetGameState<ANBCGameStateBase>() : nullptr;
	if (NBCGameState)
	{
		NBCGameState->UpdateHUD();
	}
}

