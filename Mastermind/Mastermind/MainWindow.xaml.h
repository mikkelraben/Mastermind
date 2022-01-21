#pragma once
#include "MainWindow.g.h"

namespace winrt::Mastermind::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();


        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::Mastermind::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
