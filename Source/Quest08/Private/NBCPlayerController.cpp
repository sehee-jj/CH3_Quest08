// Fill out your copyright notice in the Description page of Project Settings.


#include "NBCPlayerController.h"
#include "EnhancedInputSubsystems.h"

ANBCPlayerController::ANBCPlayerController()
	: InputMappingContext(nullptr),
	MoveAction(nullptr),
	JumpAction(nullptr),
	LookAction(nullptr),
	SprintAction(nullptr)
{
}

void ANBCPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// ����  PlayerController�� ����� Local Player ��ü�� ������
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		// Local Player���� EnhancedInputLocalPlayerSubsystem�� ȹ��
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (InputMappingContext)
			{
				// Subsystem�� ���� �츮�� �Ҵ��� IMC�� Ȱ��ȭ
				// �켱������ 0 (0�� ���� ���� �켱����)
				Subsystem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}
}

