#pragma once

#include "RowViewModel.g.h"

namespace winrt::Mastermind::implementation
{
    struct RowViewModel : RowViewModelT<RowViewModel>
    {
        RowViewModel() = default;

        Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> Columns();
        void Columns(Windows::Foundation::Collections::IVector<IInspectable> value);

        Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> Result();
        void Result(Windows::Foundation::Collections::IVector<IInspectable> value);

        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        winrt::event<winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
        Windows::Foundation::Collections::IVector<IInspectable> m_columns;
        Windows::Foundation::Collections::IVector<IInspectable> m_result;
    };
}

namespace winrt::Mastermind::factory_implementation
{
    struct RowViewModel : RowViewModelT<RowViewModel, implementation::RowViewModel>
    {
    };
}
