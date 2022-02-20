#include "pch.h"
#include "ResultViewModel.h"
#if __has_include("ResultViewModel.g.cpp")
#include "ResultViewModel.g.cpp"
#endif

namespace winrt::Mastermind::implementation
{
    Windows::UI::Color ResultViewModel::Color(){
        return m_color;
    }
    void ResultViewModel::Color(Windows::UI::Color value){
        m_color = value;
        m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Color" });
    }

    winrt::event_token ResultViewModel::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
	{
		return m_propertyChanged.add(handler);
	}
	void ResultViewModel::PropertyChanged(winrt::event_token const& token) noexcept
	{
		m_propertyChanged.remove(token);
	}
}
