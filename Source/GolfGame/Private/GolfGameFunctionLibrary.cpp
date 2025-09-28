// Copyright Epic Games, Inc. All Rights Reserved.

#include "GolfGameFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"

AGolfGameCharacter* UGolfGameFunctionLibrary::GetGolfGameCharacter(UObject* WorldContextObject)
{
    UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
    if (!World) return nullptr;

    APlayerController* PC = UGameplayStatics::GetPlayerController(World, 0);
    if (!PC) return nullptr;

    return Cast<AGolfGameCharacter>(PC->GetCharacter());
}

ABall* UGolfGameFunctionLibrary::GetGolfGameBall(UObject* WorldContextObject)
{
    UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
    if (!World) return nullptr;

    TArray<AActor*> ballArray;

    UGameplayStatics::GetAllActorsOfClass(World, ABall::StaticClass(), ballArray);

    return Cast<ABall>(ballArray[0]);
}
