#include "VTPawn.h"
#include "Net/UnrealNetwork.h"

AVTPawn::AVTPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AVTPawn::BeginPlay()
{
	Super::BeginPlay();	
}

void AVTPawn::Tick(float DeltaTime)
{
	if (MoveCharacter)
	{
		FVector Location(GetActorLocation());
		if (CurrentDirection == EDirection::UP)
		{

		}
		else if (CurrentDirection == EDirection::DOWN)
		{

		}
		else if (CurrentDirection == EDirection::LEFT)
		{

		}
		else if (CurrentDirection == EDirection::RIGHT)
		{

		}
		SetActorLocation(Location);
	}
}

void AVTPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction<FVTInputDelegate>("Up", IE_Pressed, this, &AVTPawn::OnMovePressed, EDirection::UP);
	InputComponent->BindAction<FVTInputDelegate>("Down", IE_Pressed, this, &AVTPawn::OnMovePressed, EDirection::DOWN);
	InputComponent->BindAction<FVTInputDelegate>("Left", IE_Pressed, this, &AVTPawn::OnMovePressed, EDirection::LEFT);
	InputComponent->BindAction<FVTInputDelegate>("Right", IE_Pressed, this, &AVTPawn::OnMovePressed, EDirection::RIGHT);

	InputComponent->BindAction("Action", IE_Pressed, this, &AVTPawn::OnActionPressed);
}

void AVTPawn::OnMovePressed(EDirection Direction)
{
	MoveOnServer(Direction);
}

void AVTPawn::OnActionPressed()
{
	if (ActionPressed != 0)
	{
		++ActionPressed;
	}	
}

void AVTPawn::MoveOnServer_Implementation(EDirection NewDir)
{
	MoveCharacter = CurrentDirection != EDirection::NONE;	
}

bool AVTPawn::MoveOnServer_Validate(EDirection NewDir)
{
	return true;
}

void AVTPawn::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}