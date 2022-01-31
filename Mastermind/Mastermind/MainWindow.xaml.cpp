﻿#include "pch.h"
#include "MainWindow.xaml.h"
#include "Colors.h"
#include "ColorButton.h"
#include "InFlyoutButton.h"
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
        //myButton().Background(SolidColorBrush(test.color));
        //myButton().Resources().Insert(winrt::box_value(L"ButtonBackgroundPointerOver"), winrt::box_value(SolidColorBrush(test.hoverColor)));
        //myButton().Resources().Insert(winrt::box_value(L"ButtonBackgroundPressed"), winrt::box_value(SolidColorBrush(test.PressedColor)));
        auto btn = SelectColor();
        MainGrid().Children().Append(btn);
        btn.Background(SolidColorBrush(test.color));
        
        test = colors.Colors[1].color;
        InFlyoutButton *button = new InFlyoutButton(test);
        //*button->button
        winrt::Microsoft::UI::Xaml::Controls::Button button1 = *button->button;
        
        MainGrid().Children().Append(button1);

    }


    //void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    //{
    //    myButton().Content(box_value(L"Clicked"));

    //}

}
