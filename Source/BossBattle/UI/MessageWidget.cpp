// Fill out your copyright notice in the Description page of Project Settings.


#include "MessageWidget.h"
#include "Utilities/CustomMacros.h"
#include "Components/TextBlock.h"


void UMessageWidget::SetMessage(const FText& MessageToSet, const FText& SenderToSet) {

	Message = MessageToSet;

	Sender = SenderToSet;
}