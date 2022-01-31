#include "pch.h"
#include "CodeButton.h"
#if __has_include("CodeButton.g.cpp")
#include "CodeButton.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Mastermind::implementation
{
    CodeButton::CodeButton()
    {
        DefaultStyleKey(winrt::box_value(L"Mastermind.CodeButton"));
    }

    int32_t CodeButton::ColorInt()
    {
        throw hresult_not_implemented();
    }

}
