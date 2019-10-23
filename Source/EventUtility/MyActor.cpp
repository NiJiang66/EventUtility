// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include "Engine/Engine.h"
#include "Json.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	
		FString JsonValue = "[{\"author\":\"4446545646544\"},{\"name\":\"jack\"}]";

		FString JsonStr;
		TArray<TSharedPtr<FJsonValue>> JsonParsed;
		TSharedRef< TJsonReader<TCHAR> > JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonValue);

		bool BFlag = FJsonSerializer::Deserialize(JsonReader, JsonParsed);
		if (BFlag)
		{
			int ArrayNumber = JsonParsed.Num();
			if (ArrayNumber == 2)
			{
				FString FStringAuthor = JsonParsed[0]->AsObject()->GetStringField("author");
				if (GEngine)
				{
					FString TmpString = "author :" + FStringAuthor;
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TmpString);
				}
				FString FStringName = JsonParsed[1]->AsObject()->GetStringField("name");
				if (GEngine)
				{
					FString TmpString = "name :" + FStringName;
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TmpString);
				}
			}
		}
	



}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

