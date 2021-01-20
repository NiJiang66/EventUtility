#include "EventDataBase.h"


FString UEventDataBase::GetEventName() const
{
	return EventName;
}

FString UEventDataBase::SetEventName(FString InEventName)
{
	// 消除前后空格后输出
	return EventName = InEventName.TrimStartAndEnd();
}

FString UEventDataBase::SetEventNameAndDispatch(FString InEventName)
{
	FString ErrInfo = UEventManager::DispatchEvent(SetEventName(InEventName), this);
	return ErrInfo;
}
