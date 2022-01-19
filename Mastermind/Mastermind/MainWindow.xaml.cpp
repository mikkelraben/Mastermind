﻿#include "pch.h"
#include "MainWindow.xaml.h"
#include "Color.h"
#include "Colors.h"
#include "Board.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Media;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Mastermind::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
        masterColors colors;


        m_Color::Color test = colors.Colors[0].color;
        myButton().Background(SolidColorBrush(test.color));
        myButton().Resources().Insert(winrt::box_value(L"ButtonBackgroundPointerOver"), winrt::box_value(SolidColorBrush(test.hoverColor)));
        myButton().Resources().Insert(winrt::box_value(L"ButtonBackgroundPressed"), winrt::box_value(SolidColorBrush(test.PressedColor)));
            

    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
    }
}
