#pragma once

#include "ResultViewModel.g.h"

namespace winrt::Mastermind::implementation
{
    struct ResultViewModel : ResultViewModelT<ResultViewModel>
    {
        ResultViewModel() = default;

        Windows::UI::Color Color();
        void Color(Windows::UI::Color value);

        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        winrt::event<winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
        Windows::UI::Color m_color;
    };
}

namespace winrt::Mastermind::factory_implementation
{
    struct ResultViewModel : ResultViewModelT<ResultViewModel, implementation::ResultViewModel>
    {
    };
}
