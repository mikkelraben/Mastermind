#include "pch.h"
#include "SelectColor.xaml.h"
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
    SelectColor::SelectColor() : m_colors(winrt::single_threaded_observable_vector<IInspectable>())
    {
        InitializeComponent();

    }


    void SelectColor::GridView_ItemClick(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Controls::ItemClickEventArgs const& e)
    {
        MainColor().Color(e.ClickedItem().as<ColorViewModel>().Color());
        MainColor().Background(e.ClickedItem().as<ColorViewModel>().Background());
        ColorPresenter().Background(Microsoft::UI::Xaml::Media::SolidColorBrush(e.ClickedItem().as<ColorViewModel>().Background()));
    }

    Microsoft::UI::Xaml::DependencyProperty SelectColor::m_colorProperty =
        Microsoft::UI::Xaml::DependencyProperty::Register(
            L"MainColor",
            winrt::xaml_typename<ColorViewModel>(),
            winrt::xaml_typename<Mastermind::SelectColor>(),
            Microsoft::UI::Xaml::PropertyMetadata{ winrt::box_value(L"Number??"), Microsoft::UI::Xaml::PropertyChangedCallback{ &SelectColor::OnMainColorChanged } }
    );

    Microsoft::UI::Xaml::DependencyProperty SelectColor::m_enabledProperty =
        Microsoft::UI::Xaml::DependencyProperty::Register(
            L"Enabled",
            winrt::xaml_typename<bool>(),
            winrt::xaml_typename<Mastermind::SelectColor>(),
            Microsoft::UI::Xaml::PropertyMetadata{ winrt::box_value(L"Number??"), Microsoft::UI::Xaml::PropertyChangedCallback{ &SelectColor::OnEnabledChanged } }
    );

    Microsoft::UI::Xaml::DependencyProperty SelectColor::m_colorsProperty =
        Microsoft::UI::Xaml::DependencyProperty::Register(
            L"NumColors",
            winrt::xaml_typename<Windows::Foundation::Collections::IVector<IInspectable>>(),
            winrt::xaml_typename<Mastermind::SelectColor>(),
            Microsoft::UI::Xaml::PropertyMetadata{ winrt::box_value(L"Number??"), Microsoft::UI::Xaml::PropertyChangedCallback{ &SelectColor::OnColorsChanged } }
    );


    void SelectColor::OnMainColorChanged(Microsoft::UI::Xaml::DependencyObject const& d, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
    {
        if (Mastermind::SelectColor theControl{ d.try_as<Mastermind::SelectColor>() })
        {
            // Call members of the projected type via theControl.

            Mastermind::implementation::SelectColor* ptr{ winrt::get_self<Mastermind::implementation::SelectColor>(theControl) };
            // Call members of the implementation type via ptr.

        }
    }

    void SelectColor::OnEnabledChanged(Microsoft::UI::Xaml::DependencyObject const& d, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
    {
        if (Mastermind::SelectColor theControl{ d.try_as<Mastermind::SelectColor>() })
        {
            // Call members of the projected type via theControl.

            Mastermind::implementation::SelectColor* ptr{ winrt::get_self<Mastermind::implementation::SelectColor>(theControl) };
            // Call members of the implementation type via ptr.

        }
    }

    void SelectColor::OnColorsChanged(Microsoft::UI::Xaml::DependencyObject const& d, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
    {
        if (Mastermind::SelectColor theControl{ d.try_as<Mastermind::SelectColor>() })
        {
            // Call members of the projected type via theControl.

            Mastermind::implementation::SelectColor* ptr{ winrt::get_self<Mastermind::implementation::SelectColor>(theControl) };
            // Call members of the implementation type via ptr.

        }
    }

    winrt::event_token SelectColor::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void SelectColor::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
