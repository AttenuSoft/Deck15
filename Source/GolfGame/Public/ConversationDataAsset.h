// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ConversationDataAsset.generated.h"

UENUM(BlueprintType)
enum class EDialogueType : uint8
{
    Player UMETA(DisplayName="Player"),
    Terra  UMETA(DisplayName="Terra")
};

USTRUCT(BlueprintType)
struct GOLFGAME_API FDialogueTrack
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Dialogue")
	USoundBase* DialogueTrack;

	UPROPERTY(EditAnywhere, Category = "Dialogue")
	EDialogueType Type;
};

UCLASS(BlueprintType)
class GOLFGAME_API UConversationDataAsset : public UDataAsset
{
	GENERATED_BODY()

	public:

		UPROPERTY(EditAnywhere, Category = "Dialogue")
		TArray<FDialogueTrack> Conversation;
	
};
