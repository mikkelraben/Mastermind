#include "pch.h"
#include "Row.xaml.h"
#if __has_include("Row.g.cpp")
#include "Row.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Mastermind::implementation
{
    Row::Row()
    {
        InitializeComponent();
    }


    Microsoft::UI::Xaml::DependencyProperty Row::m_rowViewModelProperty =
        Microsoft::UI::Xaml::DependencyProperty::Register(
            L"rowViewModel",
            winrt::xaml_typename<Windows::Foundation::Collections::IVector<IInspectable>>(),
            winrt::xaml_typename<Mastermind::Row>(),
            Microsoft::UI::Xaml::PropertyMetadata{ winrt::box_value(L"Number??"), Microsoft::UI::Xaml::PropertyChangedCallback{ &Row::OnrowViewModelChanged } }
    );


    void Row::OnrowViewModelChanged(Microsoft::UI::Xaml::DependencyObject const& d, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const& e)
    {
        if (Mastermind::Row theControl{ d.try_as<Mastermind::Row>() })
        {
            // Call members of the projected type via theControl.

            Mastermind::implementation::Row* ptr{ winrt::get_self<Mastermind::implementation::Row>(theControl) };
            // Call members of the implementation type via ptr.

        }
    }

    winrt::event_token Row::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    void Row::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }
}
