#include "pch.h"
#include "Menu.xaml.h"
#if __has_include("Menu.g.cpp")
#include "Menu.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Mastermind::implementation
{
    Menu::Menu()
    {
        InitializeComponent();
    }

    void Menu::Button_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        this->Parent().as<Microsoft::UI::Xaml::Controls::Frame>().Navigate(xaml_typename<Game>());
    }
}



