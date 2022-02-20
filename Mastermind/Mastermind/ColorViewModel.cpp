#include "pch.h"
#include "ColorViewModel.h"
#if __has_include("ColorViewModel.g.cpp")
#include "ColorViewModel.g.cpp"
#endif

namespace winrt::Mastermind::implementation
{
	int32_t ColorViewModel::Color()
	{
		return m_color;
	}
	void ColorViewModel::Color(int32_t value)
	{
		m_color = value;
		m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Color" });
	}
	Windows::UI::Color ColorViewModel::Background()
	{
		return m_background;
	}
	void ColorViewModel::Background(Windows::UI::Color value)
	{
		m_background = value;
		m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Background" });
	}


	winrt::event_token ColorViewModel::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
	{
		return m_propertyChanged.add(handler);
	}
	void ColorViewModel::PropertyChanged(winrt::event_token const& token) noexcept
	{
		m_propertyChanged.remove(token);
	}

}
