#pragma once

#include "MainWindow.g.h"

namespace winrt::WindowsApps::Toolkit::WinUI::Test::implementation
{
    using namespace winrt;
    using namespace winrt::Windows::Foundation;
    using namespace winrt::Microsoft::UI::Xaml;

    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();
    };
}

namespace winrt::WindowsApps::Toolkit::WinUI::Test::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
