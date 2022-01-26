#include "pch.h"
#include "WinUIMethods.h"

void WinUIMethods::initialize()
{
}

void WinUIMethods::reset()
{
}

void WinUIMethods::setResult(int color)
{
}

void WinUIMethods::setupColorButton(winrt::Microsoft::UI::Xaml::Controls::Button& button)
{
	winrt::Microsoft::UI::Xaml::CornerRadius corner = winrt::Microsoft::UI::Xaml::CornerRadius();
	corner.BottomLeft = 16;
	corner.BottomRight = 16;
	corner.TopLeft = 16;
	corner.TopRight = 16;

	button.CornerRadius(corner);
	button.Width(32);
	button.Height(32);
	winrt::Microsoft::UI::Xaml::Controls::Flyout flyout;
	winrt::Microsoft::UI::Xaml::Controls::TextBlock text;
	text.Text(L"Hello World!");

	button.Flyout();
}
