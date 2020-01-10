// Fill out your copyright notice in the Description page of Project Settings.


#include "MessageWidget.h"
#include "Utilities/CustomMacros.h"
#include "Components/TextBlock.h"


void UMessageWidget::SetMessage(const FText& Message, const FText& Sender) {

	this->Message = Message;

	this->Sender = Sender;
}