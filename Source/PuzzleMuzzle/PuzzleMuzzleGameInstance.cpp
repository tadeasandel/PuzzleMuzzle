// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzleMuzzleGameInstance.h"

#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"

UPuzzleMuzzleGameInstance::UPuzzleMuzzleGameInstance(const FObjectInitializer &ObjectInitializer)
{
  UE_LOG(LogTemp, Warning, TEXT("GameInstance constructor"));
}

void UPuzzleMuzzleGameInstance::Init()
{
  UE_LOG(LogTemp, Warning, TEXT("GameInstance Init"));
}

void UPuzzleMuzzleGameInstance::Host()
{
  UEngine *Engine = GetEngine();
  if (!ensure(Engine != nullptr))
  {
    return;
  }
  Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));

  UWorld *World = GetWorld();
  if (!ensure(World != nullptr))
  {
    return;
  }

  World->ServerTravel("/game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void UPuzzleMuzzleGameInstance::Join(const FString &Address)
{
  UEngine *Engine = GetEngine();
  if (!ensure(Engine != nullptr))
  {
    return;
  }
  Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

  APlayerController *PlayerController = GetFirstLocalPlayerController();
  if (!ensure(PlayerController != nullptr))
  {
    return;
  }

  PlayerController->ClientTravel(*Address, ETravelType::TRAVEL_Absolute);
}
