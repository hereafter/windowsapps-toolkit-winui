#pragma once

#include "UI.Converters.CollectionVisibilityConverter.g.h"
#include "EmptyCollectionToObjectConverter.h"

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation
{
    struct CollectionVisibilityConverter : CollectionVisibilityConverterT<CollectionVisibilityConverter, 
                EmptyCollectionToObjectConverter>
    {
        CollectionVisibilityConverter();

    };
}

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::factory_implementation
{
    struct CollectionVisibilityConverter : CollectionVisibilityConverterT<CollectionVisibilityConverter, implementation::CollectionVisibilityConverter>
    {
    };
}
