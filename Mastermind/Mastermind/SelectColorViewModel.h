#pragma once

#include "SelectColorViewModel.g.h"

namespace winrt::Mastermind::implementation
{
    struct SelectColorViewModel : SelectColorViewModelT<SelectColorViewModel>
    {
        SelectColorViewModel() = default;

        Mastermind::ColorViewModel SelectColorViewModel::Selection() {
            return m_selection;
        }

        void SelectColorViewModel::Selection(Mastermind::ColorViewModel value) {
            m_selection = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Selection" });
        }

        bool SelectColorViewModel::Enabled() {
            return m_enabled;
        }

        void SelectColorViewModel::Enabled(bool value) {
            m_enabled = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Enabled" });
        }

        Windows::Foundation::Collections::IVector<IInspectable> SelectColorViewModel::Colors() {
            return m_numberColors;
        }

        void SelectColorViewModel::Colors(Windows::Foundation::Collections::IVector<IInspectable> value) {
            m_numberColors = value;
            m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs{ L"Colors" });
        }

        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        Mastermind::ColorViewModel m_selection;
        bool m_enabled;
        Windows::Foundation::Collections::IVector<IInspectable> m_numberColors;

        winrt::event<winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}

namespace winrt::Mastermind::factory_implementation
{
    struct SelectColorViewModel : SelectColorViewModelT<SelectColorViewModel, implementation::SelectColorViewModel>
    {
    };
}
