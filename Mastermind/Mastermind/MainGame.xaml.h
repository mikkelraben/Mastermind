#pragma once

#include "MainGame.g.h"

namespace winrt::Mastermind::implementation
{
    struct MainGame : MainGameT<MainGame>
    {
        MainGame();


        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::Mastermind::factory_implementation
{
    struct MainGame : MainGameT<MainGame, implementation::MainGame>
    {
    };
}
