#include "BTService_BatteryCheck.h"
#include "BaseDummyAIController.h"
#include "BaseDummyCharacter.h"
#include "BatteryStatus.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTService_BatteryCheck::UBTService_BatteryCheck()
{
    bCreateNodeInstance = true;
    bNotifyBecomeRelevant = true;
    bNotifyCeaseRelevant = true;
    bNotifyTick = false;
}

void UBTService_BatteryCheck::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8 *NodeMemory)
{
    Super::OnBecomeRelevant(OwnerComp, NodeMemory);
    BlackboardComponent = OwnerComp.GetBlackboardComponent();

    const ABaseDummyAIController* AIController = Cast<ABaseDummyAIController>(OwnerComp.GetAIOwner());
    if (!AIController) return;
    APawn* ControlledPawn = AIController -> GetPawn();
    if (!ControlledPawn) return;
    ControlledCharacter = Cast<ABaseDummyCharacter>(ControlledPawn);
    if (!ControlledCharacter) return;

    ControlledCharacter -> OnBatteryStatusChanged.AddDynamic(this, &UBTService_BatteryCheck::OnBatteryStatusChange);

}

void UBTService_BatteryCheck::OnCeaseRelevant(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory)
{
    Super::OnCeaseRelevant(OwnerComp, NodeMemory);
    ControlledCharacter -> OnBatteryStatusChanged.RemoveDynamic(this, &UBTService_BatteryCheck::OnBatteryStatusChange);
}

void UBTService_BatteryCheck::OnBatteryStatusChange(EBatteryStatus NewBatteryStatus)
{
	switch (NewBatteryStatus)
	{
	case EBatteryStatus::EBS_Empty:
			BlackboardComponent->SetValueAsBool(IsBatteryDepletedKey.SelectedKeyName, true);
		break;
	case EBatteryStatus::EBS_Low:
			BlackboardComponent->SetValueAsBool(IsLowOnBatteryKey.SelectedKeyName, true);
		BlackboardComponent->SetValueAsBool(IsBatteryDepletedKey.SelectedKeyName, false);
		break;
	case EBatteryStatus::EBS_Medium:
			break;
	case EBatteryStatus::EBS_Full:
			BlackboardComponent->SetValueAsBool(IsLowOnBatteryKey.SelectedKeyName, false);
		break;
	}
}
