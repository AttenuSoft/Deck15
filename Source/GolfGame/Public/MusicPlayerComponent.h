// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/AudioComponent.h"
#include "MusicPlayerComponent.generated.h"

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
//UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent, Blueprintable) )
class GOLFGAME_API UMusicPlayerComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMusicPlayerComponent();

	UPROPERTY(EditAnywhere, Category="Audio")
	float FadeDuration = 2.0f;

	UPROPERTY(BlueprintReadOnly, Category="Audio")
	USoundBase* CurrentTrack;

	UPROPERTY(EditAnywhere, Category="Audio")
	UAudioComponent* PrimaryAudioComponent;

	UPROPERTY(EditAnywhere, Category="Audio")
	UAudioComponent* SecondaryAudioComponent;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category="Audio")
	void PlayNewMusicTrack(USoundBase* newTrack);

	UFUNCTION(BlueprintCallable, Category = "Audio")
	UAudioComponent* GetAudioComponentToUse();

		
};
