// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GolfGameCharacter.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GolfGameFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class GOLFGAME_API UGolfGameFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category="Character")
	static AGolfGameCharacter* GetGolfGameCharacter(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="Ball")
	static ABall* GetGolfGameBall(UObject* WorldContextObject);

};
