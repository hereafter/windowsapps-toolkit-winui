#pragma once
#include "UI.Converters.StringFormatConverter.g.h"



namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::implementation
{
    using namespace winrt;
    using namespace winrt::Windows::Foundation;
    using namespace winrt::Windows::UI::Xaml::Interop;
    using namespace winrt::Microsoft::UI::Xaml;

    struct StringFormatConverter : StringFormatConverterT<StringFormatConverter>
    {
        StringFormatConverter() = default;

    public: //IValueConverter
        IInspectable Convert(IInspectable const& value, TypeName const& targetType, IInspectable const& parameter, hstring const& language);
        IInspectable ConvertBack(IInspectable const& value, TypeName const& targetType, IInspectable const& parameter, hstring const& language);
    };
}

namespace winrt::WindowsApps::Toolkit::WinUI::UI::Converters::factory_implementation
{
    struct StringFormatConverter : StringFormatConverterT<StringFormatConverter, implementation::StringFormatConverter>
    {
    };
}
