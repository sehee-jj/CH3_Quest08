// Fill out your copyright notice in the Description page of Project Settings.


#include "NBCGameMode.h"
#include "NBCCharacter.h"
#include "NBCPlayerController.h"

ANBCGameMode::ANBCGameMode()
{
	DefaultPawnClass = ANBCCharacter::StaticClass();
	PlayerControllerClass = ANBCPlayerController::StaticClass();
}