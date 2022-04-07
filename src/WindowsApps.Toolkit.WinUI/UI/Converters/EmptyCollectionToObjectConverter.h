#pragma once

#include "UI.Converters.EmptyCollectionToObjectConverter.g.h"
#include "EmptyObjectToObjectConverter.h"

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation
{
    using namespace winrt;
    using namespace winrt::Windows::Foundation;
    using namespace winrt::Windows::UI::Xaml::Interop;
    using namespace winrt::Microsoft::UI::Xaml;
    using namespace winrt::Microsoft::UI::Xaml::Data;

    struct EmptyCollectionToObjectConverter : EmptyCollectionToObjectConverterT<EmptyCollectionToObjectConverter,
                 EmptyObjectToObjectConverter>
    {
        EmptyCollectionToObjectConverter() = default;

    public:
        virtual bool CheckValueIsEmpty(IInspectable value);
    };
}

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::factory_implementation
{
    struct EmptyCollectionToObjectConverter : EmptyCollectionToObjectConverterT<EmptyCollectionToObjectConverter, implementation::EmptyCollectionToObjectConverter>
    {
    };
}
