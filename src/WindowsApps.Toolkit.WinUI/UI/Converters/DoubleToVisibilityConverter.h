#pragma once

#include "UI.Converters.DoubleToVisibilityConverter.g.h"
#include "DoubleToObjectConverter.h"

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation
{
    struct DoubleToVisibilityConverter : DoubleToVisibilityConverterT<DoubleToVisibilityConverter, DoubleToObjectConverter>
    {
        DoubleToVisibilityConverter();
    };
}

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::factory_implementation
{
    struct DoubleToVisibilityConverter : DoubleToVisibilityConverterT<DoubleToVisibilityConverter, implementation::DoubleToVisibilityConverter>
    {
    };
}
