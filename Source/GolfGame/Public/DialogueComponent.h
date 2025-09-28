// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"
#include "DialogueComponent.generated.h"


UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class GOLFGAME_API UDialogueComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	
	UDialogueComponent();

	UPROPERTY(BlueprintReadWrite, Category="Dialogue")
	TArray<USoundBase*> DialogueToPlay;

	UPROPERTY(EditAnywhere, Category="Dialogue")
	UAudioComponent* DialogueAudioComponent;

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	void PlayDialogueTrack();

	UFUNCTION(BlueprintCallable, Category="Dialogue")
	void AddDialogueToPlay(USoundBase* newDialogueTrack);

	UFUNCTION(BlueprintCallable, Category="Dialogue")
	void RemoveDialogueAfterFinished(USoundBase* newDialogueTrack);

	UFUNCTION(BlueprintCallable, Category="Dialogue")
	void OnDialogueFinished();

	UFUNCTION(BlueprintCallable, Category="Dialogue")
	void StopAndResetDialogue();
		
};
