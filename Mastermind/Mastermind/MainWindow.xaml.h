#pragma once
#include "MainWindow.g.h"

namespace winrt
{
    using namespace Microsoft::UI;
    using namespace Microsoft::UI::Xaml;
    using namespace Microsoft::UI::Xaml::Controls;
    using namespace Microsoft::UI::Xaml::Navigation;
    using namespace Microsoft::UI::Windowing;
    using namespace Windows::Graphics;
    using namespace Windows::Foundation;
    using namespace Windows::Foundation::Collections;
}

namespace winrt::Mastermind::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();
        void MainFrame_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void BackButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

        void SetCustomTitleBarDragRegion();
        void AppWindowChangedHandler(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Windowing::AppWindowChangedEventArgs const& e);

    private:
        winrt::AppWindow mainAppWindow{ nullptr };
        winrt::event_token m_changedToken;
    };
}

namespace winrt::Mastermind::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
