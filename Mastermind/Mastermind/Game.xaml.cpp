#include "pch.h"
#include "Game.xaml.h"
#if __has_include("Game.g.cpp")
#include "Game.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Mastermind::implementation
{
    Game::Game()
    {
        InitializeComponent();
    }
}
