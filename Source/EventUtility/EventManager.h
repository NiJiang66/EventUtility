// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SharedPointer.h"
#include "EventManager.generated.h"

/**
 * �¼��ַ����ƹ�����
 */
UCLASS()
class EVENTUTILITY_API UEventManager : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()	
public:
	/** ע��۲���(������) */
	UFUNCTION(BlueprintCallable, Category = "EventDistributionUtility")
		static void AddEventListener(FString EventName, UObject* Listener);
	/** �Ƴ��۲���(������) */
	UFUNCTION(BlueprintCallable, Category = "EventDistributionUtility")
		static void RemoveEventListener(FString EventName, UObject* Listener);

	/** �������ʹ�����������󣬲����ظö���ָ�� */
	UFUNCTION(BlueprintCallable, Category = "EventDistributionUtility")
		static UObject* NewAsset(UClass* ClassType);
	/** �����¼� */
	UFUNCTION(BlueprintCallable, Category = "EventDistributionUtility")
		static FString DispatchEvent(FString EventName, UObject* Datas);

private:
	/** ������й۲��߶�����б�����EventManager�Լ����� */
	static TMap<FString, TArray<UObject*>> AllListener;
};
