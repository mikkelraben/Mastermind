#pragma once

#include "MainGame.g.h"

namespace winrt::Mastermind::implementation
{
    struct MainGame : MainGameT<MainGame>
    {
        MainGame();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::Mastermind::factory_implementation
{
    struct MainGame : MainGameT<MainGame, implementation::MainGame>
    {
    };
}
