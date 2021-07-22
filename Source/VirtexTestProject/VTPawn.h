// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "VTPawn.generated.h"

UENUM(BlueprintType)
enum class EDirection : uint8
{
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

DECLARE_DELEGATE_OneParam(FVTInputDelegate, EDirection);

UCLASS()
class VIRTEXTESTPROJECT_API AVTPawn : public APawn
{
	GENERATED_BODY()

public:
	AVTPawn();
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(Replicated, BlueprintReadWrite)
	int32 ActionPressed;
protected:

	virtual void BeginPlay() override;

private:

	UFUNCTION(Server, Reliable, WithValidation)
	void MoveOnServer(EDirection NewDir);

	void OnMovePressed(EDirection Direction);

	void OnActionPressed();	

	EDirection CurrentDirection;

	bool MoveCharacter;
};
