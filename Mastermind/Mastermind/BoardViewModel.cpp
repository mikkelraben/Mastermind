#include "pch.h"
#include "BoardViewModel.h"
#if __has_include("BoardViewModel.g.cpp")
#include "BoardViewModel.g.cpp"
#endif

namespace winrt::Mastermind::implementation
{
	Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> BoardViewModel::Rows()
	{
		return m_rows;
	}
	void BoardViewModel::Rows(Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> value)
	{
		m_rows = value;
		m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Rows" });
	}


	winrt::event_token BoardViewModel::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
	{
		return m_propertyChanged.add(handler);
	}
	void BoardViewModel::PropertyChanged(winrt::event_token const& token) noexcept
	{
		m_propertyChanged.remove(token);
	}
}
