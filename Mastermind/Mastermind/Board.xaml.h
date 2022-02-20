#pragma once

#include "winrt/Microsoft.UI.Xaml.h"
#include "winrt/Microsoft.UI.Xaml.Markup.h"
#include "winrt/Microsoft.UI.Xaml.Controls.Primitives.h"
#include "Board.g.h"

namespace winrt::Mastermind::implementation
{
    struct Board : BoardT<Board>
    {
        Board();
    private:
        //array of rows
        Windows::Foundation::Collections::IVector<IInspectable> m_rows;
        
        //array of secret;
        int32_t* m_secret;

        //game variables
        uint8_t m_rowCount = 8;
        uint8_t m_columnCount = 4;
        uint8_t m_currentRow = 0;
        uint8_t m_numcolors = 6;
        void generateRows();
        void generateSecret();
    public:
        void CheckResult_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
        void GiveUp_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::Mastermind::factory_implementation
{
    struct Board : BoardT<Board, implementation::Board>
    {
    };
}
