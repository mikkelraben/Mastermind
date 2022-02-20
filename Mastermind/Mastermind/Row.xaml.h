#pragma once

#include "winrt/Microsoft.UI.Xaml.h"
#include "winrt/Microsoft.UI.Xaml.Markup.h"
#include "winrt/Microsoft.UI.Xaml.Controls.Primitives.h"
#include "Row.g.h"

namespace winrt::Mastermind::implementation
{
    struct Row : RowT<Row>
    {
        Row();

        Mastermind::RowViewModel rowViewModel() {
            return m_rowViewModel;
        }

        void rowViewModel(Mastermind::RowViewModel value) {
            m_rowViewModel = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"rowViewModel" });
        }

        static Microsoft::UI::Xaml::DependencyProperty rowViewModelProperty() { return m_rowViewModelProperty; }
        static void OnrowViewModelChanged(Microsoft::UI::Xaml::DependencyObject const&, Microsoft::UI::Xaml::DependencyPropertyChangedEventArgs const&);
        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;
    private:
        Mastermind::RowViewModel m_rowViewModel;

        static Microsoft::UI::Xaml::DependencyProperty m_rowViewModelProperty;
        winrt::event<winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;

    };
}

namespace winrt::Mastermind::factory_implementation
{
    struct Row : RowT<Row, implementation::Row>
    {
    };
}
