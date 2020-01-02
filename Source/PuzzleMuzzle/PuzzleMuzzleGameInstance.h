// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PuzzleMuzzleGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEMUZZLE_API UPuzzleMuzzleGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPuzzleMuzzleGameInstance(const FObjectInitializer &ObjectInitializer);

	virtual void Init();

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString &Adress);
};
