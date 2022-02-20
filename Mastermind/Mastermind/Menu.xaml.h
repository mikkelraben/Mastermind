#pragma once

#include "Menu.g.h"

namespace winrt::Mastermind::implementation
{
    struct Menu : MenuT<Menu>
    {
        Menu();
    public:
        void Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::Mastermind::factory_implementation
{
    struct Menu : MenuT<Menu, implementation::Menu>
    {
    };
}
