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

void UDialogueComponent::AddConversationToQueue(UConversationDataAsset* NewConversation)
{
	Conversations.Add(NewConversation);

	if (!bConversationPlaying)
	{
		SetupConversation();
	}

}

void UDialogueComponent::SetupConversation()
{
	CurrentConversation = Conversations[0];
	LastDialogueTrackIndex = CurrentConversation->Conversation.Num();
	PlayConversation();
}

void UDialogueComponent::PlayConversation()
{
	if (CurrentConversation->Conversation[CurrentDialogueTrackIndex].Type == EDialogueType::Player)
	{
		if (!DialogueAudioComponent->OnAudioFinished.IsBound())
		{
			DialogueAudioComponent->OnAudioFinished.AddDynamic(this, &UDialogueComponent::DialogueFinishedPlaying);
		}

		DialogueAudioComponent->SetSound(CurrentConversation->Conversation[CurrentDialogueTrackIndex].DialogueTrack);
		DialogueAudioComponent->Play();
		bConversationPlaying = true;
	}
	else
	{
		PlayLoudSpeakerDialogue(CurrentConversation->Conversation[CurrentDialogueTrackIndex].DialogueTrack);
	}


}

void UDialogueComponent::DialogueFinishedPlaying()
{
	CurrentDialogueTrackIndex++;

	if (CurrentDialogueTrackIndex == LastDialogueTrackIndex)
	{
		CurrentConversation = nullptr;
		Conversations.RemoveAt(0);
		bConversationPlaying = false;
		CurrentDialogueTrackIndex = 0;

		if (Conversations.Num() > 0)
		{
			SetupConversation();
		}
		else
		{
			DialogueAudioComponent->OnAudioFinished.RemoveDynamic(this, &UDialogueComponent::DialogueFinishedPlaying);
		}
	}
	else
	{
		PlayConversation();
	}

}

ALoudSpeaker* UDialogueComponent::FindNearestLoudSpeaker()
{
	TArray<AActor*> FoundLoudSpeakers = GetAllLoudSpeakers();

	if (FoundLoudSpeakers.Num() > 0)
	{
		float CurrentMinDistance = 1000000.0f;
		AActor* ClosestLoudSpeaker = nullptr;

		for (int i = 0; i < FoundLoudSpeakers.Num(); i++)
		{
			float tempDist = FVector::Dist(GetOwner()->GetActorLocation(), FoundLoudSpeakers[i]->GetActorLocation());
			if (tempDist < CurrentMinDistance)
			{
				ClosestLoudSpeaker = FoundLoudSpeakers[i];
			}
		}

		return Cast<ALoudSpeaker>(ClosestLoudSpeaker);
	}

	return nullptr;

}

TArray<AActor*> UDialogueComponent::GetAllLoudSpeakers()
{
	TArray<AActor*> FoundLoudSpeakers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ALoudSpeaker::StaticClass(), FoundLoudSpeakers);

	return FoundLoudSpeakers;

}

void UDialogueComponent::PlayLoudSpeakerDialogue(USoundBase* Dialogue)
{
	ALoudSpeaker* LoudSpeaker = FindNearestLoudSpeaker();

	if (LoudSpeaker != nullptr && Dialogue != nullptr)
	{
		LoudSpeaker->DialogueAudioComponent->OnAudioFinished.AddDynamic(this, &UDialogueComponent::LoudSpeakerFinishedPlaying);
		LoudSpeaker->PlayDialogueTrack(Dialogue);
		LoudSpeakerCurrentlyPlaying = LoudSpeaker;
	}

}

void UDialogueComponent::LoudSpeakerFinishedPlaying()
{
	LoudSpeakerCurrentlyPlaying->DialogueAudioComponent->OnAudioFinished.RemoveDynamic(this, &UDialogueComponent::LoudSpeakerFinishedPlaying);
	DialogueFinishedPlaying();
}



