// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/AudioComponent.h"
#include "ConversationDataAsset.h"
#include "Sound/SoundCue.h"
#include "LoudSpeaker.h"
#include "Kismet/GameplayStatics.h"
#include "DialogueComponent.generated.h"


UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class GOLFGAME_API UDialogueComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	
	UDialogueComponent();

	UPROPERTY(EditAnywhere, Category="Dialogue")
	TArray<UConversationDataAsset*> Conversations;

	UConversationDataAsset* CurrentConversation;

	UPROPERTY(EditAnywhere, Category="Dialogue")
	UAudioComponent* DialogueAudioComponent;

private:

	bool bConversationPlaying = false;
	int CurrentDialogueTrackIndex = 0;
	int LastDialogueTrackIndex = 0;

	ALoudSpeaker* LoudSpeakerCurrentlyPlaying;

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	void AddConversationToQueue(UConversationDataAsset* NewConversation);

private:

	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	void PlayConversation();

	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	void DialogueFinishedPlaying();

	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	ALoudSpeaker* FindNearestLoudSpeaker();

	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	TArray<AActor*> GetAllLoudSpeakers();

	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	void PlayLoudSpeakerDialogue(USoundBase* Dialogue);

	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	void LoudSpeakerFinishedPlaying();

	UFUNCTION(BlueprintCallable, Category = "Dialogue")
	void SetupConversation();

};
