#include "pch.h"
#include "MainGame.xaml.h"
#if __has_include("MainGame.g.cpp")
#include "MainGame.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Mastermind::implementation
{
    MainGame::MainGame()
    {
        InitializeComponent();
    }

    void MainGame::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }

}
