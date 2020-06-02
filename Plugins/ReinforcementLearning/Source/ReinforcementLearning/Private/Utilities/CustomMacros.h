// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class FString;
template <typename RetType = void, class InnerType>
RetType GetLambdaValue(InnerType&& Inner, FString CallingFunc)
{
	return Inner(CallingFunc);
}


#define validate(Expression)                                                  \
	GetLambdaValue<bool>([&] (FString FuncName) {                             \
		if((Expression) == false) {                                           \
			FString CallingActorName;                                         \
			if(StaticClass()->IsChildOf(UActorComponent::StaticClass())) {    \
				const UActorComponent* ActorComponent = Cast<UActorComponent>(this);\
				CallingActorName = ActorComponent->GetOwner()->GetName();     \
			}                                                                 \
			else                                                              \
			{                                                                 \
				CallingActorName = GetName();                                 \
			}                                                                 \
			UE_LOG(LogTemp, Error,                                            \
				TEXT("caller: %s executor: %s at: %s:%d  ("#Expression") == false"),               \
				*CallingActorName,													  \
				*FString(StaticClass()->GetName()),                           \
				*FuncName,                                                    \
				__LINE__                                                      \
			);                                                                \
			return false;                                                     \
		}                                                                     \
		return true;                                                          \
	}, FString(__func__))