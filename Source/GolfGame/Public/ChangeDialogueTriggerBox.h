#pragma once
#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GolfGameCharacter.h"
#include "Sound/SoundBase.h"
#include "GolfGameTriggerBox.h"
#include "ChangeDialogueTriggerBox.generated.h"
/**
*\brief When the player begins overlapping the ChangeDialogueTriggerBox, a new
*Sound Base is loaded into the audio component in the GolfGameCharacter and played.
*A delay can be set from the UE4 editor to postpone the playing of the new dialogue
*for a set number of seconds. The Sound Base will only be played once, then the
*DialoguePlayed boolean is set to true.
*/

UCLASS(Blueprintable, BlueprintType, meta = (BlueprintSpawnableComponent))
class GOLFGAME_API AChangeDialogueTriggerBox : public AGolfGameTriggerBox
{
	GENERATED_BODY()

protected:


	virtual void BeginPlay() override;

	virtual void OverlapBeginAction() override;

	virtual void OverlapEndAction() override;

public:

	/**\brief Sets DialoguePlayed to false.*/
	AChangeDialogueTriggerBox();

	//
	/**\brief New Sound Base to be loaded to player and player's audio component for dialogue. Sound Base
	 * is selected in the UE4 editor.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialogue")
	USoundBase* Dialogue;

	/**\brief Play dialogue for player.*/
	void DialoguePlay();

};
