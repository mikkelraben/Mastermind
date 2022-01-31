#pragma once

#include "winrt/Microsoft.UI.Xaml.h"
#include "winrt/Microsoft.UI.Xaml.Markup.h"
#include "winrt/Microsoft.UI.Xaml.Controls.Primitives.h"
#include "SelectColor.g.h"

namespace winrt::Mastermind::implementation
{
    struct SelectColor : SelectColorT<SelectColor>
    {
        SelectColor();

        int32_t MyProperty();
        void MyProperty(int32_t value);
    };
}

namespace winrt::Mastermind::factory_implementation
{
    struct SelectColor : SelectColorT<SelectColor, implementation::SelectColor>
    {
    };
}
