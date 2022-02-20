#include "pch.h"
#include "RowViewModel.h"
#if __has_include("RowViewModel.g.cpp")
#include "RowViewModel.g.cpp"
#endif

namespace winrt::Mastermind::implementation
{
	Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> RowViewModel::Columns()
	{
		return m_columns;
	}
	void RowViewModel::Columns(Windows::Foundation::Collections::IVector<IInspectable> value)
	{
		m_columns = value;
		m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Columns" });
	}

	Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> RowViewModel::Result()
	{
		return m_result;
	}
	void RowViewModel::Result(Windows::Foundation::Collections::IVector<IInspectable> value)
	{
		m_result = value;
		m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Result" });
	}

	winrt::event_token RowViewModel::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
	{
		return m_propertyChanged.add(handler);
	}
	void RowViewModel::PropertyChanged(winrt::event_token const& token) noexcept
	{
		m_propertyChanged.remove(token);
	}
}
