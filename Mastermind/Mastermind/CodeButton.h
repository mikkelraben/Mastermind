#pragma once

#include "winrt/Microsoft.UI.Xaml.h"
#include "winrt/Microsoft.UI.Xaml.Markup.h"
#include "winrt/Microsoft.UI.Xaml.Controls.Primitives.h"
#include "CodeButton.g.h"

namespace winrt::Mastermind::implementation
{
    struct CodeButton : CodeButtonT<CodeButton>
    {
        CodeButton();

        int32_t ColorInt();
        void ColorInt(int32_t value) {
            UpdateValue(L"ColorInt", m_ColorInt, value);
        }

        Windows::UI::Color RestColor() {
            return m_Color;
        }
        void RestColor(Windows::UI::Color value) {
            UpdateValue(L"Color", m_Color, value);
        }

        Windows::UI::Color HoverColor(){
            return m_HoverColor;
        }
        void HoverColor(Windows::UI::Color value){
            UpdateValue(L"Color",m_HoverColor,value);
        }

        Windows::UI::Color PressedColor(){
            return m_PressedColor;
        }
        void PressedColor(Windows::UI::Color value){
            UpdateValue(L"Color",m_PressedColor,value);
        }


    private:

        int m_ColorInt;
        Windows::UI::Color m_Color;
        Windows::UI::Color m_HoverColor;
        Windows::UI::Color m_PressedColor;


        // Property changed notification.
        event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;

        template <class T>
        void UpdateValue(hstring const& propertyName, T& var, T value)
        {
            if (var != value)
            {
                var = value;
                RaisePropertyChanged(propertyName);
            }
        }

        void RaisePropertyChanged(hstring const& propertyName)
        {
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs(propertyName));
        }
    };
}

namespace winrt::Mastermind::factory_implementation
{
    struct CodeButton : CodeButtonT<CodeButton, implementation::CodeButton>
    {
    };
}
