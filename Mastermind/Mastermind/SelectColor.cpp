#include "pch.h"
#include "SelectColor.h"
#include "Colors.h"
#if __has_include("SelectColor.g.cpp")
#include "SelectColor.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Mastermind::implementation
{
    SelectColor::SelectColor()
    {
        DefaultStyleKey(winrt::box_value(L"Mastermind.SelectColor"));
        
        
    }

    int32_t SelectColor::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void SelectColor::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
}
