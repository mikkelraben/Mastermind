#pragma once

#include "App.xaml.g.h"
#include "SelectColor.h"


namespace winrt::Mastermind::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);

    private:
        winrt::Microsoft::UI::Xaml::Window window{ nullptr };
    };
}
