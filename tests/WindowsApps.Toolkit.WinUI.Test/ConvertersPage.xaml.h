#pragma once

#include "ConvertersPage.g.h"

namespace winrt::WindowsApps::Toolkit::WinUI::Test::implementation
{
    struct ConvertersPage : ConvertersPageT<ConvertersPage>
    {
        ConvertersPage();

        bool IsTestOn();
        hstring TestValue();

        void OnButtonClick(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::WindowsApps::Toolkit::WinUI::Test::factory_implementation
{
    struct ConvertersPage : ConvertersPageT<ConvertersPage, implementation::ConvertersPage>
    {
    };
}
