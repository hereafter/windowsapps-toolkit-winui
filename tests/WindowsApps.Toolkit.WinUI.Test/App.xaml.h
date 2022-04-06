#pragma once

#include "App.xaml.g.h"

namespace winrt::WindowsApps::Toolkit::WinUI::Test::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);

    private:
        winrt::Microsoft::UI::Xaml::Window window{ nullptr };
    };
}
