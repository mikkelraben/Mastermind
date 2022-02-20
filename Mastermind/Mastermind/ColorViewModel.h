#pragma once

#include "ColorViewModel.g.h"

namespace winrt::Mastermind::implementation
{
    struct ColorViewModel : ColorViewModelT<ColorViewModel>
    {
        ColorViewModel() = default;

        int32_t Color();
        void Color(int32_t value);
        Windows::UI::Color Background();
        void Background(Windows::UI::Color value);

        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        winrt::event<winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
        int32_t m_color;
        Windows::UI::Color m_background;
    };
}

namespace winrt::Mastermind::factory_implementation
{
    struct ColorViewModel : ColorViewModelT<ColorViewModel, implementation::ColorViewModel>
    {
    };
}
