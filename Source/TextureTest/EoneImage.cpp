// Fill out your copyright notice in the Description page of Project Settings.

#include "EoneImage.h"
#include "Engine/AssetManager.h"
#include "Engine/Texture2D.h"
#include "PaperSprite.h"

#include "Engine/Texture2DDynamic.h"

#define LOCTEXT_NAMESPACE "UMG"
void UNImage::Serialize(FArchive& Ar)
{
	if (Ar.IsCooking() && Ar.IsSaving())
	{
		SetSkinName(Brush, ImageName);
	}
	
	Super::Serialize(Ar);
}

void UNImage::PostInitProperties()
{
	Super::PostInitProperties();
	if (ImageName != nullptr)
	{
		LoadTextureResource();
	}
}

void UNImage::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
}

void UNImage::SynchronizeProperties()
{
	Super::SynchronizeProperties();
}

void UNImage::SetImageName(const FString& NewName)
{
	ImageName = NewName;
	if (NewName == TEXT(""))
	{
		Brush.SetResourceObject(nullptr);
		ResourceObject1 = nullptr;
		return;
	}
	LoadTextureResource();
	MatchTextureSize();
}

void UNImage::LoadTextureResource()
{
	if (ImageName.ResolveObject() || ImageName.TryLoad())
	{
		LoadTextureDeffer();
	}
}

void UNImage::LoadTextureDeffer()
{
	UObject* temp = ImageName.ResolveObject();
	if (temp)
	{
		Brush.SetResourceObject(temp);
		ResourceObject1 = MakeWeakObjectPtr(temp);
	}
}

void UNImage::UnLoadTextureResource()
{
#if !WITH_EDITOR
	Brush.SetResourceObject(nullptr);
#endif
}

void UNImage::ReLoadTextureResource()
{
	if (nullptr != ResourceObject1)
	{
		if (ResourceObject1.IsValid())
		{
			Brush.SetResourceObject(ResourceObject1.Get());
		}
	}
}

void UNImage::MatchTextureSize()
{
	UObject* ResObj = Brush.GetResourceObject();
	if (nullptr == ResObj)
	{
		return;
	}
	if (nullptr != Cast<UTexture2D>(ResObj))
	{
		Brush.ImageSize.X = Cast<UTexture2D>(ResObj)->GetSizeX();
		Brush.ImageSize.Y = Cast<UTexture2D>(ResObj)->GetSizeY();
	}
	if (nullptr != Cast<UTexture2DDynamic>(ResObj))
	{
		Brush.ImageSize.X = Cast<UTexture2DDynamic>(ResObj)->SizeX;
		Brush.ImageSize.Y = Cast<UTexture2DDynamic>(ResObj)->SizeY;
	}
	if(nullptr != Cast<UPaperSprite>(ResObj))
	{
		Brush.ImageSize = Cast<UPaperSprite>(ResObj)->GetSlateAtlasData().GetSourceDimensions();
	}
}

void UNImage::SetSkinName(FSlateBrush& pBrush, FSoftObjectPath& SkinName)
{
	UObject* ImageRes = pBrush.GetResourceObject();
	if (nullptr != ImageRes)
	{
		SkinName.SetPath(ImageRes->GetPathName());
		pBrush.SetResourceObject(nullptr);
	}
}
#undef LOCTEXT_NAMESPACE