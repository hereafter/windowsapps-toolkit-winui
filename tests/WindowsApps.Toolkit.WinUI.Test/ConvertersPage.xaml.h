#pragma once

#include "ConvertersPage.g.h"

namespace winrt::WindowsApps::Toolkit::WinUI::Test::implementation
{
    using namespace winrt;
    using namespace winrt::Windows::Foundation;
    using namespace winrt::Microsoft::UI::Xaml;

    struct ConvertersPage : ConvertersPageT<ConvertersPage>
    {
        ConvertersPage();

        bool IsTestOn();
        hstring TestValue();

        void OnButtonClick(IInspectable const& sender, RoutedEventArgs const& args);


    private:
        void TestBoolToObjectConverter();
    };
}

namespace winrt::WindowsApps::Toolkit::WinUI::Test::factory_implementation
{
    struct ConvertersPage : ConvertersPageT<ConvertersPage, implementation::ConvertersPage>
    {
    };
}
