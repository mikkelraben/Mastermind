#pragma once

#include "winrt/Microsoft.UI.Xaml.h"
#include "winrt/Microsoft.UI.Xaml.Markup.h"
#include "winrt/Microsoft.UI.Xaml.Controls.Primitives.h"
#include "ColorButton.g.h"

namespace winrt::Mastermind::implementation
{
    struct ColorButton : ColorButtonT<ColorButton>
    {
        ColorButton();

        int32_t MyProperty();
        void MyProperty(int32_t value);
    };
}

namespace winrt::Mastermind::factory_implementation
{
    struct ColorButton : ColorButtonT<ColorButton, implementation::ColorButton>
    {
    };
}
