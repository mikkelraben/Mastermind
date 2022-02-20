#include "pch.h"
#include "Board.xaml.h"
#include "Colors.h"
#include "Result.h"
#include <cstdlib>
#if __has_include("Board.g.cpp")
#include "Board.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Mastermind::implementation
{
    Board::Board() : m_rows(winrt::single_threaded_observable_vector<IInspectable>())
    {
        InitializeComponent();
        generateSecret();
        generateRows();

        Microsoft::UI::Xaml::Media::SolidColorBrush background = Resources().TryLookup(winrt::box_value(L"ButtonBackground")).as<Microsoft::UI::Xaml::Media::SolidColorBrush>();
        Windows::UI::Color restedColor = background.Color();
        background.Color(restedColor);
        CheckResult().Background(background);
        static Microsoft::UI::Xaml::Thickness crMargin = Microsoft::UI::Xaml::ThicknessHelper::FromLengths(52 * m_columnCount + 8, 12, 0, 0);
        CheckResult().Margin(crMargin);

    }

    void Board::generateRows()
    {
        Windows::Foundation::Collections::IVector<IInspectable> m_colors = winrt::single_threaded_observable_vector<IInspectable>();
        for (int i = 0; i < m_numcolors; i++)
        {
            masterColors colors (m_numcolors);
            Windows::UI::Color color = colors.Colors[i].color;

            ColorViewModel colorvm;
            colorvm.Color(i);
            colorvm.Background(color);
            m_colors.Append(colorvm);
        }


        for (int i = 0; i < m_rowCount; i++) {
            const Windows::Foundation::Collections::IVector<IInspectable> columns = winrt::single_threaded_observable_vector<IInspectable>();
            Windows::Foundation::Collections::IVector<IInspectable> result = winrt::single_threaded_observable_vector<IInspectable>();
            for (int j = 0; j < m_columnCount; j++) {
                SelectColorViewModel selectcolorvm;
                selectcolorvm.Selection().Color(-1);
                //for all rows other than 1
                if (i == 0)
                {
                    selectcolorvm.Enabled(true);
                }
                else
                {
                    selectcolorvm.Enabled(true);
                }
                selectcolorvm.Colors(m_colors);

                columns.Append(selectcolorvm);

                
                ResultViewModel resultvm;
                resultvm.Color(Windows::UI::Colors::Transparent());
                result.Append(resultvm);
            }
            
            RowViewModel rowvm;

            rowvm.Columns(columns);
            rowvm.Result(result);
            Row row;
            row.rowViewModel(rowvm);

            m_rows.Append(row);
            
            MainGrid().RowDefinitions().Append(Controls::RowDefinition());
            MainGrid().Children().Append(row);
            MainGrid().SetRow(row, i);


        }
        MainGrid().Height(m_rowCount*52+16);
        MainGrid().Width(m_columnCount*56+68);


        for (int i = 0; i < m_columnCount; i++)
        {
            Microsoft::UI::Xaml::Shapes::Ellipse partAnswer;
            partAnswer.Height(44);
            partAnswer.Width(44);
            

            partAnswer.Margin(ThicknessHelper::FromUniformLength(4));
            
            Microsoft::UI::Xaml::Media::SolidColorBrush brush = Microsoft::UI::Xaml::Media::SolidColorBrush(m_colors.GetAt(m_secret[i]).as<ColorViewModel>().Background());
            partAnswer.Fill(brush);
            SecretRow().ColumnDefinitions().Append(Controls::ColumnDefinition());
            SecretRow().Children().Append(partAnswer);
            SecretRow().SetColumn(partAnswer, i);
        }

    }

    void Board::generateSecret(){
        srand(time(0));
        m_secret = new int32_t[m_columnCount];
        for (int i = 0; i < m_columnCount; i++) {
            
            m_secret[i] = rand() % m_numcolors;
            //m_secret[i] = i;
        }
    }
}


void winrt::Mastermind::implementation::Board::CheckResult_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    if(m_currentRow == m_rowCount){
        return;
    }
    bool hasSelectAnswer = true;
    uint8_t* guess = new uint8_t[m_columnCount];
    for (int i = 0; i < m_columnCount; i++)
    {
        guess[i] = m_rows.GetAt(m_currentRow).as<Row>().rowViewModel().as<RowViewModel>().Columns().GetAt(i).as<SelectColorViewModel>().Selection().Color();
        if (guess[i] == 0xff)
        {
            hasSelectAnswer = false;
        }
    }
    if (hasSelectAnswer)
    {

        Result m_result;

        Result::ResultType* result = m_result.getResult(guess, m_secret, m_columnCount);

        winrt::Windows::Foundation::Numerics::float3 translation = CheckResult().Translation();
        translation.y = translation.y + 52;
        CheckResult().Translation(translation);

        if (m_currentRow == m_rowCount - 1) {
            CheckResult().Visibility(Microsoft::UI::Xaml::Visibility::Collapsed);
        }

        Windows::UI::Color accent = Resources().TryLookup(winrt::box_value(L"SystemAccentColor")).as<Windows::UI::Color>();

        for (int i = 0; i < m_columnCount; i++)
        {
            if (result[i] == Result::ResultType::Black)
            {
                m_rows.GetAt(m_currentRow).as<Row>().rowViewModel().as<RowViewModel>().Result().GetAt(i).as<ResultViewModel>().Color(accent);
            }
            if (result[i] == Result::ResultType::White)
            {
                m_rows.GetAt(m_currentRow).as<Row>().rowViewModel().as<RowViewModel>().Result().GetAt(i).as<ResultViewModel>().Color(Windows::UI::Colors::LightGray());
            }
            m_rows.GetAt(m_currentRow).as<Row>().rowViewModel().as<RowViewModel>().Columns().GetAt(i).as<SelectColorViewModel>().Enabled(false);
        }
        m_currentRow++;
    }
}


void winrt::Mastermind::implementation::Board::GiveUp_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    SecretRow().Visibility(Microsoft::UI::Xaml::Visibility::Visible);
}
