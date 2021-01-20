#include "EventDataBase.h"


FString UEventDataBase::GetEventName() const
{
	return EventName;
}

FString UEventDataBase::SetEventName(FString InEventName)
{
	// ����ǰ��ո�����
	return EventName = InEventName.TrimStartAndEnd();
}

FString UEventDataBase::SetEventNameAndDispatch(FString InEventName)
{
	FString ErrInfo = UEventManager::DispatchEvent(SetEventName(InEventName), this);
	return ErrInfo;
}
