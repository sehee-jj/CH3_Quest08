// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemInterface.h"
#include "BaseItem.generated.h"

UCLASS()
class QUEST08_API ABaseItem : public AActor, public IItemInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseItem();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FName ItemType;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item|Component")
	USceneComponent* Scene;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item|Component")
	class USphereComponent* Collision;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item|Component")
	UStaticMeshComponent* StaticMesh;

	void OnItemOverlap(
		UPrimitiveComponent* OverlappedComp, 
		AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, 
		bool bFromSweep, 
		const FHitResult& SweepResult) override;
	void OnItemEndOverlap(
		UPrimitiveComponent* OverlappedComp, 
		AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex) override;
	virtual void ActivateItem(AActor*) override;
	virtual FName GetItemType() const override;

	virtual void DestroyItem();
};
