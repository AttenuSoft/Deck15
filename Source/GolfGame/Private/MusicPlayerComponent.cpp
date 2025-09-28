


#include "MusicPlayerComponent.h"


UMusicPlayerComponent::UMusicPlayerComponent()
{
	
	PrimaryComponentTick.bCanEverTick = false;

	PrimaryAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("PrimaryAudioComponent"));
	PrimaryAudioComponent->SetRelativeLocation(FVector::ZeroVector);
	PrimaryAudioComponent->bAutoActivate = false;
	
	SecondaryAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("SecondaryAudioComponent"));
	SecondaryAudioComponent->SetRelativeLocation(FVector::ZeroVector);
	SecondaryAudioComponent->bAutoActivate = false;

}



void UMusicPlayerComponent::BeginPlay()
{
	Super::BeginPlay();

}



void UMusicPlayerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UMusicPlayerComponent::PlayNewMusicTrack(USoundBase* NewTrack)
{
	//ensure new track is not null and it is not the same track that is playing
	if (NewTrack != nullptr && NewTrack != CurrentTrack)
	{
		CurrentTrack = NewTrack;
		UAudioComponent* AudioComponentToUse = GetAudioComponentToUse();

		if (AudioComponentToUse)
		{
			AudioComponentToUse->SetSound(NewTrack);
			AudioComponentToUse->FadeIn(FadeDuration, 1);
		}
		else
		{
			//log error
		}

	}
}

UAudioComponent* UMusicPlayerComponent::GetAudioComponentToUse()
{
	if (!PrimaryAudioComponent->IsPlaying())
	{
		if (SecondaryAudioComponent->IsPlaying())
		{
			SecondaryAudioComponent->FadeOut(FadeDuration, 0);
		}

		return PrimaryAudioComponent;
	}
	else if(!SecondaryAudioComponent->IsPlaying())
	{
		if (PrimaryAudioComponent->IsPlaying())
		{
			PrimaryAudioComponent->FadeOut(FadeDuration, 0);
		}

		return SecondaryAudioComponent;
	}

	return nullptr;

}
