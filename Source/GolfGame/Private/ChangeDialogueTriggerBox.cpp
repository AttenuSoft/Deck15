/*ChangeDialogueTriggerBox.cpp
 *Author: Andrew Sales
 *Revision: 1 (05/15/2020)
 *Revision: 2 (05/22/2020)
 *Rev. Author: Kaylene Petrin
 *Rev. Comments: Pushed code up to super class
 **Revision: 3 (05/31/2020)
 *Rev. Author: Kaylene Petrin
 *Rev. Comments: Added a time to delay the audio playing
 *Description: Loads a new Sound Base to the Player's audio component for dialogue and plays the cue.
 */


#include "ChangeDialogueTriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"

AChangeDialogueTriggerBox::AChangeDialogueTriggerBox()
{

};

void AChangeDialogueTriggerBox::BeginPlay()
{
	Super::BeginPlay();

}

void AChangeDialogueTriggerBox::OverlapBeginAction() 
{
	
}

void AChangeDialogueTriggerBox::DialoguePlay()
{
	
}

void AChangeDialogueTriggerBox::OverlapEndAction()
{

}
