#include "pch.h"
#include "InFlyoutButton.h"

InFlyoutButton::InFlyoutButton(m_Color::Color color)
{
	winrt::Microsoft::UI::Xaml::Controls::Button button_l = winrt::Microsoft::UI::Xaml::Controls::Button();
	winrt::Microsoft::UI::Xaml::CornerRadius corner = winrt::Microsoft::UI::Xaml::CornerRadius();
	corner.BottomLeft = 16;
	corner.BottomRight = 16;
	corner.TopLeft = 16;
	corner.TopRight = 16;

	button_l.CornerRadius(corner);
	button_l.Width(32);
	button_l.Height(32);
	button_l.Background(winrt::Microsoft::UI::Xaml::Media::SolidColorBrush(color.color));
	button_l.Resources().Insert(winrt::box_value(L"ButtonBackgroundPointerOver"), winrt::box_value(winrt::Microsoft::UI::Xaml::Media::SolidColorBrush(color.hoverColor)));
	button_l.Resources().Insert(winrt::box_value(L"ButtonBackgroundPressed"), winrt::box_value(winrt::Microsoft::UI::Xaml::Media::SolidColorBrush(color.PressedColor)));
	button = &button_l;
}
