#pragma once

#include "UI.Converters.EmptyStringToObjectConverter.g.h"
#include "EmptyObjectToObjectConverter.h"

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation
{
    using namespace winrt;
    using namespace winrt::Windows::Foundation;
    using namespace winrt::Windows::UI::Xaml::Interop;
    using namespace winrt::Microsoft::UI::Xaml;

    struct EmptyStringToObjectConverter : EmptyStringToObjectConverterT<EmptyStringToObjectConverter, EmptyObjectToObjectConverter>
    {
        EmptyStringToObjectConverter() = default;

    public:
        virtual bool CheckValueIsEmpty(IInspectable value);
    };
}

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::factory_implementation
{
    struct EmptyStringToObjectConverter : EmptyStringToObjectConverterT<EmptyStringToObjectConverter, implementation::EmptyStringToObjectConverter>
    {
    };
}
