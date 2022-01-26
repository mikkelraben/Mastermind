#pragma once
#include "Color.h"
#include "pch.h"
class InFlyoutButton
{
public:
	InFlyoutButton(m_Color::Color color);
	winrt::Microsoft::UI::Xaml::Controls::Button *button;
};

