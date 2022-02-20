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
        Mastermind::ColorViewModel MainColor() {
            return m_mainColor;
        }

        void MainColor(Mastermind::ColorViewModel value) {
            m_mainColor = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"MainColor" });
        }

        Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> Colors() const
        {
            return m_colors;
        }
        void Colors(Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable>const& value)
        {
            m_colors = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Colors" });
        }

        bool Enabled() {
            return m_enabled;
        }

        void Enabled(bool value) {
            m_enabled = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Enabled" });
        }


        void GridView_ItemClick(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::ItemClickEventArgs const& e);

        static Microsoft::UI::Xaml::DependencyProperty MainColorProperty() { return m_colorProperty; }
        static void OnMainColorChanged(Microsoft::UI::Xaml::DependencyObject const&, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);

        static Microsoft::UI::Xaml::DependencyProperty EnabledProperty() { return m_enabledProperty; }
        static void OnEnabledChanged(Microsoft::UI::Xaml::DependencyObject const&, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);

        static Microsoft::UI::Xaml::DependencyProperty ColorsProperty() { return m_colorsProperty; }
        static void OnColorsChanged(Microsoft::UI::Xaml::DependencyObject const&, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);


        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
    private:
        Mastermind::ColorViewModel m_mainColor;
        Windows::Foundation::Collections::IVector<IInspectable> m_colors{ nullptr };
        bool m_enabled;
        int numColors;

        static Microsoft::UI::Xaml::DependencyProperty m_colorProperty;
        static Microsoft::UI::Xaml::DependencyProperty m_enabledProperty;
        static Microsoft::UI::Xaml::DependencyProperty m_colorsProperty;

        winrt::event<winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}

namespace winrt::Mastermind::factory_implementation
{
    struct SelectColor : SelectColorT<SelectColor, implementation::SelectColor>
    {
    };
}
