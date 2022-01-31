﻿#include "pch.h"
#include "ColorButton.h"
#if __has_include("ColorButton.g.cpp")
#include "ColorButton.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Mastermind::implementation
{
    ColorButton::ColorButton()
    {
        DefaultStyleKey(winrt::box_value(L"Mastermind.ColorButton"));
    }

    int32_t ColorButton::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void ColorButton::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
}