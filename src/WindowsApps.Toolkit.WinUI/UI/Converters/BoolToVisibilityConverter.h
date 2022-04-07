#pragma once

#include "UI.Converters.BoolToObjectConverter.g.h"
#include "BoolToObjectConverter.h"


namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation
{
    using namespace winrt;
    using namespace winrt::Windows::Foundation;
    using namespace winrt::Windows::UI::Xaml::Interop;
    using namespace winrt::Microsoft::UI::Xaml;
    using namespace winrt::Microsoft::UI::Xaml::Data;

    struct BoolToVisibilityConverter : BoolToVisibilityConverterT<BoolToVisibilityConverter, 
        BoolToObjectConverter>
    {
        BoolToVisibilityConverter();
    };
}

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::factory_implementation
{
    struct BoolToVisibilityConverter : BoolToVisibilityConverterT<BoolToVisibilityConverter, implementation::BoolToVisibilityConverter>
    {
    };
}
