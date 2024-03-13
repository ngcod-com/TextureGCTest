// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Image.h"
#include "EoneImage.generated.h"

UCLASS()
class TEXTURETEST_API UNImage : public UImage
{
	GENERATED_BODY()
public:

	virtual void Serialize(FArchive& Ar) override;

	virtual void PostInitProperties() override;
	virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	virtual void SynchronizeProperties() override;

	UFUNCTION(BlueprintCallable)
		virtual void SetImageName(const FString& NewName);
	UFUNCTION(BlueprintCallable)
		void LoadTextureResource();
	void LoadTextureDeffer();
	
	UFUNCTION(BlueprintCallable)
		void UnLoadTextureResource();
	UFUNCTION(BlueprintCallable)
		void ReLoadTextureResource();
	UFUNCTION(BlueprintCallable)
		void MatchTextureSize();
	static void SetSkinName(FSlateBrush& Brush, FSoftObjectPath& SkinName);
public:
	UPROPERTY(BlueprintReadWrite)
		FSoftObjectPath ImageName = nullptr;
	TWeakObjectPtr<UObject> ResourceObject1;
};
