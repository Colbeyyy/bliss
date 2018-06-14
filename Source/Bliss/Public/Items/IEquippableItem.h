// Copyright 2018, Colby Hall. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/IItem.h"
#include "IEquippableItem.generated.h"

/**
 * Item that can be equipped and used
 * 
 * @abstract
 */
UCLASS(Abstract)
class BLISS_API AIEquippableItem : public AIItem
{
	GENERATED_BODY()

public:

	AIEquippableItem(const FObjectInitializer& ObjectInitializer);

private:

	/** First Person Equippable Mesh*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Item, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* FirstPersonMesh;

	/** Third Person Equippable Mesh*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Item, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* ThirdPersonMesh;

public:

	FORCEINLINE class USkeletalMeshComponent* GetFirstPersonMesh() const { return FirstPersonMesh; }

	/** Name of the First Person Mesh*/
	static FName FirstPersonMeshComponentName;

	FORCEINLINE class USkeletalMeshComponent* GetThirdPersonMesh() const { return ThirdPersonMesh; }

	/** Name of the Third Person Mesh*/
	static FName ThirdPersonMeshComponentName;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Item)
	FName SocketName;

public:

	/**
	 * Equips this item to its owner
	 *
	 * Called on server and all clients
	 */
	UFUNCTION(BlueprintNativeEvent)
	void Equip();

	/**
	 * UnEquips this item from its owner
	 *
	 * Called on server and all clients
	 */
	UFUNCTION(BlueprintNativeEvent)
	void UnEquip();

	/**
	 * 
	 */
	UFUNCTION(BlueprintNativeEvent)
	void StartFiring();

	/**
	 *
	 */
	UFUNCTION(BlueprintNativeEvent)
	void StopFiring();
	
	/**
	 *
	 */
	UFUNCTION(BlueprintNativeEvent)
	void StartAiming();

	/**
	 *
	 */
	UFUNCTION(BlueprintNativeEvent)
	void StopAiming();
	
};
