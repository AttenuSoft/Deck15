// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/AudioComponent.h"
#include "LoudSpeaker.generated.h"

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom))
class GOLFGAME_API ALoudSpeaker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALoudSpeaker();

	UPROPERTY(EditAnywhere, Category="Dialogue")
	UAudioComponent* DialogueAudioComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="SpeakerMesh")
	UStaticMeshComponent* SpeakerMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Audio")
	void PlayDialogueTrack(USoundBase* Dialogue);

};
