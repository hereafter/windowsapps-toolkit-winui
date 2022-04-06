#pragma once

#include "Extensions.StringExtensions.g.h"

namespace winrt::WindowsApps::Toolkit::WinUI::Extensions::implementation
{
    struct StringExtensions : StringExtensionsT<StringExtensions>
    {
        StringExtensions() = default;
    };
}

namespace winrt::WindowsApps::Toolkit::WinUI::Extensions::factory_implementation
{
    struct StringExtensions : StringExtensionsT<StringExtensions, implementation::StringExtensions>
    {
    };
}
