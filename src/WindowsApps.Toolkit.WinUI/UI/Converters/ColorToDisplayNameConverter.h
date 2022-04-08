#pragma once

#include "UI.Converters.ColorToDisplayNameConverter.g.h"

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation
{
    using namespace winrt;
    using namespace winrt::Windows::Foundation;
    using namespace winrt::Windows::UI::Xaml::Interop;
    using namespace winrt::Microsoft::UI::Xaml;

    struct ColorToDisplayNameConverter : ColorToDisplayNameConverterT<ColorToDisplayNameConverter>
    {
        ColorToDisplayNameConverter() = default;

    public: //IValueConverter
        IInspectable Convert(IInspectable const& value, TypeName const& targetType, IInspectable const& parameter, hstring const& language);
        IInspectable ConvertBack(IInspectable const& value, TypeName const& targetType, IInspectable const& parameter, hstring const& language);
    };
}

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::factory_implementation
{
    struct ColorToDisplayNameConverter : ColorToDisplayNameConverterT<ColorToDisplayNameConverter, implementation::ColorToDisplayNameConverter>
    {
    };
}
