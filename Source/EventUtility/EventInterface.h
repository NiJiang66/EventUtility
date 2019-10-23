// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EventInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEventInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * �¼��ַ����ƽӿ�
 */
class EVENTUTILITY_API IEventInterface
{
	GENERATED_BODY()
public:
	/** ���¼�����ʱ���ù۲���(������)��ExecuteFun������ʵ�����ͨ��ʵ�ָýӿھͳ�Ϊ�۲���(������) */
	UFUNCTION(BlueprintImplementableEvent, Category = "EventDistributionUtility")
		void ExecuteFun(UObject* Datas);
};
