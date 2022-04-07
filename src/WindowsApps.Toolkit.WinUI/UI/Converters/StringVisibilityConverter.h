#pragma once

#include "UI.Converters.StringVisibilityConverter.g.h"
#include "EmptyStringToObjectConverter.h"

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation
{
    struct StringVisibilityConverter : StringVisibilityConverterT<StringVisibilityConverter, EmptyStringToObjectConverter>
    {
        StringVisibilityConverter();
    };
}

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::factory_implementation
{
    struct StringVisibilityConverter : StringVisibilityConverterT<StringVisibilityConverter, implementation::StringVisibilityConverter>
    {
    };
}
