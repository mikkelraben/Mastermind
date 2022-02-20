#include "pch.h"
#include "MainWindow.xaml.h"
#include "Colors.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Media;
using namespace Microsoft::UI::Xaml::Controls;



// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::Mastermind::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
        Mastermind::MainWindow m_mainWindow = *this;
        winrt::com_ptr<IWindowNative> windowNative = m_mainWindow.as<IWindowNative>();

        //Get the HWND for the XAML Window
        HWND hWnd;
        windowNative->get_WindowHandle(&hWnd);

        // Get the WindowId for our window
        winrt::WindowId windowId;
        windowId = winrt::GetWindowIdFromWindow(hWnd);

        // Get the AppWindow for the WindowId
        mainAppWindow = Microsoft::UI::Windowing::AppWindow::GetFromWindowId(windowId);

        mainAppWindow.TitleBar().ExtendsContentIntoTitleBar(true);

        m_changedToken = mainAppWindow.Changed({ this, &MainWindow::AppWindowChangedHandler });

        if (MainFrame().ActualTheme() == Microsoft::UI::Xaml::ElementTheme::Dark)
        {
            mainAppWindow.TitleBar().ButtonBackgroundColor(Microsoft::UI::ColorHelper::FromArgb(0, 57, 57, 57));
            mainAppWindow.TitleBar().BackgroundColor(Microsoft::UI::ColorHelper::FromArgb(0, 57, 57, 57));
            mainAppWindow.TitleBar().ButtonInactiveBackgroundColor(Microsoft::UI::ColorHelper::FromArgb(0, 57, 57, 57));
        }
        SetCustomTitleBarDragRegion();
    }
    void MainWindow::MainFrame_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
        MainFrame().Navigate(xaml_typename<Menu>());
        
    }
    void MainWindow::AppWindowChangedHandler(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Windowing::AppWindowChangedEventArgs const& e)
    {
        if (e.DidSizeChange() && sender.as<AppWindow>().TitleBar().ExtendsContentIntoTitleBar())
        {
            SetCustomTitleBarDragRegion();
        }
    }

    void MainWindow::SetCustomTitleBarDragRegion()
    {
        int titleBarHeight = mainAppWindow.TitleBar().Height();
        int buttonWidth = 40;
        int dragRegionWidth = mainAppWindow.Size().Width - buttonWidth;

        std::vector<Windows::Graphics::RectInt32> dragRects;
        Windows::Graphics::RectInt32 dragRect;

        dragRect.X = buttonWidth;
        dragRect.Y = 0;
        dragRect.Height = titleBarHeight;
        dragRect.Width = dragRegionWidth;

        dragRects.push_back(dragRect);
        mainAppWindow.TitleBar().SetDragRectangles(dragRects);
    }

}

void winrt::Mastermind::implementation::MainWindow::BackButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    if (MainFrame().CanGoBack()) {
        MainFrame().GoBack();
    }
}
