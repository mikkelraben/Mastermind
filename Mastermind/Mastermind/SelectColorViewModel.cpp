#include "pch.h"
#include "SelectColorViewModel.h"
#if __has_include("SelectColorViewModel.g.cpp")
#include "SelectColorViewModel.g.cpp"
#endif

namespace winrt::Mastermind::implementation
{

	winrt::event_token SelectColorViewModel::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
	{
		return m_propertyChanged.add(handler);
	}
	void SelectColorViewModel::PropertyChanged(winrt::event_token const& token) noexcept
	{
		m_propertyChanged.remove(token);
	}
}
