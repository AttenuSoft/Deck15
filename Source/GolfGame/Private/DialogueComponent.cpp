#include "DialogueComponent.h"


UDialogueComponent::UDialogueComponent()
{
	
	PrimaryComponentTick.bCanEverTick = false;	

	DialogueAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("DialogueAudioComponent"));
	DialogueAudioComponent->SetRelativeLocation(FVector::ZeroVector);
	DialogueAudioComponent->bAutoActivate = false;

}



void UDialogueComponent::BeginPlay()
{
	Super::BeginPlay();
}



void UDialogueComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UDialogueComponent::PlayDialogueTrack()
{
	if (DialogueToPlay.Num() > 0)
	{
		if (!DialogueAudioComponent->OnAudioFinished.IsAlreadyBound(this, &UDialogueComponent::OnDialogueFinished))
		{
			DialogueAudioComponent->OnAudioFinished.AddDynamic(this, &UDialogueComponent::OnDialogueFinished);
		}
		
		DialogueAudioComponent->SetSound(DialogueToPlay[0]);
		DialogueAudioComponent->Play();

	}

}

void UDialogueComponent::AddDialogueToPlay(USoundBase* newDialogueTrack)
{
	if (newDialogueTrack != nullptr)
	{
		DialogueToPlay.AddUnique(newDialogueTrack);
		if (!DialogueAudioComponent->IsPlaying())
		{
			PlayDialogueTrack();
		}
	
	}

}

void UDialogueComponent::RemoveDialogueAfterFinished(USoundBase* newDialogueTrack)
{
	if (newDialogueTrack != nullptr)
	{
		DialogueToPlay.Remove(newDialogueTrack);
	}
}

void UDialogueComponent::OnDialogueFinished()
{
	RemoveDialogueAfterFinished(DialogueToPlay[0]);

	if (DialogueToPlay.Num() > 0)
	{
		PlayDialogueTrack();
	}

}

void UDialogueComponent::StopAndResetDialogue()
{
	if (DialogueAudioComponent->IsPlaying())
	{
		DialogueAudioComponent->FadeOut(2.0f, 0.0f);
		DialogueAudioComponent->OnAudioFinished.RemoveDynamic(this, &UDialogueComponent::OnDialogueFinished);
		DialogueToPlay.Empty();
	}
}

