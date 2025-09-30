// Copyright Epic Games, Inc. All Rights Reserved.


#include "LoudSpeaker.h"


ALoudSpeaker::ALoudSpeaker()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	SpeakerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpeakerMesh"));
	RootComponent = SpeakerMesh;

	DialogueAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("DialogueAudioComponent"));
	DialogueAudioComponent->SetupAttachment(SpeakerMesh);
	DialogueAudioComponent->SetRelativeLocation(FVector::ZeroVector);
	DialogueAudioComponent->bAutoActivate = false;

}


void ALoudSpeaker::BeginPlay()
{
	Super::BeginPlay();
	
}


void ALoudSpeaker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALoudSpeaker::PlayDialogueTrack(USoundBase* Dialogue)
{
	if (Dialogue != nullptr)
	{
		DialogueAudioComponent->SetSound(Dialogue);
		DialogueAudioComponent->Play();
	}
	
}

