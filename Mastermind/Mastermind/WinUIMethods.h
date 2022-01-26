#pragma once
#include "pch.h"
class WinUIMethods
{
	void initialize();
	void reset();
	void setResult(int color);
	void setupColorButton(winrt::Microsoft::UI::Xaml::Controls::Button &button);
	winrt::Microsoft::UI::Xaml::Controls::Button* Buttons;

};

