#pragma once

#include "BoardViewModel.g.h"

namespace winrt::Mastermind::implementation
{
    struct BoardViewModel : BoardViewModelT<BoardViewModel>
    {
        BoardViewModel() = default;

        Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> Rows();
        void Rows(Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> value);

        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        winrt::event<winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
        Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> m_rows;
    };
}

namespace winrt::Mastermind::factory_implementation
{
    struct BoardViewModel : BoardViewModelT<BoardViewModel, implementation::BoardViewModel>
    {
    };
}
